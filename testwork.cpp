#include<bits/stdc++.h>
using namespace std;
vector<int> solve(int A)
{
	set<int> st;
	for(int i=1;i<A;i++)
	{
	long long int x=pow(2,i);
	if(x<A)
	{
		st.insert(x-1); 
		st.insert(x); 
		st.insert(x+1); 
	}

	}
	if(st.find(1)!=st.end() && st.find(4)!=st.end() )
	{
		st.erase(1);
	}
	
	vector<int> v;
	for(auto it:st)
	{
		v.push_back(it);
	}
	return v;

}
int main()
{
	int A=10;
	vector<int> v=solve(A);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" "<<endl;
	}
}