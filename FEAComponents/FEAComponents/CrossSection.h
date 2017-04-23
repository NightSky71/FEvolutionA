/*
	Header which contains declarations for the CrossSection
*/

#include "stdafx.h"
#include "Material.h"

/*
	Base CrossSection
*/
class CrossSection{
	
public:
	// Second Moment of Area
	double Ixx, Iyy;

	// Area
	double area;

	// Maximum distance from the centeroid
	double maxX, maxY;

protected:

	Material matertial;

	unsigned int totalDimensions;

	bool initialised;

/// CONSTRUCTORS & FUNCTIONS
public:

	CrossSection();

	// Area
	virtual double GetArea() { return 0.0; };

	// Dimensions
	virtual bool SetDimensions(double dim[]) { return true; };

protected:

	// Area
	virtual double CalculateArea();
};







class RectangularSection : public CrossSection
{
public:
	/* Dimensions
				w
			+--------+
			|		 |
		y	|        | h
		^	|		 |
		|	+--------+
		|
		+----->x
	*/

	double width, height;

/// CONSTRUCTORS & FUNCTIONS
public:

	RectangularSection();
	RectangularSection(double width, double height);
	RectangularSection(double width, double height, Material matertial);

	double GetArea();

	bool SetDimensions(double dim[]);

protected:

	double CalculateArea();

};