/*
	Node.h

*/

#include "stdafx.h"

#include <MathsPack\Vector3.h>
#include "Misc.h"

class Node{

	/// Variables
public:
		
private:

	static std::size_t totalNodes;

	Vector3 pos;	// position
	Vector3 disp;	// displacement

	// This variable helps locate elements in memory
	std::list < Element* > elementPtrList;

public:
	/// Constructors
	Node();
	Node(Vector3 pos);
	Node(const Node &rhs);

	~Node();

	/// Functions
	void		addElementPtr(Element* elementPtr);
	void		setDisp(Vector3 &disp) { pos = disp; };
	Vector3&	getPos(bool bDisp = true) { return bDisp ? (pos + disp) : pos; };
};