#pragma once

class Cylinder{
public:

	Cylinder(int,float);
	
	void Intake(float*);
	void Compression();
	void Ignition(int*);
	void Push();
	int cubiCentimeters;
	int stroke;

private:

	int exauhst;
	
	float airFuel;
	float compression;
	float air;
	float fuel;

};
