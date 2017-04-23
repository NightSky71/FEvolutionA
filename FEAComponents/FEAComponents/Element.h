/*
	Element Header: Declaration for base element class and all children classes too



*/

#include "stdafx.h"
#include <MathsPack\Vector3.h>

/*
	Base Element class

	This only covers that connect between two nodes exclusively
*/
class Element3D{
/// VARIABLES
private:

	unsigned int toNode;
	unsigned int fromNode;

	// The local stiffness matrix (Using Global Coords)
	double stiffnessMatrix[2 * TOTAL_DOF_3D][2 * TOTAL_DOF_3D];

/// CONSTRUCTOR & FUNCTIONS
public:

	Element3D();
	Element3D(unsigned int fromNode, unsigned int toNode);

	virtual void SetNodeVectors(Vector3 fromNodeVector, Vector3 toNodeVector);
	virtual void print();

};

/*
	3D Frame Element
*/
class FrameElement3D : public Element3D
{
public:

	FrameElement3D();

	void SetNodeVectors(Vector3 fromNodeVector, Vector3 toNodeVector);
};