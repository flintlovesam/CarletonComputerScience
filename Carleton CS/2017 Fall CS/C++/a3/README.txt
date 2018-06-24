To compile:
make clean mytunes
To run:
./mytunes

The program reads the insert_beatles_tracks_rev1.txt script on startup.
To disable this behaviour comment out the lines:

  //initialize app with input script
  Command cmd = Command(".read insert_beatles_tracks_rev1.txt");
  executeCommand(cmd);

in the run() method at the start of the UI.cpp file.

Please report bugs to me so I can fix them.
Lou Nel
ldnel@scs.carleton.ca

