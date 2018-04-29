#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void PUSH(struct node **,int);
void POP(struct node **);
void DISPLAY(struct node*);
int main()
{
    int ch,ele;
    struct node *s=NULL;
    char pch;

    while(1)
    {
        printf("\nMenu Driven Program On Stack Using Linked List\n");
        printf("1.PUSH Element\n2.POP Element\n3.Display Elements\n4.Exit\n");
        printf("Enter Your Choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: printf("Enter Element To PUSH into Stack:\t");
                scanf("%d",&ele);
                PUSH(&s,ele);
                break;
        case 2: printf("Sure Wanna PUSH Element Out Of Stack(Y/N)\t");
                scanf("%*c%c",&pch);
                if(pch=='y'||pch=='Y')
                {
                    POP(&s);
                }
                else
                    printf("POP Undo\n");
                break;
        case 3: printf("TOP Element Of Stack is:\n");
                DISPLAY(s);
                break;
        case 4:exit(0);

        default:printf("Invalid Choice!!!");

        }

    }

}

void PUSH(struct node **head,int x)
{
    struct node*top;
    top=*head;
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=top;
    top=new_node;
    *head=top;

}
void POP(struct node **head)
{
    struct node *top;
    top=*head;
    if(top==NULL)
        printf("Underflow\n");
    else
    {
        *head=top->next;
        free(top);
        top=*head;
    }

}
void DISPLAY(struct node *head)
{
    struct node *top;
    top=head;
    if(top==NULL)
        printf("Stack Empty\n");
    else
    printf("%d",top->data);

}
