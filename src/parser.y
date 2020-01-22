%{
#include <stdio.h>

extern int	yylex();
extern int	yylineno;

int	yyerror(char const *s);
%}

%define parse.lac full
%define parse.error verbose

%token CLS
%token TXT

%token STRING
%token ENDLINE

%start entry

%%
entry:	/* empty */;
     	| ENDLINE
     	| TXT ENDLINE
     	| TXT STRING ENDLINE	{ printf("ok\n"); };
	;

%%

int	yyerror(char const *s)
{
	fprintf(stderr, "[Error] l%d: %s\n", yylineno, s);

	return (0);
}
