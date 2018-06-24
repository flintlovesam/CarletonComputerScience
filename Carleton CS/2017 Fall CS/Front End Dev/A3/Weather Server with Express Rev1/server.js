/*
NOTE: THIS CODE WILL NOT RUN UNTIL YOU ENTER YOUR OWN openweathermap.org APP ID KEY

NOTE: You need to intall the npm modules by executing >npm install
before running this server

Simple express server re-serving data from openweathermap.org
To test:
http://localhost:3000
or
http://localhost:3000/weather?city=Ottawa
to just set JSON response. (Note it is helpful to add a JSON formatter extension, like JSON Formatter, to your Chrome browser for viewing just JSON data.)
*/
const express = require('express') //express framework
const requestModule = require('request') //npm module for easy http requests
const PORT = process.env.PORT || 3000
const logger = require('morgan'); //request logger


/*YOU NEED AN APP ID KEY TO RUN THIS CODE
  GET ONE BY SIGNING UP AT openweathermap.org
  THE KEY BELOW IS FAKE
*/
const WEATHER_API_KEY = '050b19a5161a443bc753a910256b7860' //PUT IN YOUR OWN KEY HERE

const app = express()

//Middleware
app.use(express.static(__dirname + '/public')) //static server
app.use( logger('dev'));

//Routes
app.get('/', (request, response) => {
  response.sendFile(__dirname + '/views/index.html')
})

app.get('/weather', (request, response) => {
  let city = request.query.city
  if(!city) {
    return response.json({message: 'Please enter a city name'})
  }
  const url = `http://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${WEATHER_API_KEY}`
  requestModule.get(url, (err, res, data) => {
    return response.contentType('application/json').json(JSON.parse(data))
  })
})

//start server
app.listen(PORT, err => {
  if(err) console.log(err)
  else {
    console.log(`Server listening on port: ${PORT}`)
  }
})
