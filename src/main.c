#include <stdbool.h>
#include <stdio.h>

#include "util.h"

const char *usage = "medusa filepath?\n";

int main(int argc, char *argv[]) {
    bool is_file_input = false;
    FILE *input = stdin;

    if (argc > 1) {
        if (argc > 2) exit_print(1, usage);

        is_file_input = true;

        input = fopen(argv[1], "r");

        if (!input) exit_print(2, "provided filepath invalid\n");
    }


    if (is_file_input) fclose(input);

    return 0;
}