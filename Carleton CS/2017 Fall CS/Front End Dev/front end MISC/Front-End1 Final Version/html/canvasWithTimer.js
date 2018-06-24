
var words = [];

var wayPoints = []; //locations where the moving box has been
var timer;
var wordBeingMoved;
var deltaX, deltaY; //location where mouse is pressed
var canvas = document.getElementById('canvas1'); //our drawing canvas

//sets the "Grab" box for being able to pick up anywhere on word
function getWordAtLocation(aCanvasX, aCanvasY){
  for(var i=0; i<words.length; i++){
    if(((aCanvasX > words[i].x)
          && (aCanvasX < (words[i].x + words[i].wordWidth)))
      &&
      ((aCanvasY > (words[i].y - 20))
          && (aCanvasY < words[i].y)))
      return words[i];
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
    context.fillStyle = 'white';
    context.fillRect(0,0,canvas.width,canvas.height); //erase canvas

    //title
    context.font="30px Verdana";
    context.fillStyle = 'purple';
    context.strokeStyle = 'purple';
    context.strokeText("Title: ",50,50);
    context.font = '16pt Calibri';
    context.fillStyle = 'black';
    context.strokeStyle = 'black';

    //check if new array doesn't have x,y set them
    for(var i=0; i<words.length; i++){  //note i declared as var
      var data = words[i];
			context.fillText(data.word, data.x, data.y);
      context.strokeText(data.word, data.x, data.y);
      data.wordWidth = context.measureText(data.word).width;
	}

    //draw some lines
    //i is the factor by which to draw.
    context.fillStyle = 'lightblue';
    context.strokeStyle = 'black';
    context.beginPath();
    for(i=3;i<21;i++){
      context.moveTo(50, 25*i+2);
      context.lineTo(550, 25*i+2)
    }
    context.stroke();
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

	if(wordBeingMoved != null ){
    wordBeingMoved.x = canvasX;
    wordBeingMoved.y = canvasY;
	   deltaX = wordBeingMoved.x - canvasX;
	   deltaY = wordBeingMoved.y - canvasY;

       console.log(wordBeingMoved.word + "," + wordBeingMoved.x + "," +wordBeingMoved.y);
	   //document.addEventListener("mousemove", handleMouseMove, true);
       //document.addEventListener("mouseup", handleMouseUp, true);
	$("#canvas1").mousemove(handleMouseMove);
	$("#canvas1").mouseup(handleMouseUp);

	}

    // Stop propagation of the event and stop any default
    //  browser action
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

    //$("#canvas1").off(); //remove all event handlers from canvas
    //$("#canvas1").mousedown(handleMouseDown); //add mouse down handler
	//remove mouse move and mouse up handlers but leave mouse down handler
    $("#canvas1").off("mousemove", handleMouseMove); //remove mouse move handler
    $("#canvas1").off("mouseup", handleMouseUp); //remove mouse up handler
	drawCanvas(); //redraw the canvas
	}

function handleTimer(){
	drawCanvas()
}

  //KEY CODES
	var ENTER = 13;
	var RIGHT_ARROW = 39;
	var LEFT_ARROW = 37;
	var UP_ARROW = 38;
	var DOWN_ARROW = 40;

function handleKeyDown(e){

	console.log("keydown code = " + e.which );
	var dXY = 5; //amount to move in both X and Y direction
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
	//var dataObj = {x: movingBox.x, y: movingBox.y};
	//create a JSON string representation of the data object
	var jsonString = JSON.stringify(dataObj);

	$.post("positionData", jsonString, function(data, status){
			console.log("data: " + data);
			console.log("typeof: " + typeof data);
			var wayPoint = JSON.parse(data);
			wayPoints.push(wayPoint);
			for(i in wayPoints) console.log(wayPoints[i]);
			});
	}

	if(e.which == ENTER){
	   handleRequestButton(); //treat ENTER key like you would a submit
	   $('#userTextField').val(''); //clear the user text field
	}
	e.stopPropagation();
    e.preventDefault();
}

function handleRequestButton () {
    var userText = $('#userTextField').val(); //get text from user text input field
	if(userText && userText != ''){
	   //user text was not empty
	   var userRequestObj = {text: userText}; //make object to send to server
       var userRequestJSON = JSON.stringify(userRequestObj); //make json string
	   $('#userTextField').val(''); //clear the user text field

	   //Prepare a POST message for the server and a call back function
	   //to catch the server repsonse.
       //alert ("You typed: " + userText);
	   $.post("userText", userRequestJSON, function(data, status){
			console.log("data: " + data);
			console.log("typeof: " + typeof data);
			var responseObj = JSON.parse(data);
			//movingString.word = responseObj.text;
			//replace word array with new words if there are any

			 if(responseObj.wordArray) words = responseObj.wordArray;

       words[0].x = 130;
       words[0].y = 50;
       var lineCount = 1;

      for(var i=0; i<words.length; i++){  //note i declared as var
        words[i].wordWidth = getTextWidth(words[i].word, "16pt Calibri");
        if(words[i].x == null){
          words[i].x = (words[i-1].x + words[i-1].wordWidth + 10);
          words[i].y = (50*lineCount);

          // IF NEW VERSE NEW LINE
          if (words[i].word == ("verse1:" || "verse2:" || "verse3:" || "verse4:")){
            lineCount++;
            words[i].x = 50;
            words[i].y = (50*lineCount+1);
          }

          if(words[i].charAt(0) == "["){
          //  words[i].y = words[i].y - 25;
           // words[i].wordWidth = getTextWidth(words[i].word, "20pt Calibri");
          }


          //IF WRAP TO FAR NEW LINE
          if ((words[i].x + words[i].wordWidth) > 550){
            lineCount++;
            words[i].x = 50;
            words[i].y = (50*lineCount+1);

            console.log("Linecount is now" + lineCount);
          }

        }
      }
      console.log(words[0].wordWidth);
			});
	}

}

//TODO add SAVE button
function handleSubmitButton () {
    var userText = $('#userTextField').val(); //get text from user text input field
	if(userText && userText != ''){
	   //user text was not empty
	   var userRequestObj = {text: userText}; //make object to send to server
       var userRequestJSON = JSON.stringify(userRequestObj); //make json string
	   $('#userTextField').val(''); //clear the user text field

	   //Prepare a POST message for the server and a call back function
	   //to catch the server repsonse.
       //alert ("You typed: " + userText);
	   $.post("userText", userRequestJSON, function(data, status){
			console.log("data: " + data);
			console.log("typeof: " + typeof data);
			var responseObj = JSON.parse(data);
			//movingString.word = responseObj.text;
			//replace word array with new words if there are any

			 if(responseObj.wordArray) words = responseObj.wordArray;

			});
	}

}





//TODO

//     getTextWidth(sasterGoldenHair[i].word, "20pt arial"




$(document).ready(function(){
	//This is called after the broswer has loaded the web page

	//add mouse down listener to our canvas object
	$("#canvas1").mousedown(handleMouseDown);

	//add key handler for the document as a whole, not separate elements.
	$(document).keydown(handleKeyDown);
	$(document).keyup(handleKeyUp);

	timer = setInterval(handleTimer, 100);
    //timer.clearInterval(); //to stop

	drawCanvas();
});
