#include "Dice.h"


void Dice::setValue(int value) {
	if (value < 1 || value > 6) {
		throw "Dice value must be [1,6] (inclusive of both)";
	}
	valueOfDie = value;
}

void Dice::setRandom() {
	valueOfDie = rand() % 6 + 1;
}

int Dice::getValue() {
	return valueOfDie;
}

Dice::Dice () {
	valueOfDie = 1;
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