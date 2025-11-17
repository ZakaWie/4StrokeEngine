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

	int cylinderAmount = 4;

	Cylinder cylinders[4] = {{159,13},{159,13},{159,13},{159,13}};

	std::cout << "Chose how rich mix '1' '2' '3'" << std::endl;
	std::cin >> inputAmount;
	switch(inputAmount){
		case 1:
			inputAir = cylinders[1].cubiCentimeters;
			inputFuel = inputAir/10;
			running = true;
		break;
		case 2:
			inputAir = cylinders[1].cubiCentimeters;
			inputFuel = inputAir/13;
			running = true;
		break;
		case 3:
			inputAir = cylinders[1].cubiCentimeters;
			inputFuel = inputAir/15;
			running = true;
		break;
		default:
			std::cout << "invalid input" << std::endl;
	}


	while(running){
		for(int i = 0;i < cylinderAmount;i++){
		fuelTank = fuelTank - inputFuel;
		std::thread c1(runCylinder,&cylinders[i],inputFuel);
		c1.join();
		}
		if(fuelTank <= 0)break;
	}
	std::cout << "Out of fuel" << std::endl;
	return 0;
}
