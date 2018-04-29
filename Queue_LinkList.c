//mintain front and rear,from front do dequeue and rear do enqueue
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void enqueue(struct node **,struct node **,int );
void dequeue(struct node **,struct node**);
void display(struct node *,struct node *);
int main()
{
    int ch,dfield;
    struct node*s1,*s2;
    s1=s2=NULL;
    char pch;
    while(1)
    {

        printf("\nMenu Driven Program On Queue Using Linked List\n");
        printf("1.Enter Node\n2.Delete Node\n3.Display\n4.Exit\n");
        printf("Enter Your Choice\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter Node Data to Add in Queue\n");
                    scanf("%d",&dfield);
                    enqueue(&s1,&s2,dfield);
                    break;
            case 2 :printf("Are you sure wanna Dequeue(y/n)???");
                    scanf("%*c%c",&pch);
                    if(pch=='y'||pch=='Y')
                        dequeue(&s1,&s2);
                    else
                        printf("Operation Discarded By User\n");
                    break;
            case 3: display(s1,s2);
                    break;
            case 4: exit(0);
            default:printf("Invalid Choice\n");
        }
    }

return 0;
}
void enqueue(struct node **head,struct node **tail,int ele)
{
    struct node *front,*rear;
    front =*head;
    rear=*tail;
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->next=NULL;
    if(front==NULL&&rear==NULL)
    {
        front=rear=new_node;
        *head=*tail=new_node;
        printf("Enqueue Successful...\n");
    }
    else
    {
        rear->next=new_node;
        rear=new_node;
        *tail = rear;
        printf("Enqueue Successful...\n");
    }


}
void dequeue(struct node **head,struct node **tail)
{
    struct node*front,*rear;
    front=*head;
    rear=*tail;
    if(front==NULL)
        printf("Underflow\n");
    else if(front==rear)
    {
        front=rear=NULL;
        *head=front;
        *tail=rear;
        printf("Dequeue Successful...\n");
    }

    else
    {
        *head=(*head)->next;
        free(front);
        front=*head;
        printf("Dequeue Successful...\n");
    }
}

void display(struct node *head,struct node *tail)
{
    struct node *front,*rear;
    front=head;
    rear=tail;
    if(front==NULL&&rear==NULL)
        printf("Queue Is Empty\n");
    else
    {
        printf("Last Element: %d\n",rear->data);
        printf("First Element: %d\n",front->data);
    }
}
