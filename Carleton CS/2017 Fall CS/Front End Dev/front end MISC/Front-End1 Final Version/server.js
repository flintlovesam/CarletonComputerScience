/*
Here we are prepared to receive a POST message from the client,
and acknowledge that, with a very limited response back to the client
*/

/*
Use browser to view pages at http://localhost:3000/canvasWithTimer.html


When the blue cube is moved with the arrow keys, a POST message will be
sent to the server when the arrow key is released. The POST message will
contain a data string which is the location of the blue cube when the
arrow key was released. The server sends back a JSON string which the client should use
to put down a "waypoint" for where the arrow key was released

Also if the client types in the app text field and presses the "Submit Request" button
a JSON object containing the text field text will be send to this
server in a POST message.

Notice in this code we attach an event listener to the request object
to receive data that might come in in chunks. When the request end event
is posted we look and see if it is a POST message and if so extract the
data and process it.


*/

//Cntl+C to stop server (in Windows CMD console)

//DATA to be used in a future tutorial exercise.
/*Exercise: if the user types the title of a song that the server has,
  the server should send a JSON object back to the client to replace
  the words array in the client app.
*/

var fs = require('fs');

function getTextWidth(txt, font) {
    this.element = document.createElement('canvas');
    this.context = this.element.getContext("2d");
    this.context.font = font;
    return this.context.measureText(txt).width;
}

// //read the directory
// fs.readFile('songs', (err, data) => {
//   if (err) throw err;
//   console.log(data);
// });


//Server Code
var http = require('http'); //need to http
var fs = require('fs'); //need to read static files
var url = require('url');  //to parse url strings

var array1 = [];
//var array2 = [];
//var array3 = [];

var counter = 1000; //to count invocations of function(req,res)
var ROOT_DIR = 'html'; //dir to serve static files from
var MIME_TYPES = {
    'css': 'text/css',
    'gif': 'image/gif',
    'htm': 'text/html',
    'html': 'text/html',
    'ico': 'image/x-icon',
    'jpeg': 'image/jpeg',
    'jpg': 'image/jpeg',
    'js': 'text/javascript', //should really be application/javascript
    'json': 'application/json',
    'png': 'image/png',
    'txt': 'text/plain'
};

var get_mime = function(filename) {
    var ext, type;
    for (ext in MIME_TYPES) {
        type = MIME_TYPES[ext];
        if (filename.indexOf(ext, filename.length - ext.length) !== -1) {
            return type;
        }
    }
    return MIME_TYPES['txt'];
};

http.createServer(function (request,response){
    var urlObj = url.parse(request.url, true, false);
    console.log('\n============================');
    console.log("PATHNAME: " + urlObj.pathname);
    console.log("REQUEST: " + ROOT_DIR + urlObj.pathname);
    console.log("METHOD: " + request.method);

    var receivedData = '';

    //attached event handlers to collect the message data
    request.on('data', function(chunk) {
        receivedData += chunk;
    });

    //event handler for the end of the message
    request.on('end', function(){
        console.log('received data: ', receivedData);
        console.log('type: ', typeof receivedData);

        if(request.method == "POST"){
            var dataObj = JSON.parse(receivedData);
            console.log('received data object: ', dataObj);
            console.log('type: ', typeof dataObj.text);

            var filePath = "songs/" + dataObj.text + ".txt";

            fs.readFile(filePath, function(err, data) {
                if(err) {console.log(err);}
                console.log(filePath);

                var objSongToSend = [];




                var array1 = data.toString().split("\n"); //original array



                for(let i=0;i<array1.length;i++){

                  var currentLine = array1[i].replace(/(\r\n|\n|\r)/gm,"");
                  var arrayOfStrings = currentLine.split(" ");

                 console.log(arrayOfStrings);

                 for(var j=0; j<arrayOfStrings.length; j++){
                     objSongToSend.push({word: arrayOfStrings[j], x:null , y:null,
                         wordWidth:null});
                 }
              }

                function spaceBuffer(k){
                    var stringReturn = "";
                    for(l=0;l<k;l++)
                        stringReturn += " ";
                    return stringReturn
                }

                // Backend code to make consol display look FANTASTIC!
                //   Not needed for this asst, but maybe fore future
                //
                //  for(i in array1) {
                //    var lineLength = array1[i].length;
                //    var spaceCount = 0;
                //    array2[i] = "";
                //    for (j=0;j<lineLength;j++){
                //      var currentCount = 0;
                //      tempChar = array1[i].charAt(j);
                //      if (tempChar != "["){
                //        spaceCount++
                //      }
                //      if (tempChar == "["){
                //        var posRight = array1[i].indexOf("]",j);
                //        var posLeft = j;
                //        var tempString = array1[i].slice(posLeft+1, posRight);
                //        var spaceMinus = tempString.length;
                //        array2[i] += (spaceBuffer((spaceCount-2)-spaceMinus) + tempString);
                //        spaceMinus = 0;
                //        spaceCount = 0;
                //      }
                //    }
                //  }
                //  for(i in array3) {
                //    var myString = array3[i].replace(/ *\[[^\]]*]/g, '');
                //    array3[i] = myString;
                //  }

                for(i in array1) {
                    console.log(array1[i]);
                    //  console.log(array2[i]);
                    //  console.log(array3[i]);
                }

                // for(var i=0; i<array1.length; i++){
                //     objSongToSend.push({word: array1[i], x:null , y:null,
                //         wordWidth:null});
                // }
                var songs = {"Placeholder Title" : objSongToSend
                	};

                var returnObj = {};
                returnObj.wordArray =  songs["Placeholder Title"];
                returnObj.text = "HERES MORE "


                response.writeHead(200, {'Content-Type': MIME_TYPES["text"]});  //does not work with application/json MIME
                response.end(JSON.stringify(returnObj)); //send just the JSON object


            }); //END of file read

            console.log("USER REQUEST: " + dataObj.text );
            //object to return to client

        }
      });//END of POST




    if(request.method == "GET"){
        //handle GET requests as static file requests
        var filePath = ROOT_DIR + urlObj.pathname;
        if(urlObj.pathname === '/') filePath = ROOT_DIR + '/index.html';

        fs.readFile(filePath, function(err,data){
            if(err){
                //report error to console
                console.log('ERROR: ' + JSON.stringify(err));
                //respond with not found 404 to client
                response.writeHead(404);
                response.end(JSON.stringify(err));
                return;
            }
            response.writeHead(200, {'Content-Type': get_mime(filePath)});
            response.end(data);
        });
    }

}).listen(3000);

console.log('Server Running at http://127.0.0.1:3000  CNTL-C to quit');
