function myAlert(data){
	data.title ? $('#alert-dlg #alert-title').html(data.title) : '';
	$('#alert-dlg #alert-content').html(data.content);
	$('#alert-dlg').modal('show');
} 

function fomatFloat(value, fixed, length) {
	var str = ""+value.toFixed(fixed);
	while (str.length < length) {
		str = "0"+str;
	}
	return str;
}



function updateNodes(nodes) {
	var tbody = $("#node-table tbody");
	tbody.children().remove();
	var str = "";
	//console.log(nodes.length);
	
	nodes.forEach(function(node) {
		str += "<tr class='gradeX' >";
		//str += sprintf("<td>%s</td>", node.id);
		str += sprintf("<td><a target='_blank' href='%s' title='%s'>%s</a></td>", node.url, node.url, node.name);  	
		
		var oper = (node.status == 1 ? '运行':'停运');
    	str += sprintf("<td><i class='fa %s' style='color:%s' title='%s'> %s</i> </td>",(node.status == 1 ? 'fa-circle' : 'fa-circle'), (node.status == 1 ? 'green':'black')
    			, oper, oper);
   	    var dt = new Date(node.lastUpdate);
    	
    	str += sprintf("<td>%s</td>", dt.Format('yyyy-MM-dd HH:mm:ss.SSS'));
    	
    	str += sprintf("<td>%s</td>", node.cpuRate != null ? progressBar(node.cpuRate) : '-' );
    	str += sprintf("<td>%s</td>", node.memoryRate != null ? progressBar(node.memoryRate) : '-' );
    	
    	str += sprintf("<td>%s</td>",node.taskCount !=null && node.taskCount > 0 ? node.taskCount : '-' );
    	str += sprintf("<td>%s</td>",node.jobCount !=null && node.jobCount > 0 ? node.jobCount : '-' );
	    
    	var oper = "";
    	if (node.status==1) {
    		oper = "暂停";
    	} else if (node.status==2) {
    		oper = "继续";
    	} 
    	if (oper.length > 0)
    	str += sprintf("<td data-id='%s' data-state='%s'> "
	            +" <button class='btn btn-info btn-xs node-state' type='button'  title=%s> %s </button>"
	            +"</td>", node.status, node.id, oper, oper);
	        
		str += "</tr>";
	});
	
		
	tbody.append(str);
	
	$(".node-delete").click(function () {
		var id = $(this).parent().attr("data-id");
		
		$.ajax({
			url : "node/delete/"+id,
			type : "POST",
			data : null,

			success : function(msg) {
				console.log(msg);
				window.location.href ="/home";
			},
			error : function() {
				alert("fail to delete node : id= "+ id);
			}
		});
	});
	
	$(".node-edit").click(function() {
		var id = $(this).parent().attr("data-id");
		
		window.location.href = "/node/edit/"+id;
		
	});
}


function updateModels(models) {
	var tbody = $("#model-table tbody");
	tbody.children().remove();
	var str = "";
	//console.log(nodes.length);
	
	models.forEach(function(model) {
		str += "<tr class='gradeX' >";
		//console.log(model);
		
		//str += sprintf("<td>%s</td>", node.id);
		
		var url = "model/browse/"+model.id;
		
		str += sprintf("<td><a target='_blank' href='%s' title='%s'>%s</a></td>", url, url, model.name);
		
		str += sprintf("<td>%s</td>", (model.desc != null)? model.desc : "");

		str += sprintf("<td>%s</td>", (model.lastUpdate != null ? new Date(model.lastUpdate).Format('yyyy-MM-dd HH:mm:ss.SSS') : '-'));
		str += sprintf("<td>%s</td>", (model.space != null ? formateByte(model.space) : '-'));
		
		
    	str += sprintf("<td data-id='%s'> "
	            +" <button class='btn btn-info btn-xs model-remove' type='button'  title='删除模型包含的文件'> 删除 </button>"
	            +"</td>", model.id);
    	
		str += "</tr>";
		
	});
	
		
	tbody.append(str);
	
	$(".model-remove").click(function () {
		var id = $(this).parent().attr("data-id");
		
		$.ajax({
			url : "/model/remove/"+id,
			type : "POST",
			data : null,

			success : function(msg) {
				if (msg.code=='OK')
					;//alert("succeed to remove model : "+id);
				else
					myAlert({
						title : '删除模型失败',
						content :msg.detail
						});
					
			},
			error : function() {
				alert("fail to remove model : id= "+ id);
 				}
 			});
 		});
    	
    }
    
   // setting defaults for the editable
$.fn.editable.defaults.mode = 'inline';
 
    // 格式化显示  
function valueFormatter(value, row, index) {
    if (value != undefined && value.type != 'p_group' ) {
      	//if (value.value != undefined)
    	  //return sprintf('<a href="#" id="%s">%d</a>', value.id, value.value);
      	//else
      	  return sprintf('<a href="#" id="%s" style="width:%s;margin:0;padding:0"></a>', value.id, "100%");
    } else {
      return '';
    }
}
function progressBar(value, fixed, length) {
	if (fixed == undefined) {
		fixed = 1;
	}
	
	if (length == undefined) {
		length = 4;
	}
	
	var str = '';
	var v = fomatFloat(value, fixed, length);
	str += sprintf("<span class='pull-right'> %s</span>", v+'%');
	str += "<div class='progress' style='margin-bottom:0px'>";
    str += sprintf("<div class='progress-bar' role='progressbar' aria-valuenow='%s' aria-valuemin='0' aria-valuemax='100'  style='width:%s'></div>",v,v+'%');
    str += '</div>';
    return str;
}

function progressFormatter(value) {
	return value != null? progressBar(job.progress) : progressBar(0);
}

function dateFormatter(value) {
	if (value != null) {
		var dt = new Date(value);
		return dt.Format('yyyy-MM-dd HH:mm:ss.SSS');    			
	} else {
		return '-';
	}
}

/* key1:value1,key2:value2*/
function toValueList(content) {
	if (content === undefined || content.trim() == '') {
		return [];
	}
	return content.split(/;|,/).map(function(o) {var segs = o.trim().split(':'); return {value:segs[0].trim(), text:segs[1].trim()}; })
}

function toValueMap(content) {
	var vm = {};
	toValueList(content).forEach(function (rec){vm[rec.value] = rec.text;});
	return vm;
}

function jobFormatter(value) {
	//return value.name;
	return sprintf("<a target='_blank' href='%s' title='%s'>%s</a>", value.url, value.url, value.name);
}

function modelFormatter(value) {
	//return value.id;
	return sprintf("<a target='_blank' href='%s' title='%s'>%s</a>", value.url, value.url, value.name);
}


var onClickJobBtn = function (btn) {
	//$(btn);   	
	var id = $(btn).attr("data-id");
	var oper = $(btn).attr("data-type");
	
	console.log("Post job operataion : id= "+id+", operation="+oper);
	$.ajax({
		url : "/job/"+oper+"/"+id,
		type : "POST",
		data : null,

		success : function() {
			jobApi.getJobs(initJobTable);
		},
		error : function() {
			alert("fail to "+oper+" job : id= "+ id);
		}
	});   	
}

function jobOperationFormater(value) {

   var states = [{
	   				title:'停止正在进行的计算',
	   				name:'停止',
	                btn:'btn-info',
	                type:'stop'
	             }, {
	            	 title:'暂停正在进行的计算',
	            	 name:'暂停',
	            	 btn:'btn-info',
	            	 type:'pause'
	             }, {
	            	 title:'启动计算任务',
	            	 name:'启动',		            	 
	            	 btn:'btn-info',
	            	 type:'restart'
	             }, {
	            	 title:'取消正在计算的任务',
	            	 name:'取消',		            	 
	            	 btn:'btn-warning',
	            	 type:'cancel'
	             }];
   
   var html = "";
   states.forEach(function (state) {
	   html += sprintf(" <button data-id='%s' class='btn %s btn-xs job-btn' data-type='%s' type='button'  title='%s' onclick='onClickJobBtn(this)'> %s </button> ", 
			   value.id, state.btn, state.type, state.title, state.name);
   });
   
  // console.log("jobOperationFormater");
   return html;
}

function extendJob(jobs) {
	var modelProperty = adsApi.findPropertyName('CalcJob', 'modelId');
	//console.log(modelProperty);
    	var modelMap = toValueMap(modelProperty.optionValues);
    	
    	var i = 0;
 
    	
    	jobs.forEach(function(job) {
    		var modelName = modelMap[job.modelId];
    		if (modelName === undefined)
    			modelName = job.modelId;
    		 
    		$.extend(job,{
    			name : {
    				name:(job.name != null ? job.name : job.id),
    				url: "job/browse/"+job.id
				},
			operation : {
				state: job.state, 
				id: job.id
             },
             model: {
            	 id: job.modelId, 
            	 name: modelName, 
            	 url: "model/browse/"+job.modelId
             },
             number: i++
		});
    });
	
	return jobs;
}

function updateJobTable(jobs) {
	jobs = extendJob(jobs).map(function (job) {
		return {
            id: job.id,
            row: {
                state: job.state
            }
        }
	});
	
	$("#table-job").bootstrapTable('updateByUniqueId', jobs);	
    	   	
    }
   
    function initJobTable(jobs) {
    	jobs = extendJob(jobs);
    	
    	//console.log(modelMap);
	var columns = [{
			      	  field: 'number',
			    	  title: '序号',
			       }, {
    	              field: 'id',
    	              title: '标识',
    	              visible: false
    	           }, {
	            	  field: 'name',
	            	  title: '名称',
	            	  formatter: jobFormatter
	               }, {
 	            	  field: 'model',
 	            	  title: '模型',
 	            	  formatter : modelFormatter
 	               }, {
 	            	  field: 'progress',
 	            	  title: '进度',
 	            	  formatter : progressFormatter
 	               }, {
 	            	  field: 'state',
 	            	  title: '状态',
 	               }, {
 	            	  field: 'start',
 	            	  title: '开始时间',
 	            	  formatter : dateFormatter
 	               }, {
 	            	  field: 'end',
 	            	  title: '结束时间',
 	            	  formatter : dateFormatter
 	               }, {
 	            	  field: 'elapse',
 	            	  title: '耗时',
 	               }, {
 	            	  field: 'operation',
 	            	  title: '操作',
 	            	  formatter : jobOperationFormater
 	               }];

	
	$("#table-job").bootstrapTable('destroy').bootstrapTable({
	    striped: true,                      //是否显示行间隔色
	    width: 300,
	    uniqueId: 'id',
		//height : 400,
		pagination: jobs.length < 100 ? false : true ,
		pageSize: 100,
		pageList: [10, 25, 50, 100], 
		//minimumCountColumns: 10,             //最少允许的列数
		toggle: 'table',
		showColumns : true,                  //是否显示所有的列
		//dataToggle:table,                    //是否显示详细视图和列表视图的切换按钮
		//detailView: true,
		//detailFormatter : detailFormatter,
		search:true,
		//showToggle:false,                    //是否显示详细视图和列表视图的切换按钮
		//queryParams: queryParams,//传递参数（*）
		//showExport: true,                     //是否显示导出
		exportDataType: "all",              //basic', 'all', 'selected'.
	    columns: columns,
	    data: jobs,
	    toolbar: '#job-toolbar'
	});	
	

}

$(function () {
	$('.js-activated').dropdownHover().dropdown();

	setTimeout(function(){
		nodeApi.getNodes(updateNodes);
		//var jobs = jobApi.getJobs();
		//updateJobs(jobs);
		//initJobTable(jobs);
		 jobApi.getJobs(initJobTable);
		modelApi.getRoots(updateModels);
	}, 0);
	
	setInterval(function(){
		nodeApi.getNodes(updateNodes);
		//jobApi.getJobs(updateJobs);
		modelApi.getRoots(updateModels);
		//var jobs = jobApi.getJobs();
		//updateJobs(jobs);
		jobApi.getJobs(updateJobTable);
		//jobApi.getJobs(initJobTable);
	}, 500);
	
	  // We can attach the `fileselect` event to all file inputs on the page
	  $(document).on('change', ':file', function() {
	    var input = $(this),
	        numFiles = input.get(0).files ? input.get(0).files.length : 1,
	        label = input.val().replace(/\\/g, '/').replace(/.*\//, '');
	    input.trigger('fileselect', [numFiles, label]);
	  });

	  // We can watch for our custom `fileselect` event like this
      $(':file').on('fileselect', function(event, numFiles, label) {

          var input = $(this).parents('.input-group').find(':text'),
              log = numFiles > 1 ? numFiles + ' files selected' : label;

          if( input.length ) {
              input.val(log);
          } else {
              if( log ) alert(log);
          }

      });

	  
		$("#upload-model-form input[type=file]").change(function() {
			var file = $(this).val();
			 var pos=file.lastIndexOf("\\");
			    
			var fileName = file.substring(pos+1); 
			pos = fileName.lastIndexOf('.');
			var modelName = fileName.substring(0, pos);
			var input = $('#upload-model-form input[name="name"]');
			if (input.val()=='')
				input.val(modelName);
			
			var input = $('#upload-model-form input[name="desc"]');
			if (input.val()=='')
				input.val(modelName);
			
			localStorage['modelName'] = modelName; 
			//alert("on change file:"+fileName);
		});
			
	  $('#upload-model-form').submit(function(e) {
		 event.preventDefault();
		 var data = new FormData($('#upload-model-form')[0]);
         data.append('type', 'BPA');
		$.ajax({
			type : 'POST',
			enctype : 'multipart/form-data',
			url : "/model/upload",
			data : data,
			processData : false, // prevent jQuery from automatically
									// transforming the data into a query
									// string
			contentType : false,
			cache : false,
			timeout : 600000,
			success : function(msg) {
				if (msg.code == 'OK') {
					//alert('上传模型成功.');	
					//window.close();
					$('#upload-model-dlg').modal('hide');
				} else {
					alert('上传模型失败 : ' + msg.detail);
				}
				
				
			},
		    error: function (e) {
		        alert('fail to upload model : ' +e);
		    }
		});
	  });
	  
	 var $table = $('#config-table'); 
	  
	 $('#new-job-dlg').on('shown.bs.modal', function () {
		 		 
		$('#new-job-dlg #name').val(jobApi.newJobName());	 
		
		 var records = adsApi.getDefaultProperty("reliability");
		 var datas = records.map(function (value) {
			return {id:value.id, name:value.name, pid:value.pid, value:value}; 
		 });
		 
		 
		 var w = $table.width() *.382;
		 //console.log("table width:"+w);
		 $table.bootstrapTable('destroy').bootstrapTable({
		     // url:"/job/config/reliability",
		      //height: $(window).height(),
		      striped: true,
		      //sidePagination: 'server',
		      idField: 'id',
		      data: datas,
		      columns: [
		        {
		          field: 'name',
		          title: '名称',
		          width: w
		        //  checkbox: true
		        },

		        // {field: 'id', title: '编号', sortable: true, align: 'center'},
		        // {field: 'pid', title: '所属上级'},
		        {
		          field: 'value',
		          title: '值',
		         // sortable: true,
		          align: 'center',
		          formatter: 'valueFormatter',
		          //editable: {
	                   // type: 'text',
	                   // title: '值',
	                   // validate: function (v) {
	                    //    if (!v) return '值不能为空';

	                   // }
	                //}
		        }
		      ],
		     onEditableSave: function (field, row, oldValue, $el) {
		    	 
		     },
		      // bootstrap-table-tree-column.js 插件配置
		      // treeShowField: 'name',
		      // parentIdField: 'pid'
		      // bootstrap-table-tree-column.js 插件配置
		      // bootstrap-table-treegrid.js 插件配置
		      treeShowField: 'name',
		      parentIdField: 'pid',
		      //onLoadSuccess: function(data) {
 			  onPostBody : function(data) {
 			        //console.log('load');
 			        // jquery.treegrid.js
 			        $table.treegrid({
 			          // initialState: 'collapsed',
 			          treeColumn: 0,
 			          expanderExpandedClass: 'fa fa-minus',
 			          expanderCollapsedClass: 'fa fa-plus',
 			          onChange: function() {
 			            $table.bootstrapTable('resetWidth');
 			          }
 			        });
 			  }
		 });
		 

		//增加编辑行为
		records.forEach(function(record) {
			var editor = $('#'+record.id);
 			if (record.type == 'p_group') {
 				return;
 			} else if (record.optionValues != null && record.optionValues.length > 0) {
 				editor.editable({
 	 			   type: 'select',
 	 			   toggle: 'mouseenter',
 	 			   value: record.value,
 	 			   source : toValueList(record.optionValues),
 	 			   title: record.name,
 	 			   showbuttons:false
 	 			}); 
 			} else {
 				editor.editable({
 	 			  type: 'text',
 	 			  toggle: 'mouseenter',
 	 			  value: record.value,
 	 			  // pk: 1,
 	 			  //url: '/post',
 	 			  title: record.name,
 	 			  showbuttons:false
 	 			}); 		
 			}
 			editor.on("save", function(e, params) {
 			    //alert('Saved value: ' + params.newValue);
 			    record.value = params.newValue;
 			});
					
		});
		
// 			$('#username').editable({
 //			    type: 'text',
		   // pk: 1,
		    //url: '/post',
// 			    title: 'Enter username'
// 			});
     });
	 
	 $("#commit-job-btn").on('click', function() {
		var config = {};
		 $table.bootstrapTable('getData').forEach(function(obj) {
			//console.log(obj);
			
			if (obj.value.type != 'p_group') {
				config[obj.id] = obj.value.value;
			}
		});

		console.log(JSON.stringify(config));
		
		
		var job = {
				name:$("#new-job-dlg #name").val(),
		        desc:$("#new-job-dlg #desc").val(),
				modelId:config.modelId, 
				typeId:'reliability', 
				parameter:JSON.stringify(config)	
		};
		
		$.ajax({
			type : 'POST',
			url : "/job/add",			
			data : job,
			dataType:'json',
			success : function(msg) {
				if (msg.code == 'OK') {
					console.log('新建工作成功.');	
					//window.close();
					$('#new-job-dlg').modal('hide');
					jobApi.getJobs(initJobTable);
				} else {
					alert('上传模型失败 : ' + msg.detail);
				}				
			},
		    error: function (e) {
		        alert('fail to upload model : ' +e);
		    }
		});
		
	 });
	 
	 
	// updateJobTable();
	 
});
