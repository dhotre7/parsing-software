#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lookup.h"   
#define MAX_TOKENS 1000

//  struct for tokens
typedef struct {
    char* type;   
    char* value; 
} Token;



Token* tklist[MAX_TOKENS]; // array to store token list
int n = 0;


//  tokenize function
void tokenize(char *code){
	int i = 0;
	while(code[i] != '\0'){
		if(code[i] == ' ' || code[i] == '\n'){
			i++;
			continue;
		}


		
		//check for keyword or indentifier
		if (code[i] == '_' || (code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z')) {
			int j = 0;
			char token[100];

			while ((code[i] == '_' || (code[i] >= 'a' && code[i] <= 'z') ||
				   (code[i] >= 'A' && code[i] <= 'Z') || (code[i] >= '0' && code[i] <= '9')) &&
				   code[i] != '\0') {
				 token[j++] = code[i];
			     i++;
			}

			token[j] = '\0';

			//  check if it's a keyword or identifier
			if (isKeyword(token)){
				 tklist[n] = (Token*) malloc(sizeof(Token));
				 tklist[n]->type = strdup("KEYWORD");
				 tklist[n]->value = strdup(token);
				 n++;
			}else{
				tklist[n] = (Token*) malloc(sizeof(Token));
				tklist[n]->type = strdup("IDENTIFIER");
				tklist[n]->value = strdup(token);
				n++;

			}
		}




		//check for header files
		if (code[i] == '#') {
			int j = 0;
			char token[200];

		    while (code[i] != '\n' && code[i] != '\0') {
		        token[j++] = code[i++];
			}
			token[j] = '\0';

			tklist[n] = (Token*) malloc(sizeof(Token));
			tklist[n]->type = strdup("HEADER");
			tklist[n]->value = strdup(token);
			n++;

		}




		// check for number
	    if (code[i] >= '0' && code[i] <= '9') {
			int j = 0;
			char token[50];

			while ((code[i] >= '0' && code[i] <= '9') || code[i] == '.') {
				token[j++] = code[i++];
			}
			token[j] = '\0';

			tklist[n] = (Token*) malloc(sizeof(Token));
			tklist[n]->type = strdup("NUMBER");
			tklist[n]->value = strdup(token);
			n++;

		}




		//check for  operators
		if (strchr("+-*/%=!<>&|", code[i])) {
			char token[3];
			int j = 0;

			token[j++] = code[i++];

			// Check for possible two-character operators
			if ((token[0] == '+' && code[i] == '+') || 
				(token[0] == '-' && code[i] == '-') || 
				(token[0] == '=' && code[i] == '=') || 
				(token[0] == '!' && code[i] == '=') || 
				(token[0] == '<' && code[i] == '=') || 
				(token[0] == '>' && code[i] == '=') || 
				(token[0] == '&' && code[i] == '&') || 
				(token[0] == '|' && code[i] == '|')) {
				token[j++] = code[i++];
			}

			token[j] = '\0';
			tklist[n] = (Token*) malloc(sizeof(Token));
			tklist[n]->type = strdup("OPERATOR");
		    tklist[n]->value = strdup(token);
			n++;

		}


		//check for separators
		if (strchr(";,.:(){}[]", code[i])) {
			char token[2];
			token[0] = code[i++];
			token[1] = '\0';

			tklist[n] = (Token*) malloc(sizeof(Token));
			tklist[n]->type = strdup("SEPARATOR");
			tklist[n]->value = strdup(token);
			n++;

		}


		//check for strin_literal
		if (code[i] == '"') {
			int j = 0;
			char token[200];

			i++; 

			while (code[i] != '"' && code[i] != '\0') {
					token[j++] = code[i++];
			}

			token[j] = '\0';
			if (code[i] == '"') i++;

			tklist[n] = (Token*) malloc(sizeof(Token));
			tklist[n]->type = strdup("STRING_LITERAL");
			tklist[n]->value = strdup(token);
			n++;

		}
	}	

}


void printTokens() {
    printf("\n===== TOKEN LIST =====\n");
    for (int i = 0; i < n; i++) {
        if (tklist[i] != NULL) {
            printf("Token %d -> Type: %-15s | Value: %s\n", i + 1, tklist[i]->type, tklist[i]->value);
        }
    }
    printf("=======================\n");
}
void freeTokens() {
    for (int i = 0; i < n; i++) {
        free(tklist[i]->type);
        free(tklist[i]->value);
        free(tklist[i]);
    }
}
	
#endif // TOKEN_H
