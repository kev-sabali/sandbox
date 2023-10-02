#include <stdio.h>
#include "names.h"

int main() {
    // Load names from the CSV file
    loadNamesFromFile("names.csv");

    // Pair and list unpaired names
    pairNames();
    listUnpairedNames();

    return 0;
}
