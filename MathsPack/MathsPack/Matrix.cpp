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

Matrix2::Matrix2(const Matrix2& matrix){
	mData.clear();

	Rows = matrix.Rows;
	Cols = matrix.Cols;

	for (unsigned int i = 0; i < Rows; i++){
		std::vector<double> row; // Create an empty row

		for (unsigned int j = 0; j < Cols; j++){
			row.push_back(matrix.mData[i][j]);
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

bool Matrix2::set(std::size_t row, std::size_t col, const Matrix2& matrix){
	if (matrix.Cols + col > Cols || matrix.Rows + row > Rows){
		throw std::invalid_argument("Set - Input matrix is too large or offsets outside of the base matrix.");
	}

	for (int i = 0; i < matrix.Rows; i++){
		for (int j = 0; j < matrix.Cols; j++){
			mData[i + row][j + col] = matrix.mData[i][j];
		}
	}
}

std::vector <double> Matrix2::GuassianElimination(std::vector <double> rhs){
	
	// Check the vector is the correct length
	if (Rows != rhs.size()){
		throw std::invalid_argument("GuassianElimination - Input vector length does not match matrix Rows");
	}
	if (Rows != Cols){
		throw std::invalid_argument("GuassianElimination - Matrix not square");
	}

	// Size of the array
	std::size_t length = rhs.size();
	Matrix2 lhs = *this;

	// Cut off precision
	double _EPSILON = 1.0e-10;

	//Variables
	int max;
	double t;
	double alpha;

	std::vector<double> temp; temp.resize(Rows);
	std::vector<double> x; x.resize(Rows);

	for (int p = 0; p < length; p++){
		
		// find pivot row and swap
		max = p;
		for (int i = p + 1; i < length; i++){
			if (abs(lhs.mData[i][p]) > abs(lhs.mData[max][p])){
				max = i;
			}
		}

		temp = lhs.mData[p];
		lhs.mData[p] = lhs.mData[max];
		lhs.mData[max] = temp;

		t = rhs[p]; 
		rhs[p] = rhs[max];
		rhs[max] = t;

		// singular or nearly singular
		if (abs(lhs.mData[p][p]) <= _EPSILON){
			throw std::invalid_argument("GuassianElimination - Matrix is singular or nearly singular");
		}

		// pivot within A and b
		for (int i = p + 1; i < length; i++){
			alpha = lhs.mData[i][p] / lhs.mData[p][p];
			rhs[i] -= alpha * rhs[p];
			for (int j = p; j < length; j++){
				lhs.mData[i][j] -= alpha * lhs.mData[p][j];
			}
		}
	}


	for (int i = length - 1; i >= 0; i--){
		double sum = 0.0;
		for (int j = i + 1; j < length; j++){
			sum += lhs.mData[i][j] * x[j];
		}
		x[i] = (rhs[i] - sum) / lhs.mData[i][i];
	}

	return x;
}

void Matrix2::Zero(){
	for (int i = 0; i < Rows; i++){
		for (int j = 0; j < Cols; j++){
			mData[i][j] = 0.0;
		}
	}
}