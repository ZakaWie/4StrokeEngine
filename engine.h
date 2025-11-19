#pragma once

class Cylinder{
public:

	Cylinder(int,float);
	
	void Intake(float);
	void Compression();
	void Ignition();
	void Push();
	int cubiCentimeters;
	int stroke;

private:

	int rpm;
	int exauhst;
	//int crankBHP;

	float airFuel;
	float compression;
	float air;
	float fuel;

};
