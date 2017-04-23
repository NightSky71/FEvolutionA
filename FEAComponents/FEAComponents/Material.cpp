/*
	Implementation of the material classes
*/

#include "Material.h"

//////////////////////////////////////////////////////////
//	CONSTRUCTOR
//////////////////////////////////////////////////////////
Material::Material(){
	this->E			= 0.0;
	this->G			= 0.0;
	this->poisson	= 0.0;
}

Material::Material(double E, double G = 0.0, double poisson = 0.0){
	this->E			= E;
	this->G			= G;
	this->poisson	= poisson;
}

void Material::AssignUseageFlags(){
	AssignUseageFlag(E, MATERIAL_USE_FLAGS::E);
	AssignUseageFlag(G, MATERIAL_USE_FLAGS::G);
	AssignUseageFlag(poisson, MATERIAL_USE_FLAGS::POISSON);
}

void Material::AssignUseageFlag(double a, MATERIAL_USE_FLAGS flag){
	if (a > 0){
		useageFlags |= flag;
	}
}