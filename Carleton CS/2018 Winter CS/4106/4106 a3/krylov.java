import java.util.*;

public class krylov{
final static int n = 8;  // represents the layers deep that we go
//static int direction = 1;
public static Random randomno = new Random();
static int loopCounter = 1000;
public static int[] scoreKeeper = {0,0,0,0,0,0,0,0};
public static boolean value;


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
// krylov(int i, int state, int theoutcome)
// 1. calculateStrength of i.
// 2. if 1, reward state(default of 4) accordingly (-1 if state%2==0, nothing if state%2 ==1)
// 3.  if 0, punish state accordingly (+1 if state%2 ==1 ) (+2 if state%2 == 0   AND add 1 to i)
// 4.  pass updated values to krylov and recursively repeat, printing out the state of every move
public static void krylov(int i,int state, int theOutcome){
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

if(theOutcome == 1){
  if(state%2==0){
    state = state - 1;
  }
  else if(state%2==1){state = state;}
}
//unfavorable
else if(theOutcome == 0){
  value = randomno.nextBoolean();
if(value){
  if(state%2==1){
    state = state + 1;
  }
  else if(state%2==0){
    if(state == 16){state = 2;}
    else if(state!=16){state = state + 2;}
  }
}
}
if(state%2 == 0){
  i = state / 2;
}
else if(state%2 == 1 ){
  i = (state + 1)/2;
}
//System.out.println("The location is: " + i + " The state is: " + state );
  krylov(i,state,calculateStrength(i));
}

public static void main(String []args){
krylov(2,4,calculateStrength(2)); // (one as a starting location)
}

}
