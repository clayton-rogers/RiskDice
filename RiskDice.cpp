/* 
This program is inteded to perform a monte carlo
analysis of the dice rolls in Risk. It then outputs
the results to file.

Mar 2013 - Clayton Rogers
claytonrogers53@gmail.com
Feb 2015 - Clayton Rogers - updated output to include all of the die combinations
*/
#include "RiskDice.h"

const int MONTE_ITER = 10000000;
const char filename[] = "output.dat";
bool firstWrite = true;

void sortDice (Dice dies[], int n); // sorts 'n' dies
double runMonte(int attackerDice, int defenderDice);


int main () {

	double results = 0;
	FILE* fp;

	fp = std::fopen(filename, "w");
	for (int i = 0; i < 8; i++) {
		//fprintf(fp, "%d:%f   ", i, double(buckets[i])/NUM);
	}
	fprintf(fp, "\n");
	
	return 0;
}

void sortDice (Dice dies[], int n) {
	bool isSorted = false;
	Dice extra;
	extra.setValue(1);

	while (!isSorted) {
		isSorted = true;
		for (int i = 0; i != n-1; ++i) {
			if (dies[i] < dies [i+1]) {
				extra = dies[i];
				dies[i] = dies[i+1];
				dies[i+1] = extra;
				isSorted = false;
			}
		}
	}
}

double runMonte() {
	Dice attacker[3] = {1,1,1}, defender[2] = {1,1};
	int loses(0), wins(0);  // loss is an attacker losing, win is attacker winning
	int numAttacks(0);

	for (int i = 0; i != MONTE_ITER; ++i) {
		// get all random dice and sort them
		for (int j = 0; j !=3; ++j) {
			attacker[j].setRandom();
		}
		for (int j = 0; j !=2; ++j) {
			defender[j].setRandom();
		}
		sortDice(attacker, 3);
		sortDice(defender, 2);

		// check how many each side won
		for (int j = 0; j != 2; ++j) {
			// if == then loses also
			++numAttacks;
			if (attacker[j] > defender[j]) {
				wins++;
			} else {
				loses++;
			}
		}
	}

	return double(wins)/numAttacks;
}