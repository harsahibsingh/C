/*Q1. Define your own iterative functions for
(using array notation as well as exclusively using pointers)
a) finding length
b) copying
c) concatenation
d) comparision
e) reversing in memory
f) finding first occurrence of given character
g)finding last occurrence of given character
h)counting no.of occurences of a given character
i) finding a substring in a main string
j) Whether a string starts or ends with a particular sub string*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void my_strlen();
void my_strcpy();
void my_strcat();
void my_strcmp();
void my_strrev();
void my_strchr();
void my_strrchr();
void my_charcnt();
void my_strstr();
void my_func();

int main()
{
    int ch;
    while(1)
    {
        printf("\nMenu Driven Program\n");
        printf("1.finding length of string\n2.copying string\n3.Concatinating String\n4.Comparison of Strings\n5.Reverse String\n\
6.Finding first occurance of character\n7.Finding last occurence of character\n8.Count number of occurence of given character\n\
9.Finding Substring in a String\n10.Whether a string starts or ends with a particular sub string\n11.Exit\n");
        printf("Enter Choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: my_strlen();//strlen(str) returns no of character in string excluding terminating null character.
                    break;
            case 2: my_strcpy();//strcpy(str1,str2) copies str2 into str1.
                    break;
            case 3: my_strcat();//strcat(str1,str2) concatenates str2 at end of str1.
                    break;
            case 4: my_strcmp();//strcmp(str1,str2) concatinates str2 at end of str1 .
                    break;
            case 5: my_strrev();//strrev(str) reverses a string
                    break;
            case 6: my_strchr();//returns pointer to first occurance of character
                    break;
            case 7: my_strrchr();//returns pointer to last(right most) element of character
                    break;
            case 8: my_charcnt();//No function in C//counting no of occurences of given character
                    break;
            case 9: my_strstr();//first occurance of substring in another string
                    break;
            case 10:my_func();
                    break;
            case 11: exit(0);
            default:printf("Invalid Choice!!!");
        }

    }
return 0;

}

void my_strlen()
{
    int len,i=0;
    char str[25];
    printf("Enter String\n");
    scanf("%s",str);
    len=strlen(str);
    printf("Length Via Function: %d\n",len);
    while(str[i]!='\0')
    {
        i++;
    }
    printf("Length Via Logic: %d\n",i);

}

void my_strcpy()
{
    int i=0;
    char str1[25],str2[25],str3[25],str4[25];
    printf("Enter First String\n");
    scanf("%s",str1);
    printf("Enter Second String\n");
    scanf("%s",str2);
    printf("First String Is:%s \n",str1);
    printf("Second String Is:%s \n",str2);
    strcpy(str3,str1);
    printf("Copying 1st string to 3rd: %s \n",str3);

    while(str2[i]!='\0')
    {
        str4[i]=str2[i];
        i++;
    }
    str4[i]='\0';
    printf("Copying 2nd String to 4th Via logic: %s \n",str4);

}
void my_strcat()
{
    int i=0;
    int j=0;
    char str1[25],str2[25],str3[50]={"Manmeet "},str4[50]={"Jaspinder "};
    printf("Enter First String to append at last\n");
    scanf("%s",str1);
    printf("Enter Second String to append at last\n");
    scanf("%s",str2);
    printf("First String Is:%s \n",str1);
    printf("Second String Is:%s \n",str2);
    strcat(str3,str1);
    printf("Concatenated 1st string to 3rd: %s \n",str3);
    while(str4[i]!='\0')
    {
        i++;
    }
    while(str2[j]!='\0')
    {
        str4[i]=str2[j];
        i++;
        j++;
    }
     printf("Concatenated 2nd string to 4th Via Logic: %s \n",str4);




}
void my_strcmp()
{
    int value,i=0;
    char str1[25],str2[25];
    printf("Enter First String\n");
    scanf("%s",str1);
    printf("Enter Second String\n");
    scanf("%s",str2);
    if(strcmp(str1,str2)==0)
        printf("Strings are Equal!!!\n");
    else
        printf("Strings are Not Equal\n");
//Via Logic
        while(str1[i]==str2[i])
        {
            if(str1[i]=='\0')
                break;
            else
                i++;
        }

            if(str1[i]=='\0')
                value=0;
            else
                value=(str1[i]-str2[i]);//doubt in this line

            if(value==0)
                printf("Strings are equal(via logic)\n");
            else if(value<0)
                printf("String1 is smaller(via logic)\n");
            else if(value>0)
                printf("String2 is smaller(via logic)\n");

}
void my_strrev()
{
    int value,i,j=0,cnt=0;
    char str1[25],str2[25],str3[25];
    printf("Enter First String\n");
    scanf("%s",str1);
    strcpy(str2,str1);
    strrev(str1);
    printf("String after reversing is: %s\n",str1);
    ///via logic
    while(str2[cnt]!='\0')
    {
        cnt++;
    }
    for(i=cnt-1;i>=0;i--)
    {
        str3[j]=str2[i];
        j++;
    }
    str3[j]='\0';
    printf("String after reversing is(via logic): %s\n",str3);



}
void my_strchr()
{

}
void my_strrchr()
{

}
void my_charcnt()
{

}
void my_strstr()
{

}
void my_func()
{

}

