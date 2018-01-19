package com.znd.ei;

import java.io.File;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.context.ApplicationContext;
import org.springframework.stereotype.Component;

import com.znd.ei.codegen.service.CheckService;
import com.znd.ei.codegen.service.ClassCreateService;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.DbException;
import com.znd.ei.memdb.MetaField;
import com.znd.ei.memdb.MetaTable;

/**
 * 
 * @author wangheng
 *
 *处理一些命令行参数
 *
 */
@Component
public class AppCommand  {
	static  Logger logger = Logger.getLogger(AppCommand.class.getName());
	private ApplicationArguments args;
	
	@Autowired
	private ApplicationContext context;
	
	@Autowired
	public AppCommand(ClassCreateService classCreator, CheckService checkService, DbEntryOperations[] opss, ApplicationArguments args) {
		this.args = args;
		
		String strs[] = args.getSourceArgs();
		if (strs.length == 0) {
			System.out.println("--createCode for generating code for memdb. ");
			System.out.println("--check for checking memdb. ");
			System.out.println("--showdbs for db list.");
			System.out.println("--showdb");
			System.out.println("--showtable");
			System.out.println("--desctable");
			System.out.println("--export=csv export info to csvfile");
			
			return;
		}
		if (args.containsOption("showdbs")) {
			for (DbEntryOperations ops : opss) {
				System.out.println(ops.getName()+" "+ops.getDescription());
			}
			System.out.println(String.format("Sum is %d",opss.length));
		}
		if (args.containsOption("showdb")) {
			List<String> dbinfos = args.getOptionValues("showdb");

			for (DbEntryOperations ops : opss) {
				if (dbinfos.contains(ops.getName())) {
					
				   System.out.println(ops.getName()+" "+ops.getDescription());
				   List<MetaTable> tables = ops.getTables();
				   for (MetaTable table : tables) {
					   System.out.println("    "+table.getName()+" "+table.getDescription());
				   }
				   System.out.println(String.format("Sum is %d",tables.size()));
				}
			}	
		}
		//boolean export = args.containsOption("export");
		boolean export = true;
		if (args.containsOption("showtable")) {
			List<String> tables = args.getOptionValues("showtable");
			List<String> dbs = args.getOptionValues("db");
			
			if (tables == null || tables.isEmpty()) {
				System.out.println("Find no table.");
			}
			for (DbEntryOperations ops : opss) {
				if (dbs == null || dbs.isEmpty() || dbs.contains(ops.getName())) {			   
				   System.out.println(ops.getName()+" "+ops.getDescription());
				   List<MetaTable> mtables = ops.getTables();
				   int tablesum = 0;
				   for (MetaTable table : mtables) {
					  
					   if (tables.contains(table.getName())) {
						   System.out.println("    "+table.getName()+" "+table.getDescription());
						   List<MetaField> fields = table.getFields();
						   String dent = "       ";
						   System.out.print(dent);
						   for (MetaField f : fields) {
							   System.out.print(f.getName()+" ");
						   }
						   System.out.println();
						   
						   System.out.print(dent);
						   for (MetaField f : fields) {
							   System.out.print(f.getDescription()+" ");
						   }
						   System.out.println();
						   List<String[]> records = null;
						   try {
							   records = ops.findAllRecords(table);
							} catch (DbException e) {
								// TODO Auto-generated catch block
								e.printStackTrace();
								return;
							}
						   
						   if (records != null) {
							   for (String[] record : records) {
								   System.out.print(dent);
								   for (String f : record) {
									   System.out.print(f+" ");
								   }
								   System.out.println();
							   }
						   }
						   
						   System.out.print("       ");
						   System.out.println(String.format("Record sum is %d", records != null ? records.size() : 0));
						   tablesum++;
					   }
				   }
				   System.out.println(String.format("Table sum is %d",tablesum));
				}
			}	
		}
		
		if (args.containsOption("desctable")) {
			List<String> tables = args.getOptionValues("desctable");
			List<String> dbs = args.getOptionValues("db");
			System.out.println("Table filter is : "+String.join(",", tables));
			 int tablesum = 0;
			String path = "export/desc";
			if (export) {
				File file = new File(path);
				if (!file.exists()) {
					file.mkdirs();
				}
			}
			for (DbEntryOperations ops : opss) {
				if (dbs == null || dbs.isEmpty() || dbs.contains(ops.getName())) {	
				   String base = path+"/" +ops.getName();	
					File baseDir = new File(base);
					if (!baseDir.exists()) {
						baseDir.mkdirs();
					}
					
				   System.out.println(ops.getName()+" "+ops.getDescription());
				   List<MetaTable> mtables = ops.getTables();
				  
				   for (MetaTable table : mtables) {
					   boolean flag = false;
					  if (tables == null || tables.isEmpty())
						  flag = true;
					  else {
						  for (String rx : tables) {
							  if (rx.compareTo(table.getName()) == 0) {
								  flag = true;
								  break;
							  }
						  }
					  }
					 

					   if (flag) {
						   System.out.println("    "+table.getName()+" "+table.getDescription());
						   List<MetaField> fields = table.getFields();
						   String dent = "       ";
						   CSVFile file = null;
						   if (export) {
							   
							   file = new CSVFile(base+"/"+table.getName()+".csv");
							   file.line().add("序号").add("名称").add("描述").add("类型").add("长度").end();
						   }
						   for (MetaField f : fields) {
							   System.out.print(dent+f.getIndex()+" "+f.getName()+" "+f.getDescription()+" "+f.getType()+" "+f.getLen());
							   System.out.println();
							   if (file != null) {
								   file.line().add(f.getIndex()).add(f.getName()).add(f.getDescription()).add(f.getType().name()).add(f.getLen()).end();
							   }
							   
						   }
						   
						   if (file != null) {
							   file.close();
							   System.out.println("Save to file :"+file.getPath());
						   }
						    
						   tablesum++;
					   }
				   }
				   

				}
				
			}	
			
		   if (tablesum==0) {
				System.out.println("Find no table.");
				return;
		   }
		   System.out.println(String.format("Table sum is %d",tablesum));
		}
		
		if (args.containsOption("check")) {
			checkService.check(opss, ".");
		}
		
		
		if (args.containsOption("createCode")) {
			logger.log(Level.INFO, "Create code");
			//classCreator.deleteAll();
			checkService.check(opss, classCreator.getRootLocation().toString());
			classCreator.init();
			classCreator.createClasses();
			
			//System.exit(SpringApplication.exit(SpringApplication));
		} 
		
		if (args.containsOption("createCode")) {
			logger.log(Level.INFO, "Create code");
			//classCreator.deleteAll();
			checkService.check(opss, classCreator.getRootLocation().toString());
			classCreator.init();
			classCreator.createClasses();
			
			//System.exit(SpringApplication.exit(SpringApplication));
		} 
		if (args.containsOption("createCode")) {
			checkService.check(opss, classCreator.getRootLocation().toString());			
		}
		

		
		
		if (args.containsOption("clear")) {
			//classCreator.deleteAll();
			classCreator.init();			
		}
		
		
		//System.out.println("arguments:"+args.toString());
		
		//List<String> files = args.getNonOptionArgs();
		// if run with "--debug logfile.txt" debug=true, files=["logfile.txt"]
	}

	

	
}
