/*
	Implementation of the ElementFrame Class
*/

#include "stdafx.h"
#include "Element.h"

void FrameElement3D::SetNodeVectors(Vector3 fromNodeVector, Vector3 toNodeVector){

	length = (toNodeVector - fromNodeVector).Modulus();

}

void FrameElement3D::CreateStiffnessMatrix(){
	
}