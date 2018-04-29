//Q1_B.To implement own strstr(substr) function???

#include<stdio.h>

char input[50];
char temp[50];

int length(char *);//function declaration to find the lenght of the string
void inputStr();//function declaration to input the string
void inputSubStr();//function declaration to input substring
void findSubStr();//to find the substring within the main string

int main()
{	
	unsigned int len;
	printf("To find Substring in the entered String\n");
			
		inputStr();
		inputSubStr();
		findSubStr();
		
		
	return 0;
	
	
}

int length(char *res)
{
	static int i=0; 
	if(res[0]=='\0')
		return 0;
	else
	{
		i++;
		length(res+1);
	}
	
	return i;
	
}
void inputStr()
{
	printf("\nEnter Main String:\t");
	scanf("%s",input);
	fflush(stdin);
	

}
void inputSubStr()
{
	
	printf("\nEnter SubString:\t");
	scanf("%s",temp);
	fflush(stdin);
}

void findSubStr()
{
	int len1=length(input);
	int len2=length(temp);
	int flag=1,i,pos=0;
	for( i=0;i<len1;i++)
	{	
		flag=1;
		
			if(temp[0]==input[i])
			{
				for(int j=1;j<len2;j++)
				{
					if(input[i+j]!=temp[j])
					{		
						flag=0;
						break;
						
					}
					pos=i;
				}
			}
	
	}
	if(flag==1)
	{
		printf("\nSubstring %s found in %s at %d position\n",temp,input,pos);
		
	}
	else
		printf("\nSubstring %s not found in %s position\n",temp,input);
if(flag==1)
printf("String is : %s\n",input+pos);

}



