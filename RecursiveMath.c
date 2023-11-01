using System;

class MainClass {
  public static int recursive_multiply(int firstNum, int secNum){
    if(firstNum < secNum){
      return recursive_multiply(secNum, firstNum);
    }
    else if(secNum != 0){
      return (firstNum + recursive_multiply(firstNum, secNum-1));
    }
    else{
      return 0;
    }
  }
  public static int recursive_div(int firstNum, int secNum){
    if(secNum == 0){
      return -1;
    }
    else if(firstNum < secNum){
      return 0;
    }
    else{
      return 1 + recursive_div(firstNum - secNum, secNum);
    }
  }
  public static int recursive_mod(int firstNum, int secNum){
    if(secNum == 0){
      return -1;
    }
    if(firstNum < secNum){
      return firstNum;
    }
    else{
      return recursive_mod(firstNum - secNum, secNum);
    }
  }
  public static void Main (string[] args) {
    int choice = 0;
    int firstNum;
    int secNum;

    do{
      Console.WriteLine("Choose from the following:");
      Console.WriteLine("0. Quit");
      Console.WriteLine("1. Multiply 2 numbers");
      Console.WriteLine("2. Div 2 numbers");
      Console.WriteLine("3. Mod 2 numbers");
      choice = Convert.ToInt32(Console.ReadLine());

      switch(choice){
        case 0: 
          break;
        case 1:
          Console.WriteLine("Enter first number");
          firstNum = Convert.ToInt32(Console.ReadLine());
          Console.WriteLine("Enter second number");
          secNum = Convert.ToInt32(Console.ReadLine());
          Console.WriteLine("Answer: " + recursive_multiply(firstNum,secNum));
          break;
        case 2:
          Console.WriteLine("Enter first number");
          firstNum = Convert.ToInt32(Console.ReadLine());
          Console.WriteLine("Enter second number");
          secNum = Convert.ToInt32(Console.ReadLine());
          Console.WriteLine("Answer: " + recursive_div(firstNum,secNum));
          break;
        case 3: 
          Console.WriteLine("Enter first number");
          firstNum = Convert.ToInt32(Console.ReadLine());
          Console.WriteLine("Enter second number");
          secNum = Convert.ToInt32(Console.ReadLine());
          Console.WriteLine("Answer: " + recursive_mod(firstNum,secNum));
          break;
      }
    }while(choice != 0);
  }
}
