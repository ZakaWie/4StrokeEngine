#pragma once
#include <condition_variable>

extern std::mutex conditionM;
extern std::condition_variable condition;

class Cylinder{
public:

	Cylinder(int,float);
	
	void Intake(float*);
	void Compression();
	void Ignition(int*,int*);
	void Push();
	int cubiCentimeters;

private:

	int exauhst = 0;
	
	float airFuel = 0;
	float compression = 0;
	float air = 0;
	float fuel = 0;

};
