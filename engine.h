#pragma once

class Cylinder{
public:

	Cylinder(int,float);
	
	void Intake(float);
	void Compression();
	void Ignition();
	void Push();
	int cubiCentimeters;

private:

	int stroke;
	int rpm;
	int exauhst;
	//int crankBHP;

	float airFuel;
	float compression;
	float air;
	float fuel;

};
