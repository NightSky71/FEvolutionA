// MathsTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Matrix.h"

typedef Matrix2* (__cdecl *matrix2type)();


void MatrixMathsTests_Addition(){
	std::cout <<
		"Matrix Multiplication Test\n\n"
		"| 7  8 | +  | 8  9 | = | 15  17 |\n"
		"| 1  2 | +  | 3  7 | = | 4   9  |\n"
		<< std::endl;

	Matrix2 matA = Matrix2(2, 2);

	matA.mData[0][0] = 7;
	matA.mData[0][1] = 8;
	matA.mData[1][0] = 1;
	matA.mData[1][1] = 2;


	Matrix2 matB = Matrix2(2, 2);

	matB.mData[0][0] = 8;
	matB.mData[0][1] = 9;
	matB.mData[1][0] = 3;
	matB.mData[1][1] = 7;

	Matrix2 matC = matA + matB;

	matC.print();
}

void MatrixMathsTests_Multiplication(){

	std::cout <<
		"Matrix Multiplication Test\n\n"
		"| 2  3 |                     | 25  39   9   6  |\n"
		"| 7  8 | *  | 8  9  3  0 | = | 80  119  29  16 |\n"
		"| 1  2 | *  | 3  7  1  2 | = | 14  23   5   4  |\n"
		"| 4  9 |                     | 59  99   21  18 |\n "
		<< std::endl;

	//Matrix2* matA = matrix_func();

	
	Matrix2 matA = Matrix2(4, 2);

	matA.mData[0][0] = 2;
	matA.mData[0][1] = 3;
	matA.mData[1][0] = 7;
	matA.mData[1][1] = 8;
	matA.mData[2][0] = 1;
	matA.mData[2][1] = 2;
	matA.mData[3][0] = 4;
	matA.mData[3][1] = 9;


	Matrix2 matB = Matrix2(2, 4);

	matB.mData[0][0] = 8;
	matB.mData[0][1] = 9;
	matB.mData[0][2] = 3;
	matB.mData[0][3] = 0;
	matB.mData[1][0] = 3;
	matB.mData[1][1] = 7;
	matB.mData[1][2] = 1;
	matB.mData[1][3] = 2;

	Matrix2 matC;

	for (int i = 0; i < 1; i++){
		 matC = matA * matB;
	}
	
	matC.print();


	// Destroy it explicitly
	//matA->destroy();
}

void MatrixMathsTests_GuassianElimination(){
	
	std::cout <<
		"Matrix Multiplication Test\n\n"
		"| 9  3  4 | 7 |\n"
		"| 4  3  4 | 8 |\n"
		"| 1  1  1 | 3 | \n"
		<< std::endl;

	Matrix2 matA = Matrix2(3, 3);

	matA.mData[0][0] = 1;
	matA.mData[0][1] = 1;
	matA.mData[0][2] = 1;
	matA.mData[1][0] = 1;
	matA.mData[1][1] = -2;
	matA.mData[1][2] = 2;
	matA.mData[2][0] = 1;
	matA.mData[2][1] = 2;
	matA.mData[2][2] = -1;


	std::vector<double> vecA;
	vecA.push_back(0);
	vecA.push_back(4);
	vecA.push_back(2);

	std::vector<double> vecB = matA.GuassianElimination(vecA);
	
	for (int i = 0; i < 3; i++){
		std::cout << vecB[i] << std::endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	// Load the DLL
	/*
	HINSTANCE dll_handle = ::LoadLibrary(TEXT("MathsPack.dll"));

	
	if (!dll_handle) {
		std::cerr << "Unable to load DLL!\n";
		return 1;
	}
	*/

	/*
	matrix2type matrix_func = reinterpret_cast <matrix2type> (
		::GetProcAddress(dll_handle, "create_matrix"));
	if (!matrix_func) {
		std::cerr << "Unable to load create_klass from DLL!\n";
		::FreeLibrary(dll_handle);
		return 1;
	}
	*/

	MatrixMathsTests_Addition();

	MatrixMathsTests_Multiplication();

	MatrixMathsTests_GuassianElimination();

	std::cin.ignore();
	return 0;
}

