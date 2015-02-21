#include "Dice.h"


void Dice::setValue(int value) {
	if (value < 1 || value > 6) {
		value = -1;

	}
	valueOfDie = value;
}

void Dice::setRandom() {
	double temp = rand() / double(RAND_MAX);
	double sliceSize = 1.0 / 6;

	valueOfDie = -1;

	for (int i = 0; i != 6; ++i) {
		if ((temp > sliceSize*i) && (temp < sliceSize*(i+1))) {
			valueOfDie = i+1;
			break;
		}
	}

	if (valueOfDie == -1) {
		// if we somehow happen to hit right on the edge
		valueOfDie = 4;
		// ^^ very random;
	}
}

int Dice::getValue() {
	return valueOfDie;
}

Dice::Dice (int value) {
	if (!randomInitialized) {
		srand(unsigned int(time(NULL)));
		randomInitialized = true;
	}
	if (value < 1 || value > 6) {
		value = -1;
	}
	valueOfDie = value;
}

bool Dice::randomInitialized = false;

bool Dice::operator> (Dice otherDie) {
	return (valueOfDie > otherDie.valueOfDie);
}

bool Dice::operator< (Dice otherDie) {
	return (valueOfDie < otherDie.valueOfDie);
}

bool Dice::operator== (Dice otherDie) {
	return (valueOfDie == otherDie.valueOfDie);
}