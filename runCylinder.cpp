#include "engine.h"
void runCylinder(Cylinder* cylinder,float* inputFuel,int* spark){
	while(*inputFuel){
		cylinder->Intake(inputFuel);
		cylinder->Compression();
		cylinder->Ignition(spark);
		cylinder->Push();
	}
}
