#include <iostream>

#include "engine.h"

	Engine::Engine(int cubiCentimeters,float compression){
		this->cubiCentimeters = cubiCentimeters;
		this->compression = compression;

		if((cubiCentimeters < 1)||(compression < 1))
			throw std::invalid_argument("argument invalid");

	}

	void Engine::Intake(float fuel){
		stroke = 1;
		air = cubiCentimeters;
		this->fuel = fuel;

}
	void Engine::Compression(){
		stroke = 2;
		airFuel = air + fuel;
		airFuel = airFuel/compression;

}
	void Engine::Ignition(){
		stroke = 3;
		exauhst = airFuel;
		airFuel = 0;
}
	void Engine::Push(){
		stroke = 4;
		exauhst = 0;

}
