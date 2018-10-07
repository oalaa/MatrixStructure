#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

// A structure to store a matrix

struct matrix
{
    int* data;       // Pointer to 1-D array that will simulate matrix
    int row, col;
};

void createMatrix   (int row, int col, int num[], matrix& mat);
ostream& operator<< (ostream& out, matrix mat);
bool   operator==   (matrix mat1, matrix mat2);	// True if identical
bool   operator!=   (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare     (matrix mat);  // True if square matrix
bool   isSymetric   (matrix mat);  // True if square and symmetric
bool   isIdentity   (matrix mat);  // True if square and identity
matrix transpose    (matrix& mat);    // Return new matrix with the transpose


int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,18,5,6,7};
    int data3 [] = {10,100,10,100,10,100,10,100};
    matrix mat1, mat2, mat3 ;
    createMatrix (4, 2, data1, mat1);
    createMatrix (2, 3, data2, mat2);
    createMatrix (4, 2, data3, mat3);
// The next code will not work until you write the functions
    cout << mat1 << endl;
    cout << mat2 << endl;
    cout << mat3 << endl;
    if (mat1==mat3)
    {
        cout << "True" <<endl;
    }
    else
    {
        cout << "False" << endl;
    }
    if (mat1 != mat3)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    cout << isSquare(mat1) << endl ;
    cout << isIdentity(mat1) << endl ;
    cout << transpose(mat3);
    return 0;

}

// Takes an array of data and stores in matrix according
// to rows and columns

void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int [row * col];
    for (int i = 0; i < row * col; i++)
        mat.data [i] = num [i];
}

ostream& operator<< (ostream& out, matrix mat)
{
    out << "The Content Of Matrix : "<< endl;

    for (int i=0 ; i<mat.row ; i++)
    {
        for (int j=0 ; j<mat.col ; j++)
        {
            out << mat.data[i*mat.col+j] << " ";
        }
        cout << endl;

    }
    cout << endl;
    return out ;
}
bool   operator== (matrix mat1, matrix mat2)
{
    if ((mat1.row == mat2.row) && (mat1.col == mat2.col))
    {
        for (int i=0 ; i<mat1.row ; i++ )
        {
            for (int j=0 ; j<mat1.col ; j++)
            {
                if (mat1.data[i*mat1.col+j] == mat2.data[i*mat2.col+j])
                {
                    return true;
                }
                else
                    return false;
            }
        }
    }
    else
    {
        return false;
    }

}

bool   operator!= (matrix mat1, matrix mat2)
{
    if ((mat1.row == mat2.row) && (mat1.col == mat2.col))
    {
        for (int i=0 ; i<mat1.row ; i++ )
        {
            for (int j=0 ; j<mat1.col ; j++)
            {
                if (mat1.data[i*mat1.col+j] != mat2.data[i*mat2.col+j])
                {
                    return true;
                }
                else
                    return false;
            }
        }
    }
    else if ((mat1.row != mat2.row) && (mat1.col != mat2.col) )
        return true;
}
bool   isSquare   (matrix mat)
{
    if (mat.row == mat.col)
    {
        return true;
    }
    else
        return false;
}
bool   isIdentity (matrix mat)
{


    if (isSquare(mat) ==1 )
    {
        for (int i = 0; i < mat.row; i++)
        {
            for (int j = 0; j < mat.col; j++)
            {
                if (i == j && mat.data[i*mat.col+j] == 1) {}
                else if (i!= j && mat.data[i*mat.col+j] == 0)
                    return true;
            }
        }
        return false;
    }
    else
        return false;
}
bool   isSymetric (matrix mat)
{
    if (isSquare(mat) == 1)
    {


        for (int i=0 ; i< mat.row ; i++)
        {
            for (int j=0 ; j< mat.col ; j++)
            {
                if (mat.data[i*mat.col+j] == mat.data[j*mat.col+i])
                {
                    return true;

                }
                else
                    return false;
            }
        }
    }
    else
        return false;
}

matrix transpose(matrix& mat)
{
    matrix TransposeMatrix;
    TransposeMatrix.row = mat.col;
    TransposeMatrix.col = mat.row;
    TransposeMatrix.data = new int [TransposeMatrix.col * TransposeMatrix.row];


    for (int i=0 ; i<mat.row ; i++)
    {
        for (int j=0 ; j<mat.col ; j++)
        {
            TransposeMatrix.data[j*mat.row+i] = mat.data[i*mat.col+j];
        }
    }
    return TransposeMatrix;
}
