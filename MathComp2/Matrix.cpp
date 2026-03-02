#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
	// Default constructor, initalizes object to a N(10)xM(10) matrix
	m = M;
	n = N;
	// 0 out all inital values of matrix
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = 0;
		}
	}
}

Matrix::Matrix(int _m, int _n) : m(_m), n(_n)
{
	// Overload constructor, initalizes object to a custom _m x _n matrix
	for (int i = 0; i < _m; i++) {
		for (int j = 0; j < _n; j++) {
			A[i][j] = 0;
		}
	}
}

void Matrix::read()
{
	// Reads user input from the console into matrix
	std::cout << "Fill your matrix: " << std::endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> A[i][j];
		}
	}
	std::cout << std::endl;
}

void Matrix::fill(int Arr[3][3])
{
	// Fills the matrix with hardcoded values
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = Arr[i][j];
		}
	}
}

void Matrix::print()
{
	// Prints your matrix contents to the console
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Matrix Matrix::multiply(Matrix other)
{
	// Dynamic multiplication for all matrix sizes.
	if ((m != other.n) || (other.m != n)) {
		std::cout << "Cannot multiply" << std::endl;
		return Matrix();
	}

	Matrix dynamicResult(m, other.n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < other.n; j++) {
			for (int k = 0; k < n; k++) {
				double resultValue = dynamicResult.A[i][j] + (A[i][k] * other.A[k][j]);
				dynamicResult.A[i][j] = resultValue;
			}
		}
	}

	return dynamicResult;
}

Matrix Matrix::transpose()
{
	// Swap m (row) and n (column) indexes for the matrix
	Matrix transposedMatrix(n, m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			transposedMatrix.A[j][i] = A[i][j];
		}
	}

	return transposedMatrix;
}

double get2x2Determinant(double a, double b, double c, double d)
{
	return (a * d) - (b * c);
}

double Matrix::determinant()
{
	// Make sure matrix is square and 3x3
	if (m != 3 || n != 3) {
		std::cout << "Cannot calculate determinant" << std::endl;
		return 0.0;
	}

	double determinantValue =
		A[0][0] * get2x2Determinant(A[1][1], A[1][2], A[2][1], A[2][2]) -
		A[0][1] * get2x2Determinant(A[1][0], A[1][2], A[2][0], A[2][2]) +
		A[0][2] * get2x2Determinant(A[1][0], A[1][1], A[2][0], A[2][1]);

	return determinantValue;
}

Matrix Matrix::inverse()
{
	double determinant = Matrix::determinant();

	Matrix inverseMatrix(m, n);

	if (determinant == 0) {
		std::cout << "Cannot calculate inverse" << std::endl;
		return inverseMatrix;
	}

	Matrix cofactorMatrix(m, n);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Matrix minorMatrix(2, 2);
			int r = 0, c = 0;

			for (int k = 0; k < 3; k++) {
				if (k != i) {
					c = 0;
					for (int l = 0; l < 3; l++) {
						if (l != j) {
							minorMatrix.A[r][c] = A[k][l];
							c++;
						}
					}
					r++;
				}
			}

			double minorDet = get2x2Determinant(
				minorMatrix.A[0][0], minorMatrix.A[0][1],
				minorMatrix.A[1][0], minorMatrix.A[1][1]
			);

			cofactorMatrix.A[i][j] = pow(-1, i + j) * minorDet;
		}
	}

	Matrix adjugateMatrix = cofactorMatrix.transpose();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			inverseMatrix.A[i][j] = 1 / determinant * adjugateMatrix.A[i][j];
		}
	}

	return inverseMatrix;
}

Vector3D::Vector3D() {
	for (int i = 0; i < 3; i++) {
		A[i][0] = 0;
	}
}

Vector3D::Vector3D(double _x, double _y, double _z) {
	A[0][0] = _x;
	A[1][0] = _y;
	A[2][0] = _z;
}

Vector3D Matrix::multiply(Vector3D v)
{
	// Multiply a 3x3 matrix with a 3x1 vector, return a 3x1 vector
	Vector3D multipliedVector;

	for (int i = 0; i < 3; i++) {
		multipliedVector.A[i][0] = 0;
		for (int j = 0; j < 3; j++) {
			multipliedVector.A[i][0] += A[i][j] * v.A[j][0];
		}
	}

	return multipliedVector;
}

void Vector3D::print()
{
	//Prints the vector contents to the console
	for (int i = 0; i < 3; i++) {
		std::cout << A[i][0] << std::endl;
	}
	std::cout << std::endl;
}