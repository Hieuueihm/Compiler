#include <stdio.h>
#include "scanner.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int symLength = sizeof(SymNames) / sizeof(SymNames[0]);
int keywordLength = sizeof(Keywords) / sizeof(Keywords[0]);
char id[100], num[100], special[100];

int isKeyword(char buff[])
{
    for (int i = 0; i < keywordLength; i++)
    {
        if (strcmp(buff, Keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
char *toUpper(char buff[])
{
    int i = 0;
    while (buff[i] != '\0')
    {
        buff[i] = toupper(buff[i]);
        i++;
    }
    return buff;
}
int isBoolean(char buff[])
{
    if (strcmp(buff, "false") == 0 || strcmp(buff, "true") == 0)
    {
        return 1;
    }
    return 0;
}
int main()
{
    FILE *f1, *f2;
    f1 = fopen("input.upl", "r");
    f2 = fopen("output.txt", "w");
    char c;
    int state = 0;
    int i = 0, j = 0, k = 0;
    int line = 1, column = 1;
    int cLine = 0, cColumn = 0;
    long position = 0;
    char prevC;
    do
    {
        c = fgetc(f1);
        long currentPosition = ftell(f1);
        if (c == '\n' && prevC != c)
        {
            line += 1;
            column = 1;
        }
        else if (currentPosition != position)
        {

            column += 1;
        }
        position = ftell(f1);

        switch (state)
        {
        case 0:
            if (c == ' ' || c == '\n')
            {
                state = 0;
            }
            if (c == '>')
            {
                state = 13;
                special[k++] = c;
            }
            if (c == ';')
            {
                state = 31;
            }
            if (c == '*')
            {
                state = 29;
            }
            if (c == '+')
            {
                state = 30;
            }
            if (c == '/')
            {
                state = 23;
            }
            if (c == '(')
            {
                state = 19;
            }
            if (c == ')')
            {
                state = 20;
            }
            if (c == '{')
            {
                state = 21;
            }
            if (c == '}')
            {
                state = 22;
            }
            if (c == '=')
            {
                state = 16;
            }
            if (isalpha(c))
            {
                state = 1;
                id[i++] = c;
            }
            if (isdigit(c))
            {
                state = 9;
                num[j++] = c;
            }
            break;

        case 1:

            if (isalpha(c))
            {
                id[i++] = c;
                state = 1;
            }
            else if (isdigit(c))
            {
                id[i++] = c;
                state = 2;
            }
            else
            {
                state = 6;
                ungetc(c, f1);
            }
            break;
        case 2:
            if (isdigit(c))
            {
                id[i++] = c;
                state = 2;
            }
            else if (isalpha(c))
            {
                id[i++] = c;
                state = 3;
            }
            else
            {
                state = 5;
                ungetc(c, f1);
            }
            break;
        case 3:
            if (isalpha(c) || isdigit(c))
            {
                id[i++] = c;
                state = 3;
            }
            else
            {
                state = 4;
                ungetc(c, f1);
            }
            break;
        case 4:
            fprintf(f2, "<%s, %s - %s> line %d column %d\n", SymNames[sym.ERROR], "INVALID IDENTIFIER", id, line, column - strlen(id) - 1);
            state = 0;
            ungetc(c, f1);
            memset(id, 0, sizeof(id));
            i = 0;
            break;
        case 5:
            fprintf(f2, "<%s, %s>\n", SymNames[sym.ID], id);
            state = 0;
            ungetc(c, f1);
            memset(id, 0, sizeof(id));
            i = 0;
            break;
        case 6:
            if (isKeyword(id))
            {
                state = 7;
            }
            else if (isBoolean(id))
            {
                state = 35;
            }
            else
            {
                state = 8;
            }
            ungetc(c, f1);

            break;
        case 7:
            fprintf(f2, "<%s, >\n", toUpper(id));
            memset(id, 0, sizeof(id));
            state = 0;
            i = 0;
            ungetc(c, f1);
            break;
        case 8:
            fprintf(f2, "<%s, %s>\n", SymNames[sym.ID], id);
            memset(id, 0, sizeof(id));
            state = 0;
            i = 0;
            ungetc(c, f1);
            break;
        case 9:
            if (isdigit(c))
            {
                state = 9;
                num[j++] = c;
            }
            else if (isalpha(c))
            {
                state = 10;
                num[j++] = c;
            }
            else
            {
                state = 12;
                ungetc(c, f1);
            }
            break;
        case 10:
            if (isalnum(c))
            {
                state = 10;
                num[j++] = c;
            }
            else
            {
                state = 11;
                ungetc(c, f1);
            }
            break;
        case 11:
            fprintf(f2, "<%s, %s - %s> line %d column %d\n", SymNames[sym.ERROR], "INVALID IDENTIFIER", num, line, column - strlen(num) - 1);
            state = 0;
            ungetc(c, f1);
            memset(num, 0, sizeof(num));
            j = 0;
            break;
        case 12:
            fprintf(f2, "<%s, %s>\n", SymNames[sym.NUM], num);
            state = 0;
            ungetc(c, f1);
            memset(num, 0, sizeof(num));
            j = 0;
            break;
        case 13:
            if (c == '=')
            {
                state = 14;
                special[k++] = c;
            }
            else
            {
                state = 15;
            }
            ungetc(c, f1);

            break;
        case 14:
            fprintf(f2, "<%s, %s>\n", SymNames[sym.ROP], ">=");
            ungetc(c, f1);
            memset(special, 0, sizeof(special));
            k = 0;
            state = 0;
            break;
        case 15:
            fprintf(f2, "<%s, %s>\n", SymNames[sym.ROP], ">");
            ungetc(c, f1);
            memset(special, 0, sizeof(special));
            k = 0;
            state = 0;
            break;
        case 16:
            if (c == '=')
            {
                state = 17;
            }
            else
            {
                state = 18;
                ungetc(c, f1);
            }
            break;
        case 17:
            fprintf(f2, "<%s, %s>\n", SymNames[sym.ROP], "==");
            ungetc(c, f1);
            state = 0;
            break;

        case 18:
            fprintf(f2, "<%s, >\n", SymNames[sym.ASSIGN]);
            ungetc(c, f1);
            state = 0;
            break;
        case 19:
            fprintf(f2, "<%s, >\n", SymNames[sym.LPAREN]);
            ungetc(c, f1);
            state = 0;
            break;
        case 20:
            fprintf(f2, "<%s, >\n", SymNames[sym.RPAREN]);
            ungetc(c, f1);
            state = 0;
            break;
        case 21:
            fprintf(f2, "<%s, >\n", SymNames[sym.LBRACE]);
            ungetc(c, f1);
            state = 0;
            break;
        case 22:
            fprintf(f2, "<%s, >\n", SymNames[sym.RBRACE]);
            ungetc(c, f1);
            state = 0;
            break;
        case 23:
            cLine = line;
            cColumn = column;
            if (c == EOF)
            {
                state = 33;
                c = ' ';
            }
            else if (c == '/')
            {
                state = 24;
            }
            else if (c == '*')
            {
                state = 26;
            }
            else if (c != '\n')
            {
                special[k++] = '/';
                special[k++] = c;
                state = 32;
            }
            else if (c == '\n')
            {
                state = 33;
                special[k++] = '/';
            }
            break;

        case 24:
            if (c != '\n')
            {
                special[k++] = c;
                state = 24;
            }
            else if (c == '\n')
            {
                state = 25;
            }
            break;

        case 25:
            fprintf(f2, "<%s, %s>\n", SymNames[sym.COMMENT], special);
            state = 0;
            ungetc(c, f1);
            memset(special, 0, sizeof(special));
            k = 0;
            break;
        case 26:
            if (c == EOF)
            {
                state = 34;
                c = ' ';
            }
            else if (c != '*')
            {
                special[k++] = c;
                state = 26;
            }
            else if (c == '*')
            {
                state = 27;
                special[k++] = c;
            }

            break;
        case 27:
            if (c == EOF)
            {
                state = 26;
                c = ' ';
            }
            else if (c == '*')
            {
                special[k++] = c;
                state = 27;
            }
            else if (c == '/')
            {
                state = 28;
                c == ' ';
            }
            else if (c != '/')
            {
                state = 26;
                special[k++] = c;
            }
            break;
        case 28:
            special[k - 1] = '\0';
            fprintf(f2, "<%s, %s>\n", SymNames[sym.COMMENT], special);
            state = 0;
            ungetc(c, f1);
            memset(special, 0, sizeof(special));
            k = 0;
            break;
        case 29:
            fprintf(f2, "<%s, >\n", SymNames[sym.MULT]);
            state = 0;
            ungetc(c, f1);
            break;
        case 30:
            fprintf(f2, "<%s, >\n", SymNames[sym.PLUS]);
            state = 0;
            ungetc(c, f1);
            break;
        case 31:
            fprintf(f2, "<%s, >\n", SymNames[sym.SEMICOLON]);
            state = 0;
            ungetc(c, f1);
            break;
        case 32:
            if (c == EOF)
            {
                state = 33;
                c = ' ';
            }
            else if (c != '\n')
            {
                special[k++] = c;
                state = 32;
            }
            else if (c == '\n')
            {
                state = 33;
            }
            break;
        case 33:
            fprintf(f2, "<%s, %s - %s> line %d column %d\n", SymNames[sym.ERROR], "INVALID CHARACTER", special, cLine, cColumn - 2);
            state = 0;
            memset(special, 0, sizeof(special));
            k = 0;
            break;
        case 34:
            fprintf(f2, "<%s, %s - %s> line %d column %d\n", SymNames[sym.ERROR], "INVALID CHARACTER", special, cLine, cColumn - 2);
            state = 0;
            memset(special, 0, sizeof(special));
            cColumn = 0;
            cLine = 0;
            k = 0;
            break;
        case 35:
            fprintf(f2, "<%s, %s>\n", SymNames[sym.BOOLEAN], id);
            memset(id, 0, sizeof(id));
            state = 0;
            i = 0;
            ungetc(c, f1);
            break;
        }
        prevC = c;

    } while (c != EOF);
    fclose(f1);
    fclose(f2);
}