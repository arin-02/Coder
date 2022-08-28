#include<iostream>
using namespace std;

#define n 5
int arr[n];
int top=-1;

void push(int num)
{
    if(top==n-1) cout<<"overflow"<<endl;
    else if(top==-1)
    {
        top=0;
        arr[top]=num;
        top++;
    }
    else
    {
        arr[top]=num;
    top++;
    }
}
void display()
{
    for(int i=top-1; i>=0; i--)
    {
        cout<<arr[i]<<" ";
    }
}
void pop()
{
    if(top==-1)
    {
        cout<<"underflow"<<endl;
    }
    top=top-1;

}
int main()
{
    push(2);
    push(3);
    push(4);
    display();
    cout<<endl;
    pop();
    display();
}