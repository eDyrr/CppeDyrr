%{
    #include<iostream>
    #include<string>
%}

TAB     [\t ]
NEWLINE [\n ]
DELIM   {TAB}{NEWLINE}
WS      {DELIM}+
DIGIT   [0-9]
LETTER  [a-zA-Z]
STRING  [a-zA-Z]+
ID      {LETTER}({LETTER}|{DIGIT})*
NUMBER  {DIGIT}+(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?

%%
{STRING} { }
{WS}     {/*DO NOTHING*/}
if       { }
then     { }
else     { }
{ID}     { }
{NUMBER} { }
"<"      { }
">"      { }
"="      { }
"<="     { }
">="     { }
"<>"     { }
%%

int main()
{
    yylex() ;
    return 0 ; 
}