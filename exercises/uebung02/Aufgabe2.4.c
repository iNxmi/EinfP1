#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
 	if (argc != 3) {
		printf("This Program must be called with exactly two arguments specifying the name of the input and output file. Terminating.\n");
		return 1;
	}

	FILE *inputFilePointer = fopen(argv[1], "r");
	if (inputFilePointer == NULL) {
		fprintf(stderr, "Can't open input file!\n");
		return 1;
	}

	FILE *outputFilePointer = fopen(argv[2], "w");
	if (outputFilePointer == NULL) {
		fprintf(stderr, "Can't open output file!\n");
		return 1;
	}

	int divisor = 0;
	int number = 0;
	int isFirstIteration = true;
	while(fscanf(inputFilePointer, "%d", &number) > 0) {
		if (isFirstIteration) {
			divisor = number;
			isFirstIteration = false;
			continue;
		}

		if (number % divisor != 0)
			continue;

		fprintf(outputFilePointer, "%i\n", number);
	}

	fclose(inputFilePointer);
	fclose(outputFilePointer);

	return 0;
}
