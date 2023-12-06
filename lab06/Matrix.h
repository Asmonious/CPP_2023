//
// Created by TZ on 10/30/2023.
//

#ifndef CPP_2022_MATRIX_H
#define CPP_2022_MATRIX_H


#include <iosfwd>
#include <iostream>

using namespace std;

class Matrix {
public:
//Methods
// Default constructor
    Matrix(int mRows = 10, int mCols = 10);

// Copy constructor
    Matrix(const Matrix &what);

// Move constructor
    Matrix(Matrix &&what);

// Destructor
    ~Matrix();

    void printMatrix(ostream &os = cout) const;

    void fillMatrix(double value = 0);

    void randomMatrix(int a, int b);

    bool isSquare() const;

    int getRows() const;

    int getCols() const;

    friend Matrix operator+(const Matrix& x, const Matrix& y);
    friend Matrix operator*(const Matrix& x, const Matrix& y);
    friend istream & operator>>(istream& is, Matrix& mat);
    friend ostream & operator<<(ostream& os, const Matrix& mat);
    // index operator
    double* operator[] (int index);
    // index operator that works on constant matrices!
    double* operator[] (int index) const;
    // Copy assignment
    // operation is permitted between matrices having the same dimensions
    // otherwise throws an exception (out_of_range)
    Matrix & operator=(const Matrix& mat);
    // Move assignment
    Matrix & operator=(Matrix&& mat);
private:
//Data
    double **mElements;
    int mRows; //number of rows
    int mCols; //number of columns
};



#endif //CPP_2022_MATRIX_H
