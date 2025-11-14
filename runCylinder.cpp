#include "engine.h"

void runCylinder(Cylinder* cylinder1,float inputFuel){
		cylinder1->Intake(inputFuel);
		cylinder1->Compression();
		cylinder1->Ignition();
		cylinder1->Push();
	}
