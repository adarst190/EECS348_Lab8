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
    
    
    
    return 0;
}
