#pragma once

class Engine{
public:

	Engine(int,float);
	
	void Intake(float);
	void Compression();
	void Ignition();
	void Push();

private:

	int cubiCentimeters;
	int stroke;
	int rpm;
	int exauhst;
	//int crankBHP;

	float airFuel;
	float compression;
	float air;
	float fuel;

};
