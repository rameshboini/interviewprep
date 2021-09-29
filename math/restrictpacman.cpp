// { Driver Code Starts
//Initial Template for C++

//GFG-100 8
#include <bits/stdc++.h> 
#include <unordered_set>
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


class Solution{
    public:
    int candies(int m, int n) 
    { 
    	queue<int> Q;
    	unordered_set<int> S;
    	int max = m*n-m-n;
    	if(max<=1)
    	    return 1;
    	int ans=1;//for 1 value
    	Q.emplace(max);
    	S.emplace(max);
    	
    	while(!Q.empty()){
    	    int t = Q.front();
    	    
    	    if(t-m>1 && S.find(t-m)==S.end())
    	    {
    	        Q.emplace(t-m);
    	        S.emplace(t-m);
    	    }
    	    if(t-n>1 && S.find(t-n)==S.end())
    	    {
    	        Q.emplace(t-n);
    	        S.emplace(t-n);
    	    }
    	    ans++;
    	    Q.pop();
    	}
    	return ans;
    } 
};

// { Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		Solution obj;
		cout << obj.candies(m,n)<<endl; 
	}
	return 0; 
} 