/*
	Implementation of the ElementFrame Class
*/

#include "stdafx.h"
#include "Element.h"

void FrameElement3D::SetNodeVectors(Node* fromNode, Node* toNode){

	Element3D::SetNodeVectors(fromNode, toNode);

	CreateStiffnessMatrix(fromNode->getPos(), toNode->getPos());

}

void FrameElement3D::CreateStiffnessMatrix(Vector3 fNV, Vector3 tNV){
	
	double l, m, n, D;
	int row = 0;

	l = (tNV.X - fNV.X) / length;
	m = (tNV.Y - fNV.Y) / length;
	n = (tNV.Z - fNV.Z) / length;

	D = sqrt(l*l + m*m);

	Matrix2 lambda = Matrix2(3, 3);

	lambda.set(0, 0, l);		lambda.set(0, 1, m);		lambda.set(0, 2, n);
	lambda.set(1, 0, -(m/D));	lambda.set(1, 1, (l/D));	lambda.set(1, 2, 0.0);
	lambda.set(2, 0, -(l*n/D)); lambda.set(2, 1, -(m*n/D)); lambda.set(2, 2, D);

	Matrix2 T = Matrix2(2 * TOTAL_DOF_3D, 2 * TOTAL_DOF_3D);

	T.set(0, 0, lambda);
	T.set(3, 3, lambda);
	T.set(6, 6, lambda);
	T.set(9, 9, lambda);

	// Row 0
	stiffnessMatrix.set(row, 0, crossSection.area * crossSection.matertial.E / length);
	stiffnessMatrix.set(row, TOTAL_DOF_3D, -crossSection.area * crossSection.matertial.E / length);
	row++;

	// Row 1
	stiffnessMatrix.set(row, 1, (12 * crossSection.matertial.E*crossSection.Ixx) / (length * length * length));
	stiffnessMatrix.set(row, 5, (6 * crossSection.matertial.E*crossSection.Ixx) / (length * length));
	stiffnessMatrix.set(row, TOTAL_DOF_3D + 1, -stiffnessMatrix.mData[row][1]);
	stiffnessMatrix.set(row, TOTAL_DOF_3D + 5, -stiffnessMatrix.mData[row][5]);
	row++;

	// Row 2
	stiffnessMatrix.set(row, 2, (12 * crossSection.matertial.E*crossSection.Iyy) / (length * length * length));
	stiffnessMatrix.set(row, 4, -(6 * crossSection.matertial.E*crossSection.Iyy) / (length * length));
	stiffnessMatrix.set(row, TOTAL_DOF_3D + 2, -stiffnessMatrix.mData[row][2]);
	stiffnessMatrix.set(row, TOTAL_DOF_3D + 4, stiffnessMatrix.mData[row][4]);
	row++;

	// Row 3
	stiffnessMatrix.set(row, 3, crossSection.matertial.G * crossSection.J);
	stiffnessMatrix.set(row, TOTAL_DOF_3D + 3, -stiffnessMatrix.mData[row][5]);
	row++;

	// Row 4
	stiffnessMatrix.set(row, 2, -(6 * crossSection.matertial.E*crossSection.Iyy) / (length * length));
	stiffnessMatrix.set(row, 4, (4 * crossSection.matertial.E*crossSection.Iyy) / (length));
	stiffnessMatrix.set(row, TOTAL_DOF_3D + 2, -stiffnessMatrix.mData[row][2]);
	stiffnessMatrix.set(row, TOTAL_DOF_3D + 4, 0.5*stiffnessMatrix.mData[row][4]);
	row++;

	// Row 5
	stiffnessMatrix.set(row, 1, (6 * crossSection.matertial.E*crossSection.Ixx) / (length * length));
	stiffnessMatrix.set(row, 5, (4 * crossSection.matertial.E*crossSection.Ixx) / (length));
	stiffnessMatrix.set(row, TOTAL_DOF_3D + 1, -stiffnessMatrix.mData[row][1]);
	stiffnessMatrix.set(row, TOTAL_DOF_3D + 5, 0.5*stiffnessMatrix.mData[row][5]);
	row++;

	// Row 6
	stiffnessMatrix.set(row, 0, -stiffnessMatrix.mData[row - TOTAL_DOF_3D][0]);
	stiffnessMatrix.set(row, TOTAL_DOF_3D, -stiffnessMatrix.mData[row - TOTAL_DOF_3D][TOTAL_DOF_3D]);
	row++;

	// Row 7
	stiffnessMatrix.set(row, 1, -stiffnessMatrix.mData[row - TOTAL_DOF_3D][1]);
	stiffnessMatrix.set(row, TOTAL_DOF_3D + 1, -stiffnessMatrix.mData[row - TOTAL_DOF_3D][5]);
	row++;
} 