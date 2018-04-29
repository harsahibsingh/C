/* Q2. Implement income tax calculator by considering best possible parameters ( gender, senior citizen benefits, exemption for investment
and other possible consideration). Make use of if-else ladder. */
#include<stdio.h>
int main()
{
    char gen;
    int age,var;
    float sal;
    printf("*****Income Tax Calculator*****\n");
    printf("Enter Your Details:\n");
    printf("Enter Salary AmountPer Annum(In Lakhs):\t");
    scanf("%f",&sal);
    printf("Gender:\t");
    scanf("%*c%c",&gen);
    printf("Age:\t");
    scanf("%d",&age);
    printf("Investment Details(Choose Appropriate):\n");
    printf(" 1.Housing\n 2.Health Insurance\n 3.Children Education\n 4.Others\n");
    scanf("%d",&var);
    if(sal<2.5)
    {
        printf("Not In Income Tax Limit!!!");
    }
    else
        {
         if(gen=='M'||gen=='m')
            {
                if(age>=60)
                    {
                        if(var==1)
                            printf("Income Tax:%f/%",0.10);
                        else if(var==2)
                            printf("Income Tax:%f/%",0.09);
                        else if(var==3)
                            printf("Income Tax:%f/%",0.08);
                        else
                            printf("Income Tax:%f/%",0.078);
                    }
                    else if(age>=40&&age<60)
                    {
                        if(var==1)
                            printf("Income Tax:%f/%",0.19);
                        else if(var==2)
                            printf("Income Tax:%f/%",0.18);
                        else if(var==3)
                            printf("Income Tax:%f/%",0.168);
                        else
                            printf("Income Tax:%f/%",0.178);
                    }
                     else
                    {
                        if(var==1)
                            printf("Income Tax:%f/%",0.23);
                        else if(var==2)
                            printf("Income Tax:%f/%",0.25);
                        else if(var==3)
                            printf("Income Tax:%f/%",0.21);
                        else
                            printf("Income Tax:%f/%",0.22);
                    }

            }
             else
                {

                if(age>=60)
                    {
                        if(var==1)
                            printf("Income Tax:%f/%",0.08);
                        else if(var==2)
                            printf("Income Tax:%f/%",0.07);
                        else if(var==3)
                            printf("Income Tax:%f/%",0.06);
                        else
                            printf("Income Tax:%f/%",0.068);
                    }
                    else if(age>=40&&age<60)
                    {
                        if(var==1)
                            printf("Income Tax:%f/%",0.18);
                        else if(var==2)
                            printf("Income Tax:%f/%",0.17);
                        else if(var==3)
                            printf("Income Tax:%f/%",0.175);
                        else
                            printf("Income Tax:%f/%",0.16);
                    }
                     else
                    {
                        if(var==1)
                            printf("Income Tax:%f/%",0.21);
                        else if(var==2)
                            printf("Income Tax:%f/%",0.20);
                        else if(var==3)
                            printf("Income Tax:%f/%",0.19);
                        else
                            printf("Income Tax:%f/%",0.185);
                    }


        }
    }
return 0;
}
