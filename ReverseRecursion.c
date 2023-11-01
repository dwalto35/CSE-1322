using System;

class Recursion {
  public static string repeatNTimes(string str, int num){
    if(num <= 0){
      return "";
    }
    if(num == 1){
      return str;
    }
    return str + repeatNTimes(str, num-1);
  }
  public static bool isReverse(string str1, string str2){
    if(str1.Length != str2.Length){
      return false;
    }
    if(str1.Length == 0){
      return true;
    }
    if(str1[0]==str2[str1.Length-1]){
      return isReverse(str1.Substring(1),str2.Substring(0,str1.Length-1));
    }
    else{
      return false;
    }
  }
  public static void Main (string[] args) {
    Console.WriteLine(Recursion.repeatNTimes("I must study recursion until it makes sense\n",100));
    string str1;
    string str2;
    Console.WriteLine("Enter first string: ");
    str1 = Console.ReadLine();
    Console.WriteLine("Enter second string: ");
    str2 = Console.ReadLine();
    if(Recursion.isReverse(str1, str2)==true){
      Console.WriteLine(str1 + " is the reverse of " + str2);
    }
    else{
      Console.WriteLine(str1 + " is not the reverse of " + str2);
    }
  }
}
