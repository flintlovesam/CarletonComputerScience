

import java.util.*;
import java.util.concurrent.TimeUnit;

public class DFS {
//public static void main()

public static void main(String[] args){

  //  CustomObject myObject = new CustomObject();

    int [][] board = new int [7][7];

  //  LinkedList ll = new LinkedList(); //or maybe make an array ?
    // ArrayList<DArray> myList = new ArrayList<DArray>();



   boardIter(populateBoard(board));


  }


//left,right,up,down doing check for peg that does the jump. // being jumped or doing jumping

// i or y dictates the row being examined   .... height
// j or x dictates  the position in the rown .... width


static Deque <int[][]> myList = new ArrayDeque<int[][]>();


public static void boardIter (int[][] arr){
int counter = 0;
        for(int i=0; i<7; i++){
          System.out.println();
          for(int j=0; j<7; j++){

            //right moving peg jump
              if(j < 5 && (arr[i][j] == 1) ){
          //      System.out.println(counter);

                 if(   (arr[i][j] == 1) && (arr[i][j+1] == 1) && (arr[i][j+2] == 0) ){

                   //perform the move
                      arr[i][j]=0;
                      arr[i][j+1]=0;
                      arr[i][j+2]=1;

                   // create new 2d array called updated
                     int [][] changedBoard = copyBoard(arr);
                   myList.add(changedBoard);

                  //check for win
                   winCheck(changedBoard);

              //     if(myList.peekFirst() == null ){System.exit(0);}
                   boardIter(myList.poll());



                   //undo move
                   arr[i][j]=1;
                   arr[i][j+2]=0;
                   arr[i][j+1]=1;
              //     counter++;
                 }

                              }

            //left moving peg jump
            if(j > 1 && (arr[i][j] == 1)){
            if(   (arr[i][j] == 1) && (arr[i][j-1] == 1) && (arr[i][j-2] == 0) ){

              //make move
              arr[i][j]=0;
              arr[i][j-1]=0;
              arr[i][j-2]=1;

              //add board
            int [][] changedBoard = copyBoard(arr);
            myList.add(changedBoard);
            //   myList.add(new DArray(arr));

               //check for win
                winCheck(changedBoard);

                if(myList.peekFirst() == null ){System.exit(0);}
                boardIter(myList.poll());

                //undo move
                arr[i][j]=1;
                arr[i][j-1]=1;
                arr[i][j-2]=0;





            }}


            //up moving peg jump: check peg above for 0 and below for 1
            if(i > 1 && (arr[i][j] == 1)){
            if(   (arr[i][j] == 1) && (arr[i-1][j] == 1) && (arr[i-2][j] == 0) ){

              arr[i][j]=0;
              arr[i-1][j]=0;
              arr[i-2][j]=1;

              //add board
            int [][] changedBoard = copyBoard(arr);
            myList.add(changedBoard);
            //   myList.add(new DArray(arr));

               //check for win
                winCheck(changedBoard);

                if(myList.peekFirst() == null ){System.exit(0);}
                boardIter(myList.poll());

                //undo move
                arr[i][j]=1;
                arr[i-2][j]=0;
                arr[i-1][j]=1;

            }}

            //down moving peg jump: check peg below for 0 and for 1 above
            if(i < 5 && (arr[i][j] == 1)){
            if(   (arr[i][j] == 1) && (arr[i+1][j] == 1) && (arr[i+2][j] == 0) ){

              arr[i][j]=0;
              arr[i+1][j]=0;
              arr[i+2][j]=1;

              //add board
            int [][] changedBoard = copyBoard(arr);
            myList.add(changedBoard);
            //   myList.add(new DArray(arr));


               //check for win
                winCheck(changedBoard);

                if(myList.peekFirst() == null ){System.exit(0);}
                boardIter(myList.poll());

                //undo move
                arr[i][j]=1;
                arr[i+2][j]=0;
                arr[i+1][j]=1;

            }}





}}

// AFTER LAST condition checked: recursively pass boardIter the NEXT element in the linked list
//System.out.println(myList.peek());
  //     System.out.println(myList.peekFirst());

/*
       for(int i=0; i<7; i++){
         System.out.println();   //("row: " + i);
         for(int j=0; j<7; j++){
       System.out.print(myList.peekFirst()[i][j]);
         }}
         */


       // if(myList.peekFirst() == null ){System.exit(0);}
       //   boardIter(myList.poll());

      // System.out.println("size is: " + myList.size());




}

public static void winCheck (int[][] arry){
  int pegsRemaining = 0;

  for(int i=0; i<7; i++){
    System.out.println();   //("row: " + i);
    for(int j=0; j<7; j++){
      if( arry[i][j] == 1){
        pegsRemaining++;
      }
  System.out.print(arry[i][j]);
    }}

    System.out.println();
    if(arry[1][3] == 1 && (pegsRemaining == 1) ){
      System.out.println("Game has been won");
      System.exit(0);  }
      }

/*
  int pegsRemaining = 0;
  outerloop:
  for(int i=0; i<7; i++){
    for(int j=0; j<7; j++){

      if( arry[i][j] == 1){
        pegsRemaining++;
      }
    if(pegsRemaining > 1){break outerloop;}


}} */





public static int[][] copyBoard(int[][] oldBoard ){

  int [][] current = new int [7][7];


//  System.out.print("Print of original board");
//    for(int i=0; i<7; i++){
//      System.out.println();   //("row: " + i);
//      for(int j=0; j<7; j++){
//    System.out.print(oldBoard[i][j]);
//      }}

    for(int i=0; i<oldBoard.length; i++) {
      for(int j=0; j<oldBoard[i].length; j++){
  current[i][j]=oldBoard[i][j];
    }}


//System.out.print("Print of copied board");
//  for(int i=0; i<7; i++){
//    System.out.println();   //("row: " + i);
//    for(int j=0; j<7; j++){
//  System.out.print(current[i][j]);
//    }}



    return current;
}



// i or y dictates the row being examined   .... height
// j or x dictates  the position in the rown .... width

public static int[][] populateBoard(int[][] theBoard ){
    //  [row][col]
/*
theBoard[0][0] = 2;
theBoard[0][1] = 2;
theBoard[0][2] = 0;
theBoard[0][3] = 0;
theBoard[0][4] = 0;
theBoard[0][5] = 2;
theBoard[0][6] = 2;

theBoard[1][0] = 2;
theBoard[1][1] = 0;
theBoard[1][2] = 0;
theBoard[1][3] = 0;
theBoard[1][4] = 0;
theBoard[1][5] = 1;
theBoard[1][6] = 2;


theBoard[2][0] = 0;
theBoard[2][1] = 0;
theBoard[2][2] = 0;
theBoard[2][3] = 0;
theBoard[2][4] = 1;
theBoard[2][5] = 0;
theBoard[2][6] = 0;


theBoard[3][0] = 0;
theBoard[3][1] = 0;
theBoard[3][2] = 1;
theBoard[3][3] = 0;
theBoard[3][4] = 0;
theBoard[3][5] = 0;
theBoard[3][6] = 0;


theBoard[4][0] = 1;
theBoard[4][1] = 1;
theBoard[4][2] = 0;
theBoard[4][3] = 0;
theBoard[4][4] = 1;
theBoard[4][5] = 0;
theBoard[4][6] = 0;


theBoard[5][0] = 2;
theBoard[5][1] = 0;
theBoard[5][2] = 0;
theBoard[5][3] = 1;
theBoard[5][4] = 0;
theBoard[5][5] = 0;
theBoard[5][6] = 2;

theBoard[6][0] = 2;
theBoard[6][1] = 2;
theBoard[6][2] = 0;
theBoard[6][3] = 0;
theBoard[6][4] = 0;
theBoard[6][5] = 2;
theBoard[6][6] = 2;
*/

theBoard[0][0] = 2;
theBoard[0][1] = 2;
theBoard[0][2] = 0;
theBoard[0][3] = 0;
theBoard[0][4] = 0;
theBoard[0][5] = 2;
theBoard[0][6] = 2;

theBoard[1][0] = 2;
theBoard[1][1] = 0;
theBoard[1][2] = 0;
theBoard[1][3] = 0;
theBoard[1][4] = 0;
theBoard[1][5] = 1;
theBoard[1][6] = 2;


theBoard[2][0] = 1;
theBoard[2][1] = 1;
theBoard[2][2] = 0;
theBoard[2][3] = 0;
theBoard[2][4] = 1;
theBoard[2][5] = 0;
theBoard[2][6] = 0;


theBoard[3][0] = 1;
theBoard[3][1] = 1;
theBoard[3][2] = 1;
theBoard[3][3] = 0;
theBoard[3][4] = 1;
theBoard[3][5] = 0;
theBoard[3][6] = 0;


theBoard[4][0] = 1;
theBoard[4][1] = 0;
theBoard[4][2] = 0;
theBoard[4][3] = 1;
theBoard[4][4] = 1;
theBoard[4][5] = 0;
theBoard[4][6] = 0;


theBoard[5][0] = 2;
theBoard[5][1] = 0;
theBoard[5][2] = 0;
theBoard[5][3] = 0;
theBoard[5][4] = 1;
theBoard[5][5] = 1;
theBoard[5][6] = 2;

theBoard[6][0] = 2;
theBoard[6][1] = 2;
theBoard[6][2] = 0;
theBoard[6][3] = 0;
theBoard[6][4] = 1;
theBoard[6][5] = 2;
theBoard[6][6] = 2;



for(int i=0; i<7; i++){
  System.out.println();   //("row: " + i);
  for(int j=0; j<7; j++){
System.out.print(theBoard[i][j]);
  }}

  System.out.println();


  return theBoard;
}

}
// fix win condition
// depth first search
//A* search
//start A2
