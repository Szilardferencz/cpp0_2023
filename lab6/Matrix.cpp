//
// Created by Szilárd on 11/2/2023.
//

#include "Matrix.h"
#include <time.h>

Matrix::Matrix(int mRows, int mCols) {
    this->mCols = mCols;
    this->mRows = mRows;
    mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i]=new double[mCols];
    }
}

Matrix::Matrix(const Matrix &what) {
    this->mCols = what.mCols;
    this->mRows = what.mRows;
    for (int i = 0; i < mRows; ++i) {
        mElements[i]=new double[mCols];
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    this->mCols = what.mCols;
    this->mRows = what.mRows;
    this->mElements = what.mElements;
    what.mCols=0;
    what.mRows=0;
    what.mElements= nullptr;
}

Matrix::~Matrix() {
    if(this->mElements != nullptr){
        for (int i = 0; i < mRows; ++i) {
            delete[] this->mElements[i];
        }
        delete[] mElements;
    }
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            this->mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    srand(time(0));
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            this->mElements[i][j] = (rand()%(a-b));
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            os << this->mElements[i][j] << " ";
        }
        os << endl;
    }
}

bool Matrix::isSquare() const {
    return this->mRows == this->mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if((x.mRows == y.mRows) && (x.mCols == y.mCols)){
        Matrix matrix(x.mRows, x.mCols);
        for (int i = 0; i < x.mRows; ++i) {
            for (int j = 0; j < x.mCols; ++j) {
                matrix.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
            }
        }
        return matrix;
    }
    else {
        throw out_of_range("error");
    }
}
Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.mCols == y.mRows) {
        Matrix result(x.mRows, y.mCols);
        for (int i = 0; i < x.mRows; ++i) {
            for (int j = 0; j < y.mCols; ++j) {
                for (int k = 0; k < x.mCols; ++k) {
                    result.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
                }
            }
        }
        return result;
    } else {
        throw std::out_of_range("error");
    }
}


istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

double *Matrix::operator[](int index) {
    if(index >= 0 && index < mRows){
        return mElements[index];
    }
    throw out_of_range("index error");

}

double *Matrix::operator[](int index) const {
    if(index >= 0 && index < mRows){
        return mElements[index];
    }
    throw out_of_range("index error");
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            os << mat.mElements[i][j];
        }
    }
    return os;
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if(this->mRows = mat.mRows && this->mCols == mat.mCols){
        for (int i = 0; i < mat.mRows; ++i) {
            for (int j = 0; j < mat.mCols; ++j) {
                this->mElements[i][j] = mat.mElements[i][j];
            }
        }
        return *this;
    }
    throw out_of_range("error=");
}

Matrix &Matrix::operator=(Matrix &&mat) {
    if(this->mElements != nullptr) {
        for (int i = 0; i < mRows; ++i) {
            delete[] this->mElements[i];
        }
        delete[] mElements;
    }
    this->mRows = mat.mRows;
    this->mCols = mat.mCols;
    this->mElements = mat.mElements;
    mat.mRows = 0;
    mat.mCols = 0;
    mat.mElements = nullptr;
    return *this;
}

