#include<iostream>
using namespace std;

// same ques as maximum adjacent sum bs isme circular hai

// same code hai bs 2 parts mei todo ... 1st part 1st index se end tk ek vector<int> temp1
// temp2 vector mei last index vala chd ke baaki saare lelo
// last mei return max(temp1, temp2);krdo
int main()
{
    int arr[]={2,3,2,3,5};
    int n=5;
    int a=solve(n-2,arr,1);
    int b=solve(n-2,arr,3);
}