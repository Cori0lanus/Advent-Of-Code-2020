#include <stdio.h>
#include <stdlib.h>

int* readInput(int length) {
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    int* input = (int*)malloc(sizeof(int) * length);

    fp = fopen("../../src/input_file.txt", "r");

    if (fp == NULL) {
        printf("Failed To Open File!\n");
        exit(EXIT_FAILURE);
    }

    int onLine = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
    	input[onLine] = (int)strtol(line, NULL, 10);
    	onLine++;
    }

    fclose(fp);
    if (line)
    	free(line);

    return input;
}

int main() {
	int length = 200;
	int* input = readInput(length);

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (input[i] + input[j] == 2020) {
				printf("%d\n", input[i] * input[j]); // 100419
				return 0;
			}
		}
	}
	printf("Answer Not Found");
	return 1;
}