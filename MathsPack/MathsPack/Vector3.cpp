#include "stdafx.h"
#include "Vector3.h"

/// Constructors

// To create an empty vector
Vector3::Vector3()
{
	X = 0.0;
	Y = 0.0;
	Z = 0.0;
}

// Define a vector array
Vector3::Vector3(double x, double y, double z)
{
	X = x;
	Y = y;
	Z = z;
}

/// Operator overrides
Vector3 Vector3::operator+=(const Vector3& vector)
{
	X += vector.X;
	Y += vector.Y;
	Z += vector.Z;
	return *this;
}

Vector3 Vector3::operator-=(const Vector3& vector)
{
	X -= vector.X;
	Y -= vector.Y;
	Z -= vector.Z;
	return *this;
}

double Vector3::Modulus()
{
	return sqrt((Vector3::X * Vector3::X) + (Vector3::Y * Vector3::Y) + (Vector3::Z * Vector3::Z));
}

Vector3 Vector3::CrossProduct(Vector3 vector)
{
	X = Y * vector.Z - Z * vector.Y;
	Y = X * vector.Z - Z * vector.X;
	Z = X * vector.Y - Y * vector.X;
	return *this;
}

Vector3 Vector3::Zero()
{
	X = 0.0;
	Y = 0.0;
	Z = 0.0;
	return *this;
}
