#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50

struct stack
{
    int s[max];
    int top;
};
int empty(struct stack stk)
{
    return(stk.top==-1);
}
void push(struct stack *stk,int data)
{
    stk->top=stk->top+1;
    stk->s[stk->top]=data;
}
int *pop(struct stack *stk)
{
    return(stk->s[stk->top--]);
}
int isfull(struct stack stk)
{
    return(stk.top==max-1);
}
void enqueue(struct stack *stk,int data)
{int x=data;
        push(stk,x);
}
int dequeue(struct stack *stk,struct stack *stk2)
{
    int i,x,m,f;
    if(!(empty(*stk)))
    {
        m=stk->top;
        printf("\nm->%d",m);
        for(i=0;i<=m;i++)
        {
            push(stk2,pop(stk));
        }
        f=pop(stk2);
        if(!(empty(*stk2)))
        {
            m=stk2->top;
            for(i=0;i<=m;i++)
            {
                int x=pop(stk2);
                push(stk,x);
            }
        }
        else
            printf("\nqueue empty");
    }
    else
    {
        printf("queue empty");
        return;
    }
    return f;
}
void display(struct stack stk)
{int x,i;
    if(!(empty(stk)))
{
    x=stk.top;
    printf("\stktop: %d",x);
    for(i=0;i<=x;i++)
    {
        printf("%d->",stk.s[i]);
    }
}
else
    printf("\n queue empty");
}
int main()
{struct stack stk,stk2;
int num,choice,x,i;
stk.top=(-1);
stk2.top=(-1);
do
{
printf("\n\nQUEUE OPERATIONS\n\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n\n");
scanf("%d",&choice);
switch (choice)
{
case 1:
printf("\nEnter item : ");
scanf("%d",&num);
enqueue(&stk,num);
break;
case 2:
if(!(empty(stk)))
{
    printf("\nDequeued element : %d",dequeue(&stk,&stk2));
printf("\nstk->top : %d",stk.top);
}
else
printf("\nEMPTY QUEUE\n");
break;
case 3: display(stk);
break;
}}while(choice!=4);
return 0;
}

