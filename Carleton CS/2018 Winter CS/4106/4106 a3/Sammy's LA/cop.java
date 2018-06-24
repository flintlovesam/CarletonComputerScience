import java.util.*;

public class Ass3{
final int n = 10;  // represents the layers deep that we go
final static int direction = 1;


public static int outcome(int theDirection){  // returns +1/-1
  Random rn = new Random();
  double number = rn.nextDouble();

  double functionF = 0;
  functionF =  (3 * (  theDirection)/2) + rn.nextGaussian() ;

// System.out.println(functionF);
// System.out.println(number);
  if(functionF/15 > number ){   // change .8 to being greater than or less than a random double
    System.out.println("Reward");
    return 0 ; //return the reward
  }
  else if(functionF/15 < number){
      System.out.println("Punish");
    return 1;
  }
return 99;
}



public static void tsetlin(int n, int i, int theOutcome){
  //favorable
if(theOutcome == 0){
  if( (2<=i && i<=n) || (n+2 <= i &&  i<= 2*n)){
    i = n-1;
  }
  else{  //??
  }
}
//unfavorable
else{
  if((1<=i && i<=n-1) || (n+1<=i && i<= 2*n - 1)){
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
}

/* Pseudo
1< = i < = n ...... alpha =1 (left side).....
N+1 <= i <= 2*n.....alpha = 2 (right side)
}
*/










//probability i get a penalty


public static void main(String []args){
System.out.println(outcome(direction) );

}


// returns a -1 or 1 for tsetlin based on whether it passes probability for
}
