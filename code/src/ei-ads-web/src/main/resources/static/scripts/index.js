var stateSampleConfigNames = [];
var stateEstimateConfigNames = [];

var init = function() {
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

$('#start-calc-reliability').click(
		function() {
			var f = $("#state-estimate-config-form");
			var estimateConfig = f.serializeObject();
			
			var f1 = $("#state-sample-config-form");
			var sampleConfig = f1.serializeObject();
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
					console.log('calc reliability request accepted : '
							+ JSON.stringify(msg));

					$('#request-response').html(msg.code == 'OK'?'Request accepted!':'Fail to submit calc!');
					$("#start-calc-reliability").prop("disabled", false);
				},
				 error: function (e) {

			            $("#request-response").html(e.responseText);
			            console.log("ERROR : ", e);
			            $("#start-calc-reliability").prop("disabled", false);

			        }

			});

			// $.ajax({
			// url : "./pr/calcReliability",
			// type : "POST",
			// data : {"sampleConfig" : sampleConfig, "estimateConfig" :
			// estimateConfig},
			// async : true,
			// success : function(msg) {
			// console
			// .log('calc reliability request accepted : '
			// + JSON
			// .stringify(msg));
			//	
			// msg.code == 'OK' ? $(
			// '#request-response')
			// .html(
			// 'request accepted!')
			// : $('#request-response')
			// .html(
			// "request accepted!");
			// }
			//	
			// });

			$("#pbar_outerdiv").show();
			pbar = ProgressBar();
			pbar.animateUpdate();

		});