

var http = require('http');
var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var logger = require('morgan');

var  app = express(); //create express middleware dispatcher

const PORT = process.env.PORT || 3000

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'hbs'); //use hbs handlebars wrapper

app.locals.pretty = true; //to generate pretty view-source code in browser

//read routes modules
var routes = require('./routes/index');

//some logger middleware functions
function methodLogger(request, response, next){
		   console.log("METHOD LOGGER");
		   console.log("================================");
		   console.log("METHOD: " + request.method);
		   console.log("URL:" + request.url);
		   next(); //call next middleware registered
}
function headerLogger(request, response, next){
		   console.log("HEADER LOGGER:")
		   console.log("Headers:")
           for(k in request.headers) console.log(k);
		   next(); //call next middleware registered
}

//register middleware with dispatcher
//ORDER MATTERS HERE
//middleware
app.use(routes.authenticate); //authenticate user
app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(logger('dev'));
//app.use(methodLogger);
//routes
app.get('/index.html', routes.index);  //basic homepage
app.get('/find', routes.find);   //recipe can be  gotten at "/find"  or at "/recipes"
app.get('/recipes', routes.find);  //see line 46
app.get('/users', routes.users);
app.get('/recipes/*', routes.recipeDetails);  // route used for whatever recipe a person clicks on

//start server
app.listen(PORT, err => {
  if(err) console.log(err)
  else {console.log(`Server listening on port: ${PORT} CNTL:-C to stop`)}
})
