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
	float compression = 13.0f;
	int inputAmount;
	int inputCc;
	int cylinderAmount;

	int rpm;
	int rotation = 0;

	bool running = false;

	std::cout << "choose engine spec" << std::endl;
	std::cout << "CC:" <<std::endl;
	std::cin >> inputCc;
	std::cout << "Cylinder amount" << std::endl;
	std::cin >> cylinderAmount;

	

	std::vector<Cylinder> cylinders;
	for(int i = 0; i < cylinderAmount;i++){
		cylinders.push_back({(inputCc/cylinderAmount),compression});
	}
	std::vector<int> sparkPlugs;
	for(int i = 0;i < cylinderAmount;i++){
		sparkPlugs.push_back(0);
	}

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

	for(unsigned i = 0; i < cylinders.size();i++){
		std::thread c1(runCylinder,&cylinders[i],&inputFuel,&sparkPlugs[i]);
		runningCylinders.push_back(move(c1));
	}

	auto clockOuter {std::chrono::steady_clock::now()};
	while(running){
		rotation++;
		for(unsigned i = 0;i<cylinders.size();i++){
			std::cout << "cylinder:" << i+1 << " in:" << cylinders[i].stroke <<std::endl;
		if(cylinders[i].stroke == 1){
			fuelTank = fuelTank - inputFuel;
		}
		else if(cylinders[i].stroke == 2){
				sparkPlugs[i] = 1;
			}
		else if(cylinders[i].stroke == 3){
			sparkPlugs[i] = 0;
		}
		}
		if(fuelTank <= 0){
			inputFuel = 0;
			break;
		}
		auto clockInner{std::chrono::steady_clock::now()};
		std::chrono::duration<double> elapsed_seconds{clockInner - clockOuter};
		if(elapsed_seconds.count() >= 1){
			rpm = rotation*60;
			rotation = 0;
			std::cout<< "RPM:" << rpm << std::endl;
			clockOuter = {std::chrono::steady_clock::now()};
		}
	}
	for(unsigned i = 0; i < runningCylinders.size();i++){
		runningCylinders[i].join();
	}
	std::cout << "Out of fuel" << std::endl;
	return 0;
}
