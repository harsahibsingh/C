#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
void createLL(struct node **);
void displayLL(struct node *);
void insertAtBeg(struct node **);
void insertAtLast(struct node**);
void deleteAtBeg(struct node **);
void deleteAtLast(struct node **);
void insertAtPos(struct node **);
void insertBeforeEle(struct node **);
void insetAfterEle(struct node **);
void delAtPos(struct node **);
void delByEle(struct node **);
void reverseLL(struct node **);

/*int main()
{
struct node s={10,NULL};//Creating a variable s of type struct node
printf("%d\t",s.data);//addressing to data part of the structure via object s using dot operator.
printf("%d",s.next);//addressing to next part of the structure via object s using dot operator.
return 0;
}*/
/*int main()
{
struct node *s;//declaring a pointer of struct node type
s=(struct node*)malloc(sizeof(struct node));//dynamic memmory allocation using malloc
function.
s->data=10;
s->next=NULL;
printf("%d\t",s->data);
printf("%d",s->next);
return 0;
}*/
int main()
{
struct node *s=NULL;
int ch;
while(1)
{
printf("\n*****MENU DRIVEN PROGRAM ON SINGLE LINKED LIST*****\n");
printf("\n 1.Create Linked List\n 2.Display Linked List\n 3.Adding Node At Beginning\n \
4.Inserting Node At Last\n 5.Delete At Beginning\n 6.Delete At Last\n 7.Insert At Particular Position\n \
8.Insert Node Before Particular Element\n 9.Insert Node After Particular Element\n 10.Delete At Particular Position\n \
11.Delete Particular Element\n 12.Reverse A Link List\n 13.Exit\n");

printf("Enter Your Choice:\t");
scanf("%d",&ch);
switch(ch)
{
case 1:createLL(&s);
        break;
case 2:displayLL(s);
        break;
case 3:insertAtBeg(&s);
        break;
case 4:insertAtLast(&s);
        break;
case 5:deleteAtBeg(&s);
        break;
case 6:deleteAtLast(&s);
        break;
case 7:insertAtPos(&s);
        break;
case 8:insertBeforeEle(&s);
        break;
case 9:insertAfterEle(&s);
        break;
case 10:delAtPos(&s);
        break;
case 11:delByEle(&s);
        break;
case 12:reverseLL(&s);
        break;
case 13 :exit(0);
default:printf("Invalid Choice!!!\n");
}
}
return 0;
}
void createLL(struct node **head)
{
int dfield;
struct node *tempptr;
tempptr=*head;
struct node *new_node=(struct node*)malloc(sizeof(struct node));
printf("Enter The Data Field:\t");
scanf("%d",&dfield);
if(tempptr==NULL)
{
new_node->data=dfield;
new_node->next=NULL;
tempptr=new_node;
*head=tempptr;//this is important because to modify the head pointer to point to first node instead of NULL
}
else{
while(tempptr->next!=NULL)
{
tempptr=tempptr->next;
}
tempptr->next=new_node;
new_node->data=dfield;
new_node->next=NULL;
}
}
void displayLL(struct node *head)
{
struct node *tempptr;
tempptr=head;
if(tempptr==NULL)
{
    printf("Link List Is Empty\n");
}
else
    {
        printf("The Linked List Is:  ");
        while(tempptr->next!=NULL)
        {
        printf("%d - >",tempptr->data);
        tempptr=tempptr->next;
        }
        printf("%d",tempptr->data);
    }

}
void insertAtBeg(struct node **head)
{
    int dfield;
    struct node* tempptr;
    tempptr=*head;
    struct node* new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter The Data Field To Insert At Beginning Of Current Linked List:\t");
    scanf("%d",&dfield);
    if(tempptr==NULL)//The Linked List Is Empty and this would be the first node
    {
      new_node->data=dfield;
      new_node->next=NULL;
      tempptr=new_node;
      *head=tempptr;//this is important because to modify the head pointer to point to first node instead of NULL
    }
    else
        {
            new_node->data=dfield;
            new_node->next=tempptr;
            tempptr=new_node;

    }
    *head=tempptr;
}
void insertAtLast(struct node **head)
{
    int dfield;
    struct node *tempptr;
    tempptr=*head;
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter The Data Filed Of Node To Be Inserted At The Last\t");
    scanf("%d",&dfield);
    if(tempptr==NULL)//This is going to be the last node in the given linked list
    {
       new_node->data=dfield;
       new_node->next=NULL;
       tempptr=new_node;
       *head=tempptr;//this is important because to modify the head pointer to point to first node instead of NULL
    }
    else
    {
        while(tempptr->next!=NULL)
        {
            tempptr=tempptr->next;
        }
        tempptr->next=new_node;
        new_node->data=dfield;
        new_node->next=NULL;

    }

}

void deleteAtBeg(struct node **head)
{
    struct node *tempptr;
    tempptr=*head;
    if(tempptr==NULL)
       {
            printf("No Node Available to Delete\n");

       }
       else
        {
                //*head=tempptr->next;
                *head=(*head)->next;//The above syntax or this both will work...
                printf("Node In The Beginning Containing : %d  deleted",tempptr->data); //The above syntax or this both will work...
                free(tempptr);

       }
}

void deleteAtLast(struct node **head)
{
    struct node *tempptr;
    struct node *prev;
    tempptr=*head;
    if(tempptr==NULL)
    {

        printf("No Node Available to Delete\n");
    }
    else
        {
            while(tempptr->next!=NULL)
            {
                prev=tempptr;
                tempptr=tempptr->next;//The above syntax or this both will work...
            }
            prev->next=NULL;
            printf("Node At The End Containing: %d  is Deleted Successfully\n",tempptr->data);
            free(tempptr);

        }
}

void insertAtPos(struct node **head)
{
    int pos,dfield,i,count=1;
    char ch;
    struct node *tempptr;
    struct node *prev;
    tempptr=*head;
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter The Position To Enter Data:\t");
    scanf("%d",&pos);
    printf("Enter The Data To Enter In Node\n");
    scanf("%d",&dfield);
    new_node->data=dfield;
    new_node->next=NULL;
    if(tempptr==NULL)
    {
        printf("Linked List Is Empty,Data Will Be Added At 1st Node\n");
        printf("Want To Add(y/N)????\t");
        scanf("%*c%c",&ch);
        if(ch=='y'||ch=='Y')
        {
            tempptr=new_node;
            *head=tempptr;
        }
        else
            exit(0);
    }
       else
        {
             while(tempptr->next!=NULL)
            {
                tempptr=tempptr->next;
                count++;
            }
                if(count>=pos)
                    {
                        tempptr=*head;
                            for (i=1;i<pos;i++)
                            {   prev=tempptr;
                                tempptr=tempptr->next;
                            }
                        new_node->next=prev->next;
                        prev->next=new_node;
                        printf("Addition Success\n");
                    }
                else
                {
                    printf("Not Adequate Position\n");
                    printf("Want To Add At Last(y/n)\n");
                    scanf("%*c%c",&ch);
                    if(ch=='y'||ch=='Y')
                    {
                        while(tempptr->next!=NULL)
                        {
                            prev=tempptr;
                            tempptr=tempptr->next;
                        }
                        tempptr->next=new_node;
                    }
                        else
                            exit(0);

            }

        }

}

void insertBeforeEle(struct node **head)
{
    int ele,dfield,count=0;
    char ch;
    struct node *tempptr;
    struct node *prev;
    struct node *tempptr2;
    tempptr=*head;
    tempptr2=*head;
    prev=tempptr;
    printf("Enter The element before which to insert node\t");
    scanf("%d",&ele);
    printf("Enter The Node's Data field\t");
    scanf("%d",&dfield);
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=dfield;
    new_node->next=NULL;

    if(tempptr==NULL)
    {
        printf("Linked List Is Empty\n");
        printf("Wanna Insert At The Begining(y/n)");
        scanf("%*c%c",&ch);
        if(ch=='y'||ch=='Y')
        {
            tempptr=new_node;
            *head=tempptr;
        }
    }
    else if((tempptr->next==NULL)||(tempptr->data==ele))
    {

       // printf("Only One Element In Linked List\n");
        if(tempptr->data==ele)
        {
            new_node->next=tempptr;
            tempptr=new_node;
            *head=tempptr;
        }
        else
            {
                printf("Wanna Insert At The Begining Of present element(y/n)");
                scanf("%*c%c",&ch);
                if(ch=='y'||ch=='Y')
                    {
                        new_node->next=*head;
                        tempptr=new_node;
                        *head=tempptr;
                    }
            }
    }
    else
    {
        while(tempptr->data!=ele)
        {
            prev=tempptr;
            tempptr=tempptr->next;
        }
        //if(tempptr->data==ele)
       // {
            prev->next=new_node;
            new_node->next=tempptr;
            //tempptr=new_node;
            printf("Element Added Successfully\n");
       // }
       // else
           /* {
                printf("No Such Element Found\n");
                printf("Insertion Unsuccessful\n");
            }*/

    }


}
void insertAfterEle(struct node **head)
{
    int ele,dfield;
    char ch;
    struct node *tempptr;
    tempptr=*head;
    struct node*new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter The Element After Which To Insert Node\n");
    scanf("%d",&ele);
    printf("Enter The Data field of node\n");
    scanf("%d",&dfield);
    new_node->data=dfield;
    new_node->next=NULL;
    if(tempptr==NULL)
    {
        printf("EMpty Link List\n");
        printf("Want To Enter The Node As First Node\n");
        scanf("%*c%c",&ch);
        if(ch=='y'||ch=='Y')
        {
            tempptr=new_node;
            //tempptr->next=NULL;
            *head=tempptr;
        }
    }
    else
    {
        while(tempptr->data!=ele)
        {
            tempptr=tempptr->next;
        }
        if((tempptr->data==ele) && (tempptr->next==NULL))
        {
           // new_node->next=tempptr;
            tempptr->next=new_node;

        }
        else if((tempptr->data==ele) && (tempptr->next!=NULL))
        {
             new_node->next=tempptr->next;
            tempptr->next=new_node;


        }
        else
            printf("No Element Found\n");

    }

}

void delAtPos(struct node **head)
{
    int pos,i;
    struct node *tempptr;
    struct node *prev;
    tempptr=*head;
    printf("Enter Position To Delete Element\n");
    scanf("%d",&pos);
    if(tempptr==NULL)
    {
        printf("No Element Present IN Linked List For Deletion\n");
    }
    else if(pos==1)
    {
        *head=tempptr->next;
        free(tempptr);
    }
    else
        {
            for(i=1;i<pos;i++)
            {
                prev=tempptr;
                tempptr=tempptr->next;
            }
            if(tempptr->next==NULL)
            {
                prev->next=NULL;
                free(tempptr);
            }
            else
            {
                prev->next=tempptr->next;
                free(tempptr);

            }

        }
}
void delByEle(struct node **head)
{
    int ele;
    struct node *tempptr;
    struct node *prev;
    tempptr=*head;
    printf("Enter Node Element To Delete\n");
    scanf("%d",&ele);
    if(tempptr==NULL)
    {

        printf("No Element To Delete In Linked List\n");
    }
    else if(tempptr->next==NULL)
        {
            if(tempptr->data==ele)
               {
                 free(tempptr);
                *head=NULL;
               }
               else
                printf("Element Not Found\n");

        }
        else
            {
                while(tempptr->data!=ele)
                {
                    prev=tempptr;
                    tempptr=tempptr->next;
                }
                if(tempptr==*head)
                {
                    *head=tempptr->next;
                    free(tempptr);
                }
                else if(tempptr!=*head)
                    {
                        prev->next=tempptr->next;
                        free(tempptr);

                    }
                    else
                        printf("Element Not Found\n");

            }
}

void reverseLL(struct node **head)

{
    struct node *tempptr,*p,*q;
    tempptr=*head;
    p=q=NULL;
    if(tempptr==NULL)
    {
        printf("Link List Is Empty\n");

    }
    else if(tempptr->next==NULL)
    {
        printf("Reverse Linked List\n");
        printf("%d",tempptr->data);
    }
    else
        {
            while(tempptr!=NULL)
                {
                    p=q;
                    q=tempptr;
                    tempptr=tempptr->next;
                    q->next=p;

                }
                tempptr=q;
                printf("Reverse Linked List Is\n");
                while(tempptr->next!=NULL)
                {
                     printf("%d-->",tempptr->data);
                     tempptr=tempptr->next;

                }
                printf("%d",tempptr->data);

        }

}
