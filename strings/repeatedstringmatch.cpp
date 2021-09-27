/*Given two strings A and B. 
The task is to find the minimum number of times A has to be repeated such that B is a substring of it. 
If no such solution exists, print -1.*/

//GFG-100 6

#include "basic.h"
#include <string>

bool isSubstring(string A, string B)
{
    cout<<A<<endl<<B<<endl;
    int a = A.length();
    int b = B.length();

    for(int i=0;i<=b-a;i++)
    {
        int j=0;
        for(;j<a;j++)
        {
            if(A[j]!=B[i+j])
                break;
        }
        if(j==a)
            return true;
    }
    return false;
}

int minrepeat(string A, string B)
{
    int a = A.length();
    int b = B.length();

    int count = 1;

    string tmp = A;

    while (tmp.length() < b)
    {
        tmp += A;
        count++;
    }

    if (isSubstring(B, tmp))
    {
        return count;
    }

    tmp += A;
    count++;

    if (isSubstring(B, tmp))
    {
        return count;
    }

    return -1;
}

int main()
{
    string A = "abcd";
    string B = "abcd";

    cout << "A should be repeated [ " << minrepeat(A, B) << " ] times to become B" << endl;
}
