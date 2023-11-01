using System;

class MainClass{
  public static int myMethod(string theString){
    
  
   //splitting the string into 3 parts
   string[] arrOfStr1 = theString.Split(":",3);
   //string[] arrOfStr2 = input2.Split(":",3);

   if(arrOfStr1.Length != 3){
      throw new InvalidTimeException("The number of place values should be like this (HH:MM:SS)");
    }

   //Converting string to int of first value
   int h1 = Int32.Parse(arrOfStr1[0]);
   int m1 = Int32.Parse(arrOfStr1[1]);
   int s1 = Int32.Parse(arrOfStr1[2]);

   //Converting string to int of second value
   //int h2 = Int32.Parse(arrOfStr1[0]);
   //int m2 = Int32.Parse(arrOfStr1[1]);
   //int s2 = Int32.Parse(arrOfStr1[2]);


   if(h1 < 0 || h1 > 23){
     throw new InvalidTimeException("Hour must be below 24");
   }
   if(m1 < 0 || m1 > 60){
     throw new InvalidTimeException("Minutes nmust be less than 60");
   }
   if(s1 < 0 || s1 > 60){
     throw new InvalidTimeException("Seconds must be less than 60");
   }

   int secDiff = (h1*60*60) + (m1*60) + s1;
   return secDiff;
  }
  public static void Main (string[] args){
    try{
   //Prompting the user for 2 times
   Console.WriteLine("Enter time 1 in 24hr format as follows (HH:MM:SS)");
   string input1 = Console.ReadLine();
   Console.WriteLine("Enter time 2 in 24hr format as follows (HH:MM:SS)");
   string input2 = Console.ReadLine();
   //myMethod(input1);
   //myMethod(input2);

   int Result1 = myMethod(input1);
   int Result2 = myMethod(input2);

   int diff = Result1 - Result2;
   diff = Math.Abs(diff);

   Console.WriteLine("Difference in seconds: " + diff);
  }
   catch(InvalidTimeException e){
    Console.WriteLine(e.Message);
    }
   catch(FormatException f){
    Console.WriteLine("Enter a valid time");
   }
  }
}
class InvalidTimeException: Exception{
  public InvalidTimeException(string Message):base(Message){

  }
}
