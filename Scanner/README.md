# Introduction
Lexical analysis (or scanning) is the process by which the stream of characters is grouped into strings representing the words of a language (called lexemes) which correspond to specific grammatical elements of that language (called tokens). We implement a scanner by using C language. We further handle the case when number = number.
# Authors
- Nguyễn Minh Hiếu - 21020908
- Nguyễn Việt Đức - 21020904
- Nguyễn Hữu Việt Hưng - 21020442
# Scanner
Token pattern: `<Token Name , Attribute Value>`

Token includes: 
- Keyword: `IF`, `THEN`, `ELSE`
- Identifier: `Letter.Digit.(Letter|Digit)*`
- Number
- Relational Operator: `>`
- Assignment Operator
- Semi-colon

# Transition Diagram
<img src="https://github.com/Hieuueihm/Compiler/assets/95173069/832637a6-de4b-4d49-80aa-fbbd8371a7c4" />

# Get Source Code
```
git clone https://github.com/Hieuueihm/Compiler
cd Compiler/Scanner
gcc -o des scanner.c
des
```
# Results
| Test Case     	| Input         									|	Token    				|
| ------------- 	| ------------- 									| -------- 					|
| 1             		| ``if a > b then a = b else a = 1;``       	| `<IF, >`, `Invalid Identifier <ID, a>`, `<ROP, > >`, `Invalid Identifier <ID, b>`, `<THEN, >`, `Invalid Identifier <ID, a>`, `<ASS, >`, `Invalid Identifier <ID, b>`, `<ELSE, >`, `Invalid Identifier <ID, a>`, `<ASS, >, <NUM, 1>`, `<SEM, >`|
| 2             		|``if a1 > 2 then a5 = 0 else a3 = a2;``| `<IF, >`,  `<ID, a1>`, `<ROP, > >`,  `<NUM, 2>`, `<THEN, >`, `<ID, a5>`, `<ASS, >`,  `<NUM, 0>`, `<ELSE, >`, `<ID, a3>`, `<ASS, >`, `<ID, a2>`, `<SEM, >`|
| 3             		|``if 3 > 2 then 15 = 0 else aa3 = a2;``| `<IF, >`, `<NUM, 3>`, `<ROP, > >`, `<NUM, 2>`, `<THEN, >`,  `<NUM, 15>`, `Invalid Ass`, `<NUM, 0>`, `<ELSE, >`, `Invalid Identifier <ID, aa3>`, `<ASS, >`, `<ID, a2>`, `<SEM, >`|
