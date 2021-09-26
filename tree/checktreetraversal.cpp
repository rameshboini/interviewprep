//GFG-100 2

/*
Given Preorder, Inorder and Postorder traversals of some tree of size N. 
The task is to check if they are all of the same tree or not.
*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
    	if(N==0)
    	return true;
    	if(N==1)
    	{
    	    return (preorder[0]==inorder[0] && preorder[0]==postorder[0]);
    	}
    	
    	//find index of inorder
    	int ind = -1;
    	for(int i=0;i<N;i++)
    	{
    	    if(preorder[0]==inorder[i])
    	    {
    	        ind=i;
    	        break;
    	    }
    	}
    	
    	if(ind == -1)
    	return false;
    	
    	//check in post order aswell
    	int post = -1;
    	for(int i=0;i<N;i++)
    	{
    	    if(preorder[0]==postorder[i])
    	    {
    	        post=i;
    	        break;
    	    }
    	}
    	
    	if(post == -1)
    	{
    	    return false;
    	}
    	
    	//check left tree and right tree
    	return (checktree(preorder+1, inorder, postorder, ind) && 
    	checktree(preorder+ind+1, inorder+ind+1, postorder+ind, N-ind-1));
    	
    } 

};


// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 

  // } Driver Code Ends