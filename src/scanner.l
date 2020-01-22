%{
/* remove "error: ‘input’ defined but not used" */
#define YY_NO_INPUT

#include <stdio.h>
#include "parser.h"
%}

%option noyywrap
%option caseless
%option nounput

%%
\n			{ yylineno++; return (ENDLINE); }
[ \t]+			/* ignore */;
("rem/"|"//"|"'").*	/* comment */;
"cls/"			return (CLS);
"txt/"			return (TXT);

[a-zA-Z0-9!?;.% ]+	return (STRING);

.			return (*yytext);

%%
