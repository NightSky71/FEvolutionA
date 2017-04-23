#pragma once

#define VECTOR3
#include <cmath>

// This class handles the vector maths and storage of planetary positions

class Vector3
{
public:

	double X;
	double Y;
	double Z;

	// Constructors
	Vector3();
	Vector3(double x, double y, double z);

	/// Operator Overloading
	// Basic Arthimatic
	Vector3			operator+(const Vector3& vector);
	Vector3			operator-(const Vector3& vector);
	Vector3			operator*(double num) const;
	Vector3			operator/(double num) const;

	// Basic Vector Arthimatic
	Vector3			operator*(const Vector3& vector);

	// Assignment
	Vector3			operator+=(const Vector3& vector);
	Vector3			operator-=(const Vector3& vector);

	// Comparison
	bool			operator==(const Vector3& vector);
	bool			operator!=(const Vector3& vector);

	// Advanced Functions
	double			Modulus();
	Vector3			CrossProduct(Vector3 vector);
	Vector3			Zero();
};
inline bool Vector3::operator==(const Vector3& vector)
{
	return X == vector.X && Y == vector.Y && Z == vector.Z;
}
inline bool Vector3::operator!=(const Vector3& vector)
{
	return X != vector.X || Y != vector.Y || Z != vector.Z;
}
inline Vector3 Vector3::operator+(const Vector3& vector)
{
	return Vector3(X + vector.X, Y + vector.Y, Z + vector.Z);
}
inline Vector3 Vector3::operator-(const Vector3& vector)
{
	return Vector3(X - vector.X, Y - vector.Y, Z - vector.Z);
}
inline Vector3 Vector3::operator*(double num) const
{
	return Vector3(X * num, Y * num, Z * num);
}
inline Vector3 Vector3::operator/(double num) const
{
	return Vector3(X / num, Y / num, Z / num);
}
inline Vector3 Vector3::operator*(const Vector3& vector)
{
	return Vector3(X * vector.X, Y * vector.Y, Z * vector.Z);
}
