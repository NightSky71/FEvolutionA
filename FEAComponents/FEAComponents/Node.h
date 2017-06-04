/*
	Node.h

*/

#include "stdafx.h"

#include <MathsPack\Vector3.h>

class Node{
		
public:

	Vector3 pos;	// position

	Vector3 disp;	// displacement

public:
	// Constructors
	Node();
	Node(Vector3 pos);
	Node(const Node &rhs);

	// Functions
	void setDisplacement(Vector3 disp);
	Vector3 getPos(bool bDisp = true);
};