package upl;

%%
%type int
%line
%column
%char
%class Scanner
%{

    private String line = "", column = "";
    private String buffer = "";
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
    private final int ROP = 14;
    private final int PLUS = 15;
    private final int MULT = 16;
    private final int LPAREN = 17;
    private final int RPAREN = 18;
    private final int LBRACE = 19;
    private final int RBRACE = 20;
    private final int SEMICOLON = 21;
    private final int COMMENT = 22;
    private final int BOOLEAN = 23;
	private final String[] tokenNames = {
    "ERROR",
    "BEGIN",
    "END",
    "INT",
    "BOOL",
    "IF",
    "THEN",
    "ELSE",
    "DO",
    "WHILE",
    "PRINT",
    "IDENTIFIER",
    "NUMBER",
    "ASSIGN",
    "ROP",
    "PLUS",
    "MULT",
    "LPAREN",
    "RPAREN",
    "LBRACE",
    "RBRACE",
    "SEMICOLON",
    "COMMENT",
    "BOOLEAN"
    };
    private String Token(int token){
        if (token >= 0 && token <  tokenNames.length) {
            return "<" + tokenNames[token] + ", >";
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

%state START_COMMENT
%state IN_SG_LINE_COMMENT
%state IN_ERROR
%state IN_MT_LINE_COMMENT
%state PRE_FINISH_MUL_LINE_COMMENT



%eofval{
    return 1;
%eofval}
letter 	=  [A-Za-z]
digit  	=  [0-9]

number = {digit}[{digit}]*
identifier= {letter}+{digit}*?
errIdentifier =  {digit}+{letter}+({letter}|{digit})* | {letter}+{digit}+{letter}+({letter} | {digit})*?



%%

<PRE_FINISH_MUL_LINE_COMMENT> {
    "/" {yybegin(YYINITIAL); System.out.println(Token(COMMENT, buffer.substring(2, buffer.length() - 1))); buffer = ""; return 0;}
    <<EOF>> {yybegin(YYINITIAL); String buffer2 = "INVALID CHARACTER - " + buffer;System.out.println(Token(ERROR, buffer2) + "at line " + line + " column "+ column); column = ""; line = ""; buffer = ""; return 0;}
    "\n" {buffer += yytext(); return 0;}
    . {
        if(yytext().equals("*")){
            buffer += yytext();
            return 0;
        }
        yybegin(IN_MT_LINE_COMMENT); buffer += yytext(); return 0;
    }
}
<IN_MT_LINE_COMMENT> {
    "*" {
        yybegin(PRE_FINISH_MUL_LINE_COMMENT); buffer += yytext(); return 0;
        
        }
    "\n" {buffer += yytext(); return 0;}
    <<EOF>> {yybegin(YYINITIAL); String buffer2 = "INVALID CHARACTER - " + buffer ; System.out.println(Token(ERROR, buffer2) + " at line " + line + " column "+ column);column = ""; line  = ""; buffer = ""; return 0;}

    . { buffer += yytext();return 0;}
    
}

<IN_SG_LINE_COMMENT> {
    "\n" {yybegin(YYINITIAL); System.out.println(Token(COMMENT, buffer)); buffer = ""; return 0;}
    <<EOF>> {yybegin(YYINITIAL); System.out.println(Token(COMMENT, buffer)); buffer = ""; return 0;}
    . { buffer += yytext();return 0;}
}
<IN_ERROR> {
    "\n" {yybegin(YYINITIAL); String buffer2 = "INVALID CHARACTER - " + buffer; System.out.println(Token(ERROR, buffer2) + "at line " + line + " column "+ column);column = ""; line  = ""; buffer = ""; return 0;}
    <<EOF>> {yybegin(YYINITIAL); String buffer2 = "INVALID CHARACTER - " + buffer; System.out.println(Token(ERROR, buffer2) + "at line " + line + " column "+ column);column = ""; line  = ""; buffer = ""; return 0;}

    . { buffer += yytext();return 0;}
}

<START_COMMENT> {
    "\n" {System.out.println(buffer); buffer = ""; yybegin(YYINITIAL); return 0;}
    "/" {yybegin(IN_SG_LINE_COMMENT); buffer = ""; return 0;}
    "*" {yybegin(IN_MT_LINE_COMMENT); buffer += yytext() ;return 0;}
    .   {yybegin(IN_ERROR); buffer += yytext(); return 0;}

}
<YYINITIAL>"/"    {
    line = incrementString(yyline);
    column = incrementString(yycolumn);
    buffer += yytext();
    yybegin(START_COMMENT);  return 0;  
}


<YYINITIAL> "begin" {System.out.println(Token(BEGIN)); return 0;}
<YYINITIAL> "end"   {System.out.println(Token(END)); return 0;}
<YYINITIAL> "int"   {System.out.println(Token(INT)); return 0;}
<YYINITIAL> "bool"  {System.out.println(Token(BOOL)); return 0;}
<YYINITIAL> "end"   {System.out.println(Token(END)); return 0;}
<YYINITIAL> "if"    {System.out.println(Token(IF)); return 0;}
<YYINITIAL> "then"  {System.out.println(Token(THEN)); return 0;}
<YYINITIAL> "else"  {System.out.println(Token(ELSE)); return 0;}
<YYINITIAL> "do"    {System.out.println(Token(DO)); return 0;}
<YYINITIAL> "while" {System.out.println(Token(WHILE)); return 0;}
<YYINITIAL> "=="    {System.out.println(Token(ROP, yytext())); return 0;}
<YYINITIAL> ">="    {System.out.println(Token(ROP, yytext())); return 0;}
<YYINITIAL> "="     {System.out.println(Token(ASSIGN)); return 0;}
<YYINITIAL> ">"     {System.out.println(Token(ROP, yytext())); return 0;}
<YYINITIAL> "true"  {System.out.println(Token(BOOLEAN, yytext())); return 0;}
<YYINITIAL> "false" {System.out.println(Token(BOOLEAN, yytext())); return 0;}
<YYINITIAL> "+"     {System.out.println(Token(PLUS)); return 0;}
<YYINITIAL> "*"     {System.out.println(Token(MULT)); return 0;}
<YYINITIAL> "print" {System.out.println(Token(PRINT)); return 0;}
<YYINITIAL> "("     {System.out.println(Token(LPAREN)); return 0;}
<YYINITIAL> ")"     {System.out.println(Token(RPAREN)); return 0;}
<YYINITIAL> "{"     {System.out.println(Token(LBRACE)); return 0;}
<YYINITIAL> "}"     {System.out.println(Token(RBRACE)); return 0;}
<YYINITIAL> ";"     {System.out.println(Token(SEMICOLON)); return 0;}



<YYINITIAL> {errIdentifier} {System.out.println("<Error, INVALID IDENTIFIER - " + yytext() + "> at line " + incrementString(yyline) + ", column " + incrementString(yycolumn)); return 0;}
<YYINITIAL> {identifier} {System.out.println(Token(ID, yytext())); return 0;}
<YYINITIAL> {number}    {System.out.println(Token(NUM, yytext())); return 0;}

[ \t\r\n\f] { /* ignore white space. */ }

 . { System.out.println("<ILL, " +yytext() + ">"); return 0;}