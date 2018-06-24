import java.util.*;

public class lri{
//static int location = 0;
static double totalOfSpots = 0;




  public static double strengthPopulator(int spot){  // returns +1/-1
   Random rn = new Random();
   double functionF =  ((3 * (spot)/2) + rn.nextGaussian()) ; // multiply by sigma to achieve result (multiply by 1)...my standard deviation (1.0)
  //  System.out.println("The spot is: " + spot + " The strength is: "  + functionF);
  return functionF;
  }

public static int getLocation(double location, double[] theArray){
  int desiredLocation =0;

  for(int k = 0; k<15;k++){
    double sum = 0;
    for(int j = 0; j<=k;j++){
      sum = sum + theArray[j];  //generates sum value for each spot in the array
    }
  //System.out.println("This is the sum : " + sum);
  if(sum >= location){
     desiredLocation = k;
  //   System.out.println("The location in the array is : " + desiredLocation);
    break;
  }
  }
  return desiredLocation;

}
public static double[] lriRec(int x, double[] theLocations){

//public static double[] otherWay(double[] theLocations){
  totalOfSpots =0;

Random generator = new Random();

double number = generator.nextDouble();
//System.out.println("This is the random number made: " + number);

int rightSpot = getLocation(number,theLocations);

if(strengthPopulator(rightSpot)>=9){
for(int k = 0; k<8;k++){
    // if the strength of the location is high enough
if(k != rightSpot){
theLocations[k] = theLocations[k] * .9;
totalOfSpots = totalOfSpots + theLocations[k];
//System.out.println("The total of the other spots is : " + totalOfSpots);
}
theLocations[rightSpot] = 1 - totalOfSpots;

}
}
// after having changed all of the other spots, reassign value for location


System.out.println("THIS IS THE RESULT");
 for(int k = 0; k<8;k++){
   System.out.println(theLocations[k]);
 }

 if(x==0){
   return theLocations;
 }
 else{
   return lriRec(x-1,theLocations);
   }
}

public static void main(String []args){
  double[] other = {.125,.125,.125,.125,.125,.125,.125,.125};
  lriRec(100,other);
}


}
