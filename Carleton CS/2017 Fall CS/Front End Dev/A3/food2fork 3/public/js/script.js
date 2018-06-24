let getIngredients =  () => {

    let ingredient = document.getElementById('ingredientz').value
    if(ingredient === '') {
        return alert('Please enter a ingredient')
    }

    let ingredientDiv = document.getElementById('ingredientType')
    ingredientDiv.innerHTML = ''

    let xhr = new XMLHttpRequest()
    xhr.onreadystatechange = () => {
        if (xhr.readyState == 4 && xhr.status == 200) {
            let response = JSON.parse(xhr.responseText)
// or rTitle = response.recipes.title
     //rLink = response.recipes.image_url

// for loop through
            console.log(response);
            for(i = 0; i < response.count; i++){

              let rTitle = response.recipes[i].title;
              let rLink = response.recipes[i].image_url;
              let rSource = response.recipes[i].source_url;

              console.log(rTitle);
              console.log(rLink);


              ingredientDiv.innerHTML += `


              <div class = "item">

              <a href=${rSource}>
              <img src= ${rLink} width="250" height="250"  >
              </a>
              <p>${rTitle}</p>
              </div>
              `

            }


//            //create a div, in it have a title section, and have a image section


        }
    }
   // xhr.open('GET', `q=${ingredient}`, true)
    xhr.open('GET', `/search?q=${ingredient}`, true)
    xhr.send()
}

//Attach Enter-key Handler
const ENTER=13
document.getElementById("ingredientz")
    .addEventListener("keyup", function(event) {
    event.preventDefault();
    if (event.keyCode === ENTER) {
        document.getElementById("submit").click();
    }
});
