#include <condition_variable>
#include <chrono>

#include "engine.h"
void runCylinder(Cylinder* cylinder,float* inputFuel,int* spark,int* stroke){
	while(*inputFuel){

		std::unique_lock<std::mutex> threadLock(conditionM);

		switch(*stroke){
			case 0:
			condition.wait(threadLock);
			cylinder->Intake(inputFuel);
				break;

			case 1:
			condition.wait(threadLock);
			cylinder->Compression();
				break;

			case 2:
			condition.wait(threadLock);
			cylinder->Ignition(spark);
			break;

			case 3:
			condition.wait(threadLock);
			cylinder->Push();
			break;
		}
	}
}
