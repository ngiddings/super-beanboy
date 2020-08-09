%option noyywrap

%{
#include "bsm.h"
#include "bsm-types.h"
%}

%%

#.*?
" "|\t
=	|
\n	return yytext[0];

[0-9]+			yylval.value = atoi(yytext); return VALUE;
\-[0-9]+		yylval.value = atoi(yytext); return VALUE;
0x[0-9A-Fa-f]+ 		yylval.value = strtol(yytext + 2, NULL, 16); return VALUE;
0b[0-1]+		yylval.value = strtol(yytext + 2, NULL, 2); return VALUE;

[A-Za-z0-9]+ {
	yylval.text = malloc(yyleng + 1);
	memcpy(yylval.text, yytext, yyleng);
	yylval.text[yyleng] = '\0';
	return TEXT;
}
