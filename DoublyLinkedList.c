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
struct node*deletefront(struct node *first)
{
    struct node *cur,*prev;
    prev=first;
    if(first==NULL)
        printf("no list");
    else
        {
                for(cur=first;cur->next!=first;cur=cur->next);
                {
                    first=first->next;
                    first->pr=cur;
                    cur->next=first;
                    free (prev);
                }
        }
        return (first);
}
void dis(struct node *x)
{
    struct node *cur;
    for(cur=x;cur->next!=x;cur=cur->next)
    printf("%d-> ",cur->data);
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
    int ch;
    struct node *first=NULL;
    first=getnode();
    first=NULL;
    do
    {
      printf("choice   ");
      scanf("%d",&ch);
    switch(ch)
    {
        case 1: first=addfront(first);
        break;
        case 2: first=addrear(first);
        break;
        case 3:dis(first);
        break;
        case 4: first=deleterear(first);
        break;
        case 5: first=deletefront(first);
        break;
        case 6: redis(first);
        break;
    }
    }while(ch!=8);
}



