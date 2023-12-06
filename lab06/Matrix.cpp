//
// Created by TZ on 10/30/2023.
//

#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) : mRows(mRows), mCols(mCols) {
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double[mCols];
    }
}

void Matrix::printMatrix(ostream &os) const {
    os << endl;
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << " ";
        }
        os << endl;
    }
}

Matrix::~Matrix() {
    cout << "Destruktor" << endl;
    for (int i = 0; i < mRows; ++i) {
        if (mElements[i] != nullptr) {
            delete[]mElements[i];
        }
    }
    if (mElements != nullptr) {
        delete[]mElements;
    }
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double[mCols];
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = what.mElements[i][j];
        }

    }
}

Matrix::Matrix(Matrix &&what) {
    cout << "Move konstruktor" << endl;
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = what.mElements;
    what.mRows = 0;
    what.mCols = 0;
    what.mElements = nullptr;
}

void Matrix::randomMatrix(int a, int b) {
    srand(time(NULL));
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = a + (rand() % (b - a + 1));
        }

    }
}

bool Matrix::isSquare() const {
    if (getRows() == getCols()) {
        return true;
    }
    return false;
}

int Matrix::getRows() const { return this->mRows; }

int Matrix::getCols() const { return this->mCols; }

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.getRows() != y.getRows() || x.getCols() != y.getCols()) {
        throw out_of_range("Nem osszeadhato");
    }
    Matrix result(x.getRows(), x.getCols());
    for (int i = 0; i < result.getRows(); ++i) {
        for (int j = 0; j < result.getCols(); ++j) {
            result.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];

        }
    }
    return result;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.getRows() != y.getCols()) {
        throw out_of_range("Nem szorozhato");
    }
    Matrix result(x.getRows(), y.getCols());
    for (int i = 0; i < result.getRows(); ++i) {
        for (int j = 0; j < result.getCols(); ++j) {
            for (int k = 0; k < x.getCols(); ++k) {
                result.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }
    return result;
}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.getRows(); ++i) {
        for (int j = 0; j < mat.getCols(); ++j) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < mat.getRows(); ++i) {
        for (int j = 0; j < mat.getCols(); ++j) {
            os << mat.mElements[i][j] << " ";
        }
        os << endl;
    }
    return os;
}


double *Matrix::operator[](int index) {
    return mElements[index];
}


double *Matrix::operator[](int index) const {
    return mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (this->mRows != mat.mRows || this->mCols != mat.mCols) {
        throw out_of_range("Nem egyezik a meret");
    }
    cout << "Copy assignment operator" << endl;
    if (this != &mat) {
        mRows = mat.mRows;
        mCols = mat.mCols;

        mElements = new double *[mRows];
        for (int i = 0; i < mRows; ++i) {
            mElements[i] = new double[mCols];
        }

        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < mCols; ++j) {
                mElements[i][j] = mat.mElements[i][j];
            }
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&mat) {
    cout << "Move assignment operator" << endl;
    if (this != &mat) {
        delete[] mElements;
        mRows = mat.mRows;
        mCols = mat.mCols;
        mElements = mat.mElements;
        mat.mRows = 0;
        mat.mCols = 0;
        mat.mElements = nullptr;
    }
    return *this;
}
