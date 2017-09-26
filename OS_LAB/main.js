var c=document.getElementById("myCanvas");
var ctx=c.getContext("2d");
var n = 5, n = 4;

var p1 = [0,0,0,0,0], p2 = [0,0,0,0];

ctx.fillStyle = '#ff3300';
for(var i = 30, j = 60; i<=500 && j<=500; i += 90, j+=100){
	ctx.beginPath();
	ctx.arc(i,20,5,0,2*Math.PI);
	ctx.stroke();
	ctx.fill();
	ctx.closePath();
	if(j<400)
		ctx.arc(j,230,5,0,2*Math.PI);
	ctx.fill();
	ctx.stroke();
	ctx.closePath();
}

ctx.beginPath();
ctx.moveTo(0,20);
ctx.lineTo(500,20);
ctx.strokeStyle = '#ffffff';
ctx.stroke();

ctx.beginPath();
ctx.moveTo(0,230);
ctx.lineTo(500,230);
ctx.stroke();