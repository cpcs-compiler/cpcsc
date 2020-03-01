%{
#include <stdio.h>
#include "node.h"
#include "error.h"

extern int	yylex();
extern int	yylineno;

int	yyerror(char const *s);
int	error_count;
%}

%define parse.lac full
%define parse.error verbose

%token CLS "cls/"
%token TXT "txt/"

%token IF "if/"
%token THEN "then"
%token ELSE "else"

%token COLON ":"

%token STRING
%token ENDLINE

%type <node> entry
%type <node> stmts stmt
%type <node> stmt_txt
%type <str> STRING

%union
{
	char	*str;
	struct node_s	*node;
}

%start entry

%%
entry:
	stmts			{ dump_nodes($1); }
	| optional_linebreak	{ NULL; }
;

linebreak:
	ENDLINE
	| linebreak ENDLINE
;

optional_linebreak: /* empty */
	| linebreak
;

stmts:
	stmts linebreak stmt
	{
		node_stmts_t *tmp = (node_stmts_t *)$1;
		$$ = new_node_stmts(tmp->stmts, tmp->len, $3);
	}
	| optional_linebreak stmt linebreak
	{
		$$ = new_node_stmts(NULL, 0, $2);
	}
;

stmt:	stmt_txt		{ $$ = $1; }
//    	| CLS
//	| stmt_if
//	| ENDLINE
;

stmt_txt:
       	TXT STRING
	{
		node_t *tmp = new_node_str($2);
		$$ = new_node_txt(tmp);
	}
   	| TXT
	{
		$$ = new_node_txt(NULL);
	}
;

/*
stmt_if:
	IF THEN COLON stmt 
	| IF THEN COLON ENDLINE stmts ENDLINE
;
*/
%%

int	yyerror(char const *s)
{
	error_count++;
	error("l%d: %s", yylineno, s);

	return (0);
}
