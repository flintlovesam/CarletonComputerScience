/*
Before you run this app first execute
>npm install
to load npm modules listed in package.json file

Then launch this server.
Then open several browsers to: http://localhost:3000/index.html

*/

var http = require('http');
//npm modules (need to install these first)
var WebSocketServer = require('ws').Server; //provides web sockets
var ecStatic = require('ecstatic');  //provides static file server service

//static file server
var server = http.createServer(ecStatic({root: __dirname + '/www'}));

var wss = new WebSocketServer({server: server});
wss.on('connection', function(ws) {
  console.log('Client connected');
  ws.on('message', function(msg) {
    console.log('Message: ' + msg);
    broadcast(msg);
  });
});

function broadcast(msg) {
  wss.clients.forEach(function(client) {
    client.send(msg);
  });
}

server.listen(3000);
console.log('Server Running at http://127.0.0.1:3000  CNTL-C to quit');
