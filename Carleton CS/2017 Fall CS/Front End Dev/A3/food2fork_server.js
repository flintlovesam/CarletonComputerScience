/*
Interacting with external services

Simple example of node.js app serving contents based
on an available internet service.
In this case api.openweathermap.org

***IMPORTANT NOTE***
As of 2015 openweather requires that you provide an APPID
with your HTTP requests. You can get on by creating a
free account at: http://openweathermap.org/appid

To Test: Use browser to view http://localhost:3000/
*/

let http = require('http')
let url = require('url')
let qstring = require('querystring')

const PORT = process.env.PORT || 3000
//Please register for your own key replace this with your own.
const API_KEY = 'c630c59692a73fac12d2a6c2cd9801ab'

function sendResponse(weatherData, res){
  var page = '<html><head><title>API Example</title></head>' +
    '<body>' +
    '<form method="post">' +
    'Ingredient: <input name="ingredient"><br>' +
    '<input type="submit" value="Get recipe">' +
    '</form>'
  if(weatherData){
    page += '<h1>Recipes: </h1><p>' + weatherData +'</p>'
  }
  page += '</body></html>'
  res.end(page);
}

function parseData(recipeResponse, res) {
  let recipeData = ''
  recipeResponse.on('data', function (chunk) {
    recipeData += chunk
  })
  recipeResponse.on('end', function () {
    sendResponse(recipeData, res)
  })
}
/*
function getWeather(ingredient, res){

//New as of 2015: you need to provide an appid with your request.
//Many API services now require that clients register for an app id.

//Make an HTTP GET request to the openweathermap API
  let options = {
    host: 'api.openweathermap.org',
    path: '/data/2.5/weather?q=' + ingredient +
	'&appid=' + API_KEY
  }
  http.request(options, function(apiResponse){
    parseWeather(apiResponse, res)
  }).end()
}
*/

function getRecipes(ingredient, res){

//You need to provide an appid with your request.
//Many API services now require that clients register for an app id.

  const options = {
     host: 'www.food2fork.com',
     path: `/api/search?q=${ingredient}&key=${API_KEY}`
  }
  http.request(options, function(apiResponse){
    parseData(apiResponse, res)
  }).end()
}

http.createServer(function (req, res) {
  let requestURL = req.url
  let query = url.parse(requestURL).query //GET method query parameters if any
  let method = req.method
  console.log(`${method}: ${requestURL}`)
  console.log(`query: ${query}`) //GET method query parameters if any

  if (req.method == "POST"){
    let reqData = ''
    req.on('data', function (chunk) {
      reqData += chunk
    })
    req.on('end', function() {
	  console.log(reqData);
      var queryParams = qstring.parse(reqData)
	  console.log(queryParams)
      getRecipes(queryParams.ingredient, res)
    })
  }
  else if(req.method == "GET")
  {
    let reqData = ''
    req.on('data', function (chunk) {
      reqData += chunk
    })
    req.on('end', function() {
	  console.log(reqData);
      var queryParams = qstring.parse(reqData)
	  console.log(queryParams)
      getRecipes(queryParams.ingredient, res)
    })
  }
   else{
    sendResponse(null, res)
  }
}).listen(PORT, (error) => {
  if (error)
    return console.log(error)
  console.log(`Server is listening on PORT ${PORT} CNTL-C to quit`)
})
