package upl;


%%
%type int
%line
%column
%char
%class Scanner
%{
    int hasPreNumber = 0;
    public static String incrementString(int number) {
        number += 1; // Tăng giá trị lên 1
        return String.valueOf(number); // Chuyển số nguyên trở lại thành chuỗi
    }

	
%}

%eofval{
    System.out.println("EOF"); return 1;
%eofval}

letter 	=  [A-Za-z]
digit  	=  [0-9]
number = {digit}[{digit}]*
identifier = {letter}{digit}[{letter}|{digit}]*
errIden = {letter}{letter}+[{letter}|{digit}]* | {digit}+{letter}+[{letter} | {digit}]* | {letter}


%%
"if" { System.out.println("<IF, >"); hasPreNumber = 0; return 0;}
"then" {System.out.println("<THEN, >"); hasPreNumber = 0; return 0;}
"else" {System.out.println("<ELSE, >"); hasPreNumber = 0; return 0;}
"+" {System.out.println("<PLUS, >"); return 0;}
">=" { System.out.println("<ROP, >= >"); return 0;}
">" { System.out.println("<ROP, > >"); return 0;}
"=" { if (hasPreNumber == 1) {
    System.out.print("Error: <Invalid Ass>");
    System.out.println(" at line " + incrementString(yyline) + ", column " + incrementString(yycolumn));

} else {
    System.out.println("<ASS, >");
}
return 0;}
";" { System.out.println("<SEM, >\n" ); hasPreNumber = 0; return 0; }
{errIden} {System.out.println("Error: <Invalid identifier, " + yytext() + "> at line " + incrementString(yyline) + ", column " + incrementString(yycolumn)); hasPreNumber = 0; return 0;}
{identifier} { System.out.println("<IDEN, "+ yytext() + "> "); hasPreNumber = 0; return 0;}
{number} { System.out.println("<NUM, "  + yytext() + "> "); hasPreNumber = 1; return 0;}
[ \t\r\n\f] { /* ignore white space. */ }
. { System.out.println("<ILL, " +yytext() + ">"); return 0;}