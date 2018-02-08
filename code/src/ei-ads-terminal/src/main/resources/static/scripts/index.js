var stateSampleConfigNames = [];


var init = function() {
	
	var modelName = localStorage['modelName']; 
	$("#modelName").val(modelName); 
	$("#modelName").change(function() { 
	  localStorage['modelName'] = $(this).val(); 
	  console.log("modelName :"+$(this).val()); 
	}); 
	
	$.ajax({
		url : "pr/adequacySetting",
		type : "GET",
		data : null,

		success : function(config) {
			console.log("PRAdequacySetting = " + JSON.stringify(config));

			$.each(config, function(name, value) {
				var control = $("#" + name);
//				if (control == null)
//					continue;
				
				//stateSampleConfigNames.push(name);
				// console.log("control type is "+control.attr('type')+",
				// id="+name);
				if (control.length != 0) {
					if (control.attr('type') == "text") {
						control.val(value);
					} 
					else if (control.attr('type') == "checkbox") {
						value == '1' ? control.attr("checked", true) : control
								.attr("checked", false);
					} else {
						var cname = "input[name='{0}'][value={1}]".format(name,
								value);
						$(cname).attr("checked", true);
					} 
			    }
			});

		},
		error : function() {
			alert("get default PRAdequacySetting failed!");
		}
	});


	$("input[type=file]").change(function() {
		var file = $(this).val();
		 var pos=file.lastIndexOf("\\");
		    
		var fileName = file.substring(pos+1); 
		pos = fileName.lastIndexOf('.');
		var modelName = fileName.substring(0, pos);
		$('#modelName').val(modelName);
		localStorage['modelName'] = modelName; 
		//alert("on change file:"+fileName);
	});

	$("#pbar_outerdiv").hide();
};

$(document).ready(init);




$('#cancel-calc-reliability').click(function() {
	//pbar.stop();
	$('#request-response').html('Succeed to cancel!');
	//$("#pbar_outerdiv").toggle("slow");
	$("#log-brower").toggle("slow");
	 $("#start-calc-reliability").prop("disabled", false);
});

$.fn.serializeObject = function()
{
    var o = {};
    var a = this.serializeArray();
    $.each(a, function() {
        if (o[this.name]) {
            if (!o[this.name].push) {
                o[this.name] = [o[this.name]];
            }
            o[this.name].push(this.value || '');
        } else {
            o[this.name] = this.value || '';
        }
    });
    return o;
};

var browser = LogBrowser();

$('#clear-database').click(function() {
	var data = $("#modelName").val();
	$.ajax({
		url : "pr/clearDatabase/"+data,
		type : "POST",
		data : null,

		success : function(msg) {
			console.log(msg);

		},
		error : function() {
			alert("fail to clear!");
		}
	});
});

$('#start-calc-reliability').click(
		function() {
			var f = $("#pr-adequacy-setting-form");
			var prAdequacySetting = f.serializeObject();
			
			var checkbox = f.find("input[type=checkbox]"); 
			$.each(checkbox, function(key, val) { 
				prAdequacySetting[$(val).attr('name')] = ($(val).is(":checked") ? 1 : 0);		 
            }); 
			
		    // Get form
		    //var form = $('#model-config-form')[0];
			var form = $('#pr-adequacy-setting-form')[0];

		    var data = new FormData(form);
			
		    var setting = JSON.stringify(prAdequacySetting);
		    data.append("setting", setting);
					   
			$.ajax({
				type : "POST",
				enctype : 'multipart/form-data',
				url : "./pr/submitCalc",
				data : data,
				// http://api.jquery.com/jQuery.ajax/
				// https://developer.mozilla.org/en-US/docs/Web/API/FormData/Using_FormData_Objects
				processData : false, // prevent jQuery from automatically
										// transforming the data into a query
										// string
				contentType : false,
				cache : false,
				timeout : 600000,
				success : function(msg) {
					console.log('calc reliability request accepted : ' + JSON.stringify(msg));
					//$('#request-response').html(msg.code == 'OK'?'Request accepted!' : 'Fail to submit calc : ' + msg.detail);
					$("#start-calc-reliability").prop("disabled", true);
				},
				 error: function (e) {
			            $("#request-response").html(e.responseText);
			            console.log("ERROR : ", e);
			            $("#start-calc-reliability").prop("disabled", true);
			        }

			});

			
			$("#log-brower").show();
			
			//browser.animateUpdate();
			browser.updateLog();
			$("#log-update").click(function () {
				browser.updateLog();
			});
		});

function LogBrowser() {
	var logger = {};
	
	
	logger.timeoutVal = 3000;
	logger.stopFlag = false;

	logger.updateLog = function() {
		var modelName = $("#modelName").val();
		$.ajax({
			url : "pr/log/"+modelName,
			type : "GET",
			data : modelName,

			success : function(logs) {
				if (logs == null)
					return;
				
				console.log("get logs size : "+logs.length);
				for (var i = 0; i < logs.length; i++) {
					var txt = $.trim(logs[i]);
					  var box = $("#text-box");
					  box.val(box.val()+"\n " + txt);
					  console.log(logs[i]);
				}
									
			},
			error : function() {
				console.log("Fail to get logs!");
			}
		});
	};

	logger.stop = function() {
		this.stopFlag = true;
	}

	logger.animateUpdate = function() {	
		if (this.stopFlag) {
			return;
		} else {	 
			this.updateLog();
			setTimeout(function() {
				logger.animateUpdate();
			}, this.timeoutVal);
		}
	};

	
	return logger;
}
