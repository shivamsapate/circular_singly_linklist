#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;

}*last=NULL;
void insert_b();
void insert_e();
void delete_e();
void delete_b();
void display();
void main()
{
    int c;
    while(1)
   {
    printf("\n\nThe choices are:\n1.insert at begining\n2.insert at end \n3.delete at begining\n4.delete at end\n5.display\n6.exit");
    printf("\nEnter the choice:- ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:insert_b();
        break;
        case 2:insert_e();
        break;
        case 3:delete_b();
        break;
        case 4:delete_e();
        break;
        case 5:display();
        break;
        case 6:exit(0);
        default:printf("enter the correct choice");
    }
   }
}
void insert_b()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&temp->data);
    if(last==NULL)
    {
        last=temp;
        temp->next=temp;
    }
    else
    {
        temp->next=last->next;
        last->next=temp;
    }
}
void insert_e()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&temp->data);
    if(last==NULL)
    {
        last=temp;
        last->next=temp;
    }
    else
    {
        temp->next=last->next;
        last->next=temp;
        last=temp;
        
    }
}
void display()
{
    struct node *temp;
    temp=last;
    do
    {
        temp=temp->next;
        printf("%d\t",temp->data);
    }
    while(last->next!=temp->next);
    
}
void delete_b()
{
    struct node *temp;
    struct node *prv;
    temp=last;
    
    if(temp->next!=NULL)
    { 
        temp=temp->next;
        prv=temp;
        prv=prv->next;
    }
    last->next=prv;
    free(temp);

}
void delete_e()
{
    struct node *temp;
    struct node *prv;
    temp=last;
        
    do
    {
        prv=temp;        
        temp=temp->next;
    }
    while(temp!=last);
    prv->next=last->next;
    last=prv;
    free(temp);

}
