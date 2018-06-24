import java.util.*;

public class HelloWorld{

     public static void main(String []args){
            Random randomn = new Random();
            Random rn = new Random();
            int GofI = rn.nextInt(8) + 1;


   //System.out.println("Next Gaussian value: " + randomn.nextGaussian());

   double functionF = 0;
   functionF =  (3 * (  GofI)/2) + randomn.nextGaussian() ;

     System.out.println("The functionF yields: " + functionF);

     }
}
