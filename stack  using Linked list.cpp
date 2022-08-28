#include<iostream>
using namespace std;

struct node{

    struct node* next;
    int data;
    
    public:
        node(int val)
        {
            data = val;
        }
};
bool isempty(node* head)
{
    if(head==NULL) return false;
    return true;
}
// ye sbh O(1) mei complete ho rhe hai jaise stack mei hote hai
void push(int value,node* &head)
{
    node* ptr=new node(value);
    ptr->next=head;
    head=ptr;
    

}
void pop(node* &head)
{
    if(isempty(head)==0)
    {
        cout<<"end";
        return;
    }
    node* ptr=head;
    head=head->next;
    delete (ptr);


}
int main()
{
    // push to make ll
    node*head=NULL;
    push(1,head);
     
    push(2,head);

    // while(head!=NULL)
    // {
    //     cout<<head->data<<"->";
    //     head=head->connected;
    // }
    pop(head);
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}