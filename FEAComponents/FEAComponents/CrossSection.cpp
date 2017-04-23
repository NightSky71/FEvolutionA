/*
	Implementation of the Base CrossSection class

*/

#include "stdafx.h"
#include "CrossSection.h"

/*
	
*/
CrossSection::CrossSection(){
	
	// Properties
	Ixx		= 0.0;
	Iyy		= 0.0;
	area	= 0.0;
	maxX	= 0.0;
	maxY	= 0.0;

	// Other
	totalDimensions	= 0;
	initialised		= false;
}

/*
	Rectangular Section
*/
RectangularSection::RectangularSection(){
	this->width		= 0.0;
	this->height	= 0.0;

	totalDimensions = 2;
	initialised		= false;
}
RectangularSection::RectangularSection(double width, double height){
	this->width		= width;
	this->height	= height;

	totalDimensions = 2;
	initialised		= true;
}
RectangularSection::RectangularSection(double width, double height, Material material){
	this->width = width;
	this->height = height;

	totalDimensions = 2;
	initialised = true;
}

/*
	Set new dimensions for the shape.

	width  = dim[0]
	height = dim[1]

	@param 1D double dimension array
	@return true if assignement has been successful.
*/
bool RectangularSection::SetDimensions(double dim[]){

	// Check the size of the dimensions
	if (sizeof(dim) != totalDimensions){
		return false;
	}

	// Check to see if there are any illegal dimensions eg dim[0] <= 0
	for (int i = 0; i < totalDimensions; i++){
		if (dim[i] <= 0.0){
			return false;
		}
	}

	// Assign new dimensions
	width	= dim[0];
	height	= dim[1];

	// The section can now be recognised as initialised.
	initialised = true;

	return true;
}


/*
	Get the Area of the shape. Overrides a base virtual

	@return Area of the Shape.
*/
double RectangularSection::GetArea(){

	// If the shape has been initialised but has no area then recalc it
	if (initialised && area == 0.0){
		CalculateArea();
	}

	// Return Area
	return area;
}

/*
	Calculates Area. Overrides a base virtual

	@return Area of the Shape.
*/
double RectangularSection::CalculateArea(){
	area = width * height;
}