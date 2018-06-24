public static void boardIter (board arr){

if(board.maximisingPlayer){
//then we are max, and by extension we are first player (blue)
//generate next move using minimax
for(int i=0; i<6; i++){
    for(int j=0; j<6; j++) {


                if(arr.childBoard[i][j] == 2){   //if the piece is red(attacker) - check all other pieces in row
                  int currVerticalPlace = i;  //2

        // for loop for checking upwards of the spot
                    for(int k=0; k<currVerticalPlace; k++){
                      if(arr.childBoard[0][j]!=2){   //check to make sure the upper cap is not oppositional

                        if(arr.childBoard[0][k] == 1){    //check to see if the place above is is oppositional
                          int pushdown = Math.abs(i-k);    // distance between where attacker and oppositional piece ... 2 in this case... 2-0


// break it down: take all the moves up for that piece [x,y]--> [x,y]


                           // for(int l=0; l<pushdown; l++){
                           //   if(arr.childBoard[0][l] == 1){
                           //     int attackblePegs ++;
                           //   }
                           // }
                           // while(attackblePegs != 0){
                           //
                           //   // per
                           //
                           //   attackblePegs--;
                           // }

                          // count the number of pegs I can kill
                          // I found a peg I can move!
                           // make move
                           //copy board



                        }

                      }

                    }



                  }}}}}


                  if(i+pushdown>=5 && arr.childBoard[k][j] != 2){
                        arr.childBoard[i][k] = 0;
                    }
                    else if (j+pushdown<=5){
                        arr.childBoard[i][j+pushdown] = arr.childBoard[i][j];

                    }
