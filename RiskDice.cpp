/* 
This program is inteded to perform a monte carlo
analysis of the dice rolls in Risk. It then outputs
the results to file.

Mar 2013 - Clayton Rogers
claytonrogers53@gmail.com
*/
#include "RiskDice.h"

const int MONTE_ITER = 10000000;
const int ITER = 1;
bool firstWrite = true;


int main () {

	double results(0);
	FILE* fp;

	for (int i = 0; i != ITER; ++i) {
		results += runMonte();
	}

	results /= ITER;
	fp = fopen("output.dat", "a");
	fprintf(fp, "Win % = %f\n", results);

	return 0;
}

void sortDice (dice dies[], int n) {
	bool isSorted = false;
	dice extra;

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
	dice attacker[3], defender[2];
	int loses(0), wins(0);  // loss is an attacker losing, win is attacker winning
	FILE* fp;
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

	// output the data to file (clear it if it is the first run)
	if (firstWrite) {
		fp = fopen("output.dat", "w");
		firstWrite = false;
	} else {
		fp = fopen("output.dat", "a");
	}
	fprintf(fp, "%d   %d   %d   %f\n", numAttacks, wins, loses, double(wins) / numAttacks);
	fclose(fp);

	return double(wins)/numAttacks;
}