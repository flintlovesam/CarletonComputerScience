////CITATION: We utilized the chat app provided by Lou Nel as starting infrastructure


var ws = new WebSocket('ws://' + window.document.location.host);

//global variables
var gameWon = 0;    // variable used to check that win has not occured
var playerID = 0;     // used to store a global copy of the sent identity
var xCoordinate = 0;     //value of the x coordinate
var winCounter = 0;     // checks how many wins have occured
var alertCounter = 0;  //
var nameCounter = 0;


	var person = prompt("Welcome to Word Matcher! Please enter your name to start :-->", "");

	ws.onmessage = function(message){

		if(message.data != null ){
					playerID = (JSON.parse(message.data).identit);  // playerID corresponds to the int 

					if(playerID == 0 && (nameCounter == 0) ) {
						alert("Hi:  " + person + " You are player 1: You must drag the matching word for the definition to the left side of the screen to win. ");
					//	alert("Hi! You are player 1: You must drag the matching word for the definition to the left side of the screen to win. If you are player 2, drag to the right"  )

						var playerString = " You are Player One";
					}
					else if ((playerID == 1) && (nameCounter == 0)) {
						alert("Hi:  " + person + " You are player 2: You must drag the matching word for the definition to the right side of the screen to win. ");

						playerString = " You are Player two";
					}
					


			 	if((JSON.parse(message.data).word) == "Definition"){ 

			 // set the x value of "this" clients word to match the coordinates of the word being moved
				wordsInMotion[0].x = (JSON.parse(message.data).x);
				wordsInMotion[0].y = (JSON.parse(message.data).y);

				xCoordinate = (JSON.parse(message.data).x);

			//check for player 1 win condition
				if(xCoordinate < 70 ){
					var winnerString = "Player one wins";

				}

//checks for player two win condition
				if(xCoordinate > 430){
				winnerString = "Player two wins!"
				}


				drawCanvas();

			}
			// change location of other words
			else if((JSON.parse(message.data).word) == "Cat"){
				wordsInMotion[1].x = (JSON.parse(message.data).x);
				wordsInMotion[1].y = (JSON.parse(message.data).y);
				drawCanvas();
			}
			else if((JSON.parse(message.data).word) == "Fossil"){
				wordsInMotion[2].x = (JSON.parse(message.data).x);
				wordsInMotion[2].y = (JSON.parse(message.data).y);
				drawCanvas();
			}
			
			else if((JSON.parse(message.data).word) == "Dictionary"){

				wordsInMotion[3].x = (JSON.parse(message.data).x);
				wordsInMotion[3].y = (JSON.parse(message.data).y);
				var printteew = (JSON.parse(message.data).x);

				drawCanvas();
			}

		}

// update the DIV to correspond to the player ID

		var playerDiv = document.createElement('div');  //
		
		playerDiv.innerHTML = playerString;

		if( (playerString != undefined) && (nameCounter == 0) ){
			nameCounter = 1
			document.getElementById('pStat').appendChild(playerDiv);
		}

// update the DIV to correspond to the win status 

		var msgDiv = document.createElement('div');  
		
		msgDiv.innerHTML = winnerString;

		if( (winnerString != undefined) && (winCounter == 0) ){
			winCounter = 1
			document.getElementById('messages').appendChild(msgDiv);
		}
	}

	function sendMessage() {
		var message = document.getElementById('msgBox').value;
		ws.send(message);                       // used to indicate a win.... send json object if stringified.....ws.send("win")
document.getElementById('msgBox').value = '';
	}

function handleKeyPress(event){
	if(event.keyCode == 13){
		sendMessage();
		return false; //don't propogate event
	}
}


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
	context.strokeStyle = 'black';

	for(var i=0; i<wordsInMotion.length; i++){  //note i declared as var

		var data = wordsInMotion[i];
		context.fillText(data.word, data.x, data.y);
					context.strokeText(data.word, data.x, data.y);
					data.wordWidth = context.measureText(data.word).width;
}





	for(var i = 0; i < wordsInMotion.length; i++){
	wordsInMotion[i].stringWidth = context.measureText( wordsInMotion[i].word).width;
	context.fillText(wordsInMotion[i].word, wordsInMotion[i].x, wordsInMotion[i].y);
}


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
//draw square      // draws the boxes for the left and right side
 	context.fillRect(0, 0, 100, 100);
	context.fillStyle = 'red';

	context.fillRect(500, 100, 100, 100);
	context.fillStyle = 'red';

	context1.fillRect(500, 0, 100, 100);
	context.fillStyle = 'cornflowerblue';

	context1.fillRect(0, 100, 100, 100);
	context.fillStyle = 'cornflowerblue';	

	context.fillRect(0, 200, 100, 100);
	context.fillStyle = 'red';
	context.fillRect(500, 200, 100, 100);


}

function handleMouseDown(e){

//get mouse location relative to canvas top left
var rect = canvas.getBoundingClientRect();
	//var canvasX = e.clientX - rect.left;
	//var canvasY = e.clientY - rect.top;
	var canvasX = e.pageX - rect.left; //use jQuery event object pageX and pageY
	var canvasY = e.pageY - rect.top;

wordBeingMoved = getWordAtLocation(canvasX, canvasY);
if(wordBeingMoved == "Definition"){
	gameWon = 1;
}

if(wordBeingMoved != null ){
	 deltaX = wordBeingMoved.x - canvasX;
	 deltaY = wordBeingMoved.y - canvasY;
	 document.getElementById('canvas1').addEventListener('mousemove', handleMouseMove);
	 document.getElementById('canvas1').addEventListener('mouseup', handleMouseUp);

}
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


var inMotion = JSON.stringify(wordBeingMoved);
ws.send(inMotion);
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
