#include "matrixHead.h"
#include <iostream>
#include <fstream>
using namespace std;


int main() {
	ofstream outfile;
	int filechoice = 0;
	const int k = 9;
	MatrixType matrixF[k];
	MatrixType r;
	int printNum = 0;
	int item = 0;
	int sizeRow = 0, sizeColumn = 0;

	int selectedM = 0, selectedN = 0;
	int n = 0;
	int numMatrix = 0;
	cout << "New matrice: 1 " << endl;
	cout << "Add matrices: 2 " << endl;
	cout << "Subtract matrices:3 " << endl;
	cout << "Multiply matrices: 4" << endl;
	cout << "Print matrices: 5 " << endl;
	cout << "Quit 6 " << endl;
	cin >> n;
	int i = 0;


	while (n != 0) {
		switch (n) {
		case 1: n = 1;

			cout << "Enter a row and column size for the matrix" << endl;
			cin >> sizeRow >> sizeColumn;
			matrixF[i].SetSize(sizeRow, sizeColumn);

			cout << "Store the values in the matrix you made" << endl;
			for (int k = 0; k < sizeRow; ++k) {
				for (int j = 0; j < sizeColumn; j++) {
					cout << "Enter element " << k + 1 << "," << j + 1 << " : ";
					cin >> item;
					matrixF[i].StoreItem(item, k, j);
				}
			}
			i++;
			numMatrix++;
			cout << "New matrice: 1 " << endl;
			cout << "Add matrices: 2 " << endl;
			cout << "Subtract matrices:3 " << endl;
			cout << "Multiply matrices: 4" << endl;
			cout << "Print matrices: 5 " << endl;
			cout << "Quit 6 " << endl;
			cin >> n;
			break;
		case 2: n = 2;

			cout << "Which matrices do you want to add?" << endl;
			cin >> selectedM;
			cin >> selectedN;
			matrixF[selectedM].AddSubCompatible(matrixF[selectedN]);
			matrixF[selectedM].Add(matrixF[selectedN], r);
			cout << "New matrice: 1 " << endl;
			cout << "Add matrices: 2 " << endl;
			cout << "Subtract matrices:3 " << endl;
			cout << "Multiply matrices: 4" << endl;
			cout << "Print matrices: 5 " << endl;
			cout << "Quit 6 " << endl;
			cin >> n;
			break;




		case 3: n = 3;
			cout << "Which matrices do you want to subtract? " << endl;
			cin >> selectedM;
			cin >> selectedN;
			matrixF[selectedM].AddSubCompatible(matrixF[selectedN]);
			matrixF[selectedM].Sub(matrixF[selectedN], r);
			cout << "New matrice: 1 " << endl;
			cout << "Add matrices: 2 " << endl;
			cout << "Subtract matrices:3 " << endl;
			cout << "Multiply matrices: 4" << endl;
			cout << "Print matrices: 5 " << endl;
			cout << "Quit 6 " << endl;
			cin >> n;
			break;
		case 4: n = 4;
			cout << "Which matrices do you want to multiply?" << endl;
			cin >> selectedM;
			cin >> selectedN;
			matrixF[selectedM].MultCompatible(matrixF[selectedN]);
			matrixF[selectedM].Mult(matrixF[selectedN], r);
			cout << "New matrice: 1 " << endl;
			cout << "Add matrices: 2 " << endl;
			cout << "Subtract matrices:3 " << endl;
			cout << "Multiply matrices: 4" << endl;
			cout << "Print matrices: 5 " << endl;
			cout << "Quit 6 " << endl;
			cin >> n;
			break;
		case 5: n = 5;
			cout << "Which matrix would you like to print to a do" << endl;

			cin >> filechoice;
			matrixF[filechoice].Print(outfile);
			cout << "New matrice: 1 " << endl;
			cout << "Add matrices: 2 " << endl;
			cout << "Subtract matrices:3 " << endl;
			cout << "Multiply matrices: 4" << endl;
			cout << "Print matrices: 5 " << endl;
			cout << "Quit 6 " << endl;
			cin >> n;

			break;
		case 6: n = 6;
			exit(0);
			break;
		default:
			break;



		}









	}

	return 0;
}