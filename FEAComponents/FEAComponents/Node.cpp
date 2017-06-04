/*
	Implementation of the Node class
*/

#include "stdafx.h"
#include "Node.h"

std::size_t totalNodes = 0;

// Vector 3 class already has a default constructor to initialise X, Y, Z
Node::Node(){
	totalNodes++; 
}

Node::Node(Vector3 pos){
	this->pos = pos;
	totalNodes++;
}

Node::Node(const Node &rhs){
	pos = rhs.pos;

	disp = rhs.disp;
}

Node::~Node(){
	totalNodes--;
}

void Node::addElementPtr(Element* elementPtr){
	if (elementPtr){
		elementPtrList.push_back(elementPtr);
	}
	else {
		throw std::exception("NODE: Element Pointer Does Not Exist");
	}
}