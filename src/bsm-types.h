#ifndef BSM_TYPES_H
#define BSM_TYPES_H

#include <stdint.h>

struct symbol_t
{
	char* name;
	short value;
};

struct symtab_t
{
	struct symbol_t symbol;
	struct symtab_t* next;
};

union YYSTYPE
{
	struct symbol_t symbol;
	char* text;
	short value;
};

#endif
