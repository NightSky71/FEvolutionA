/*
	Element Header: Declaration for base element class and all children classes too



*/

#include "stdafx.h"
#include <MathsPack\Vector3.h>
#include <MathsPack\Matrix.h>

#include "CrossSection.h"
#include "Node.h"

/*
	Base Element class

	This only covers that connect between two nodes exclusively
*/
class Element3D{
/// VARIABLES
protected:
	// Element ID
	static unsigned int total;

	// Node Pointers
	Node* toNode;
	Node* fromNode;

	// Element 
	double length;

	// Indexs

	// CrossSection
	CrossSection crossSection;

	// The local stiffness matrix (Using Global Coords)
	Matrix2 stiffnessMatrix = Matrix2(2 * TOTAL_DOF_3D , 2 * TOTAL_DOF_3D);

	// Useful variables
	//double lambda[TOTAL_DOF_3D][TOTAL_DOF_3D];

/// CONSTRUCTOR & FUNCTIONS
public:

	Element3D();
	Element3D(unsigned int fromNode, unsigned int toNode);

	virtual void SetNodeVectors(Node* fromNode, Node* toNode);
	virtual void print();

protected:

	virtual void CreateStiffnessMatrix(Vector3 fromNodeVector, Vector3 toNodeVector);
};

/*
	3D Frame Element
*/
class FrameElement3D : public Element3D
{
public:

	FrameElement3D();

	void SetNodeVectors(Node* fromNode, Node* toNode);
	void CreateStiffnessMatrix(Vector3 fromNodeVector, Vector3 toNodeVector);
};