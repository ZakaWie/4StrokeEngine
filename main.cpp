#include <iostream>
#include <chrono>
#include <thread>
#include<array>

#include "engine.h"
#include "runCylinder.h"

int main(void){

	int fuelTank = 18000;
	float inputFuel;
	float inputAir;
	int inputAmount;
	bool running = false;

	Cylinder cylinder1(159,13);

	std::cout << "Chose how rich mix '1' '2' '3'" << std::endl;
	std::cin >> inputAmount;
	switch(inputAmount){
		case 1:
			inputAir = cylinder1.cubiCentimeters;
			inputFuel = inputAir/10;
			running = true;
		break;
		case 2:
			inputAir = cylinder1.cubiCentimeters;
			inputFuel = inputAir/13;
			running = true;
		break;
		case 3:
			inputAir = cylinder1.cubiCentimeters;
			inputFuel = inputAir/15;
			running = true;
		break;
		default:
			std::cout << "invalid input" << std::endl;
	}


	while(running){
		fuelTank = fuelTank - inputFuel;
		std::thread c1(runCylinder,&cylinder1,inputFuel);
		c1.join();
		if(fuelTank <= 0)break;
	}
	std::cout << "Out of fuel" << std::endl;
	return 0;
}
