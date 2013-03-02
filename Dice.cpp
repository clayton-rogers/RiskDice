#include "Dice.h"


void dice::setValue(int value) {
	if (value < 1 || value > 6) {
		value = -1;

	}
	valueOfDie = value;
}

void dice::setRandom() {
	valueOfDie = int (rand() / double(RAND_MAX) * 6.0);
}

int dice::getValue() {
	return valueOfDie;
}

dice::dice (int value) {
	if (!randomInitialized) {
		srand(unsigned int(time(NULL)));
		randomInitialized = false;
	}
	if (value < 1 || value > 6) {
		value = -1;
	}
	valueOfDie = value;
}

bool dice::randomInitialized = false;

bool dice::operator> (dice otherDie) {
	return (valueOfDie > otherDie.valueOfDie);
}

bool dice::operator< (dice otherDie) {
	return (valueOfDie < otherDie.valueOfDie);
}

bool dice::operator== (dice otherDie) {
	return (valueOfDie == otherDie.valueOfDie);
}