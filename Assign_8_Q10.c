/* Q10. Convert the string in a.b.c.d format into 32 bit unsigned integer
(use pointer operations for packing purpose)*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void decodeString(char str1[], char);

int main() {
	char str[25] = "10.20.30.40";
	 decodeString(str, '.');
	return 0;
}

void decodeString(char str1[], char delimiter)
{
	//char *temp = str;
	//int num = 0;
	char str2[25];
	int i=0,j=0;
	while(str1[i]!= '\0')
        {
		// skip iteration if you find a delimiter
		if(str1[i] == delimiter)
            {

			i++;
			//continue;
            }
		else
            {
            str2[j]=str1[i];
            j++;
            i++;

            }

		// *temp - '0' to convert char to int
		//num = num * 10 + (*temp - '0');
		//temp++;
	}str2[j]='\0';
	//return num;
	printf("After Func Call: %s",str2);
}
