
//Use javascript array of objects to represent words and their locations

/*
var words = [];
words.push({word: "I", x:50, y:50});
words.push({word: "like", x:70, y:50});
words.push({word: "the", x:120, y:50});
words.push({word: "way", x:170, y:50});
words.push({word: "your", x:230, y:50});
words.push({word: "sparkling", x:300, y:50});
words.push({word: "earrings", x:430, y:50});
words.push({word: "lay", x:540, y:50});
*/
var wordDefPair = { "the formal statement of the meaning or significance of a word, phrase" : ["Definition","Dictionary","Cat","Fossil"],
             "an animal that feeds on plants": ["Herbivore","Carnivore","R Kelly", "wild Mongo DB"]  
             "feeling or showing pleasure or contentment." : ["Happy","Sad","Bobby Fischer"]  
			 };


var wordsInMotion= [];

 wordsInMotion.push({word: "Definition",
                    x: 300,
					y:125,
					xDirection: 1, //+1 for leftwards, -1 for rightwards
					yDirection: -1, //+1 for downwards, -1 for upwards
					stringWidth: 50, //will be updated when drawn
					stringHeight: 24}); //assumed height based on drawing point size

wordsInMotion.push({word: "Cat", x: 300, y:125, xDirection: -1, yDirection: 1, stringWidth: 50, stringHeight: 24}); 

wordsInMotion.push({word: "Fossil", x: 300, y:125, xDirection: -1, yDirection: -1, stringWidth: 50, stringHeight: 24});

wordsInMotion.push({word: "Dictionary", x: 300,y:125,xDirection: 1, yDirection: 1,stringWidth: 50, stringHeight: 24}); 

var movingString = {word: "theWord",
                    x: 100,
					y:100,
					xDirection: 1, //+1 for leftwards, -1 for rightwards
					yDirection: 1, //+1 for downwards, -1 for upwards
					stringWidth: 50, //will be updated when drawn
					stringHeight: 24}; //assumed height based on drawing point size

//indended for keyboard control
var movingBox = {x: 50,
                 y: 50,
				 width: 50,
				 height: 50};

var wayPoints = []; //locations where the moving box has been

var timer;

var wordBeingMoved;

var deltaX, deltaY; //location where mouse is pressed
var canvas = document.getElementById('canvas1'); //our drawing canvas

//canvas.style = "position: absolute; top: 50px; left: 50px; border:2px solid blue"


// here we set the definition
document.getElementById('userTextField').value='the formal statement of the meaning or significance of a word, phrase';

function getWordAtLocation(aCanvasX, aCanvasY){

/*
	  for(var i=0; i<wordsInMotion.length; i++){
		 if(Math.abs(wordsInMotion[i].x - aCanvasX) < 20 &&
		    Math.abs(wordsInMotion[i].y - aCanvasY) < 20) return wordsInMotion[i];
	  }
	  return null;
	  */

  for(var i=0; i<wordsInMotion.length; i++){
    if(((aCanvasX > wordsInMotion[i].x) &&
     (aCanvasX < (wordsInMotion[i].x + wordsInMotion[i].wordWidth))) &&
     ((aCanvasY > (wordsInMotion[i].y - 20))&& 
     (aCanvasY < wordsInMotion[i].y)))
     return wordsInMotion[i];
  }



    }

    function getTextWidth(txt, font) {
  this.element = document.createElement('canvas');
  this.context = this.element.getContext("2d");
  this.context.font = font;
  return this.context.measureText(txt).width;
}

var drawCanvas = function(){

    var context = canvas.getContext('2d');
     var context1 = canvas.getContext('2d');

    context.fillStyle = 'white';
    context.fillRect(0,0,canvas.width,canvas.height); //erase canvas

    context.font = '20pt Arial';
    context.fillStyle = 'cornflowerblue';
    context.strokeStyle = 'blue';

    for(var i=0; i<wordsInMotion.length; i++){  //note i declared as var

			var data = wordsInMotion[i];
			context.fillText(data.word, data.x, data.y);
            context.strokeText(data.word, data.x, data.y);
            data.wordWidth = context.measureText(data.word).width;
	}


/*
    for(var i=0; i<words.length; i++){  //note i declared as var

			var data = words[i];
			context.fillText(data.word, data.x, data.y);
            context.strokeText(data.word, data.x, data.y);
	}
	*/



		for(var i = 0; i < wordsInMotion.length; i++){
		wordsInMotion[i].stringWidth = context.measureText(	wordsInMotion[i].word).width;
		context.fillText(wordsInMotion[i].word, wordsInMotion[i].x, wordsInMotion[i].y);
	}

//    movingString.stringWidth = context.measureText(	movingString.word).width;

//    context.fillText(movingString.word, movingString.x, movingString.y);


    //draw moving box
	context.fillRect(movingBox.x,
	                 movingBox.y,
					 movingBox.width,
					 movingBox.height);

	//draw moving box way points
	for(i in wayPoints){
		context.strokeRect(wayPoints[i].x,
		             wayPoints[i].y,
					 movingBox.width,
					 movingBox.height);
	}
	//draw square
   //  context.beginPath();

    context.fillRect(0, 0, 100, 100);
    context.fillStyle = 'red';
    context1.fillRect(500, 0, 100, 100);
    context.fillStyle = 'yellow';
   	context.fillRect(0, 200, 100, 100);
   	context.fillStyle = 'green';
   	context.fillRect(500, 200, 100, 100);


/* for the triangle
    context.fillStyle = 'yellow';
    context.beginPath();     //Begin a path..
    context.moveTo(50, 25);  //Startpoint (x, y)
    context.lineTo(100, 50); //Point 1    (x, y)
    context.lineTo(50, 75);  //Point 2    (x, y)
    context.closePath();     //Close the path.
    //Fill triangle with previous set color.
    context.fill();
*/



}

function handleMouseDown(e){

	//get mouse location relative to canvas top left
	var rect = canvas.getBoundingClientRect();
    //var canvasX = e.clientX - rect.left;
    //var canvasY = e.clientY - rect.top;
    var canvasX = e.pageX - rect.left; //use jQuery event object pageX and pageY
    var canvasY = e.pageY - rect.top;
	console.log("mouse down:" + canvasX + ", " + canvasY);

	wordBeingMoved = getWordAtLocation(canvasX, canvasY);
	//console.log(wordBeingMoved.word);
	if(wordBeingMoved != null ){
	   deltaX = wordBeingMoved.x - canvasX;
	   deltaY = wordBeingMoved.y - canvasY;
	   document.getElementById('canvas1').addEventListener('mousemove', handleMouseMove);
	   document.getElementById('canvas1').addEventListener('mouseup', handleMouseUp);

	}

    // Stop propagation of the event and stop any default browser action
    e.stopPropagation();
    e.preventDefault();
	drawCanvas();
	}

function handleMouseMove(e){

	console.log("mouse move");

	//get mouse location relative to canvas top left
	var rect = canvas.getBoundingClientRect();
  var canvasX = e.pageX - rect.left;
  var canvasY = e.pageY - rect.top;
	wordBeingMoved.x = canvasX + deltaX;
	wordBeingMoved.y = canvasY + deltaY;
	e.stopPropagation();
	drawCanvas();
	}

function handleMouseUp(e){
	console.log("mouse up");

	e.stopPropagation();
	//remove mouse move and mouse up handlers but leave mouse down handler
 	document.getElementById('canvas1').removeEventListener('mousemove', handleMouseMove);
	document.getElementById('canvas1').removeEventListener('mouseup', handleMouseUp);
	drawCanvas(); //redraw the canvas
	}

// nest the below function which accesses a moving string from an array of moving strings
function handleTimer(){
	
	for(var i = 0; i < wordsInMotion.length; i++){


	wordsInMotion[i].x = (wordsInMotion[i].x + 5*wordsInMotion[i].xDirection);
	wordsInMotion[i].y = (wordsInMotion[i].y + 5*wordsInMotion[i].yDirection);

	//keep inbounds of canvas
	if(wordsInMotion[i].x + wordsInMotion[i].stringWidth > canvas.width) wordsInMotion[i].xDirection = -1;
	if(wordsInMotion[i].x < 0) wordsInMotion[i].xDirection = 1;
	if(wordsInMotion[i].y > canvas.height) wordsInMotion[i].yDirection = -1;
	if(wordsInMotion[i].y - wordsInMotion[i].stringHeight < 0) wordsInMotion[i].yDirection = 1;

	

	drawCanvas()
}

/*
	movingString.x = (movingString.x + 5*movingString.xDirection);
	movingString.y = (movingString.y + 5*movingString.yDirection);

	//keep inbounds of canvas
	if(movingString.x + movingString.stringWidth > canvas.width) movingString.xDirection = -1;
	if(movingString.x < 0) movingString.xDirection = 1;
	if(movingString.y > canvas.height) movingString.yDirection = -1;
	if(movingString.y - movingString.stringHeight < 0) movingString.yDirection = 1;

	drawCanvas()
	*/





}

    //KEY CODES
	//should clean up these hard coded key codes
	var ENTER = 13;
	var RIGHT_ARROW = 39;
	var LEFT_ARROW = 37;
	var UP_ARROW = 38;
	var DOWN_ARROW = 40;


function handleKeyDown(e){

	console.log("keydown code = " + e.which );

	var dXY = 5; //amount to move in both X and Y direction
	if(e.which == UP_ARROW && movingBox.y >= dXY)
	   movingBox.y -= dXY;  //up arrow
	if(e.which == RIGHT_ARROW && movingBox.x + movingBox.width + dXY <= canvas.width)
	   movingBox.x += dXY;  //right arrow
	if(e.which == LEFT_ARROW && movingBox.x >= dXY)
	   movingBox.x -= dXY;  //left arrow
	if(e.which == DOWN_ARROW && movingBox.y + movingBox.height + dXY <= canvas.height)
	   movingBox.y += dXY;  //down arrow

    var keyCode = e.which;
    if(keyCode == UP_ARROW | keyCode == DOWN_ARROW){
       //prevent browser from using these with text input drop downs
       e.stopPropagation();
       e.preventDefault();
	}

}

function handleKeyUp(e){
	console.log("key UP: " + e.which);
	if(e.which == RIGHT_ARROW | e.which == LEFT_ARROW | e.which == UP_ARROW | e.which == DOWN_ARROW){
	var dataObj = {x: movingBox.x, y: movingBox.y};
	//create a JSON string representation of the data object
	var jsonString = JSON.stringify(dataObj);

    var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function(){
		  if(this.readyState == 4 && this.status == 200 ){
			console.log("data: " + this.responseText);
			console.log("typeof: " + typeof this.responseText);
			//we are expecting the response text to be a JSON string
			var wayPoint = JSON.parse(this.responseText); 'text/plain'
			wayPoints.push(wayPoint);
			for(i in wayPoints) console.log(wayPoints[i]);
		  }
	  };
	  xhttp.open("POST", "positionData", true);
      xhttp.send(jsonString);

	}
	if(e.which == ENTER){
	   handleSubmitButton(); //treat ENTER key like you would a submit
	   document.getElementById('userTextField').value='';

	}

	e.stopPropagation();
    e.preventDefault();


}

function handleSubmitButton () {
	var userText = document.getElementById('userTextField').value;
	if(userText && userText != ''){
	   var userRequestObj = {text: userText};
       var userRequestJSON = JSON.stringify(userRequestObj);
	   document.getElementById('userTextField').value='';
       alert ("You typed: " + userText);

      //This is based on examples from W3 schools:
	  //https://www.w3schools.com/js/js_ajax_intro.asp

	  var xhttp = new XMLHttpRequest();
	  xhttp.onreadystatechange = function(){
		  if(this.readyState == 4 && this.status == 200 ){
			console.log("data: " + this.responseText);
			console.log("typeof: " + typeof this.responseText);
			//we are expecting the response text to be a JSON string
			var responseObj = JSON.parse(this.responseText); 'text/plain'
			movingString.word = responseObj.text;
			//if(responseObj.wordArray) words = responseObj.wordArray;
		  }
	  };
	  xhttp.open("POST", "userText", true);
      xhttp.send(userRequestJSON);

	}

}

document.addEventListener('DOMContentLoaded',function(){
	//This is called after the broswer has loaded the web page

	//add mouse down listener to our canvas object
	document.getElementById('canvas1').addEventListener('mousedown', handleMouseDown);

	//add key handler for the document as a whole, not separate elements.
	document.addEventListener('keydown', handleKeyDown);
	document.addEventListener('keyup', handleKeyUp);

	timer = setInterval(handleTimer, 100);
    //timer.clearInterval(); //to stop

	drawCanvas();
});
