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

            console.log(response);
            for(i = 0; i < response.count; i++){

              let rTitle = response.recipes[i].title;   //stores the title of an object from the recipes array
              let rLink = response.recipes[i].image_url;   //stores the image link of an object from the recipes array
              let rSource = response.recipes[i].source_url; //stores the URL of an item

              ingredientDiv.innerHTML += `
              <div class = "item">

              <a href=${rSource}>
              <img src= ${rLink} width="250" height="250"  >
              </a>
              <p class= "one">${rTitle}</p>
              </div>
              `
            }
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
