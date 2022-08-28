#include<iostream>

using namespace std;

struct  node
{
     node* next=NULL;
     int data;
        public:
                node(int val)
                {
                    data = val;
                }
};
// ye order of n hai lekin queue mei order of 1 hota hai to isliye last pointer bnao jo last value ko store rkhta ho...traverse nhi krna pdega
// void enqueue(int num,node*&head)
// {
//     node*ptr=head;
//     node* thatnum=new node(num);
//     if(head == NULL)
//     {
//         head=thatnum;
//         return ;
//     }
//     while(ptr->next != NULL)
//     {
//         ptr=ptr->next;
//     }
//     ptr->next=thatnum;
    
// }
// abh ye O(1) mei ho gya
void enqueue(int num,node*&head,node* &last)
{
    node*ptr=new node(num);
    if(head == NULL && last == NULL)
    {
        head=last=ptr;
        return ;
    }
    last->next=ptr;
    last=ptr;
}
void dequeue(node*&head)
{
    if(head == NULL)
    {
        cout<<"dequeue failed"<<endl;
    }
    node*x=head;
    head=head->next;
    delete(x);
}
void display(node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}

int main()
{
    node * head=NULL;
    node * last=NULL;
    enqueue(5,head,last);
    enqueue(4,head,last);
    enqueue(3,head,last);
    display(head);
    cout<<endl;
    dequeue(head);
    dequeue(head);
    display(head);
    cout<<endl;
}