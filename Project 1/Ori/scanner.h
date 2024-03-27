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
    int ROP;
    int PLUS;
    int MULT;
    int LPAREN;
    int RPAREN;
    int LBRACE;
    int RBRACE;
    int SEMICOLON;
    int COMMENT;
    int BOOLEAN;
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
    "BOOLEAN"};
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
    .ROP = 14,
    .PLUS = 15,
    .MULT = 16,
    .LPAREN = 17,
    .RPAREN = 18,
    .LBRACE = 19,
    .RBRACE = 20,
    .SEMICOLON = 21,
    .COMMENT = 22,
    .BOOLEAN = 23};
