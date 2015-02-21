/*
This class can be used to simulate a single die
*/

#ifndef _Dice
#define _Dice

#include <cstdlib>        // for making a random dice roll
#include <ctime>          // for initialization of rand()

class dice {
public:
	void setValue(int);   // allows the setting of the value of the die, if the value is out of bounds, it is set to -1
	void setRandom();     // sets the die to a random value
	int getValue();       // returns the current value of the die
	dice(int value);
	bool operator> (dice);
	bool operator< (dice);
	bool operator== (dice);

private:
	int valueOfDie;       // the current value of the die (a value of -1 means the die is unInitialized)
	static bool randomInitialized;// the status of the random number generator (common to all instanses)
};


#endif