using System;

class BlueRayDisc{
  public string title = "";
  public string director = "";
  public int yearOfRelease = 0;
  public double cost = 0;

  public BlueRayDisc(string t, string d, int yor, double c){
    title = t;
    director = d;
    yearOfRelease = yor;
    cost = c;
  }
  public override string ToString(){
    return "$" + cost + " " + yearOfRelease + " " + title + ", " + director;
  }
}
class Node{
  public BlueRayDisc disc;
  public Node next;
  public Node(){
    next = null;
  }
  public Node(BlueRayDisc disc){
    this.disc = disc;
  }
}
class BlueRayCollection{
  private Node head = null;

  public void Add(string title, string director, int yearOfRelease, double cost){
    BlueRayDisc brd = new BlueRayDisc(title, director, yearOfRelease, cost);
    Node newNode = new Node(brd);
    if(head == null) {
      head = newNode;
    } 
    else{
      Node temp = head;
      while(temp.next != null)
      temp = temp.next;

      temp.next = newNode;
    }    
  }
  public void show_all(){
    Node current = head;

    while(current != null){
      Console.WriteLine(current.disc);
      current = current.next;
    }
  }
}
class MainClass {
  public static void Main (string[] args) {
    BlueRayCollection brc = new BlueRayCollection();
    int user_input;
    do{
      Console.WriteLine("0. Quit");
      Console.WriteLine("1. Add BlueRay to collection");
      Console.WriteLine("2. See collection");
      user_input = Convert.ToInt32(Console.ReadLine());

      if(user_input == 1){
      Console.WriteLine("What is the title?");
      string title = Console.ReadLine();
      Console.WriteLine("What is the director?");
      string director = Console.ReadLine();
      Console.WriteLine("What is the year of the release");
      int yearOfRelease = Convert.ToInt32(Console.ReadLine());
      Console.WriteLine("What is the cost");
      double cost = Convert.ToDouble(Console.ReadLine());
      Console.WriteLine();
      brc.Add(title, director, yearOfRelease, cost);
      }
      if(user_input == 2){
        brc.show_all();
        Console.WriteLine();
        
      }
    }while(user_input != 0);
  }
}
