#include<stdio.h>
#include<stdlib.h>
struct stu
{
    char name[25];
    int roll_no;
    int marks;
};
struct node
{
    struct stu data;
    struct node *prev;
    struct node *next;
};
void addAtBeg(struct node **);
void addAtLast(struct node **);
void DelFromBeg(struct node **);
void DelFromLast(struct node **);
void display(struct node *);
void display_rev(struct node *);
void addAtPos(struct node **);
void delFromPos(struct node**);
int main()
{
    int ch;
    struct node *s=NULL;
    while(1)
    {
        printf("\n\n Menu driven program on double linked list\n");
        printf("1.Add at beg\n2.Add at end\n3.del at beg\n4.del at end\n5.display\n6.reverse display\n\
7.insert at particular pos\n8.delete from particular pos\n9.exit\n");
        printf("Enter your choice:\t");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:addAtBeg(&s);
                    break;
            case 2:addAtLast(&s);
                    break;
            case 3:DelFromBeg(&s);
                    break;
            case 4:DelFromLast(&s);
                    break;
            case 5:display(s);
                    break;
            case 6:display_rev(s);
                    break;
            case 7:addAtPos(&s);
                    break;
            case 8:delFromPos(&s);
                    break;
            case 9:exit(0);
            default:printf("Invalid Choice!!!");
        }

    }

return 0;
}
void addAtBeg(struct node **head)
{
    struct node *tempptr;
    tempptr=*head;
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter Details:\n");
    printf("Name:\t");
    scanf("%s",&(new_node->data.name));
    printf("Roll Number:\t");
    scanf("%d",&(new_node->data.roll_no));
    printf("Marks:\t");
    scanf("%d",&(new_node->data.marks));
    new_node->next=NULL;
    new_node->prev=NULL;

    if(tempptr==NULL)
    {
        printf("This will be the first node\n");
        tempptr=*head=new_node;
        tempptr->next=NULL;
        tempptr->prev=NULL;
    }
    else
    {
        *head=new_node;
        new_node->next=tempptr;
        tempptr->prev=new_node;
    }


}
void addAtLast(struct node **head)
{
    struct node *tempptr;
    tempptr=*head;
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter Details:\n");
    printf("Name:\t");
    scanf("%s",&(new_node->data.name));
    printf("Roll Number:\t");
    scanf("%d",&(new_node->data.roll_no));
    printf("Marks:\t");
    scanf("%d",&(new_node->data.marks));
    new_node->next=NULL;
    new_node->prev=NULL;

    if(tempptr==NULL)
    {
        printf("This will be the first node\n");
        tempptr=*head=new_node;
    }
    else
    {
        while(tempptr->next!=NULL)
        {
            tempptr=tempptr->next;
        }
        tempptr->next=new_node;
        new_node->prev=tempptr;
    }

}
void DelFromBeg(struct node **head)
{
    struct node*tempptr=*head;
    if(tempptr==NULL)
    {
        printf("No element to delete\n");
    }
    else if(tempptr->next==NULL)
    {
        tempptr=*head=NULL;
    }
    else
    {
        *head=tempptr->next;
        free(tempptr);
        tempptr=*head;
        tempptr->prev=NULL;
    }

}
void DelFromLast(struct node **head)
{
     struct node*tempptr=*head;
     struct node *prev;
    if(tempptr==NULL)
    {
        printf("No element to delete\n");
    }
    else
    {
        while(tempptr->next!=NULL)
        {
            prev=tempptr;
            tempptr=tempptr->next;
        }
        prev->next=NULL;
        free(tempptr);
    }

}
void display(struct node *head)
{
    struct node*tempptr;
    tempptr=head;
    if(tempptr==NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        while(tempptr->next!=NULL)
        {
            printf("%s : %d : %d \n",tempptr->data.name,tempptr->data.roll_no,tempptr->data.marks);
            tempptr=tempptr->next;
        }printf("%s : %d : %d \n",tempptr->data.name,tempptr->data.roll_no,tempptr->data.marks);

    }


}

void display_rev(struct node *head)
{
    struct node*tempptr;
    tempptr=head;
    if(tempptr==NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        while(tempptr->next!=NULL)
        {
            tempptr=tempptr->next;
        }
        while(tempptr->prev!=NULL)
        {
            printf("%s : %d : %d \n",tempptr->data.name,tempptr->data.roll_no,tempptr->data.marks);
            tempptr=tempptr->prev;

        }printf("%s : %d : %d \n",tempptr->data.name,tempptr->data.roll_no,tempptr->data.marks);


    }

}


void addAtPos(struct node **head)
{
    int i,pos,count =1;
    struct node*tempptr,*prev;
    tempptr=*head;
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
     printf("Enter Position to Add node\n");
    scanf("%d",&pos);
    printf("Enter Details:\n");
    printf("Name:\t");
    scanf("%s",&(new_node->data.name));
    printf("Roll Number:\t");
    scanf("%d",&(new_node->data.roll_no));
    printf("Marks:\t");
    scanf("%d",&(new_node->data.marks));
    new_node->next=NULL;
    new_node->prev=NULL;
     if(tempptr==NULL)
    {
        printf("Linked List Is Empty,Data Will Be Added At 1st Node\n");
    }
       else
        {
             while(tempptr->next!=NULL)
            {
                tempptr=tempptr->next;
                count++;
            }
            tempptr=*head;
            if(pos==1)
            {
                new_node->next=tempptr;
                tempptr->prev=new_node;
                *head=tempptr=new_node;
            }
               else if(count>=pos)
                    {
                        tempptr=*head;
                            for (i=1;i<pos;i++)
                            {   prev=tempptr;
                                tempptr=tempptr->next;
                            }
                        new_node->next=prev->next;
                        prev->next=new_node;
                        new_node->prev=prev;
                        tempptr->prev=new_node;
                        printf("Addition Success\n");
                    }
                else
                {
                    printf("Not Adequate Position\n");
                }


    }






}
void delFromPos(struct node **head)
{

}
