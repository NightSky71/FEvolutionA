/*
	This header implements constants to be used through out the code.
*/

const int TOTAL_DOF_2D = 3;  // x, y, phi
const int TOTAL_DOF_3D = 6;  // x, y, z, theta, phi

/*
	Material Constants
*/

// Flags
enum MATERIAL_USE_FLAGS
{
	E		= 1 << 0,
	G		= 1 << 1,
	POISSON = 1 << 2
};