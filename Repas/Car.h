#pragma once
#include "Vehicle.h"

class Car : protected Vehicle {
public:
	Car() {
		numberOfWheels = 4;
	}
};

void Function() {
	Car c;
	c.numberOfWheels = 10;
}