#include<stdio.h>
#include<stdlib.h>

struct stu
{
	char name[50];
	int roll_no;
	int age;
	int marks1;
	int marks2;
	int marks3;
	int tot_marks;	
};

struct node
{
	struct stu data;
	struct node *next;
};

void insert(struct node**);
void delete(struct node**);
void display(struct node*);
void dispTop(struct node*);

int main()
{
	struct node*s=NULL;
	int ch;
	while(1)
		{
			printf("\n*****Student Details*****\n");
			printf("1.Insert Details.\n2.Delete Details.\n3.Display.\n4.Display Top Three\n5.Exit.\n");
			printf("Enter Your Choice:\t");
			scanf("%d",&ch);
			switch(ch)
				{
					case 1:	insert(&s);
						break;
					case 2:	delete(&s);
						break;
					case 3:	display(s);
						break;
					case 4:dispTop(s);
						break;
					case 5: exit(0);
					default:printf("Invalid Choice!!!\n");
				}
		}

return 0;
}

void insert(struct node **head)
{
	int val1,val2,val3;
    struct node *tempptr;
    tempptr=*head;
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    char opt;
    printf("Wanna Enter Details(y/n)");
    scanf("%*c%c",&opt);
    if(opt=='y'||opt=='Y')
        {
		
		printf("Enter Name:\t");
            	scanf("%s",new_node->data.name);	
		printf("Enter Roll No:\t");
            	scanf("%d",&(new_node->data.roll_no));
            	printf("Enter marks1:\t");
            	scanf("%d",&(new_node->data.marks1));
		val1=new_node->data.marks1;
		printf("Enter marks2:\t");
            	scanf("%d",&(new_node->data.marks2));
		val2=new_node->data.marks2;
		printf("Enter marks3:\t");
            	scanf("%d",&(new_node->data.marks3));
		val3=new_node->data.marks3;
		new_node->data.tot_marks=(val1+val2+val3);
            	new_node->next=NULL;
		    if(tempptr==NULL)
		    {
		        printf("Linked List Is Empty\n");
		        printf("Want to make entered node as first node(y/n)????");
		        scanf("%*c%c",&opt);
		        if(opt=='y'||opt=='Y')
		        {
		            tempptr=new_node;
		            *head=tempptr;
		        }
		    }
		    else
		    {
		        *head=new_node;
		        new_node->next=tempptr;
		        tempptr=*head;
		    }
		}

}

void delete(struct node **head)
{
    char opt;
    struct node *tempptr;
    tempptr=*head;
    printf("Sure Deletion(y/n)????");
    scanf("%*c%c",&opt);
    if(opt=='y'||opt=='Y')
    {
        if(tempptr==NULL)
            printf("No Node to delete in Linked list\n");
        else if(tempptr->next==NULL)
        {
            free(tempptr);
            *head=tempptr=NULL;
        }
        else
        {
            *head=tempptr->next;
            free(tempptr);
            tempptr=*head;
        }

    }

}


void display(struct node *head)
{
    struct node *tempptr;
    tempptr=head;
    if(tempptr==NULL)
    {
        printf("Empty Linked List\n");

    }
    else if(tempptr->next==NULL)
    {
       printf("Name: %s : Roll_No: %d : Marks1: %d : Marks2: %d : Marks3: %d : Total Marks:%d \n",tempptr->data.name,tempptr->data.roll_no,tempptr->data.marks1,tempptr->data.marks2,tempptr->data.marks3,tempptr->data.tot_marks);
    }
    else
    {
        while(tempptr->next!=NULL)
        {
             printf("Name: %s : Roll_No: %d : Marks1: %d : Marks2: %d : Marks3: %d : Total Marks:%d \n",tempptr->data.name,tempptr->data.roll_no,tempptr->data.marks1,tempptr->data.marks2,tempptr->data.marks3,tempptr->data.tot_marks);
            tempptr=tempptr->next;
        } printf("Name: %s : Roll_No: %d : Marks1: %d : Marks2: %d : Marks3: %d : Total Marks:%d \n",tempptr->data.name,tempptr->data.roll_no,tempptr->data.marks1,tempptr->data.marks2,tempptr->data.marks3,tempptr->data.tot_marks);
    }

}

void dispTop(struct node*head)
{
	struct node *tempptr;
	    tempptr=head;
	struct node *max1,*max2,*max3;
	    if(tempptr==NULL)
	    {
		printf("Empty Linked List\n");

	    }
		else
		{
			max1=max2=max3=head;
			while(tempptr->next!=NULL)
			{
				
				tempptr=tempptr->next;
				if(max1->data.tot_marks<tempptr->data.tot_marks)
					max1=tempptr;
			}
				tempptr=head;
		
			while(tempptr->next!=NULL)
				{
					tempptr=tempptr->next;
					if((max2->data.tot_marks<tempptr->data.tot_marks)&&(max2->data.tot_marks!=max1->data.tot_marks))
						max2=tempptr;

				}

				tempptr=head;
		
			while(tempptr->next!=NULL)
				{
					tempptr=tempptr->next;
					if((max3->data.tot_marks<tempptr->data.tot_marks)&&(max3->data.tot_marks!=max2->data.tot_marks))
						max3=tempptr;

				}

printf("Name: %s : Roll_No: %d : Marks1: %d : Marks2: %d : Marks3: %d : Total Marks:%d \n",max1->data.name,max1->data.roll_no,max1->data.marks1,max1->data.marks2,max1->data.marks3,max1->data.tot_marks);
printf("Name: %s : Roll_No: %d : Marks1: %d : Marks2: %d : Marks3: %d : Total Marks:%d \n",max2->data.name,max2->data.roll_no,max2->data.marks1,max2->data.marks2,max2->data.marks3,max2->data.tot_marks);
printf("Name: %s : Roll_No: %d : Marks1: %d : Marks2: %d : Marks3: %d : Total Marks:%d \n",max3->data.name,max3->data.roll_no,max3->data.marks1,max3->data.marks2,max3->data.marks3,max3->data.tot_marks);
		}


}


