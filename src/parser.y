%{
#include <stdio.h>

extern int	yylex();
extern int	yylineno;

int	yyerror(char const *s);
%}

%define parse.lac full
%define parse.error verbose

%token CLS "cls/"
%token TXT "txt/"

%token STRING
%token ENDLINE

%type <str> STRING

%union
{
	char	*str;
}

%start entry

%%
entry:	/* empty */;
     	| stmts
	;

stmts: /* empty */;
     	| stmt ENDLINE stmts;
	| stmt
	;

stmt:	txt;
    	| CLS
    	| ENDLINE
	;

txt:	TXT STRING	{ printf("%s\n", $2); };
   	| TXT		{ putchar('\n'); };
	;

%%

int	yyerror(char const *s)
{
	fprintf(stderr, "[Error] l%d: %s\n", yylineno, s);

	return (0);
}
