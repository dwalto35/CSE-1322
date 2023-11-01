using System;

class MainClass
{
    public static void Main(string[] args)
    {
        char[,] myArray = new char[4, 13];
        myArray = make_forward();
        for (int i = 0; i < 4; i++)
        {
            Console.WriteLine();
            for (int j = 0; j < 13; j++)
            {
                Console.Write(myArray[i, j]);
            }
        }
        char[,] mirror = new char[4, 13];
        mirror = make_mirror(myArray);
        for (int i = 0; i < 4; i++)
        {
            Console.WriteLine();
            for (int j = 0; j < 13; j++)
            {
                Console.Write(mirror[i, j]);
            }
        }
        for (int i = 0; i < 4; i++)
        {
            Console.WriteLine();
            for (int j = 0; j < 26; j++)
            {
                if (j < 13)
                {
                    Console.Write(myArray[i, j]);
                }
                else
                {
                    Console.Write(mirror[i, j % 13]);
                }
            }
        }
    }
    public static char[,] make_mirror(char[,] myArray)
    {
        char[,] art = new char[4, 13];
        /*for(int i = 0; i < 4; i++){
          for(int j = 0; j < 13; j++){
            art[i,j] = myArray[i,j];
          }
        }*/
        int k = 0;
        for (int i = 0; i < 4; i++)
        {
            k = 12;
            for (int j = 0; j < 13; j++)
            {
                art[i, j] = myArray[i, k];
                k--;
                //art[0,0] = myArray[0,13];
                //art[0,1] = myArray[0,12];
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                if (art[i, j] == '\\')
                {
                    art[i, j] = '/';
                    continue;
                }
                if (art[i, j] == '/')
                {
                    art[i, j] = '\\';
                    continue;
                }
                if (art[i, j] == '(')
                {
                    art[i, j] = ')';
                    continue;
                }
                if (art[i, j] == ')')
                {
                    art[i, j] = '(';
                    continue;
                }

            }
        }
        return art;
    }

    public static char[,] make_forward()
    {
        char[,] pixel = new char[4, 13];
        pixel[0, 0] = ' ';
        pixel[0, 1] = ' ';
        pixel[0, 2] = '_';
        pixel[0, 3] = '_';
        pixel[0, 4] = '_';
        pixel[0, 5] = '_';
        pixel[0, 6] = '_';
        pixel[0, 7] = '_';
        pixel[0, 8] = ' ';
        pixel[0, 9] = ' ';
        pixel[0, 10] = ' ';
        pixel[0, 11] = ' ';
        pixel[0, 12] = ' ';
        pixel[1, 0] = ' ';
        pixel[1, 1] = '/';
        pixel[1, 2] = '|';
        pixel[1, 3] = '_';
        pixel[1, 4] = '|';
        pixel[1, 5] = '|';
        pixel[1, 6] = '_';
        pixel[1, 7] = '\\';
        pixel[1, 8] = '\'';
        pixel[1, 9] = '.';
        pixel[1, 10] = '_';
        pixel[1, 11] = '_';
        pixel[1, 12] = ' ';
        pixel[2, 0] = '(';
        pixel[2, 1] = ' ';
        pixel[2, 2] = ' ';
        pixel[2, 3] = ' ';
        pixel[2, 4] = '_';
        pixel[2, 5] = ' ';
        pixel[2, 6] = ' ';
        pixel[2, 7] = ' ';
        pixel[2, 8] = ' ';
        pixel[2, 9] = '_';
        pixel[2, 10] = ' ';
        pixel[2, 11] = '_';
        pixel[2, 12] = '\\';
        pixel[3, 0] = '=';
        pixel[3, 1] = '\'';
        pixel[3, 2] = '-';
        pixel[3, 3] = '(';
        pixel[3, 4] = '_';
        pixel[3, 5] = ')';
        pixel[3, 6] = '-';
        pixel[3, 7] = '-';
        pixel[3, 8] = '(';
        pixel[3, 9] = '_';
        pixel[3, 10] = ')';
        pixel[3, 11] = '-';
        pixel[3, 12] = '\'';
        return pixel;
    }
}
