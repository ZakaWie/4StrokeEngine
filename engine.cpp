#include <iostream>
#include "engine.h"

	Cylinder::Cylinder(int cubiCentimeters,float compression){
		this->cubiCentimeters = cubiCentimeters;
		this->compression = compression;

		if((cubiCentimeters < 1)||(compression < 1))
			throw std::invalid_argument("argument invalid");

	}

	void Cylinder::Intake(float* fuel){

		air = cubiCentimeters;
		this->fuel = *fuel;
		std::cout << "fuel: " << Cylinder::fuel << std::endl;

}
	void Cylinder::Compression(){

		airFuel = air + fuel;
		airFuel = airFuel/compression;
		std::cout << "airFuel: " << airFuel << std::endl;

}
	void Cylinder::Ignition(int* spark,int* rotation){

		if(*spark == true){
		exauhst = airFuel;
		std::cout << "Boom" << std::endl;
		*rotation = *rotation + 2;

	}
	else std::cout << "Missed fire timing" << std::endl;
	airFuel = 0;
}
	void Cylinder::Push(){

		std::cout << "exauhst: "<< exauhst << std::endl;
		exauhst = 0;

}
