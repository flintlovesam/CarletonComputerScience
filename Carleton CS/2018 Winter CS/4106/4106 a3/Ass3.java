import java.util.*;

public class Ass3{
final static int n = 24;  // represents the layers deep that we go
//static int direction = 1;
static int loopCounter = 1000;


public static void outcome(int location){  // returns +1/-1
  loopCounter--;
  if(loopCounter ==0){System.exit(0);}

  System.out.println(location);
  Random rn = new Random();
  double number = rn.nextDouble();

  double functionF =  (3 * (  location)/2) + rn.nextGaussian() ;
// System.out.println(functionF);
// System.out.println(number);
  if(functionF/15 > .8  ){   // number change .8 to being greater than or less than a random double
    System.out.println("Reward");
    tsetlin(location,1);
    //return 0 ; //return the reward
  }
  else if(functionF/15 < number){
      System.out.println("Punish");
      tsetlin(location,0);

    //return 1;
  }
//return 99;
}


public static void tsetlin(int i, int theOutcome){
  //favorable
if(theOutcome == 1){
  if( ((2<=i) && (i<=n)) || ( (n+2 <= i) &&  (i<= 2*n) )){
    System.out.println("This is favorable");
    i = n-1;
  }
  else{  //??

  }
}
//unfavorable
else if(theOutcome == 0){
  if((1<=i && i<=n-1) || (n+1<=i && i<= 2*n - 1)){
      System.out.println("This is unfavorable");
    i = n+1;
  }
  //loop case
  if(i==n){
    i=2*n;
  }
  else if(i == 2*n){
    i=n;
  }
}
System.out.println("This is the state: " + i);
outcome(i);
}

/* Pseudo
1< = i < = n ...... alpha =1 (left side).....
N+1 <= i <= 2*n.....alpha = 2 (right side)
}
*/










//probability i get a penalty


public static void main(String []args){
outcome(3);
}


// returns a -1 or 1 for tsetlin based on whether it passes probability for
}
