#pragma once
#include <condition_variable>

extern std::mutex conditionM;
extern std::condition_variable condition;

class Cylinder{
public:

	Cylinder(int,float);
	
	void Intake(float*);
	void Compression();
	void Ignition(int*);
	void Push();
	int cubiCentimeters;

private:

	int exauhst;
	
	float airFuel;
	float compression;
	float air;
	float fuel;

};
