#include "basic.h"
#include <string>
#include <unordered_map>

int countAnagrams(string pat, string txt)
{
    int count = 0;
    int len1=txt.length();
    int len2=pat.length();

    if(len1 <= 0 || len2 <= 0 || len1 <len2)
        return 0;

    const int CHARS = 256;
    array<char, CHARS> patA;
    array<char, CHARS> txtA;
    patA.fill(0);
    txtA.fill(0);
    int i=0;
    for(;i<len2;i++)
    {
        patA[CHARS-pat[i]]++;
        txtA[CHARS-txt[i]]++;
    }
    if(patA==txtA)
    {
        count++;
    }

    for(;i<len1;i++)
    {
        txtA[CHARS-txt[i]]++;
        txtA[CHARS-txt[i-len2]]--;

        if(patA==txtA)
    {
        count++;
    }
    }
    return count;
}

int main()
{
    string txt = "";
    string pat = "";

    cout<<"Anagrams count: "<<countAnagrams(pat,txt)<<endl;
}