/* 
This program is inteded to perform a monte carlo
analysis of the dice rolls in Risk. It then outputs
the results to file.

Mar 2013 - Clayton Rogers
claytonrogers53@gmail.com
*/
#include "RiskDice.h"

const int ITER = 100000;


int main () {
	dice attacker[3], defender[2];
	int loses(0), wins(0);  // loss is an attacker losing, win is attacker winning
	FILE* fp;

	for (int i = 0; i != ITER; ++i) {
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
			if (attacker[j] > defender[j]) {
				wins++;
			} else {
				loses++;
			}
		}
	}

	// output the data to file
	fp = fopen("output.dat", "w");
	fprintf(fp, "Total iterations = %d\n", ITER);
	fprintf(fp, "Total wins = %d\n", wins);
	fprintf(fp, "Total loses = %d\n",  loses);
	fclose(fp);

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