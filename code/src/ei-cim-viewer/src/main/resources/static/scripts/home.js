function initSvg(content) {
	$('.svg-container').html(content);
	$('.svg-container svg')
	.attr("preserveAspectRatio", "xMinYMin meet")
	//.attr("viewBox", "0 0 300 300")
	//.attr("transform", "scale(.5)")
	.addClass('svg-content');
	
	$('.svg-amplify').html(content);
	$('.svg-amplify svg')
	//.attr("preserveAspectRatio", "xMinYMin meet")
	.addClass('svg-content');
	//.attr("preserveAspectRatio", "xMinYMin slice");	
	

	  
	$("use").hover(function(e) {
		  $('#info-box').css('display','block');
		  //$('#info-box').html($(this).data('info'));
		  var html = '<ul class="info-list">';
		  var p = $(this).parent();
		  var id = p.attr('id');
		  html += '<li>id : '+p.attr('id')+'</li>';
		  var escaped = $("<div>").text(p.find("metadata").html()).html();
		  html += '<li>metadata :'+escaped+'</li>';
		  html += '</ul>';		  
		  $('#info-box').html(html);

	});
	$("use").mouseleave(function(e) {
	  $('#info-box').css('display','none');
	});

}

$(function() {
	  $(document).resize(function() {
		  //alert("resize");
		  $('.svg-content').resize();
	  });
	  
	$(document).mousemove(function(e) {
		var svg = $('.svg-container svg'); 
		if (svg.length == 0)
			  return;
		  
		  $('#info-box').css('top',e.pageY-$('#info-box').height()-30);
		  //$('#info-box').css('left',e.pageX-($('#info-box').width())/2);
		  $('#info-box').css('left',e.pageX);
		 

		  var pt = svg[0].createSVGPoint();
		  pt.x = e.pageX;
		  pt.y = e.pageY;
		  
		  var svgP = pt.matrixTransform(svg[0].getScreenCTM().inverse());
		  var w = 200;
		  var h = 200;
		  svgP.x -= w/2;
		  svgP.y -= h/2;
		  console.log("pt=("+pt.x+","+pt.y+")"+", svgP=("+svgP.x+","+svgP.y+")");
		  $('.svg-amplify svg').attr("viewBox", ""+svgP.x+" "+svgP.y+" "+w+" "+h).attr("preserveAspectRatio", "xMidYMid meet");
		  
		}).mouseover();
		
  $('#file-list').jstree({
	    "plugins" : ["wholerow"],
	    'core' : {
	        'data' : [
	          { "text" : "wuxipms1.0", "state" : {"opened" : true}, "children" : [
	              { "text" : "安镇变-10kv安国线114.svg", "data" : "wuxipms1.0/安镇变-10kv安国线114.svg"},
	              { "text" : "安镇变-10kv安铁线118.svg", "data" : "wuxipms1.0/安镇变-10kv安铁线118.svg"},
	              { "text" : "test.svg", "data" : "test.svg"},
	            ]
	          }
	        ]
	      }
	    });
  $('#file-list').on("changed.jstree", function (e, data) {
	    console.log("The selected nodes are:");
	    console.log(data.selected);
	    var url = data.instance.get_node(data.selected[0]).data;
	    console.log(url);
		$.ajax({
			url : "/svg/file/"+url,
			type : "GET",
			data : null,

			success : function(rt) {
				console.log(rt);
				if (rt.code=='OK') {
					initSvg(rt.value);
				} else 
					$('.svg-container').html('<p>Fail to load file:'+url+", "+rt.detail+'</p>');
			},
			error : function() {
				alert("fail to get file");
			}
		});
	  });
});