/*
 * Class: CMSC140 CRN 10016
 * Instructor: Margaret Tseng
 * Project 5
 * Description: Program asks user for values for a 3 cells by 3 cells square, the values are stored in 3 arrays with a size of 3 cells each that act as rows of the table. The program calls functions that verify if the values in the square happen to be a Lo Shu magic square, the functions check to see if they values entered
 * satisfies the condition for a Lo Shu magic square and shows the user the values they entered in a 3x3 grid and whether the values entered  in the square make it a magic square. 
 * Due Date: 8/9/24
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Taylor Horton
*/
#include<iostream>
#include<vector>

using namespace std;

// Global constants 

const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

// Function prototypes, the three int [] arrays correspond each to magicArrowRow
bool isMagicSquare(int [], int [], int [], int size);
bool checkRange(int [], int [], int [], int size, int min, int max);
bool checkUnique(int [], int [], int [], int size);
bool checkRowSum(int [], int [], int [], int size);
bool checkColSum(int [], int [], int [], int size);
bool checkDiagSum(int [], int [], int [], int size);
void fillArray(int [], int [], int [], int size);
void showArray(int [], int [], int [], int size);


int main()
{
	
	/*  Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid */

	int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
    char choice;

    do{                                                                                                     // do while to let user keep playing if they want (Y or y)

        fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);                                   
        showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

        if(isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS) == true){                        // function called in condition, the function calls all the other functions 

            cout<<"This is a Lo Shu magic square.\n";
        }
        else{
            cout<<"This is not a Lo Shu magic square.\n";
        }

        cout<<"Do you want to play again? Enter (Y or y) to play again, enter any other key to exit ";
        cin>>choice;

    }while(choice == 'Y' || choice == 'y');

	return 0;
}
void fillArray(int magicArrayRow1[], int magicArrayRow2[], int magicArrayRow3[], int size){                         // 3 for loops, each iterates through one of the three int arrays passed through, user inputs values that go into each cell of the array size of 3

    int userInput = 0;

    for(int i =0; i<size; i++)
    {
        cout<<"Enter the number for row 0 and column "<<i<<" : ";
        cin>>userInput;
        magicArrayRow1[i] = userInput;
    }
    for(int i =0; i<size; i++)
    {
        cout<<"Enter the number for row 1 and column "<<i<<" : ";
        cin>>userInput;
        magicArrayRow2[i] = userInput;
    }
    for(int i =0; i<size; i++)
    {
        cout<<"Enter the number for row 2 and column "<<i<<" : ";
        cin>>userInput;
        magicArrayRow3[i] = userInput;
    }
}
void showArray(int magicArrayRow1[], int magicArrayRow2[], int magicArrayRow3[], int size){                     // 3 for loops, each iterates through one of the arrays (rows), and displays its value, newline after each row

    for(int i =0; i<size; i++){

        cout<<magicArrayRow1[i]<<" ";

    }
    cout<<"\n";
    for(int i =0; i<size; i++){

        cout<<magicArrayRow2[i]<<" ";

    }
    cout<<"\n";
    for(int i =0; i<size; i++){

        cout<<magicArrayRow3[i]<<" ";

    }
    cout<<"\n";
}
bool isMagicSquare(int magicArrayRow1[], int magicArrayRow2[], int magicArrayRow3[], int size){                 // this bool function calls all the othe bool functions, checks if they are all true

    bool check1 = checkRange(magicArrayRow1, magicArrayRow2, magicArrayRow3, size, MIN, MAX);
    bool check2 = checkUnique(magicArrayRow1, magicArrayRow2, magicArrayRow3, size);
    bool check3 = checkRowSum(magicArrayRow1, magicArrayRow2, magicArrayRow3, size);
    bool check4 = checkColSum(magicArrayRow1, magicArrayRow2, magicArrayRow3, size);
    bool check5 = checkDiagSum(magicArrayRow1, magicArrayRow2, magicArrayRow3, size);

    if(check1 == true && check2 == true && check3 == true && check4 == true && check5 == true)
        return true;
    else
        return false;


}
bool checkDiagSum(int magicArrayRow1[], int magicArrayRow2[], int magicArrayRow3[], int size){              // two variables defined, each set equal to the cells that form a diagonal line , opposite directions

    int topLBotR = 0;
    int botLtopR = 0;
    
    topLBotR = magicArrayRow1[0] + magicArrayRow2[1] + magicArrayRow3[2];

    botLtopR = magicArrayRow3[0] + magicArrayRow2[1] + magicArrayRow1[2];

    if(topLBotR == botLtopR)
        return true;
    else
        return false;

}
bool checkRowSum(int magicArrayRow1[], int magicArrayRow2[], int magicArrayRow3[], int size){               // for loop iterates through size of the array, each row is accessed at index value of the for loop and summed up, if all the row sums are equal returns true otherwise false

    int row1 = 0;
    int row2 = 0;
    int row3 = 0;

    for(int i =0; i<size; i++){
        
        row1 += magicArrayRow1[i];
        row2 += magicArrayRow2[i];
        row3 += magicArrayRow3[i];
    }
    if(row1 == row2 && row1 == row3)
        return true;
    else
        return false;

}
bool checkColSum(int magicArrayRow1[], int magicArrayRow2[], int magicArrayRow3[], int size){               // adds different rows but at the same column value to three different column variables, checks if all are equal to each other


    int col1 = 0;
    int col2 = 0;
    int col3 = 0;

    col1 = magicArrayRow1[0] + magicArrayRow2[0] + magicArrayRow3[0];

    col2 = magicArrayRow1[1] + magicArrayRow2[1] + magicArrayRow3[1];

    col3 = magicArrayRow1[2] + magicArrayRow2[2] + magicArrayRow3[2];

    if(col1 == col2 && col1 == col3)
        return true;
    else    
        return false;

}
bool checkRange(int magicArrayRow1[], int magicArrayRow2[], int magicArrayRow3[], int size, int min, int max){              /// iterates through every row at index i from the loop, if its below or above the max it returns false


    for(int i=0; i<size; i++){

        if(magicArrayRow1[i] > max || magicArrayRow1[i] < min || magicArrayRow2[i] > max || magicArrayRow2[i] < min || magicArrayRow3[i] > max || magicArrayRow3[i] < min)
            return false;
    }
    return true;
}
bool checkUnique(int magicArrayRow1[], int magicArrayRow2[], int magicArrayRow3[], int size){                       // creates a vector with the size of the three arrays, star the values of the three arrays into the vector. Iterates through the vector to see if any duplicates. 

    vector<int>tempArray(9);

    for(int i=0; i<size; i++){

        tempArray[i] = magicArrayRow1[i];

    }
    for(int i=0; i<size; i++){
        
        tempArray[i+3] = magicArrayRow2[i];
    }
    for(int i=0; i<size; i++){
        
        tempArray[i+6] = magicArrayRow3[i];

    }
    for(int i =0; i < 9; i++){

        for(int x = i +1 ; x < 9; x++)

            if(tempArray[i] == tempArray[x]){
                return false;
            }
    }
    return true;
}