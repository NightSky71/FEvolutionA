

#ifdef MATHPACK_EXPORTS
#define MATHPACK_API __declspec(dllexport)
#else
#define MATHPACK_API __declspec(dllimport)
#endif

#pragma once 
#ifndef MATRIX_H
#define MATRIX_H

#include "stdafx.h"
#include <vector>
#include <iostream>

class Matrix2
{
public:
	std::vector<std::vector<double>> mData;

	std::size_t Rows;
	std::size_t Cols;

	// Constructors
	MATHPACK_API Matrix2();
	MATHPACK_API Matrix2(std::size_t size);
	MATHPACK_API Matrix2(std::size_t rows, std::size_t cols);
	MATHPACK_API Matrix2(const double **lhs, const std::size_t rows, const std::size_t cols);
	MATHPACK_API Matrix2(const Matrix2& matrix);

	MATHPACK_API ~Matrix2();

	// Operators

	// Addition
	MATHPACK_API Matrix2 operator+(const double rhs) const;
	MATHPACK_API Matrix2 operator+(const std::vector<double> vector) const;
	MATHPACK_API Matrix2 operator+(const Matrix2& matrix) const;

	// Subtraction
	MATHPACK_API Matrix2 operator-(const double rhs) const;
	MATHPACK_API Matrix2 operator-(const std::vector<double> vector) const;
	MATHPACK_API Matrix2 operator-(const Matrix2& matrix) const;

	// Mutliplication
	MATHPACK_API Matrix2 operator*(const double rhs) const;
	MATHPACK_API std::vector<double> operator*(const std::vector<double> vector) const;
	MATHPACK_API Matrix2 operator*(const Matrix2& matrix);

	/// Functions
	// Assignment
	MATHPACK_API bool set(std::size_t row, std::size_t col, double value){
		if (row >= Rows || col >= Cols){
			mData[row][col] = value; return true;
		} return false;
	}

	MATHPACK_API double get(std::size_t row, std::size_t col){
		if (row >= Rows || col >= Cols){
			return mData[row][col];
		} return 0.0;
	}

	MATHPACK_API bool set(std::size_t row, std::size_t col, const Matrix2& matrix);

	MATHPACK_API std::vector <double> GuassianElimination(std::vector <double> rhs);
	MATHPACK_API Matrix2 inverse();
	MATHPACK_API void Zero();

	MATHPACK_API void print();
};

/*
extern "C" __declspec(dllexport) Matrix2* __cdecl createMatrix2(){
	return new Matrix2;
}
*/


#endif