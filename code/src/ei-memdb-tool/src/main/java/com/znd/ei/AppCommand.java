package com.znd.ei;

import java.util.ArrayList;
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
