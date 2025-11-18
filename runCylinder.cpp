#include "engine.h"
void runCylinder(Cylinder* cylinder,float* inputFuel){
	while(*inputFuel){
		cylinder->Intake(*inputFuel);
		cylinder->Compression();
		cylinder->Ignition();
		cylinder->Push();
	}
}
