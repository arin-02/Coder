#include<iostream>
using namespace std;

class test{

    int arr[6];
    public:

            void takeinput()
            {
                for(int i=0;i<6;i++)
                {
                    cin>>arr[i];
                    
                }

            }
            void display()
            {
                for(int i=0;i<6;i++)
                {
                cout<<i+1<<" :- "<<arr[i]<<endl;

                }
            }
            
            friend test operator -(test &ar);

};
test  operator -(test &ar)
{
    
        for(int i=0;i<6;i++)
            {
                ar.arr[i]=-ar.arr[i];
            }
            return ar;
}
int main()
{
    test one;
    
    one.takeinput();
    one=-one;
    one.display();

}