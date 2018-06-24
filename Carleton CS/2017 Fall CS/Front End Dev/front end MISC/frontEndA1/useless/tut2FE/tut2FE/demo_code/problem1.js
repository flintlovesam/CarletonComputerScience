/* Example of javascript functions



Exercise 2: 

Modify the code from exercise 1 so you can have both hills and mountains. 
Mountains are require two output lines. 

After completing exercise 2 the following BUILD SCRIPT portion should produce the output shown. 

  //BUILD SCRIPT
  flat(3)
  mountain(3);
  flat(2);
  mountain(0);
  flat(4);
  hill(1);
  flat(1);
  //END SCRIPT


function and the program produces the following terrain.

     ___  
    /   \    /\      _
___/     \__/  \____/ \_


*/
// define string 1.... this is the u[[er string which will have appended to it the tops
// define string 2...this is the lower level string which will have appended to it everything but the tops
// after both are finished being drawn on, then we print them both, but the top, new line, then the botoom


// var bot;

let landscape = function() {
  let result = "";
  var top = "";
  var middle = " ";

  
  let flat = function(size) {
    for (let count = 0; count < size; count++){
      result += "_";
  	  top += " ";	
      middle += " ";
  	}
  };


  let hill = function(size) {
    result += "/";
    top += " ";
    for (let count = 0; count < size; count++){
      result += " ";
      top += "_";

    }
      
    result += "\\";
    top += " ";
  };


    let mountain = function(size) {
    middle += "/";
    result += "/";
    top += " ";
    for (let count = 0; count < size; count++){
      result += " ";
      top += "_";
      middle += " ";
    }
     middle += "\\"; 
    result += "\\";
    top += " ";
  };

/*
  //BUILD SCRIPT 1
  
  flat(3)
  hill(4);
  flat(6);
  hill(1);
  flat(1);
  //END SCRIPT
*/
  //BUILD SCRIPT 2
  flat(3)
  mountain(3);
  flat(2);
  mountain(0);
  flat(4);
  hill(1);
  flat(1);
  //END SCRIPT

    console.log(top);
    console.log(middle);

  return result;

};

console.log("");
console.log(landscape());
//  ___/''''\______/'\_
