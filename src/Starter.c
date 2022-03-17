#include <stdio.h>
#include <stdlib.h>
#include "Executor.h"

int main(int argc, char *argv[]) {
  	// get argument from user using argv[1]
	// and turn into an int using atoi()
	int seed = atoi(argv[1]);

	// set the seed and use srand() then print out to user
	srand(seed);
	printf("[Starter]: With seed: %d\n", seed);

	// invoke executor
	double running_ratio = get_running_ratio();
	printf("[Starter]: Running ratio: %f\n", running_ratio);
}