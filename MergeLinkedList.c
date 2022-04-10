#include<stdio.h>
#include<stdlib.h>
struct node
{
    int ID;
    char name[10];
    char branch[10];
    int marks;
    struct node *next;

};
struct node *getnode()
{
  return(malloc(sizeof(struct node)));
}
struct node *read(struct node *x)
{
    scanf("%d%s%s%d",&x->ID,x->name,x->branch,&x->marks);
    return x;
}
struct node*addrear(struct node *first)
{
    struct node *cur,*nw;
    nw=getnode();
    nw=read(nw);
    if(first==NULL)
    {
        first=nw;
        first->next=NULL;
    }
    else
    {
        for(cur=first;cur->next!=NULL;cur=cur->next);
        cur->next=nw;
        nw->next=NULL;
    }
    return first;

}
struct node *merge(struct node *A,struct node *B)
{
    struct node *cur;
    if(A==NULL)
    A=B;
    else
    {
        for(cur=A;cur->next!=NULL;cur=cur->next);
        cur->next=B;
    }
    return A;
}
void disall(struct node *A)
{
        struct node *cur;
    if(A==NULL)
    {
            printf("no list");
    }
    else
    {
        for(cur=A;cur!=NULL;cur=cur->next)
        display(cur);
    }
    printf("\nstudents above marks 40\n");
}

void display(struct node *x)
{
    printf("ID : %d \n name : %s \n branch : %s \n marks : %d\n",x->ID,x->name,x->branch,x->marks);
}
void searchformarks(struct node *A)
{
    struct node *cur;
    if(A==NULL)
    {
            printf("no list");
    }
    else
    {
        for(cur=A;cur!=NULL;cur=cur->next)
        {
            if(cur->marks>40)
            display(cur);
        }
    }
}
int main()
{
        struct node *A,*B;
        int ch;
        A=NULL;
        B=NULL;
        do
        {
            printf("choice");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:A=addrear(A);
                            break;
                case 2:B=addrear(B);
                            break;
            }
        } while(ch!=3);
        A=merge(A,B);
        disall(A);
        searchformarks(A);
}
