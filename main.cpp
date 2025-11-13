#include <iostream>

#include "engine.h"

int main(void){

	int fuelTank = 18000;
	float inputFuel;
	int inputAmount;
	bool running = false;

	Engine ZX6(636,13);

	std::cout << "Chose how rich mix '1' '2' '3'" << std::endl;
	std::cin >> inputAmount;
	switch(inputAmount){
		case 1: 
			inputFuel = 45;
			running = true;
		break;
		case 2: 
			inputFuel = 53;
			running = true;
		break;
		case 3:
			inputFuel = 60;
			running = true;
		break;
		default:
			std::cout << "invalid input" << std::endl;
	}

	while(running){
		fuelTank = fuelTank - inputFuel;
		ZX6.Intake(inputFuel);
		ZX6.Compression();
		ZX6.Ignition();
		ZX6.Push();
		if(fuelTank == 0)break;
	}
	return 0;
}
