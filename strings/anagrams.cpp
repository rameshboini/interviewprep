#include "basic.h"
#include <string>
#include <unordered_map>

bool isMatch(string a, string b)
{
    unordered_map<char,int> x;
    for(int i=0;i<a.length();i++)
    {
        x[a[i]]++;
    }

    for(int i=0;i<b.length();i++)
    {
        x[b[i]]--;
    }

    for(auto y = x.begin();y!=x.end();y++)
    {
        if(y->second!=0)
            return false;
    }
    return true;


}

int countAnagrams(string pat, string txt)
{
    int count = 0;
    int len1=txt.length();
    int len2=pat.length();
    for(int i=0;i<len1-len2+1;i++)
    {
        if(isMatch(txt.substr(i,len2), pat))
            count++;
    }
    return count;
}

int main()
{
    string txt = "forxxorfxdofr";
    string pat = "for";

    cout<<"Anagrams count: "<<countAnagrams(pat,txt)<<endl;
}