#include <stdio.h>
#include <stdlib.h>
#include "lookup.h"
#include "token.h"

// Function to read entire file into a string
char* readFile(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        perror("Error opening file");
        exit(1);
    }

    fseek(f, 0, SEEK_END); //moves the f pointer to the end of file
    long size = ftell(f); // return pos of f pointer which is last byte
    rewind(f); // moves back pointer to start 

    char* buffer = malloc(size + 1); // buffer allocation to store the code
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(f);
        exit(1);
    }

    fread(buffer, 1, size, f); //reading each byte character into the buffer
    buffer[size] = '\0';
    fclose(f);

    return buffer;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    char* code = readFile(filename);
	tokenize(code);
    printTokens();
	freeTokens();
    // You can now pass 'code' to your lexer/parser
    free(code);
    return 0;
}

