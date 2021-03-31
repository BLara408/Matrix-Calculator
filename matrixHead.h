#pragma once
#pragma once
const int MAX_ROWS = 10;
const int MAX_COLS = 10;
#include <fstream>
using namespace std;
class MatrixType
{
public:
    MatrixType();
    void MakeEmpty();
    void SetSize(int rowsSize, int colSize);
    void StoreItem(int item, int row, int col);
    void Add(MatrixType otherOperand, MatrixType& result);
    void Sub(MatrixType otherOperand, MatrixType& result);
    void Mult(MatrixType otherOperand, MatrixType& result);
    void Print(ofstream& outfile);
    void Printsize();
    void testPrint(int row, int col);
    bool AddSubCompatible(MatrixType otherOperand);
    bool MultCompatible(MatrixType otherOperand);
private:
    int values[MAX_ROWS][MAX_COLS];
    int numRows;
    int numCols;
};
