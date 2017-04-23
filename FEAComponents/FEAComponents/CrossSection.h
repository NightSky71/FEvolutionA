/*
	Header which contains declarations for the CrossSection
*/

#include "stdafx.h"

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

/// CONSTRUCTORS & FUNCTIONS
protected:

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

	double w, h;



};