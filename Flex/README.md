# Authors
- Nguyễn Minh Hiếu - 21020908
- Nguyễn Việt Đức - 21020904
- Nguyễn Hữu Việt Hưng - 21020442
# Scanner
Token includes: 
- Keyword: `IF`, `THEN`, `ELSE`
- Identifier: `Letter.Digit.(Letter|Digit)*`
- Number
- Relational Operator: `>`, `>=`
- Assignment Operator
- Semi-colon


# Get Source Code
```
git clone https://github.com/Hieuueihm/Compiler
cd Compiler/Flex
ant run
```
# Results
| Test Case     	| Input         									|	Token    				|
| ------------- 	| ------------- 									| -------- 					|
| 1             		| ``if a > b then a = b else a = 1;``       	| `<IF, >`, ` Error: <Invalid identifier, a> at line 2, column 4`, `<ROP, > >`, `Error: <Invalid identifier, b> at line 2, column 8`, `<THEN, >`, ` Error: <Invalid identifier, a> at line 2, column 15`, `<ASS, >`, `Error: <Invalid identifier, b> at line 2, column 19`, `<ELSE, >`, ` Error: <Invalid identifier, a> at line 2, column 26`, `<ASS, >, <NUM, 1>`, `<SEM, >`|
| 2             		|``if a1 > 2 then a5 = 0 else a3 = a2;``| `<IF, >`,  `<IDEN, a1>`, `<ROP, > >`,  `<NUM, 2>`, `<THEN, >`, `<IDEN, a5>`, `<ASS, >`,  `<NUM, 0>`, `<ELSE, >`, `<IDEN, a3>`, `<ASS, >`, `<IDEN, a2>`, `<SEM, >`|
| 3             		|``if 3 > 2 then a2 = 0 else aa3=a2;``| `<IF, >`, `<NUM, 3>`, `<ROP, > >`, `<NUM, 2>`, `<THEN, >`,  ` <IDEN, a2>`, `<ASS, >`, `<NUM, 0>`, `<ELSE, >`, `Error: <Invalid identifier, aa3> at line 6, column 27`, `<ASS, >`, `<IDEN, a2>`, `<SEM, >`|
| 4                     | `` if3 >= 2 then 22 = 0 else aa3=a2;`` | `<IF, >`, `<NUM, 3>`,  `<ROP, >= >`, `<NUM, 2>`, `<THEN, >`, `<NUM, 22>`, `Error: <Invalid Ass> at line 8, column 19`, `<NUM, 0>`,`<ELSE, >`, `Error: <Invalid identifier, aa3> at line 8, column 28`, `<ASS, >`, `<IDEN, a2>`, `<SEM, >` |


