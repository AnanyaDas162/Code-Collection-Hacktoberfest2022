#include <iostream>
using namespace std;
#define MAX 5
int stack[MAX];
int top = -1;
int isFull()
{

    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void peek()
{
    if (isEmpty()){
        cout<<"stack is empty\n";
    }
    else
    {
        cout<< stack[top];
    }
}
void push(int x)
{

    if (isFull())
    {
        cout<<"Overflow\n";
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    int item;
    if (isEmpty())
    {
        cout<<"underflow\n";
    }
    else
    {
        item = stack[top];
        top--;
        cout<< item;
    }
}

void display()
{
    int i;
    if (top >= 0)
    {
        cout<<"STACK :";
        for (i = top; i >= 0; i--)
            cout<< stack[i]<<endl;
    }
    else
    {
        cout<<"The STACK is empty\n";
    }
}
int main()
{

    int ch;

    do
    {

        cout<<"Enter choice: 1:push 2:pop 3:peek 4:display 0.Exit\n";
        cin>>ch;
        switch (ch)
        {
           case 1:
        {
            int x;
            cout<<"Enter data: ";
            cin>>x;
            push(x);
        }
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
      
        case 4:
            display();
            break;
        default:
            cout<<"Invalid choice\n";
        }
    } while (ch != 0);
    return 0;
}
