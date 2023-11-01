using System;
using System.Threading;

class MainClass {
  public static void Main (string[] args) {
    Thread[] threads = new Thread[100];
    for(int i=0;i<100;i++) {
      threads[i]=new Thread(new ThreadStart(new Guesser().run));
      threads[i].Start();
    }
  }
}
class Guesser{
  public int threadID;
  public static int nextThreadID = 1;

  public Guesser(){
    threadID = nextThreadID;
    nextThreadID++;
  }
  public void run(){
    Random r1 = new Random();
    int numOfGuesses = 1;
    int currentGuess;
    do{
      currentGuess = r1.Next(1000000);
      numOfGuesses++;
    }while(currentGuess != 123456);
    Console.WriteLine("I'm thread " + threadID + " I just found it on guess " + numOfGuesses);
  }
}
