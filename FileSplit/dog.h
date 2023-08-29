#pragma once

#include "animal.h"

class Dog : public Animal {
public:
	void bark(void);
private:
	int speed;
};
