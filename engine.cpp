#include <iostream>
#include "engine.h"

	Cylinder::Cylinder(int cubiCentimeters,float compression){
		this->cubiCentimeters = cubiCentimeters;
		this->compression = compression;

		if((cubiCentimeters < 1)||(compression < 1))
			throw std::invalid_argument("argument invalid");

	}

	void Cylinder::Intake(float* fuel){
		stroke = 1;
		air = cubiCentimeters;
		this->fuel = *fuel;
		std::cout << "fuel: " << Cylinder::fuel << std::endl;

}
	void Cylinder::Compression(){
		stroke = 2;
		airFuel = air + fuel;
		airFuel = airFuel/compression;
		std::cout << "airFuel: " << airFuel << std::endl;

}
	void Cylinder::Ignition(int* spark){
		stroke = 3;
		if(*spark == true){
		exauhst = airFuel;
		std::cout << "Boom" << std::endl;
	}
		airFuel = 0;
}
	void Cylinder::Push(){
		stroke = 4;
		std::cout << "exauhst: "<< exauhst << std::endl;
		exauhst = 0;

}
