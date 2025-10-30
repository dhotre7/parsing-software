#ifndef LOOKUP_H
#define LOOKUP_H

#include <stdio.h>
#include <string.h>


// Keywords
const char* keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for",
    "goto", "if", "inline", "int", "long", "register", "restrict",
    "return", "short", "signed", "sizeof", "static", "struct",
    "switch", "typedef", "union", "unsigned", "void", "volatile", "while",
    "_Alignas", "_Alignof", "_Atomic", "_Bool", "_Complex", "_Generic",
    "_Imaginary", "_Noreturn", "_Static_assert", "_Thread_local",
    NULL
};

// Standard Library Headers
const char* headers[] = {
    "stdio.h", "stdlib.h", "string.h", "math.h", "ctype.h",
    "stdbool.h", "time.h", "assert.h", "limits.h", "float.h",
    "signal.h", "setjmp.h", "stdarg.h", "errno.h", "stddef.h",
    "stdint.h", "locale.h", "wchar.h", "wctype.h",
    NULL
};

// Operators
const char* operators[] = {
    "+", "-", "*", "/", "%", "++", "--",
    "=", "+=", "-=", "*=", "/=", "%=",
    "==", "!=", "<", ">", "<=", ">=",
    "&&", "||", "!", "&", "|", "^", "~", "<<", ">>",
    "?", ":", 
    NULL
};

//  Delimiters
const char* symbols[] = {
    "(", ")", "{", "}", "[", "]",
    ";", ",", ".", "#",
    "<", ">", "\"", "'", "\\",
    NULL
};


// Check if a word is in a given string array
int inList(const char* word, const char* list[]) {
    for (int i = 0; list[i] != NULL; i++) {
        if (strcmp(word, list[i]) == 0)
            return 1;
    }
    return 0;
}

// Check if a word is a keyword
int isKeyword(const char* word) {
    return inList(word, keywords);
}

// Check if word is a standard header
int isHeader(const char* word) {
    return inList(word, headers);
}

// Check if token is an operator
int isOperator(const char* token) {
    return inList(token, operators);
}

// Check if token is a symbol
int isSymbol(const char* token) {
    return inList(token, symbols);
}

// Check if token is an identifier
// (Starts with letter or underscore, followed by letters/digits/underscores)
int isIdentifier(const char* token) {
    if (!( (token[0] >= 'a' && token[0] <= 'z') ||
           (token[0] >= 'A' && token[0] <= 'Z') ||
           token[0] == '_' ))
        return 0;

    for (int i = 1; token[i] != '\0'; i++) {
        if (!( (token[i] >= 'a' && token[i] <= 'z') ||
               (token[i] >= 'A' && token[i] <= 'Z') ||
               (token[i] >= '0' && token[i] <= '9') ||
               token[i] == '_' ))
            return 0;
    }
    return 1;
}

#endif

