package upl;

%%
%type int
%line
%column
%char
%class Scanner
%{


    private final int ERROR = 0;
    private final int BEGIN = 1;
    private final int END = 2;
    private final int INT = 3;
    private final int BOOL = 4;
    private final int IF = 5;
    private final int THEN = 6;
    private final int ELSE = 7;
    private final int DO = 8;
    private final int WHILE = 9;
    private final int PRINT = 10;
    private final int ID = 11;
    private final int NUM = 12;
    private final int ASSIGN = 13;
    private final int GTE = 14;
    private final int GT = 15;
    private final int EQUAL = 16;
    private final int PLUS = 17;
    private final int MULT = 18;
    private final int LPAREN = 19;
    private final int RPAREN = 20;
    private final int LBRACE = 21;
    private final int RBRACE = 22;
    private final int SEMICOLON = 23;
    private final int COMMENT = 24;
	private final String[] tokenNames = {
        "ERROR",
        "BEGIN", "END", "INT", "BOOL", "IF", "THEN", "ELSE", "DO", "WHILE", "PRINT",
        "ID", "NUMBER", "ASSIGN", "GTE", "GT", "EQUAL", "PLUS", "MULT", "LPAREN",
        "RPAREN", "LBRACE", "RBRACE", "SEMICOLON", "COMMENT"
    };
    private String Token(int token){
        if (token >= 0 && token <  tokenNames.length) {
            return "<" + tokenNames[token] + ">";
        } else {
            return "UNKNOWN";
        }
    }
    private String Token(int token, String value){
        if (token >= 0 && token < tokenNames.length) {
            return "<" + tokenNames[token] + ", " + value + ">";
        } else {
            return "UNKNOWN";
        }
    }
   public static String incrementString(int number) {
        number += 1; // Tăng giá trị lên 1
        return String.valueOf(number); // Chuyển số nguyên trở lại thành chuỗi
    }

%}

%state MULTILINE_COMMENT
%state SINGLELINE_COMMENT

%eofval{
    System.out.println("EOF"); return 1;
%eofval}
letter 	=  [A-Za-z]
digit  	=  [0-9]

number = {digit}[{digit}]*
identifier= {letter}+{digit}*?
errIdentifier =  {digit}+{letter}+({letter}|{digit})* | {letter}+{digit}+{letter}+({letter} | {digit})*?





%%
"//"    {yybegin(SINGLELINE_COMMENT); return 0;}
<SINGLELINE_COMMENT>[^\n]+    {yybegin(YYINITIAL); System.out.println(Token(COMMENT, yytext())); return 0;}
"/*"            { yybegin(MULTILINE_COMMENT); return 0; }
<MULTILINE_COMMENT>[^*\/]+  {System.out.println(Token(COMMENT, yytext())); return 0;}
<MULTILINE_COMMENT> "*/" { yybegin(YYINITIAL); return 0; }
<YYINITIAL> "begin" {System.out.println(Token(BEGIN)); return 0;}
"end"   {System.out.println(Token(END)); return 0;}
"int"   {System.out.println(Token(INT)); return 0;}
"bool"  {System.out.println(Token(BOOL)); return 0;}
"end"   {System.out.println(Token(END)); return 0;}
"if"    {System.out.println(Token(IF)); return 0;}
"then"  {System.out.println(Token(THEN)); return 0;}
"else"  {System.out.println(Token(ELSE)); return 0;}
"do"    {System.out.println(Token(DO)); return 0;}
"while" {System.out.println(Token(WHILE)); return 0;}
"=="    {System.out.println(Token(EQUAL)); return 0;}
"="     {System.out.println(Token(ASSIGN)); return 0;}
">="    {System.out.println(Token(GTE)); return 0;}
">"     {System.out.println(Token(GT)); return 0;}
"+"     {System.out.println(Token(PLUS)); return 0;}
"*"     {System.out.println(Token(MULT)); return 0;}
"print" {System.out.println(Token(PRINT)); return 0;}
"("     {System.out.println(Token(LPAREN)); return 0;}
")"     {System.out.println(Token(RPAREN)); return 0;}
"{"     {System.out.println(Token(LBRACE)); return 0;}
"}"     {System.out.println(Token(RBRACE)); return 0;}
";"     {System.out.println(Token(SEMICOLON)); return 0;}



{errIdentifier} {System.out.println("Error: <Invalid identifier, " + yytext() + "> at line " + incrementString(yyline) + ", column " + incrementString(yycolumn)); return 0;}
{identifier} {System.out.println(Token(ID, yytext())); return 0;}
{number}    {System.out.println(Token(NUM, yytext())); return 0;}

[ \t\r\n\f] { /* ignore white space. */ }

. { System.out.println("<ILL, " +yytext() + ">"); return 0;}