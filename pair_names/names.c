#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>  // For uint32_t
#include "names.h"

#define MAX_NAME_LENGTH 100
#define MAX_NAMES 1000

char names[MAX_NAMES][MAX_NAME_LENGTH];
int numNames = 0;
int pairedIndices[MAX_NAMES];
uint32_t lastOutputChecksum = 0;

// Function to calculate a simple checksum for a string
uint32_t calculateChecksum(const char *str) {
    uint32_t checksum = 0;
    while (*str) {
        checksum = (checksum << 5) + *str;
        str++;
    }
    return checksum;
}

void loadNamesFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", names[numNames]) != EOF) {
        pairedIndices[numNames] = -1;
        numNames++;
    }

    fclose(file);
}

void reset() {
    for (int i = 0; i < numNames; i++) {
        pairedIndices[i] = -1;
    }
    lastOutputChecksum = 0;
}

void pairNames() {
    srand(time(NULL));

    printf("Pairs:\n");

    uint32_t currentOutputChecksum = 0;

    while (1) {
        int index1 = rand() % numNames;
        int index2 = rand() % numNames;

        if (index1 != index2 &&
            pairedIndices[index1] == -1 &&
            pairedIndices[index2] == -1) {

            pairedIndices[index1] = index2;
            pairedIndices[index2] = index1;

            currentOutputChecksum ^= calculateChecksum(names[index1]);
            currentOutputChecksum ^= calculateChecksum(names[index2]);

            printf("%s and %s\n", names[index1], names[index2]);
        }

        int allPaired = 1;
        for (int i = 0; i < numNames; i++) {
            if (pairedIndices[i] == -1) {
                allPaired = 0;
                break;
            }
        }

        if (allPaired)
            break;
    }

    if (currentOutputChecksum != lastOutputChecksum) {
        lastOutputChecksum = currentOutputChecksum;
    } else {
        printf("No new pairs to display.\n");
    }

    printf("\n");
}

void listUnpairedNames() {
    printf("Unpaired names:\n");

    for (int i = 0; i < numNames; i++) {
        if (pairedIndices[i] == -1) {
            printf("%s\n", names[i]);
        }
    }
}
