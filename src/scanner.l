%{
/* remove "error: ‘input’ defined but not used" */
#define YY_NO_INPUT

#include <stdio.h>
#include <string.h>
#include "parser.h"
%}

%option noyywrap
%option caseless
%option nounput

string	[a-zA-Z0-9!?;.%][a-zA-Z0-9!?;.% ]?+

%%
\n			{ yylineno++; return (ENDLINE); }
[ \t\r]+			/* ignore */;
("rem/"|"//"|"'").*	{ printf("Comment: \033[92m%s\033[0m\n", yytext); };
"cls/"			return (CLS);
"txt/"			return (TXT);

{string}		{ yylval.str = strdup(yytext); return (STRING); };

.			return (*yytext);

%%
