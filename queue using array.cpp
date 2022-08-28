#include<iostream>
#include<vector>
using namespace std;
#define n 5
    int arr[n];
    int front =-1;
    int last=-1;

void enqueue(int num)
{
    if(last==n-1)
    {
        cout<<"FULL queue"<<endl;
    }
    else if(front == -1&& last==-1)
    {
        last=0;
        arr[last]=num;
        front=last;
    } 
    else{
        last++;
        arr[last]=num;
    }
    


}
void dequeue()
{
    if(front==-1 && last==-1)
    {
        cout<<"queue is empty"<<endl;
    }
    else 
    {
        int x=arr[front];
        front++;

    }
}
void peek()
{
    if(front == -1 && last==-1)
    {
        cout<<"peek is empty"<<endl;
    }
    else
    {
        cout<<arr[front]<<" "<<endl;
    }
}
void display()
{
    for(int i=front; i<last+1; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    enqueue(2);
    enqueue(3);
    enqueue(1);
    display();
    cout<<endl;
    peek();
    dequeue();
    peek();
    display();
    
}