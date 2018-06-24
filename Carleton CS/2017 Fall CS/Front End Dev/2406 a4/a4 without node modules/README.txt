Assignment 4: RESTful API of Recipe Data Using Sqlite 


Developed By:
 Dave Nelson: 100988794
 Sammy Diamantstein: 101060342 



Launching app:

1. Install npm modules:
>npm install
	This will install the modules listed as dependencies in the package.json file.


2. Launch server: enter into the demo code directory, then…..
> node server_with_SQLite_and_Handlebars.js


3. To see the "app" use your browser to visit:
> localhost:3000/recipes

4. To view a particular recipe, click on a link



XML—> Sqlite Parsing:
In order to parse the xml to the sqlite DB, go into the dbMaking folder, download the needed nom modules if needed with:

npm install 'line-reader'
npm install 'sqlite3' 

Following this, execute the parser by typing: 
node recipe_file_line_reader.js



Tested on:
- Mac OS with Chrome and Safari Browsers