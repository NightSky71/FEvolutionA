#include "stdafx.h"
#include "Matrix.h"


Matrix2::Matrix2(){
	mData.clear();

	Rows = 0;
	Cols = 0;
}

Matrix2::~Matrix2(){

}

Matrix2::Matrix2(std::size_t rows, std::size_t cols){
	
	mData.clear();
	
	Rows = rows;
	Cols = cols;

	for (unsigned int i = 0; i < rows; i++){
		std::vector<double> row; // Create an empty row

		for (unsigned int j = 0; j < cols; j++){
			row.push_back(0.0);
		}

		mData.push_back(row);
	}
}

Matrix2::Matrix2(const double **lhs, const std::size_t rows, const std::size_t cols){

	mData.clear();

	Rows = rows;
	Cols = cols;

	for (unsigned int i = 0; i < rows; i++){
		std::vector<double> row; // Create an empty row

		for (unsigned int j = 0; j < cols; j++){
			row.push_back(lhs[i][j]);
		}

		mData.push_back(row);
	}
}


/*
ADDITION OPERATORS
*/

Matrix2 Matrix2::operator+(const double rhs) const{
	unsigned int row, col;

	Matrix2 rtnMatrix;

	for (row = 0; row < Rows; row++){
		for (col = 0; col < Cols; col++){
			rtnMatrix.mData[row][col] = this->mData[row][col] + rhs;
		}
	}

	return rtnMatrix;
}

Matrix2 Matrix2::operator+(const std::vector<double> vector) const{
	unsigned int row, col;

	// Check the vector is the correct length
	if (vector.size() != Rows){
		throw std::invalid_argument("Matrix2::operator+ - Input Vector size does not match Matrix Rows ");
	}

	Matrix2 rtnMatrix;

	for (row = 0; row < Rows; row++){
		for (col = 0; col < Cols; col++){
			rtnMatrix.mData[row][col] = this->mData[row][col] + vector[row];
		}
	}

	return rtnMatrix;
}

Matrix2 Matrix2::operator+(const Matrix2& matrix) const{
	unsigned int row, col;

	// Check the vector is the correct length
	if (matrix.Rows != Rows || matrix.Cols != Cols){
		throw std::invalid_argument("Matrix2::operator+ - Input Matrix size does not match Matrix Rows ");
	}

	Matrix2 rtnMatrix = Matrix2(Rows, Cols);

	for (row = 0; row < Rows; row++){
		for (col = 0; col < Cols; col++){
			rtnMatrix.mData[row][col] = this->mData[row][col] + matrix.mData[row][col];
		}
	}

	return rtnMatrix;
}

/*
SUBTRACTION OPERATORS
*/

Matrix2 Matrix2::operator-(const double rhs) const{
	unsigned int row, col;

	Matrix2 rtnMatrix = Matrix2(Rows, Cols);

	for (row = 0; row < Rows; row++){
		for (col = 0; col < Cols; col++){
			rtnMatrix.mData[row][col] = this->mData[row][col] - rhs;
		}
	}

	return rtnMatrix;
}

Matrix2 Matrix2::operator-(const std::vector<double> vector) const{
	unsigned int row, col;

	// Check the vector is the correct length
	if (vector.size() != Rows){
		throw std::invalid_argument("Matrix2::operator+ - Input Vector size does not match Matrix Rows ");
	}

	Matrix2 rtnMatrix = Matrix2(Rows, Cols);

	for (row = 0; row < Rows; row++){
		for (col = 0; col < Cols; col++){
			rtnMatrix.mData[row][col] = this->mData[row][col] - vector[row];
		}
	}

	return rtnMatrix;
}

Matrix2 Matrix2::operator-(const Matrix2& matrix) const{
	unsigned int row, col;

	// Check the vector is the correct length
	if (matrix.Rows != Rows || matrix.Cols != Cols){
		throw std::invalid_argument("Matrix2::operator+ - Input Matrix size does not match Matrix Rows ");
	}

	Matrix2 rtnMatrix = Matrix2(Rows, Cols);

	for (row = 0; row < Rows; row++){
		for (col = 0; col < Cols; col++){
			rtnMatrix.mData[row][col] = this->mData[row][col] - matrix.mData[row][col];
		}
	}

	return rtnMatrix;
}

/*
MUTLIPLICATION OPERATORS
*/

Matrix2 Matrix2::operator*(const double rhs) const{
	unsigned int row, col;

	Matrix2 rtnMatrix = Matrix2(Rows, Cols);

	for (row = 0; row < Rows; row++){
		for (col = 0; col < Cols; col++){
			rtnMatrix.mData[row][col] = this->mData[row][col] * rhs;
		}
	}

	return rtnMatrix;
}

std::vector<double> Matrix2::operator*(const std::vector<double> vector) const{
	unsigned int row, col;

	// Check the vector is the correct length
	if (vector.size() != Rows){
		throw std::invalid_argument("Matrix2::operator+ - Input Vector size does not match Matrix Rows ");
	}

	std::vector<double> rtnVector;

	for (row = 0; row < Rows; row++){
		rtnVector.push_back(0.0);

		for (col = 0; col < Cols; col++){
			rtnVector[row] += this->mData[row][col] * vector[row];
		}
	}

	return rtnVector;
}

Matrix2 Matrix2::operator*(const Matrix2& matrix){
	unsigned int row, col, subIndex;

	// Check the vector is the correct length
	if (matrix.Rows != Cols || matrix.Cols != Rows){
		throw std::invalid_argument("Matrix2::operator+ - Input Matrix size does not match Matrix Rows ");
	}

	// Construct a matrix of lhs Rows and rhsCols
	Matrix2 rtnMatrix = Matrix2(Rows, matrix.Cols);

	for (row = 0; row < Rows; row++){
		for (col = 0; col < matrix.Cols; col++){
			for (subIndex = 0; subIndex < Cols; subIndex++){
				rtnMatrix.mData[row][col] += this->mData[row][subIndex] * matrix.mData[subIndex][col];
			}
		}
	}

	return rtnMatrix;
}

void Matrix2::print(){


	for (unsigned int i = 0; i < Rows; i++){

		std::cout << " | ";

		for (unsigned int j = 0; j < Cols; j++){
			std::cout << mData[i][j] << "  ";
		}

		std::cout << "| " << std::endl;
	}
}

