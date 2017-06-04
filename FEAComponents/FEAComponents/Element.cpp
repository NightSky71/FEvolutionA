/*
	Element base class implementation
*/

#include "stdafx.h"
#include "Element.h"

Element3D::Element3D(){
	

	// Nodes have not been assigned
	m_bNodes = false;

}

Element3D::Element3D(CrossSection* crossSection){
	// CrossSection
	this->crossSection = *crossSection;

	// Nodes have not been assigned
	m_bNodes = false;
}

Element3D::Element3D(CrossSection* crossSection, Node* fromNode, Node* toNode){
	// CrossSection
	this->crossSection = *crossSection;

	SetNodeVectors(fromNode, toNode);
}

void Element3D::SetNodeVectors(Node* fromNode, Node* toNode){
	// Assign node pointers
	this->fromNode = fromNode;
	this->toNode = toNode;
	m_bNodes = true;

	length = (fromNode->getPos() - toNode->getPos()).Modulus();

	AssignPtrToNodes();
}

void Element3D::AssignPtrToNodes(){
	// toNode, fromNode

	toNode->addElementPtr(this);
	fromNode->addElementPtr(this);
}