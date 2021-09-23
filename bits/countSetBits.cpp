#include "basic.h"

int main(){
    unsigned int n;
    cin>>n;
    unsigned int count = 0;
    //O(logn)
    // while(n)
    // {
    //     count+=n&1;
    //     n>>=1;
    // }

    //O(logn)
    // while(n)
    // {
    //     n&=(n-1);
    //     count++;
    // }



    //O(1)
    //initialise 2^8 array and use it four times for 4 octets of 32 bit interger

    int bits256[256]={0};
    for(int i=0;i<256;i++)
    {
        bits256[i]=(i&1)+bits256[i/2];
    }

    count = bits256[n&0xff]+
        bits256[(n>>8)&0xff]+
        bits256[(n>>16)&0xff]+
        bits256[n>>24];
        
    cout<<count<<endl;
}