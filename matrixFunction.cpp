#include "matrixHead.h"
#include <fstream>
#include <iostream>
using namespace std;

MatrixType::MatrixType() {
	/*Pre: The variables of the matrix type class are to be initalized to 0*/
	numRows = 0;
	numCols = 0;
	for (int i = 0; i < numRows; ++i) {
		for (int k = 0; k < numCols; ++k) {
			values[i][k] = 0;
		}
	}
	/*Post: The numRows, numCols and the values array have all been initalized to 0*/
}
void MatrixType::MakeEmpty()
/*Pre: no pre conditions*/
{
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			values[i][j] = 0;
		}

	}
	/*Post the list is initalized back to 0*/
}
void MatrixType::SetSize(int rowsize, int colsize) {
	/*Pre needs user input for row and column size as parameters passed throught main*/
	numRows = rowsize;
	numCols = colsize;
	/*Post the size of the numRows and numCols variables have been set by the values the user passes in*/

}

void MatrixType::StoreItem(int item, int row, int col)
{
	/*Pre: An item, and a specific row and col number need to be passed in by the user*/
	values[row][col] = item;
	/*Post we assign the values to that location in the values array*/
}

void MatrixType::Add(MatrixType otherOperand, MatrixType& result)
{
	/*Pre: the Number of rows and columns have to match for this function to work if it made it in here we checked that this case is true, the
	object result is also passed through the main function*/
	for (int i = 0; i < numRows; ++i) {
		for (int k = 0; k < numCols; ++k) {
			result.values[i][k] = 0;
		}
	}

	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numCols; ++j) {


			result.values[i][j] = values[i][j] + otherOperand.values[i][j];





		}
	}
	cout << endl;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			cout << result.values[i][j] << " ";
		}
		cout << endl;
	}


	/*Post: we added two matrices together and printed the resulting matrice to the screen*/

}

void MatrixType::Sub(MatrixType otherOperand, MatrixType& result)
{
	/*Pre: the Number of rows and columns have to match for this function to work if it made it in here we checked that this case is true, the
	object result is also passed through the main function*/

	for (int i = 0; i < numRows; ++i) {
		for (int k = 0; k < numCols; ++k) {
			result.values[i][k] = 0;
		}
	}

	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numCols; ++j) {


			result.values[i][j] = values[i][j] - otherOperand.values[i][j];





		}
	}
	cout << endl;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			cout << result.values[i][j] << " ";
		}
		cout << endl;
	}
	/*Post: the matrices have been subtracted and the resulting matrix was printed to the screen*/

}

void MatrixType::Mult(MatrixType otherOperand, MatrixType& result)
{
	/*Pre: The number of rows in the first matrix must equal the number of columns in the second matrix this condition is checked by a function before
	it was allowed into the mult function*/
	for (int i = 0; i < numRows; ++i) {
		for (int k = 0; k < numCols; ++k) {
			result.values[i][k] = 0;
		}
	}


	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numCols; ++j) {
			for (int k = 0; k < numCols; ++k) {

				result.values[i][j] += values[i][k] * otherOperand.values[k][j];



			}

		}
	}
	cout << endl;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			cout << result.values[i][j] << " ";
		}
		cout << endl;
	}
	/*Post: the product of the two matrices have been made and printed to the screen*/
}

void MatrixType::Print(ofstream& outfile)

{/*Pre: we must pass in the outfile object as well as open the file to be written to*/
	outfile.open("test.txt");
	for (int i = 0; i < numRows; ++i) {

		for (int j = 0; j < numCols; ++j) {
			outfile << values[i][j] << endl;
		}
	}
	outfile.close();
	/*Post we have sent the values to the file and closed the file*/
}

void MatrixType::Printsize()
{
	/*Test function to print size of arrays for each object*/
	cout << "Row size " << numRows << " Column size " << numCols << endl;

}

void MatrixType::testPrint(int row, int col)
{
	/*Another test function that displays the values of an array*/
	int sizeRow = row;
	int sizeColumn = col;

	for (int i = 0; i < sizeRow; ++i) {
		for (int j = 0; j < sizeColumn; ++j) {
			cout << values[i][j] << " ";


		}

	}


	cout << endl;


}

bool MatrixType::AddSubCompatible(MatrixType otherOperand)
{
	/*Pre: must pass in a member of the matrixtype class we are testing to see if the number of columns from the object is equal to the columns stored in the first object
	vise versa for the rows*/
	if (numCols != otherOperand.numCols) {
		cout << "The number of columns do not match in the two matrices please restart and try again" << endl;
		exit(0);

	}
	if (numRows != otherOperand.numRows) {
		cout << "The number of rows do not match in the two matrices please restart and try again" << endl;
		exit(0);

	}

	/*Post: we have tested and it either will pass or the program will repeat and as for new inputs*/

	return true;
}

bool MatrixType::MultCompatible(MatrixType otherOperand)
{
	/*Pre: We need an object passed in from main we need the numCols passed in from the object to equal the number of rows in the first object*/
	if (numRows != otherOperand.numCols) {
		cout << "To multiply matrices the number of rows and columns must be the same please restart and try again" << endl;
		exit(0);
	}
	return false;
	/*Post:Either the program continues or it asked for new in*/
}
