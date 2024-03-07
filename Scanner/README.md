# Members
- Nguyễn Minh Hiếu - 21020908
- Nguyễn Việt Đức - 21020908
- Nguyễn Hữu Việt Hưng - 21020442
# Describe Scanner
Token includes: 
- Keyword: IF, THEN, ELSE
- Number
- Relational Operator: >
- Assignment Operator
- Semi-colon

# Transition Diagram



# Get Source Code
```
git clone https://github.com/Hieuueihm/Compiler
cd Compiler/Scanner
gcc -o des scanner.c
```
# Results
| Test Case     	| Input         									|	Token    				|
| ------------- 	| ------------- 									| -------- 					|
| 1             		| if a > b then a = b else a = 1;       	| <IF, >, Invalid Identifier <ID, a>, <ROP, > >, Invalid Identifier <ID, b>, <THEN, >, Invalid Identifier <ID, a>, <ASS, >, Invalid Identifier <ID, b>, <ELSE, >, Invalid Identifier <ID, a>, <ASS, >, <NUM, 1>, <SEM, >|
| 2             		| if a1 > 2 then a5	= 0 else a3 = a2;| <IF, >,  <ID, a1>, <ROP, > >,  <NUM, 2>, <THEN, >, <ID, a5>, <ASS, >,  <NUM, 0>, <ELSE, >, <ID, a3>, <ASS, >, <ID, a2>, <SEM, >|
| 2             		|if 3 > 2 then 15 = 0 else aa3 = a2;| <IF, >, <NUM, 3>, <ROP, > >, <NUM, 2>, <THEN, >,  <NUM, 15>, Invalid Ass, <NUM, 0>, <ELSE, >, Invalid Identifier <ID, aa3>, <ASS, >, <ID, a2>, <SEM, >