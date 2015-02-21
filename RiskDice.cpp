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

	FILE* fp;

	fp = std::fopen(filename, "w");
	if (fp == NULL) {return 1;}
	fprintf(fp, "Attackers  Defenders   %% Win\n");
	for (int attackers = 1; attackers <=3; attackers++) {
		for (int defenders = 1; defenders <=2; defenders++) {
			fprintf(fp, "%d          %d           %f\n", 
				attackers, defenders, runMonte(attackers, defenders));
		}
	}
	
	return 0;
}

void sortDice (Dice dies[], int n) {
	bool isSorted = false;
	Dice extra;

	if (n < 1) {
		throw "Cannot sort none or negative dice.";
	}
	if (n == 1) {
		return;
	}

	while (!isSorted) {
		isSorted = true;
		for (int i = 0; i < n-1; ++i) {
			if (dies[i] < dies [i+1]) {
				extra = dies[i];
				dies[i] = dies[i+1];
				dies[i+1] = extra;
				isSorted = false;
			}
		}
	}
}

double runMonte(int attackerDice, int defenderDice) {
	if (attackerDice < 1 ||
		attackerDice > 3 ||
		defenderDice < 1 ||
		defenderDice > 2) {
			throw "Illegal number of dice to be tested";
	}

	Dice* attacker = new Dice[attackerDice];
	Dice* defender = new Dice[defenderDice];

	int wins(0);        // Number of attacker wins
	int attacks(0);

	for (int i = 0; i != MONTE_ITER; ++i) {
		// get all random dice and sort them
		for (int j = 0; j <=attackerDice; ++j) {
			attacker[j].setRandom();
		}
		for (int j = 0; j <=defenderDice; ++j) {
			defender[j].setRandom();
		}
		sortDice(attacker, attackerDice);
		sortDice(defender, defenderDice);

		int attacksToResolve;
		if (attackerDice > 1 &&
			defenderDice > 1) {
			attacksToResolve = 2;
		} else {
			attacksToResolve = 1;
		}
		for (int j = 0; j < attacksToResolve; ++j) {
			attacks++;
			if (attacker[j] > defender[j]) {
				wins++;
			}
		}
	}

	return double(wins)/attacks;
}