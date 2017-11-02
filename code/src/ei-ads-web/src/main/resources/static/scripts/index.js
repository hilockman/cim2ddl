var stateSampleConfigNames = [];
var stateEstimateConfigNames = [];

var init = function() {
	
	var modelName = localStorage['modelConfig'];
	$("#modelName").val(modelName);
	
	$("#modelName").change(function() {
		localStorage['modelConfig'] = $("#modelName").val();
		console.log("modelName :"+$("#modelName").val());
	});
	
//	var fileInputs = ["flowFile", "stableFile", "paramFile"];
//	for (var i = 0; i < fileInputs.length; i++) {
//		var str = localStorage[fileInputs[i]];
//		//$("#"+fileInputs[i]).val(str);	
//		
//		$("#"+fileInputs[i]).change(function(e){
//			 var fileName = $(this).val();
//			 localStorage[$(this).attr("id")] = fileName;
//			 alert("file id :"+$(this).attr("id"));
//	       // alert('The file "' + fileName +  '" has been selected.');
//	    });
//	}
	
	
	
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

	$("#pbar_outerdiv").hide();
};

$(document).ready(init);

function ProgressBar() {
	var bar = {};
	bar.start = new Date();
	bar.maxTime = 83500;
	bar.timeoutVal = Math.floor(bar.maxTime / 100);
	bar.stopFlag = false;

	bar.updateProgress = function(percentage) {
		$('#pbar_innerdiv').css("width", percentage + "%");
		$('#pbar_innertext').text(percentage + "%");
	};

	bar.stop = function() {
		this.stopFlag = true;
	}

	bar.animateUpdate = function() {
		var now = new Date();
		var timeDiff = now.getTime() - this.start.getTime();
		var perc = Math.round((timeDiff / this.maxTime) * 100);

		if (this.stopFlag) {
			this.updateProgress(0);
			return;
		}
		if (perc <= 100) {
			this.updateProgress(perc);
			setTimeout(function() {
				bar.animateUpdate();
			}, this.timeoutVal);
		}
	};

	return bar;

};
var pbar;

$('#cancel-calc-reliability').click(function() {
	pbar.stop();
	$('#request-response').html('Succeed to cancel!');
	$("#pbar_outerdiv").toggle("slow");
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

function formcheck() {
	  var fields = $(".ss-item-required")
	        .find("select, textarea, input").serializeArray();
	  
	  $.each(fields, function(i, field) {
	    if (!field.value)
	      alert(field.name + ' is required');
	   }); 
	  console.log(fields);
	}


$('#start-calc-reliability').click(
		function() {
			var sampleConfig = $("#state-sample-config-form").serializeObject();
			if ($("#model-config-form").valid()) {
				alert("some field must be filled.");
			}
			
			var f = $("#state-estimate-config-form");
			var estimateConfig = f.serializeObject();
			var checkbox = f.find("input[type=checkbox]");
			$.each(checkbox, function(key, val) {
					   estimateConfig[$(val).attr('name')] = ($(val).is(":checked") ? 1 : 0);		
				});
			
	
			
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
					console.log('calc reliability request accepted : '
							+ JSON.stringify(msg));

					$('#request-response').html(msg.code == 'OK'?'Request accepted!':'Fail to submit calc!');
					$("#start-calc-reliability").prop("disabled", true);
					$("#pbar_outerdiv").show();
					pbar = ProgressBar();
					pbar.animateUpdate();
				},
				 error: function (e) {

			            $("#request-response").html(e.responseText);
			            console.log("ERROR : ", e);
			            $("#start-calc-reliability").prop("disabled", true);

			        }

			});



		});