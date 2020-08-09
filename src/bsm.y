%{
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "bsm-types.h"

int yylex (void);
void yyerror (struct symtab_t* symtab, char const *);
	
%}

%parse-param {struct symtab_t* symtab}

%define api.value.type {union YYSTYPE}

%token <text> TEXT
%token <value> VALUE

%nterm <symbol> sym

%%


input: %empty;
input: input line;

line: '\n';

line: sym '\n'
{
        symtab->symbol.name = $1.name;
	symtab->symbol.value = $1.value;
	symtab->next = (struct symtab_t*) malloc(sizeof(struct symtab_t));
	symtab = symtab->next;
	symtab->next = NULL;
	symtab->symbol.name = NULL;
};

sym: TEXT '=' VALUE
{
	$$.name = (char*) malloc(strlen($1) + 1);
	strcpy($$.name, $1);
	$$.value = $3;
};

%%

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void yyerror(struct symtab_t* symtab, char const *s)
{
	fprintf (stderr, "%s\n", s);
}

int main()
{
	struct symtab_t symtab;
	symtab.next = NULL;
	symtab.symbol.name = NULL;
        if(yyparse(&symtab))
	{
		printf("\n");
		exit(0);
	}

	struct symtab_t* node = &symtab;
	while(node != NULL)
	{
		printf("symbol \"%s\" with value %i\n", node->symbol.name, node->symbol.value);
		node = node->next;
	}
}
