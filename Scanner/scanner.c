#include <stdio.h>
#include <ctype.h>
#include <string.h>

;
char keywords[3][30] = {"if", "then", "else"}; 
char id[20], num[20];
int test_case = 0;

int isKeyword(char buff[]){
	for(int i = 0; i < 3; i++){
		if(strcmp(buff, keywords[i]) == 0){
			return 1;
		}
	}
	return 0;
}
int isValidIden(char buff[]){
	int len = strlen(buff);
	if(len < 2) return 0;
	if(!isalpha(buff[0])){
		return 0;
	}
	if(!isdigit(buff[1])){
		return 0;
	}
	for(int i = 2; i < len; i++){
		if(!isalnum(buff[i])){
			return 0;
		}
	}
	return 1;

}
char* toUpper(char buff[]){
	 int i = 0;
    while (buff[i] != '\0') {
        buff[i] = toupper(buff[i]);
        i++;
    }
    return buff;
}

int main(){
	FILE *f1, *f2;
	char c;
	int state = 0;
	int hasPreNumber = 0;
	int i = 0;
	int j = 0;
	f1 = fopen("input.txt", "r");
	f2 = fopen("output.txt", "w");

	while((c = fgetc(f1)) != EOF){
		switch(state) {
			case 0:
				if (isalpha(c)){
					state = 1;
					id[i++] = c;
				}
				if(isdigit(c)){
					state = 2;
					num[j++] = c;
 				}
 				if(c == '>'){
 					state = 3;
 				}

 				if(c == ';'){
 					state = 8;	
 				}
 				if(c == '='){
 					state = 10;
 				}
 				if(c == '=' && hasPreNumber == 1){
 					state = 9;
 					hasPreNumber = 0;
 				}
 			
 				
				break;
			case 1:
				if(isalpha(c) || isdigit(c)){
					state = 1;
					id[i++] = c;
				}else{
					state = 4;
					ungetc(c, f1);
				}
				break;
			case 2:
				if(isalpha(c)){
					state = 5;
					num[j++] = c;
				}else if(isdigit(c)){
					state = 2;
					num[j++] = c;
				}else{
					state = 7;
					ungetc(c, f1);
				}
				break;
			case 3: 
				state = 0;
				fprintf(f2, "<ROP, > >\n");
				
				break;
			case 4:
				if(isKeyword(id)){
					fprintf(f2, "<%s, >\n", toUpper(id));
				}else if(isValidIden(id)){
					// check valid identifier
					fprintf(f2, "<ID, %s>\n", id);

				}else{
					fprintf(f2, "Invalid Identifier <ID, %s>\n", id);
				}
				state = 0;
				i = 0;
				memset(id, 0, sizeof(id));
				// printf("%c\n", c);
				ungetc(c, f1);
				hasPreNumber = 0;
				break;
			case 5:
				if(isalpha(c) || isdigit(c)){
					state = 5;
					num[j++] = c;
				}else{
					state = 6;
					ungetc(c, f1);
				}
				break;
			case 6:
				state = 0;
				j = 0;
				fprintf(f2, "Invalid Identifier <ID, %s>\n", num);
				memset(num, 0, sizeof(num));
				ungetc(c, f1);
				hasPreNumber = 0;

				break;
			case 7:
				state = 0;
				j = 0;
				ungetc(c, f1);
				fprintf(f2, "<NUM, %s>\n", num);
				memset(num, 0, sizeof(num));
				hasPreNumber = 1;
				break;
			case 8:
				state = 0;
				fprintf(f2, "<SEM, >\n");
				test_case++;
				fprintf(f2, "END TEST CASE %d \n\n", test_case);
				break;
			case 9:
				state = 0;
				fprintf(f2,"Invalid Ass\n");
				ungetc(c, f1);
				break;
			case 10:
				state = 0;
				ungetc(c, f1);
				fprintf(f2, "<ASS, >\n");
				break;
		}
	}
	return 0;
}