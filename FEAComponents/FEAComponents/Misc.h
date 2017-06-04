/*
	The header file for the misc classes and functions
*/

#include "stdafx.h"

/*
	Forward declaration of the element class to help:
	Nodes have element pointers
	Elements to have node pointers
*/
class Element{
public:
	static enum Types{
		element = 0,
		element2D,
		element3D,
		frameElement3D
	};

	Types type;

	Element(){ type = element; };

	Types getType(){ return type; };
};