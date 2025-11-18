#include <iostream>
#include <chrono>
#include <thread>
#include<vector>
//#include<semaphore>
#include<condition_variable>

#include "engine.h"
#include "runCylinder.h"

/*
 * turns out im in cpp 17
std::binary_semaphore
	smphSignalMainToThread{0};
	smphSignalThreadToMain{0};
*/

int main(void){

	int fuelTank = 18000;
	float inputFuel;
	float inputAir;
	int inputAmount;
	int inputCc;
	int cylinderAmount;
	int cylinderCc;

	bool running = false;

	std::cout << "choose engine spec" << std::endl;
	std::cout << "CC:" <<std::endl;
	std::cin >> inputCc;
	std::cout << "Cylinder amount" << std::endl;
	std::cin >> cylinderAmount;

	cylinderCc = inputCc/cylinderAmount;

	std::vector<Cylinder> cylinders = {{cylinderCc,13},{cylinderCc,13},{cylinderCc,13},{cylinderCc,13}};

	std::cout << "Chose how rich mix '1' '2' '3'" << std::endl;
	std::cin >> inputAmount;
	switch(inputAmount){
		case 1:
			inputAir = cylinders[0].cubiCentimeters;
			inputFuel = inputAir/10;
			running = true;
		break;
		case 2:
			inputAir = cylinders[0].cubiCentimeters;
			inputFuel = inputAir/13;
			running = true;
		break;
		case 3:
			inputAir = cylinders[0].cubiCentimeters;
			inputFuel = inputAir/15;
			running = true;
		break;
		default:
			std::cout << "invalid input" << std::endl;
	}
	std::vector<std::thread> runningCylinders;

	for(Cylinder cylinder:cylinders){
		std::thread c1(runCylinder,&cylinder,&inputFuel);
		runningCylinders.push_back(move(c1));
	}

	while(running){
		for(unsigned i = 0;i<cylinders.size();i++){
		fuelTank = fuelTank - inputFuel;
		}
		if(fuelTank <= 0){
			inputFuel = 0;
			break;
		}
	}
	for(unsigned i = 0; i < runningCylinders.size();i++){
		runningCylinders[i].join();
	}
	std::cout << "Out of fuel" << std::endl;
	return 0;
}
