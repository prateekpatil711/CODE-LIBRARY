#include <iostream>
using namespace std;
int top = -1; 
    void push (int *stack , int x , int n)
    {
        if ( top == n-1 )  cout << "Stack is full.Overflow condition!" ;
        else{
            top = top +1 ;         
            stack[top] = x ;  
        }

    }
    bool isEmpty ( )
    {
        if ( top == -1 )  return true ; 
        else return false;
    }
    void pop ( ) 
    {
        if(isEmpty())  cout << "Stack is empty. Underflow condition! " << endl ;
        else  top = top - 1 ; 
    }
    int size ( ){
        return top + 1;
    }
    int topElement (int *stack){
        return stack[top];
    }

    int main( )
    {
        int *stack , stack_size;
        cin >> stack_size;
        stack = new int[stack_size];
        push(stack , 5 , stack_size) ;

        cout << "Current size of stack is " << size ( ) << endl ;

        push(stack , 10 , stack_size);
        push (stack , 24 , stack_size) ;

        cout << "Current size of stack is " << size( ) << endl ;

        //As the stack is full, further pushing will show an overflow condition.
        push(stack , 12 , stack_size) ;

        //Accessing the top element
        cout << "The current top element in stack is " << topElement(stack) << endl;

        //Removing all the elements from the stack
        for(int i = 0 ; i < stack_size;i++ )
            pop( );
        cout << "Current size of stack is " << size( ) << endl ;

        //As the stack is empty , further popping will show an underflow condition.
        pop ( );  

    }