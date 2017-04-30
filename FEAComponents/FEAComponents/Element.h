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
protected:
	// Element ID
	static unsigned int total;

	// Node ID's
	unsigned int toNode;
	unsigned int fromNode;
	double length;

	// The local stiffness matrix (Using Global Coords)
	double stiffnessMatrix[2 * TOTAL_DOF_3D][2 * TOTAL_DOF_3D];

	// Useful variables
	double lambda[TOTAL_DOF_3D][TOTAL_DOF_3D];

/// CONSTRUCTOR & FUNCTIONS
public:

	Element3D();
	Element3D(unsigned int fromNode, unsigned int toNode);

	virtual void SetNodeVectors(Vector3 fromNodeVector, Vector3 toNodeVector);
	virtual void print();

protected:

	virtual void CreateStiffnessMatrix();
};

/*
	3D Frame Element
*/
class FrameElement3D : public Element3D
{
public:

	FrameElement3D();

	void SetNodeVectors(Vector3 fromNodeVector, Vector3 toNodeVector);
	void CreateStiffnessMatrix();
};