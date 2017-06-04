/*
	Implementation of the Node class
*/

#include "stdafx.h"
#include "Node.h"

// Vector 3 class already has a default constructor to initialise X, Y, Z
Node::Node(){
	
}

Node::Node(Vector3 pos){
	this->pos = pos;
}

Node::Node(const Node &rhs){
	pos = rhs.pos;

	disp = rhs.disp;
}

Vector3 Node::getPos(bool bDisp = true){
	return bDisp ? (pos + disp) : pos;
}