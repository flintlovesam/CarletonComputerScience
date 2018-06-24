/* Example of javascript functions

Example adapted from:
 "Elequent Javascript" 2nd ed. by Marijn Haverbeke
http://eloquentjavascript.net/03_functions.html


Exercise 1: 

Modify the code given below so that the hill function makes use of the 
underscore character, just like the flat function does, 
expect the mountain tops will have to be drawn on the previous line of the output.

Also modify the code so that the following script portion will 
result in the terrain shown.

  //BUILD SCRIPT
  flat(3)
  hill(5);
  flat(2);
  hill(3);
  flat(4);
  hill(0);
  flat(2);
  //END SCRIPT


function and the program produces the following terrain.

    _____    ___
___/     \__/   \____/\__


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

  
  let flat = function(size) {
    for (let count = 0; count < size; count++){
      result += "_";
  	  top += " ";	
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


  //BUILD SCRIPT
  flat(3)
  hill(4);
  flat(6);
  hill(1);
  flat(1);
  //END SCRIPT
  //return top;
    console.log(top);

  return result;

};

console.log("");
console.log(landscape());
//  ___/''''\______/'\_
