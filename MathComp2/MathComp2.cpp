#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
	// Matrix 1
	Matrix mat1(3, 3);
	//mat1.read(); //User input for matrix 1
	int A1[3][3] = { {1, 2, 3},
					{2, 3, 4},
					{3, 4, 2} };
	mat1.fill(A1); //Predefined values for matrix 1
	printf("Matrix 1: \n");
	mat1.print();

	// Matrix 2
	Matrix mat2(3, 3);
	//mat2.read(); //User input for matrix 2
	int A2[3][3] = { {1, 0, 2},
					{-3, 4, 6},
					{-1, -2, 3} };
	mat2.fill(A2); //Predefined values for matrix 2
	printf("Matrix 2: \n");
	mat2.print();

	// Multiply matrix
	printf("Multipled matrices: \n");
	Matrix multipliedMat1 = mat1.multiply(mat2);
	multipliedMat1.print();

	// Transposed matrix
	printf("Transposed matrix 1: \n");
	Matrix transposedMat1 = mat1.transpose();
	transposedMat1.print();

	printf("Transposed matrix 2: \n");
	Matrix transposedMat2 = mat2.transpose();
	transposedMat2.print();

	// Determinant
	printf("Determinant 1: %f\n\n", mat1.determinant());
	printf("Determinant 2: %f\n\n", mat2.determinant());

	// Inverse matrix
	printf("Inverse matrix 1: \n");
	Matrix inverseMat1 = mat1.inverse();
	inverseMat1.print();

	printf("Inverse matrix 2: \n");
	Matrix inverseMat2 = mat2.inverse();
	inverseMat2.print();

	// Multiply vector
	printf("Multipled vector 1: \n");
	Vector3D vec1(1, 2, 3);
	Vector3D multipliedVec1 = mat1.multiply(vec1);
	multipliedVec1.print();

	printf("Multipled vector 2: \n");
	Vector3D vec2(3, 2, 1);
	Vector3D multipliedVec2 = mat2.multiply(vec2);
	multipliedVec2.print();

	// Keep console open
	int a = 0;
	std::cin >> a;

	return 0;
}