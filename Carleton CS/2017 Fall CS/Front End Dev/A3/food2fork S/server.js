
const express = require('express') //express framework
const requestModule = require('request') //npm module for easy http requests
const PORT = process.env.PORT || 3000
const logger = require('morgan'); //request logger

const FOOD_API_KEY = 'b77a8db1a0cffb80e5d6f7db2ceadcc2'
const app = express()

//Middleware
app.use(express.static(__dirname + '/public')) //static server
app.use( logger('dev'));

//Routes

  app.get('/', (request, response) => {
    console.log(request.query);
  response.sendFile(__dirname + '/views/index.html')
})


//})

app.get('/search', (request, response) => {
  let ingredient = request.query.q   //.ingredient
  console.log(request)
  if(!ingredient) {
    return response.json({message: 'Please enter an ingredient name'})
  }

  const url = `http://food2fork.com/api/search?key=${FOOD_API_KEY}&q=${ingredient}`
  requestModule.get(url, (err, res, data) => {
    return response.send(data);
  })
})

//start server
app.listen(PORT, err => {
  if(err) console.log(err)
  else {
    console.log(`Server listening on port: ${PORT}`)
  }
})
