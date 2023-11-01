using System;

using System.Collections;


class Question
{
    private string ques;
    private string ans;
    private int diff;

    public Question(string question, string answer, int difficulty)
    {
        ques = question;
        ans = answer;
        diff = difficulty;
    }
    public void setQuestion(string question)
    {
        ques = question;
    }
    public void setAnswer(string answer)
    {
        ans = answer;
    }
    public void setDifficulty(int difficulty)
    {
        diff = difficulty;
    }
    public string getQuestion()
    {
        return ques;
    }
    public string getAnswer()
    {
        return ans;
    }
    public int getDifficulty()
    {
        return diff;
    }
}
class Quiz
{
    ArrayList questions = new ArrayList();

    public void add_question()
    {
        Console.WriteLine("What is the question Text?");
        string quesText = Console.ReadLine();
        Console.WriteLine("What is the answer?");
        string quesAnsw = Console.ReadLine();
        Console.WriteLine("How Difficult (1-3)?");
        int answDiffi = Convert.ToInt32(Console.ReadLine());

        Question q = new Question(quesText, quesAnsw, answDiffi);
        questions.Add(q);
    }
    public void remove_question()
    {
        Console.WriteLine("Choose a question to remove");
        for (int i = 0; i < questions.Count; i++)
        {
            Console.WriteLine("{0}.{1}", i, (questions[i] as Question).getQuestion());
        }
        int index = Convert.ToInt32(Console.ReadLine());
        questions.RemoveAt(index);
    }
    public void modify_question()
    {
        Console.WriteLine("Choose the question to modify?");
        for (int i = 0; i < questions.Count; i++)
        {
            Console.WriteLine("{0}.{1}", i, (questions[i] as Question).getQuestion());
        }
        int index = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("What is the question text?");
        string quesText = Console.ReadLine();
        Console.WriteLine("What is the answer?");
        string quesAnsw = Console.ReadLine();
        Console.WriteLine("How Difficult (1-3)?");
        int answDiffi = Convert.ToInt32(Console.ReadLine());

        (questions[index] as Question).setQuestion(quesText);
        (questions[index] as Question).setAnswer(quesAnsw);
        (questions[index] as Question).setDifficulty(answDiffi);
    }
    public void give_quiz()
    {
        int correct = 0;
        string ans;

        foreach (Question text in questions)
        {
            Console.WriteLine(text.getQuestion());
            ans = Console.ReadLine();
            if (ans == text.getAnswer())
            {
                Console.WriteLine("Correct");
                correct = correct + 1;
            }
            else
            {
                Console.WriteLine("Incorrect");
            }
        }
        Console.WriteLine("You got {0} out of {1}", correct, questions.Count);
    }
}
class MainClass
{
    public static void Main(string[] args)
    {
        Quiz quiz = new Quiz();
        int choice = 5;

        while (true)
        {
            Console.WriteLine("1. Add a question to the quiz");
            Console.WriteLine("2. Remove a question from the quiz");
            Console.WriteLine("3. Modify a question");
            Console.WriteLine("4. Take quiz");
            Console.WriteLine("5. Quit");
            choice = Convert.ToInt32(Console.ReadLine());
            switch (choice)
            {
                case 1:
                    quiz.add_question();
                    break;
                case 2:
                    quiz.remove_question();
                    break;
                case 3:
                    quiz.modify_question();
                    break;
                case 4:
                    quiz.give_quiz();
                    break;
                case 5:
                    System.Environment.Exit(0);
                    break;
            }
        }
    }
}
