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

alpha		[a-zA-Z]
digit		[0-9]
alphanum	{alpha}|{digit}

id		{alpha}+{alphanum}*
string		[a-zA-Z0-9!?;.%][a-zA-Z0-9!?;.% ]?+
end		"end/"|"fin"

%%
\n			{ yylineno++; return (ENDLINE); }
[ \t\r]+			/* ignore */;
("rem/"|"//"|"'").*	{ printf("Comment: \033[92m%s\033[0m\n", yytext); };
"cls/"			return (CLS);
"txt/"			return (TXT);

"if/"			return (IF);
"si/"			return (IF);

"alors"			return (THEN);
"then"			return (THEN);

"sinon"			return (ELSE);
"else"			return (ELSE);

":"			return (COLON);
"=="			;
"="			;

"!="			;
"N="			;

">"			;

"!>"			;
"N>"			;

"<"			;
"!<"			;
"N<"			;

"~="			;
"!~="			;
"N~="			;

"@#"{id}		;

{string}		{ yylval.str = strdup(yytext); return (STRING); };

.			return (*yytext);

%%
