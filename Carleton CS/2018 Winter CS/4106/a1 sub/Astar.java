

import java.util.*;

public class Astar {
    // public static int g;    need an int that keeps track of steps away we are from the begining board

    static PriorityQueue pq;

    public static void main(String[] args) {


// Make Board
        Integer [][] board = new Integer[7][7];

//Make priority queue data structure
        pq = new PriorityQueue<PriorityBoard>(new Comparator<PriorityBoard>() {

            public int compare(PriorityBoard pb1, PriorityBoard pb2) {
                return pb1.priority.compareTo(pb2.priority);
            }
        });


// make a global int to be used as the g(n), that gets iterated and changed the value globally
// make a board and populate it
// pass initial board to boarditer with initial Mahhatan length of 0       boarditer(populateBoard(board))

// in the boarditer function, for each move, do regular work, b


        pq.add(new PriorityBoard(0, populateBoard(board)));

        boardIter(( PriorityBoard) pq.poll());


    }


//static Deque <int[][]> myList = new ArrayDeque<int[][]>();


    public static void boardIter(PriorityBoard arr) {
        int counter = 0;
        for (int i = 0; i < 7; i++) {
            System.out.println();
            for (int j = 0; j < 7; j++) {

                //right moving peg jump
                if (j < 5 && (arr.board[i][j] == 1)) {
                    //      System.out.println(counter);

                    if ((arr.board[i][j] == 1) && (arr.board[i][j + 1] == 1) && (arr.board[i][j + 2] == 0)) {

                        //perform the move
                        arr.board[i][j] = 0;
                        arr.board[i][j + 1] = 0;
                        arr.board[i][j + 2] = 1;

                        // create new 2d array called updated
                        Integer[][] changedBoard = copyBoard(arr.board);

                        //calculate heuristic for new board

                        //check for win
                        winCheck(changedBoard);

                        pq.add(new PriorityBoard(heuristic(changedBoard), changedBoard));    //   INSTEAD ADD THE changedBoard to the priority queue


                        //undo move
                        arr.board[i][j] = 1;
                        arr.board[i][j + 2] = 0;
                        arr.board[i][j + 1] = 1;
                        //     counter++;
                    }

                }

                //left moving peg jump
                if (j > 1 && (arr.board[i][j] == 1)) {
                    if ((arr.board[i][j] == 1) && (arr.board[i][j - 1] == 1) && (arr.board[i][j - 2] == 0)) {

                        //make move
                        arr.board[i][j] = 0;
                        arr.board[i][j - 1] = 0;
                        arr.board[i][j - 2] = 1;

                        //add board
                        Integer[][] changedBoard = copyBoard(arr.board);

                        //check for win
                        winCheck(changedBoard);

                        pq.add(new PriorityBoard(heuristic(changedBoard), changedBoard));


                        //undo move
                        arr.board[i][j] = 1;
                        arr.board[i][j - 1] = 1;
                        arr.board[i][j - 2] = 0;


                    }
                }


                //up moving peg jump: check peg above for 0 and below for 1
                if (i > 1 && (arr.board[i][j] == 1)) {
                    if ((arr.board[i][j] == 1) && (arr.board[i - 1][j] == 1) && (arr.board[i - 2][j] == 0)) {

                        arr.board[i][j] = 0;
                        arr.board[i - 1][j] = 0;
                        arr.board[i - 2][j] = 1;

                        //add board
                      //  int[][] changedBoard = copyBoard(arr.board);
                        Integer[][] changedBoard = copyBoard(arr.board);

                        //check for win
                        winCheck(changedBoard);
                        pq.add(new PriorityBoard(heuristic(changedBoard), changedBoard));


                        //undo move
                        arr.board[i][j] = 1;
                        arr.board[i - 2][j] = 0;
                        arr.board[i - 1][j] = 1;

                    }
                }

                //down moving peg jump: check peg below for 0 and for 1 above
                if (i < 5 && (arr.board[i][j] == 1)) {
                    if ((arr.board[i][j] == 1) && (arr.board[i + 1][j] == 1) && (arr.board[i + 2][j] == 0)) {

                        arr.board[i][j] = 0;
                        arr.board[i + 1][j] = 0;
                        arr.board[i + 2][j] = 1;

                        //add board
                        Integer [][] changedBoard = copyBoard(arr.board);
                        //check for win
                        winCheck(changedBoard);
                        pq.add(new PriorityBoard(heuristic(changedBoard), changedBoard));

                        //undo move
                        arr.board[i][j] = 1;
                        arr.board[i + 2][j] = 0;
                        arr.board[i + 1][j] = 1;

                    }
                }


            }
        }


        if (pq.peek() == null) {
            //   System.exit(0);
            return;
        }


        System.out.println("size is: " + pq.size());
        System.out.println(pq.toString());

        boardIter((PriorityBoard) pq.poll());


    }

    public static int heuristic(Integer[][] arr) {
        int man = 0;
        int numPegs = 0;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                if (arr[i][j] == 1) {
                    numPegs += 1;
                }
                for (int k = 0; k < 7; k++) {
                    for (int l = 0; l < 7; l++) {
                        if (arr[k][l] == 1) {
                            man += (Math.abs(i - k) + Math.abs(j - l));

                        }
                    }
                }


            }

        }
        return (man / (2 * numPegs));
    }


    public static void winCheck(Integer[][] arry) {
        int pegsRemaining = 0;

        for (int i = 0; i < 7; i++) {
            System.out.println();   //("row: " + i);
            for (int j = 0; j < 7; j++) {
                if (arry[i][j] == 1) {
                    pegsRemaining++;
                }
                System.out.print(arry[i][j]);
            }
        }

        System.out.println();
        if (arry[1][3] == 1 && (pegsRemaining == 1)) {
            System.out.println("Game has been won");
            //  System.exit(0);
        }
    }

    public static Integer[][] copyBoard(Integer[][] oldBoard) {

        Integer[][] current = new Integer[7][7];


        for (int i = 0; i < oldBoard.length; i++) {
            for (int j = 0; j < oldBoard[i].length; j++) {
                current[i][j] = oldBoard[i][j];
            }
        }

        return current;
    }


// i or y dictates the row being examined   .... height
// j or x dictates  the position in the rown .... width

    public static Integer [][] populateBoard(Integer[][] theBoard) {
        //  [row][col]

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


        for (int i = 0; i < 7; i++) {
            System.out.println();   //("row: " + i);
            for (int j = 0; j < 7; j++) {
                System.out.print(theBoard[i][j]);
            }
        }

        System.out.println();


        return theBoard;
    }

}
