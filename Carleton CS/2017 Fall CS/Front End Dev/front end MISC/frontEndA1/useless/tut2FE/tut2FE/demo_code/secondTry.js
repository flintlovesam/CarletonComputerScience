    

  var fs = require('fs');
  var colour = require('colour');

  process.stdin.resume();
  process.stdin.setEncoding('utf8');
  var util = require('util');

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