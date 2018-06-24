//maximal rewarding


import java.util.*;

public class krinsky{
final static int n = 8;  // represents the layers deep that we go
//static int direction = 1;
static int loopCounter = 1000;
public static int[] scoreKeeper = {0,0,0,0,0,0,0,0};


public static int calculateStrength(int location){  // returns +1/-1
  loopCounter--;
  if(loopCounter ==0){
for(int i = 0; i<scoreKeeper.length;i++){System.out.println(scoreKeeper[i]);}
    System.exit(0);}

  System.out.println(location);
  Random rn = new Random();
  double number = rn.nextDouble();

  double functionF =  (3 * (  location)/2) + rn.nextGaussian() ;
// System.out.println(functionF);
// System.out.println(number);
  if(functionF >= 11.0  ){   // number change .8 to being greater than or less than a random double
    System.out.println("Reward");
    return 1;

  }
  else if(functionF < 11.0){
      System.out.println("Punish");
      return 0;

  }
  return -1;
}
// tsetlin(int i, int state, int theoutcome)
// 1. calculateStrength of i.
// 2. if 1, reward state(default of 4) accordingly (-1 if state%2==0, nothing if state%2 ==1)
// 3.  if 0, punish state accordingly (+1 if state%2 ==1 ) (+2 if state%2 == 0   AND add 1 to i)
// 4.  pass updated values to tsetlin and recursively repeat, printing out the state of every move
public static void tsetlin(int i,int state, int theOutcome){
  if(theOutcome == -1){System.out.println("yikes");}
  if(i == 1){scoreKeeper[0] = scoreKeeper[0] + 1;}
  if(i == 2){scoreKeeper[1] = scoreKeeper[1] + 1;}
  if(i == 3){scoreKeeper[2] = scoreKeeper[2] + 1;}
  if(i == 4){scoreKeeper[3] = scoreKeeper[3] + 1;}
  if(i == 5){scoreKeeper[4] = scoreKeeper[4] + 1;}
  if(i == 6){scoreKeeper[5] = scoreKeeper[5] + 1;}
  if(i == 7){scoreKeeper[6] = scoreKeeper[6] + 1;}
  if(i == 8){scoreKeeper[7] = scoreKeeper[7] + 1;}

 //state = i*2;
  //favorable
  System.out.println("The location is: " + i + " The state is: " + state );

if(theOutcome == 1){ //reward case
  if(i == 1){ state = 1;}
  else if(i == 2){ state = 5;}
  else if(i == 3){ state = 9;}
  else if(i == 4){ state = 13;}
  else if(i == 5){ state = 17;}
  else if(i == 6){ state = 21;}
  else if(i == 7){ state = 25;}
  else if(i == 8){ state = 29;}
}
//unfavorable
else if(theOutcome == 0){
  if(state%4!=0){
    state = state + 1;
  }
  else if(state%4==0){
    if(state == 32){
      state = 4;
      i = 1;
    }
    else if(state!=32){
      state = state + 4;
      i = i + 1;
    }
    // if state  = 4,8,12,16,17,21,25 add 2   -- if 29 set state = 4.
    // if not one of those numbers subtract 1
  }

}

//System.out.println("The location is: " + i + " The state is: " + state );
  tsetlin(i,state,calculateStrength(i));
}

public static void main(String []args){
tsetlin(1,4,calculateStrength(1)); // (one as a starting location)
}

}
