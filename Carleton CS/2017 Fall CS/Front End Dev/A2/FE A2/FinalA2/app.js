////CITATION: We utilized the chat app provided by Lou Nel as starting infrastructure


var http = require('http');
//npm modules (need to install these first)
var WebSocketServer = require('ws').Server; //provides web sockets
var ecStatic = require('ecstatic');  //provides static file server service
var portwizard = require('./portwizard');
//static file server
var server = http.createServer(ecStatic({root: __dirname + '/www'}));

var wss = new WebSocketServer({server: server});

var connections = {};
var connectionIDCounter = 0;   // used to count the number of connections bein made

// eula.message();


wss.on('connection', function(ws) {
  ws.id = connectionIDCounter ++;    // set an id for each new connection comming in
  connections[ws.id] = ws;    

  console.log('Client connected');

  ws.on('message', function(msg) {
    console.log('Message: ' + msg);
    //  broadcast(msg);
    if(Object.keys(JSON.parse(msg))[0] == "word")   // taking the message sent from client, check for certain type of message
    {
     // console.log("hello");
      wss.clients.forEach(function(client) { // goes through each client sends message to them...will call this function to signal game over
        if(ws.id != client.id){     // used to send a message to the opposite person, as the id's mismatch
          client.send(msg);
        }
        if(ws.id == client.id){     // send a client their ID
          var playNum = { identit : client.id};
          client.send(JSON.stringify(playNum));
                }
      });
    }
  });

});

function broadcast(msg) {
  wss.clients.forEach(function(client) { // goes through each client sends message to them...will call this function to signal game over
    client.send(msg);
  });
}

server.listen(3000);
portwizard();