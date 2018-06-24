
  /*
  Example of ASYNCHRONOUS file read.
  Function readFile does not block (wait) for the file to be read.

  Instead its argument function(err,data) will be called once the file has been read.
  function(err,data) is the "call back" function that will be called when readFile's task is done.
  */


  var fs = require('fs');
  var colour = require('colour');

  process.stdin.resume();
  process.stdin.setEncoding('utf8');
  var util = require('util');

  console.log("Enter the song name: (example sister_golden_hair.txt) \n");

  // AFTER TAKING DATT FROM THE USER USE IT IN A FUNCTION.
  process.stdin.on('data', function (text) {

    console.log('received data:', util.inspect(text));
/*
    const readFile = function(filename, callback) {
        read file
       if ( reading the file is successfull) {
        //  (err, contents)
         callback(null, contents)
      else {
        callback(err, null)
      }
       }

    }
*/

    // READING THE FILE AND USING A FUNCTION THAT DEALS WITH THE DATA.
    fs.readFile("songs/" + text.replace("\n",""), function(err, data) {
      if(err) throw err;
      var array = data.toString().split("\n");

      for(let i=0;i<array.length;i++)
      {
        //DEFINITIONS
        var currentLine = array[i].replace(/(\r\n|\n|\r)/gm,"")
        var chords = "";
        var lyrics = "";
        var oneMoreChar = 1;

        //FINDING LINES THAT HAVE CHORDS IN THEM
        while(currentLine.includes("["))  // while we have an opening bracket "[" in currentLine then keep adding codes and lyrics to the song string.
        {
          //FIRST MAKE SURE TO ADD ENOUGH SPACES SO THAT THE CHORDS ARE ABOVE THE CORRECT LYRICS THEN CUT THE CHORDS (wtv is inside the brackets). LASTLY, CUT THE LYRICS BEFORE THE CHORD AND ADD THEM IN LYRICS STRING.
          chords += ' '.repeat(currentLine.indexOf("[")) + currentLine.slice(currentLine.indexOf("[") + oneMoreChar,currentLine.indexOf("]"));
          lyrics += currentLine.slice(0,currentLine.indexOf("["));
          // WE ARE CUTTING THE LINE INTO SMALLER PIECES, SO THAT WE CAN TREAT EACH CUT AS A NEW LINE.
          currentLine = currentLine.slice(currentLine.indexOf("]")+oneMoreChar);
        }
        // WE MAKE SURE WE GET THE OTHER LINES AS LYRICS AND THEN ALSO GET THE LINES THAT ARE AT THE END AFTER THE "]" BRACKET CLOSURES
        lyrics += currentLine;
        console.log(chords.green +"\n"+lyrics.yellow);
      }
    });
   });
