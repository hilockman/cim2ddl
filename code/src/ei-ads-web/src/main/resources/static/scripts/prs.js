var stateSampleConfigNames = [];
var stateEstimateConfigNames = [];

var init = function() {
			$
					.ajax({
						url : "pr/stateSampleConfig",
						type : "GET",
						data : null,
	
						success : function(config) {
							console.log("stateSampleConfig = "+JSON
									.stringify(config));
				
							$.each(config,function(name,value) {
								var control = $("#"+name);
								stateSampleConfigNames.push(name);
								console.log("control type is "+control.attr('type')+", id="+name);
								if(control.attr('type') =="text") {
									control.val(value);
								} else {
									var cname = "input[name='{0}'][value={1}]".format(name, value);
									$(cname).attr("checked",true);
								} 
								});
								
						},
						error : function() {
							alert("get default config failed!");
						}
					});
					
					$
					.ajax({
						url : "pr/stateEstimateConfig",
						type : "GET",
						data : null,
	
						success : function(config) {
							console.log(JSON
									.stringify(config));
							
							$.each(config,function(name,value) {
								var control = $("#"+name);
								stateEstimateConfigNames.push(name);
								
								if (control.attr('type') == "checkbox") {
									value == '1' ? control.attr("checked",true) : control.attr("checked",false);
								} else {
									control.val(value);
								}
								});
						},
						error : function() {
							alert("get default config failed!");
						}
					}
					);
		};
	
	$(document).ready(init);
	
	function ProgressBar() {
		var bar = {};
		bar.start = new Date();
		bar.maxTime = 83500;
		bar.timeoutVal = Math.floor(bar.maxTime / 100);
		bar.stopFlag = false;

		bar.updateProgress = function (percentage) {
			$('#pbar_innerdiv').css("width",
					percentage + "%");
			$('#pbar_innertext').text(percentage + "%");
		};

		bar.stop = function() {
			this.stopFlag = true;
		}
		
		bar.animateUpdate = function () {
			var now = new Date();
			var timeDiff = now.getTime()
					- this.start.getTime();
			var perc = Math
					.round((timeDiff / this.maxTime) * 100);

			if (this.stopFlag) {
				this.updateProgress(0);
				return;
			}
			if (perc <= 100) {
				this.updateProgress(perc);
				setTimeout(function() {bar.animateUpdate();}, this.timeoutVal);
			}
		};
		
		return bar;

	};
	var pbar;

	$('#cancel-calc-reliability')
	.click(
		function() {
			pbar.stop();
			$(
			'#request-response')
			.html(
					'Succeed to cancel!')
		});
	$('#start-calc-reliability')
	.click(
		function() {
	
			var sampleEstimateConfig = {};
			sampleEstimateConfig.nMaxGenFault = $("#max-gen-fault")
					.val();
			
			for (var i in stateEstimateConfigNames) {
				var name = stateEstimateConfigNames[i];
				var control = $("#"+name);
				console.log("control type is "+control.attr('type')+", id="+name);
				if (control.attr('type') == "text") {
					sampleEstimateConfig[name] = control.val();
				}
			}
	
			$
					.ajax({
						url : "./pr/calcReliability",
						type : "POST",
						data : sampleEstimateConfig,
						async : true,
						success : function(msg) {
							console
									.log('calc reliability request accepted : '
											+ JSON
													.stringify(msg));
	
							msg.code == 'OK' ? $(
									'#request-response')
									.html(
											'request accepted!')
									: $('#request-response')
											.html(
													"request accepted!");
						}
	
					});
			

		pbar = ProgressBar();
		pbar.animateUpdate();

	});