#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *pr;
};
struct node *getnode()
{
    struct node *x;
    x=(struct node*)malloc(sizeof(*x));
    return x;
}
struct node*addrear(struct node *first)
{
    struct node *cur,*nw;
    nw=getnode();
    scanf("%d",&nw->data);
    if(first==NULL)
{
            first=nw;
        first->next=first;
        first->pr=first;
}
    else
    {
            for(cur=first;cur->next!=first;cur=cur->next);
           {
            nw->pr=cur;
            nw->next=first;
            cur->next=nw;
            first->pr=nw;
           }
    }
    return first;
}
struct node*addfront(struct node *first)
{
    struct node *cur,*nw;
    nw=getnode();
    scanf("%d",&nw->data);
    if(first==NULL)
{
            first=nw;
        first->next=first;
        first->pr=first;
}
    else
    {
        for(cur=first;cur->next!=first;cur=cur->next);
        {
            nw->pr=cur;
            nw->next=first;
            cur->next=nw;
            first->pr=nw;
            first=nw;
        }
    }
    return first;
}



struct node*deleterear(struct node *first)
{
    struct node *cur,*prev;
    if(first==NULL)
        printf("no list");
    else
        {
            for(cur=first,prev=NULL;cur->next!=first;prev=cur,cur=cur->next);
                    prev->next=first;
                    first->pr=prev;
            free(cur);
        }
        return (first);
}
void dis(struct node *x)
{
    struct node *cur;
    for(cur=x;cur->next!=x;cur=cur->next)
    printf("%d _  ",cur->data);
    printf("%d\n",cur->data);
}
void redis(struct node *x)
{
    struct node *cur;
    for(cur=x->pr;cur!=x;cur=cur->pr)
    printf("%d-> ",cur->data);
    printf("%d\n",cur->data);
}

int main()
{
    int ch,x,i;
    struct node *first=NULL;
    first=getnode();
    first=NULL;
    printf("\nEnter the number of songs to be added in the playlist: ");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        printf("\nenter the song number");
        first=addrear(first);
    }
    do
    {
        printf("enter the choice: 1->add song, 3->delete last song ,2->display playlist, 4->exit");
      printf("choice   ");
      scanf("%d",&ch);
    switch(ch)
    {
        case 1: first=addfront(first);
        break;
        case 2:dis(first);
        break;
        case 3:first=deleterear(first);
        break;
    }
    }while(ch!=4);
}



