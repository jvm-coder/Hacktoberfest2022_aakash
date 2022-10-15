#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

void readFile(char sudokuBoard[][9]);
void writeFile(char sudokuBoard[][9]);
void display(char sudokuBoard[][9]);
void interact();
void getOption(char sudokuBoard[][9]);
void editSquare(char sudokuBoard[][9]);
void showValues();

/**********************************************************************
* Main: Basically a delegator. Just makes other functions do its'
*       dirty work for it.
***********************************************************************/
int main()
{
   //Declare array
   char sudokuBoard[9][9];

   //Calling other functions/pass array
   readFile(sudokuBoard);
   interact();
   display(sudokuBoard);

   return 0;
}


/**********************************************************************
* readFile: Asks the user for a filename, reads a gameboard in from
*           that file name, and then places it in an array.
***********************************************************************/
void readFile(char sudokuBoard[][9])
{
   //Declare filename
   char sourceFile[256];

   //Declare file input
   ifstream fin;

   //Get filename from user
   cout << "Where is your board located? ";
   cin  >> sourceFile;

   //Open file with error checking
   fin.open(sourceFile);
   if (fin.fail())
   {
      cout << "Input file opening failed.\n";
      exit(1);
   }

   //Read file into array
   for (int col = 0; col < 9; col++)
   {
      for (int row = 0; row < 9; row++)
      {
         fin >> sudokuBoard[row][col];
         if (sudokuBoard[row][col] == '0')
         {
            sudokuBoard[row][col] = ' ';
         }
      }
   }

   //Close the file
   fin.close();
}

/***********************************************************************
* Displays the results to the screen.
***********************************************************************/
void display(char sudokuBoard[][9])
{
   //Declare variables
   char option;

   //Display Column Header
   cout << "   A B C D E F G H I" << endl

   //Row 1
        << "1  "
        << sudokuBoard[0][0]
        << " " << sudokuBoard[1][0]
        << " " << sudokuBoard[2][0]
        << "|"
        << sudokuBoard[3][0]
        << " " << sudokuBoard[4][0]
        << " " << sudokuBoard[5][0]
        << "|"
        << sudokuBoard[6][0]
        << " " << sudokuBoard[7][0]
        << " " << sudokuBoard[8][0]
        << endl

   //Row 2
        << "2  "
        << sudokuBoard[0][1]
        << " " << sudokuBoard[1][1]
        << " " << sudokuBoard[2][1]
        << "|"
        << sudokuBoard[3][1]
        << " " << sudokuBoard[4][1]
        << " " << sudokuBoard[5][1]
        << "|"
        << sudokuBoard[6][1]
        << " " << sudokuBoard[7][1]
        << " " << sudokuBoard[8][1]
        << endl

   //Row 3
        << "3  "
        << sudokuBoard[0][2]
        << " " << sudokuBoard[1][2]
        << " " << sudokuBoard[2][2]
        << "|"
        << sudokuBoard[3][2]
        << " " << sudokuBoard[4][2]
        << " " << sudokuBoard[5][2]
        << "|"
        << sudokuBoard[6][2]
        << " " << sudokuBoard[7][2]
        << " " << sudokuBoard[8][2]
        << endl

   //Visual Separator
        << "   -----+-----+-----" << endl

   //Row 4
        << "4  "
        << sudokuBoard[0][3]
        << " " << sudokuBoard[1][3]
        << " " << sudokuBoard[2][3]
        << "|"
        << sudokuBoard[3][3]
        << " " << sudokuBoard[4][3]
        << " " << sudokuBoard[5][3]
        << "|"
        << sudokuBoard[6][3]
        << " " << sudokuBoard[7][3]
        << " " << sudokuBoard[8][3]
        << endl

   //Row 5
        << "5  "
        << sudokuBoard[0][4]
        << " " << sudokuBoard[1][4]
        << " " << sudokuBoard[2][4]
        << "|"
        << sudokuBoard[3][4]
        << " " << sudokuBoard[4][4]
        << " " << sudokuBoard[5][4]
        << "|"
        << sudokuBoard[6][4]
        << " " << sudokuBoard[7][4]
        << " " << sudokuBoard[8][4]
        << endl

   //Row 6
        << "6  "
        << sudokuBoard[0][5]
        << " " << sudokuBoard[1][5]
        << " " << sudokuBoard[2][5]
        << "|"
        << sudokuBoard[3][5]
        << " " << sudokuBoard[4][5]
        << " " << sudokuBoard[5][5]
        << "|"
        << sudokuBoard[6][5]
        << " " << sudokuBoard[7][5]
        << " " << sudokuBoard[8][5]
        << endl

   //Visual Separator
        << "   -----+-----+-----" << endl

   //Row 7
        << "7  "
        << sudokuBoard[0][6]
        << " " << sudokuBoard[1][6]
        << " " << sudokuBoard[2][6]
        << "|"
        << sudokuBoard[3][6]
        << " " << sudokuBoard[4][6]
        << " " << sudokuBoard[5][6]
        << "|"
        << sudokuBoard[6][6]
        << " " << sudokuBoard[7][6]
        << " " << sudokuBoard[8][6]
        << endl

   //Row 8
        << "8  "
        << sudokuBoard[0][7]
        << " " << sudokuBoard[1][7]
        << " " << sudokuBoard[2][7]
        << "|"
        << sudokuBoard[3][7]
        << " " << sudokuBoard[4][7]
        << " " << sudokuBoard[5][7]
        << "|"
        << sudokuBoard[6][7]
        << " " << sudokuBoard[7][7]
        << " " << sudokuBoard[8][7]
        << endl

   //Row 9
        << "9  "
        << sudokuBoard[0][8]
        << " " << sudokuBoard[1][8]
        << " " << sudokuBoard[2][8]
        << "|"
        << sudokuBoard[3][8]
        << " " << sudokuBoard[4][8]
        << " " << sudokuBoard[5][8]
        << "|"
        << sudokuBoard[6][8]
        << " " << sudokuBoard[7][8]
        << " " << sudokuBoard[8][8]
        << "\n"
        << "\n";

   getOption(sudokuBoard);
}


/*************************************************************************
* Interact: Allows the user to interact and manipulate the game board.
*
************************************************************************/
void interact()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n"
        << "\n";

   return;
}


/*************************************************************************
* getOption: Gets the user's input.
*
************************************************************************/
void getOption(char sudokuBoard[][9])
{
   char option;
   cout << "> ";
   cin >> option;

   if (option == 'e' || option == 'E')
      editSquare(sudokuBoard);
   else if (option == '?')
      interact();
   else if (option == 'd' || option == 'D')
      display(sudokuBoard);
   else if (option == 's' || option == 'S')
      showValues();
   else if (option == 'q' || option == 'Q')
      writeFile(sudokuBoard);
   else
      cout << "ERROR: Invalid command";

   return;
}


/***********************************************************************
* editSquare: Edits one square of the table based on the coordinates
*             entered by the user.
************************************************************************/
void editSquare(char sudokuBoard[][9])
{
   //Declare variables
   char letter;
   int number;
   int value = 0;

   //Gets letter/number coordinates
   cout << "What are the coordinates of the square: ";
   cin  >> letter >> number;

   //Converts letter to uppercase
   letter = toupper(letter);

   //If square is full, display "read only" message
   if (sudokuBoard[letter - 65][number - 1] != ' ')
   {
      cout << "ERROR: Square \'" << letter << number << "\' is read-only\n";
      cout << "\n";
      getOption(sudokuBoard);
   }
   else
   {
      //Gets value to place in specified coordinates
      cout << "What is the value at \'" << letter << number << "\': ";
      cin  >> value;

      //Makes sure value is within correct range
      if (value < 1 || value > 9)
      {
         cout << "ERROR: Value \'" << value << "\' in square \'" << letter << number << "\' is invalid\n";
         cout << "\n";
         getOption(sudokuBoard);
      }

      cout << "\n";
      sudokuBoard[letter - 65][number - 1] = value;
      getOption(sudokuBoard);
   }

   return;
}
