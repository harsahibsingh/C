//Menu Driven Program On Circular Single Linked LIst....
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void createLL(struct node **);
void display(struct node *);
void insertAtBeg(struct node **);
void insertAtPos(struct node **);
void insertBeforeEle(struct node **);
void insertAfterEle(struct node **);
void delByIndex(struct node **);
void delByEle(struct node **);
void reverse(struct node **);
int main()
{
    int ch;
    struct node *s=NULL;

    while(1)
    {
        printf("\n*****MENU DRIVEN PROGRAM ON CIRCULAR LINKED LIST*****\n");
        printf("1.Create Linked List(Insert At Last)\n2.Display Linked List\n3.Insert At Beginning\n4.Insert At Particular Position\n\
5.Insert Before Particular Element\n\
6.Insert After Particular Element\n7.Delete Element By Index\n8.Delete Particular Element\n\
9.Reverse\n10.Exit\n");
        printf("Enter Your Choice:\t");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:createLL(&s);
                    break;
            case 2:display(s);
                    break;
            case 3:insertAtBeg(&s);
                    break;
            case 4:insertAtPos(&s);
                    break;
            case 5:insertBeforeEle(&s);
                    break;
            case 6:insertAfterEle(&s);
                    break;
            case 7:delByIndex(&s);
                    break;
            case 8:delByEle(&s);
                    break;
            case 9:reverse(&s);
                    break;
            case 10:exit(0);
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
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter The Data Field Of Node\n");
    scanf("%d",&dfield);
    new_node->data=dfield;
    new_node->next=NULL;
    if(tempptr==NULL)
    {
        printf("This Is gonna be the First Node\n");
        //new_node->data=dfield;
        tempptr=new_node;
        *head=tempptr;
        new_node->next=new_node;
    }
    else
    {
        while(tempptr->next!=*head)
        {
            tempptr=tempptr->next;
        }
        tempptr->next=new_node;
        new_node->next=*head;
        printf("Node Added Successfully");
    }

}

void display(struct node *head)
{
    struct node *tempptr;
    tempptr=head;
    if(tempptr==NULL)
    {
        printf("No Node To Display\n");
    }
    else
    {
        printf("Linked List Is:\t");
        while(tempptr->next!=head)
        {
            printf("%d-->",tempptr->data);
            tempptr=tempptr->next;
        }
        printf("%d",tempptr->data);
    }
}

void insertAtBeg(struct node **head)
{
    int dfield;
    struct node *tempptr;
    tempptr=*head;
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter data field of the node\n");
    scanf("%d",&dfield);
    new_node->data=dfield;
    new_node->next=NULL;
    if(tempptr==NULL)
    {
        tempptr=new_node;
        new_node->next=tempptr;
        *head=tempptr;
    }
    else
    {
        while(tempptr->next!=*head)
        {
            tempptr=tempptr->next;
        }
        new_node->next=*head;
        tempptr->next=new_node;
        tempptr=new_node;
        *head=new_node;
    }

}

void insertAtPos(struct node **head)
{
    int pos,dfield,i;
    struct node *tempptr;
    struct node *prev;
    tempptr=*head;
    printf("Enter The Position to insert node\n ");
    scanf("%d",&pos);
    printf("Enter the node data\n");
    scanf("%d",&dfield);
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=dfield;
    new_node->next=NULL;
    if(pos==1&&tempptr==NULL)
    {
        printf("NO node in Linked List\n");
        tempptr=new_node;
        new_node->next=tempptr;
        *head=tempptr;
    }
    else if(pos==1&&tempptr->next==*head)
    {
        new_node->next=tempptr;
        tempptr->next=new_node;
        tempptr=new_node;
        *head=tempptr;
    }
    else if(pos==1)
    {
        while(tempptr->next!=*head)
        {
            tempptr=tempptr->next;
        }
        new_node->next=*head;
        tempptr->next=new_node;
        *head=new_node;
    }

    else
    {
        if(tempptr==NULL)
        {
            printf("Invalid Location\n");
        }
        else
        {
            for(i=1;i<pos;i++)
        {
            prev=tempptr;
            tempptr=tempptr->next;
        }
        prev->next=new_node;
        new_node->next=tempptr;
        }
    }

}

void insertBeforeEle(struct node **head)
{
    int ele,dfield;
    struct node *tempptr,*prev;
    tempptr=*head;
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter The Element Before Which U wanna add node\n");
    scanf("%d",&ele);
    printf("Enter The Node Data Field\n");
    scanf("%d",&dfield);
    new_node->data=dfield;
    if(tempptr==NULL)
    {
        printf("No Element In The Linked List\n");
    }
    else
    {
        while(tempptr->data!=ele)
        {
            prev=tempptr;
            tempptr=tempptr->next;
        }
        if((tempptr->next==*head)&&(tempptr==*head))
        {
            new_node->next=tempptr;
            tempptr->next=new_node;
            tempptr=new_node;
            *head=tempptr;

        }
        else if((*head)->data==ele)
        {
            while(tempptr->next!=*head)
            {
                tempptr=tempptr->next;
            }
            new_node->next=*head;
            *head=new_node;
            tempptr->next=*head;

        }
        else
        {
            new_node->next=tempptr;;
            prev->next=new_node;
        }
    }
}

void insertAfterEle(struct node **head)
{
    int dfield,ele;
    char ch;
    struct node *tempptr;
    tempptr=*head;
    printf("Enter Element After which to Add:\t");
    scanf("%d",&ele);
    printf("Enter Nodes Data field\t");
    scanf("%d",&dfield);
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=dfield;
    new_node->next=NULL;
    if(tempptr==NULL)
    {
        printf("No Element In Linked List\n");
        printf("Wanna make his node as first node(Y/N)???\n");
        scanf("%*c%c",&ch);
        if(ch=='y'||ch=='Y')
        {
            tempptr=new_node;
            new_node->next=tempptr;
            *head=tempptr;
        }
        else
        {
            printf("Unsuccessful!!!");
        }

    }
    else
    {
        while(tempptr->data!=ele)
        {
                tempptr=tempptr->next;
        }
        if(tempptr->next==*head)//last element of LL
        {
            tempptr->next=new_node;
            new_node->next=*head;
        }
        else
        {
            new_node->next=tempptr->next;
            tempptr->next=new_node;
        }
    }


}

void delByIndex(struct node **head)
{
    int pos,count=1,i;
    struct node *tempptr,*prev,*tempptr2;
    tempptr=*head;
    tempptr2=tempptr;
    printf("Enter Position To Delete Element\t");
    scanf("%d",&pos);
    if(tempptr==NULL)
    {
        printf("Linked List Empty,cant Delete\n");
    }
    else
    {
        while(tempptr->next!=*head)
        {
            tempptr=tempptr->next;
            count++;
        }
        tempptr=*head;
        if(pos>count)
        {
            printf("Invalid Position\n");
        }
        else if(pos==1&&tempptr->next==*head)//Only one element was present that too got deleted so No Node To Display
        {
            tempptr=*head=NULL;
        }
        else if(pos==1)
        {
            while(tempptr2->next!=*head)
            {
                tempptr2=tempptr2->next;
            }
            *head=tempptr->next;
            free(tempptr);
            tempptr=*head;
            tempptr2->next=*head;

        }
        else
        {
            tempptr=*head;//re-initializing temp pointer
            for(i=1;i<pos;i++)//we start linked list by 1
            {
                prev=tempptr;
                tempptr=tempptr->next;
            }
            prev->next=tempptr->next;
            free(tempptr);
        }
    }

}
void delByEle(struct node **head)
{
    int ele;
    struct node *tempptr,*prev,*tempptr2;
    tempptr=*head;
    prev=tempptr;
    printf("Enter Linked List Element To Delete:\t");
    scanf("%d",&ele);
    if(tempptr==NULL)
    {
        printf("Empty Linked List,Cant Delete\n");
    }
    else
    {
        while(tempptr->data!=ele)
        {
            prev=tempptr;
            tempptr=tempptr->next;
        }
        if((tempptr->data==ele)&&(tempptr==*head)&&(tempptr->next==*head))
        {
            tempptr=*head=NULL;
        }
        else if((tempptr==*head)&&(tempptr->data==ele)&&(tempptr->next!=*head))
        {
            while(tempptr2->next!=*head)
            {
                tempptr2=tempptr2->next;
            }
            tempptr2->next=tempptr->next;
            free(tempptr);
            *head=tempptr2->next;
        }
        else// if(tempptr!=*head&&tempptr==ele&&tempptr->next==*head)
        {
            prev->next=tempptr->next;
            free(tempptr);

        }
    }
}

void reverse(struct node **head)
{

}
