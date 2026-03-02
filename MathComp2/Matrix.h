#pragma once

class Vector3D {
public:
	// --- Constructors ---
	Vector3D();
	Vector3D(double _x, double _y, double _z);

	//  --- Functions ---
	void print();

	//  --- Variables ---
	double A[3][1];
};

class Matrix
{
public:
	// --- Constructors ---
	Matrix();
	Matrix(int _m, int _n);

	//  --- Functions ---
	void read();
	void fill(int Arr[3][3]);
	void print();
	Matrix multiply(Matrix other);
	Matrix transpose();
	double determinant();
	Matrix inverse();
	Vector3D multiply(Vector3D v);

	//  --- Constants ---
	static const int M = 10;
	static const int N = 10;

	//  --- Variables ---
	double A[M][N];
	int m; // actual number of rows
	int n; // actual number of columns
};