typedef struct
{
    int ERROR;
    int BEGIN;
    int END;
    int INT;
    int BOOL;
    int IF;
    int THEN;
    int ELSE;
    int DO;
    int WHILE;
    int PRINT;
    int ID;
    int NUM;
    int ASSIGN;
    int GTE;
    int GT;
    int EQUAL;
    int PLUS;
    int MULT;
    int LPAREN;
    int RPAREN;
    int LBRACE;
    int RBRACE;
    int SEMICOLON;
    int COMMENT;
} Sym;
char *SymNames[] = {
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
    "ID",
    "NUM",
    "ASSIGN",
    "GTE",
    "GT",
    "EQUAL",
    "PLUS",
    "MULT",
    "LPAREN",
    "RPAREN",
    "LBRACE",
    "RBRACE",
    "SEMICOLON",
    "COMMENT"};
char *Keywords[] = {"begin", "end", "int", "bool", "if", "then", "else", "do", "while", "print"};
Sym sym = {
    .ERROR = 0,
    .BEGIN = 1,
    .END = 2,
    .INT = 3,
    .BOOL = 4,
    .IF = 5,
    .THEN = 6,
    .ELSE = 7,
    .DO = 8,
    .WHILE = 9,
    .PRINT = 10,
    .ID = 11,
    .NUM = 12,
    .ASSIGN = 13,
    .GTE = 14,
    .GT = 15,
    .EQUAL = 16,
    .PLUS = 17,
    .MULT = 18,
    .LPAREN = 19,
    .RPAREN = 20,
    .LBRACE = 21,
    .RBRACE = 22,
    .SEMICOLON = 23,
    .COMMENT = 24};
