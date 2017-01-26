#include <stdio.h>
#include <string.h> 
// In this program the user inputs a noun and is returned a plural noun

// The replacechar program goes through a noun which would need a words removed/added to become plural
void replacechar(char o[], char c, char b) {
	int i=0;
	while(o[i]!='\0') {
		if(o[i] == c) {
           		o[i] = b;
           	}  
          	 i++; 
    	 }
}

int main(void) { 
	char noun[50] = " "; 
	char origform[50] = " "; 
	int length;
	printf("Please enter a word: "); 
	scanf("%s", noun); 
//origform is used to edit the original version of the noun with if/else statements 
	strcpy(origform, noun); 
	length = strlen(noun); 
/* if and else statements used for the different conditions of nouns, specifically what letters
they end with */
	if (noun[length-1] == 'z')  {
		strcat(origform, "es"); 
		printf("The plural from of %s is %s.\n", noun, origform); 
	} 
	else if (noun[length-1] == 'x') {
                strcat(origform, "es");
                printf("The plural from of %s is %s.\n", noun, origform);
        }
	else if (noun[length-1] == 's') {
                strcat(origform, "es");
                printf("The plural from of %s is %s.\n", noun, origform);
        }
	else if ((noun[length-1] == 'h') && (noun[length-2] == 's')) {
                strcat(origform, "es");
                printf("The plural from of %s is %s.\n", noun, origform);
        }
	else if ((noun[length-1] == 'h') && (noun[length-2] == 'c')) { 
		strcat(origform, "es"); 
		printf("The plural from of %s is %s.\n", noun, origform); 
	} 
	else if ((noun[length-2] == 'a') && (noun[length-1] == 'y')) {  
		strcat(origform, "s"); 
		printf("The plural from of %s is %s.\n", noun, origform); 
	}
	else if ((noun[length-2] == 'e') && (noun[length-1] == 'y')) { 
                strcat(origform, "s"); 
                printf("The plural from of %s is %s.\n", noun, origform); 
        }
	else if ((noun[length-2] == 'i')  && (noun[length-1] == 'y')) { 
                strcat(origform, "s"); 
                printf("The plural from of %s is %s.\n", noun, origform); 
        }
	else if ((noun[length-2] == 'o')  && (noun[length-1] == 'y')) {                       
                strcat(origform, "s");
                printf("The plural from of %s is %s.\n", noun, origform);
        }
	else if ((noun[length-2] == 'u') && (noun[length-1] == 'y')) { 
                strcat(origform, "s"); 
                printf("The plural from of %s is %s.\n", noun, origform); 
        }
	else if (noun[length-1] == 'y') { 
		replacechar(origform,'y', 'i'); 
		strcat(origform, "es");
		printf("The plural from of %s is %s.\n", noun, origform); 
	}
	else if (noun[length-1] == 'f') { 
		replacechar(origform, 'f', 'v'); 
		strcat(origform, "es"); 
		printf("The plural from of %s is %s.\n", noun, origform); 
	} 
	else if ((noun[length-1] == 'e') && (noun[length-2] == 'f')) { 
		replacechar(origform, 'f', 'v'); 
		strcat(origform, "s"); 
		printf("The plural from of %s is %s.\n", noun, origform); 
	}
	else {
                strcat(origform, "s");
                printf("The plural from of %s is %s.\n", noun, origform);
	}
	return 0;
}
