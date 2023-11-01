using System;

//custom exception ColumnFull goes here
class ColumnFull: Exception{
  public ColumnFull(string Message):base(Message){
  
  }
  public ColumnFull(){

  }
}
class ConnectFour{
 char[,] myArray = new char [6,7];
 string turnVar;
 char nextToken;

 public ConnectFour(){
   for(int i = 0; i < 6; i++){
     for(int j = 0; j < 7; j++){
       myArray[i,j] = ' ';
       
     }
   }
   turnVar = "Red";
   nextToken = 'R';
 }
 public void nextTurn(){
   if(turnVar == "Red"){
     turnVar = "Yellow";
     nextToken = 'Y';
   }
   else{
     turnVar = "Red";
     nextToken = 'R';
   }
 }
 public int nextAvaliablePosition(int column){
   for(int i = 5; i >= 0;i--){
     if(myArray[i,column] == ' '){
       return i;
     }
   }
   return -1;
 }
 public void dropPiece(int column, char nextToken){
   int available = nextAvaliablePosition(column);
   if(available >= 0){
     myArray[available, column] = nextToken;
   }
   else{
     throw new ColumnFull();
   }
 }
 public override string ToString() {
    String to_return="  0   1   2   3   4   5   6";

  for(int i=0;i<6;i++) {
    to_return+="\n-----------------------------\n";
          to_return+="| ";
     for(int j=0;j<7;j++) {
       to_return+=myArray[i,j]+" | ";
    }
  }
    to_return+="\n-----------------------------\n";
        return to_return;
  }
 public static void Main (string[] args) {
    ConnectFour Connect4 = new ConnectFour();
    int userInput;
    do{
      Console.WriteLine(Connect4);
      Console.WriteLine("Which column would " + Connect4.turnVar + " like to go in (9 to quit)");
      userInput = Int32.Parse(Console.ReadLine());
      if(userInput >= 0 && userInput <= 7){
        //exception check goes here
        try{
          Connect4.dropPiece(userInput, Connect4.nextToken);
          Connect4.nextTurn();
        }
        catch(ColumnFull e){
          Console.WriteLine("That column is full try again");
        }
      }
      }while(userInput != 9);
    }
  }
