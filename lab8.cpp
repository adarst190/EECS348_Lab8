/*
Program will implement several different functions
for matrices. The program will read in a file containing the size N of
the square matrix, and 2 matrices of size NxN.
*/

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the matrix

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size, ifstream& inFile){ 
    for (int i = 0; i < size; i++){         //Loop to read in the matrix from the file
        for (int j = 0; j < size; j++){         //Loop to read in the matrix from the file
            inFile >> matrix[i][j];       //Read in the matrix from the file
        }
    }
    cout << "Matrix read from file:" << endl; //Print the matrix to the console
    for (int i = 0; i < size; i++){         //Loop to print the matrix to the console
        for (int j = 0; j < size; j++){         //Loop to print the atrix to the console
            cout << matrix[i][j] << " ";       //Print the matrix to the console
        }
        cout << endl;         //Print a new line to show each row of the result matrix
    }
}

void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size){ 
    int result[MAX_SIZE][MAX_SIZE];         //Declare the result matrix of size NxN

    for (int i = 0; i < size; i++){         //Loop to add the two matrices
        for (int j = 0; j < size; j++){         //Loop to add the two matrices
            result[i][j] = matrix1[i][j] + matrix2[i][j];       //Add the two matrices
        }
    }
    cout << "Add the two matrices:" << endl; //Print result of additon
    for (int i = 0; i < size; i++){         //Loop to print the result of the addition to the console
        for (int j = 0; j < size; j++){         //Loop to print the result of the addition to the console
            cout << result[i][j] << " ";       //Print the result of the addition to the console
        }
        cout << endl;         //Print a new line to show each row of the result matrix
    }
}

void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int size){ 
    int result[MAX_SIZE][MAX_SIZE];         //Declare the result matrix of size NxN

    for (int i = 0; i < size; i++){         //Loop to multiply the two matrices
        for (int j = 0; j < size; j++){         //Loop to multiply the two matrices
            result[i][j] = 0;       //Initialize the result matrix to 0
            for (int k = 0; k < size; k++){         //Loop to multiply the two matrices along the rows and columns
                result[i][j] += matrix1[i][k] * matrix2[k][j];       //Multiply the two matrices accordingly
            }
            
        }
    }
    cout << "Multiply the two matrices:" << endl; //Print result of multiplication
    for (int i = 0; i < size; i++){         //Loop to print the result of the multiplication 
        for (int j = 0; j < size; j++){         //Loop to print the result of the multiplication 
            cout << result[i][j] << " ";       //Print the result of the multiplication 
        }
        cout << endl;         //Print a new line to show each row of the result matrix
    }
}

void sumDiagonals(int matrix[MAX_SIZE][MAX_SIZE], int size){ 
    int mainDiagSum = 0;         //Variable to hold the sum of the first diagonal
    int secDiagSum = 0;         //Variable to hold the sum of the second diagonal

    for (int i = 0; i < size; i++){         //Loop to sum the diagonals
        mainDiagSum += matrix[i][i];       //Sum the main diagonal
        secDiagSum += matrix[i][size - i - 1];       //Sum the second diagonal
    }
    
    cout << "Sum of the main diagonal: " << mainDiagSum << endl; //Print the sum of the main diagonal
    cout << "Sum of the secondary diagonal: " << secDiagSum << endl; //Print the sum of the secondary diagonal
}

void swapMatrixRows(int matrix[MAX_SIZE][MAX_SIZE], int size){ 
    int row1, row2;         //Variables to hold the two rows to swap
    cout << "Enter the two rows to swap (0 to " << size - 1 << "): "; //Ask user for the two rows wanting to swap
    cin >> row1 >> row2;         //Get the two rows from the user
    
    if (row1 < 0 || row1 >= size || row2 < 0 || row2 >= size){         //Check if the rows are valid
        cout << "Invalid row numbers." << endl;         //Print error message
        return;         //Return from the function
    }
    for (int j = 0; j < size; j++){         //Loop to swap the two rows
        int temp = matrix[row1][j];       //Temporary variable to hold the value of the first row
        matrix[row1][j] = matrix[row2][j];       //Swap the two rows
        matrix[row2][j] = temp;       //Swap the two rows
    }
    cout << "Matrix after swapping rows: " << endl; //Print the matrix after swapping the rows
    for (int i = 0; i < size; i++){         //Loop to print the matrix after swapping the rows
        for (int j = 0; j < size; j++){         //Loop to print the matrix after swapping the rows
            cout << matrix[i][j] << " ";       //Print the matrix after swapping the rows
        }
        cout << endl;         //Print a new line to show each row of the result matrix
    }
}


int main(){
    int size;                //Variable to hold the size of the matrix
    string filename;        //Variable to hold name of the input file
    cout << "Enter the name of input file: " << endl;   //Ask user for name of input file
    cin >> filename;            //Get name of input file from user

    ifstream inFile(filename);      //Open the input file
    if (!inFile) {                  //Check if the file opened successfully 
        cout << "Error opening file." << endl;
        return 1;
    }

    inFile >> size;           //Read the size of the matrix from first line of the file
    
    int matrix1[MAX_SIZE][MAX_SIZE];         //Declare the matrix of size NxN
    int matrix2[MAX_SIZE][MAX_SIZE];        //Declare the second matrix of size NxN

    readMatrix(matrix1, size, inFile);         //Call the function to read in the first matrix
    readMatrix(matrix2, size, inFile);        //Call the function to read in the second matrix
    
    addMatrices(matrix1, matrix2, size);         //Call the function to add the two matrices

    multiplyMatrices(matrix1, matrix2, size);         //Call the function to multiply the two matrices
    
    sumDiagonals(matrix1, size);         //Call the function to sum the diagonals of the first matrix
    
    swapMatrixRows(matrix1, size);         //Call the function to swap the two rows of the first matrix

    return 0;
}
