#include<stdio.h>
#include<stdlib.h>
struct stu
{
    char name[50];
    int roll_no;
    int marks;
};
struct node
{
    struct stu data;
    struct node *next;

};
void addAtBeg(struct node **);
void addAtEnd(struct node **);
void delFromBeg(struct node **);
void delFromEnd(struct node **);
void display(struct node *);
int main()
{
    int ch;
    struct node *s=NULL;
    while(1)
    {
        printf("\nMenu Driven On Student Details Using Single Linked List\n");
        printf("1.Add Student Details(in beg)\n2.Add Student Details(at last)\n3.Delete Student Details(from beg)\n\
4.Delete Student Details(from last)\n5.Display\n6.Exit\n");
        printf("Enter Your Choice:\t");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1: addAtBeg(&s);
                    break;
            case 2:addAtEnd(&s);
                    break;
            case 3:delFromBeg(&s);
                    break;
            case 4:delFromEnd(&s);
                    break;
            case 5:display(s);
                    break;
            case 6:exit(0);
            default:printf("Invalid Choice!!!");
        }
    }
return(0);

}

void addAtBeg(struct node **head)
{
    struct node *tempptr;
    tempptr=*head;
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    char opt;
    printf("Wanna Enter Details(y/n)");
    scanf("%*c%c",&opt);
    if(opt=='y'||opt=='Y')
        {
            printf("Enter Name:\t");
            scanf("%s",&(new_node->data.name));
            printf("Enter Roll No:\t");
            scanf("%d",&(new_node->data.roll_no));
            printf("Enter marks:\t");
            scanf("%d",&(new_node->data.marks));
            new_node->next=NULL;
            if(tempptr==NULL)
            {
                printf("Linked List Is Empty\n");
                printf("Want to make entered node as first node(y/n)????");
                scanf("%d",&opt);
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
void addAtEnd(struct node **head)
{
    struct node *tempptr;
    tempptr=*head;
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    char opt;
    printf("Wanna Enter Details(y/n)");
    scanf("%*c%c",&opt);
    if(opt=='y'||opt=='Y')
        {
            printf("Enter Name:\t");
            scanf("%s",&(new_node->data.name));
            printf("Enter Roll No:\t");
            scanf("%d",&(new_node->data.roll_no));
            printf("Enter marks:\t");
            scanf("%d",&(new_node->data.marks));
            new_node->next=NULL;
            if(tempptr==NULL)
            {
                printf("Linked List Is Empty\n");
                printf("Want to make entered node as first node(y/n)????");
                scanf("%d",&opt);
                if(opt=='y'||opt=='Y')
                {
                    tempptr=new_node;
                    *head=tempptr;
                }
            }
            else if(tempptr->next==NULL)
            {
                tempptr->next=new_node;
            }
            else
            {
                while(tempptr->next!=NULL)
                {
                    tempptr=tempptr->next;
                }
                tempptr->next=new_node;
            }
        }

}
void delFromBeg(struct node **head)
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
void delFromEnd(struct node **head)
{
    char opt;
    struct node *tempptr,*prev;
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
            while(tempptr->next!=NULL)
            {
                prev=tempptr;
                tempptr=tempptr->next;
            }
            prev->next=NULL;
            free(tempptr);
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
        printf(" %s : %d : %d \n",tempptr->data.name,tempptr->data.roll_no,tempptr->data.marks);

    }
    else
    {
        while(tempptr->next!=NULL)
        {
            printf(" %s : %d : %d \n",tempptr->data.name,tempptr->data.roll_no,tempptr->data.marks);
            tempptr=tempptr->next;
        }printf(" %s : %d : %d \n",tempptr->data.name,tempptr->data.roll_no,tempptr->data.marks);
    }

}
