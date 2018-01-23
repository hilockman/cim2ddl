var stateSampleConfigNames = [];
var stateEstimateConfigNames = [];

var init = function() {
	
	var modelName = localStorage['modelConfig']; 
	$("#modelName").val(modelName); 
	$("#modelName").change(function() { 
	localStorage['modelConfig'] = $("#modelName").val(); 
	  console.log("modelName :"+$("#modelName").val()); 
	}); 
	
	$.ajax({
		url : "pr/stateSampleConfig",
		type : "GET",
		data : null,

		success : function(config) {
			console.log("stateSampleConfig = " + JSON.stringify(config));

			$.each(config, function(name, value) {
				var control = $("#" + name);
				stateSampleConfigNames.push(name);
				// console.log("control type is "+control.attr('type')+",
				// id="+name);
				if (control.attr('type') == "text") {
					control.val(value);
				} else {
					var cname = "input[name='{0}'][value={1}]".format(name,
							value);
					$(cname).attr("checked", true);
				}
			});

		},
		error : function() {
			alert("get default config failed!");
		}
	});

	$.ajax({
		url : "pr/stateEstimateConfig",
		type : "GET",
		data : null,

		success : function(config) {
			console.log(JSON.stringify(config));

			$.each(config, function(name, value) {
				var control = $("#" + name);
				stateEstimateConfigNames.push(name);

				if (control.attr('type') == "checkbox") {
					value == '1' ? control.attr("checked", true) : control
							.attr("checked", false);
				} else {
					control.val(value);
				}
			});
		},
		error : function() {
			alert("get default config failed!");
		}
	});

	$("#pbar_outerdiv").hide();};

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
$('#start-calc-reliability').click(
		function() {
			var f = $("#state-estimate-config-form");
			var estimateConfig = f.serializeObject();
			
			var f1 = $("#state-sample-config-form");

			
			var sampleConfig = f1.serializeObject();
			var checkbox = f.find("input[type=checkbox]"); 
			$.each(checkbox, function(key, val) { 
			    estimateConfig[$(val).attr('name')] = ($(val).is(":checked") ? 1 : 0);		 
            }); 
			
//			var sampleConfig = {};
//			for ( var i in stateSampleConfigNames) {
//				var name = stateSampleConfigNames[i];
//				var control = $("#" + name);
//				// console.log("control type is "+control.attr('type')+",
//				// id="+name);
//				if (control.attr('type') == "text") {
//					sampleConfig[name] = control.val();
//				}
//			}
			
			

			//console.log("estimateConfig=" + estimateConfig);

//			var estimateConfig = {};
//			for ( var i in stateEstimateConfigNames) {
//				var name = stateEstimateConfigNames[i];
//				var control = $("#" + name);
//				// console.log("control type is "+control.attr('type')+",
//				// id="+name);
//				if (control.attr('type') == "text") {
//					estimateConfig[name] = control.val();
//				}
//			}
//			
		    // Get form
		    var form = $('#model-config-form')[0];

		    var data = new FormData(form);
			
		    data.append("sampleConfig", JSON.stringify(sampleConfig));
		    data.append("estimateConfig", JSON.stringify(estimateConfig));
					    

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
					$('#request-response').html(msg.code == 'OK'?'Request accepted!' : 'Fail to submit calc : ' + msg.detail);
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