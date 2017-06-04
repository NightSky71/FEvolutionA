/*
	Declartion for the material class
*/

#include "stdafx.h"

class Material{

public:
	// Young's Modulus
	double E;

	// Torsional Stiffness
	double G;

	// Poisson's Ratio
	double poisson;

	// Useage Flags
	long useageFlags;

private:
	bool initialised();

// CONSTRUCTORS & FUNCTIONS
public:
	Material();
	Material(double E, double G = 0.0, double poisson = 0.0);

	~Material();

private:
	void AssignUseageFlag(double a, MATERIAL_USE_FLAGS flag);
	void AssignUseageFlags();
};