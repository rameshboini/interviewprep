#include "basic.h"
#include <bits/stdc++.h>


//GFG-100


// int findLogOfN(int n)
// {
//     int c = 0;
//     while(n)
//     {
//         c++;
//         n=n>>1;
//     }
//     return c-1;
// }
int setBitsTillNOpt(int n)
{
    if(n<=1)
        return n;
    int x = log2(n);
    return (x*pow(2,x-1)) + (n-pow(2,x)+1) + setBitsTillNOpt(n-pow(2,x));
}
int main()
{
    unsigned int n;
    cin >> n;
    unsigned int count = 0;

    // //O(1) to find set bits in number N
    // //initialise 2^8 array and use it four times for 4 octets of 32 bit interger
    // int bits256[256] = {0};
    // for (int i = 0; i < 256; i++)
    // {
    //     bits256[i] = (i & 1) + bits256[i / 2];
    // }

    // //now sum all set bits from 1 to N==>O(N)
    // for (int i = 1; i <= n; i++)
    // {
    //     count += bits256[i & 0xff] +
    //              bits256[(i >> 8) & 0xff] +
    //              bits256[(i >> 16) & 0xff] +
    //              bits256[i >> 24];
    // }


    //sum of all setbits from 1 to N using O(logn)
    //number bits till power of 2 is calcluated using y*2^(y-1)+1==> y is proper power 2 like 1,2,4,8,16,etc
    //1.number set bits till x-1 where x=logN, x*2^(x-1)
    //2. number of set bits from x to N is N-2^x+1  and recursively calculate N-2^x
    count=setBitsTillNOpt(n);
    cout << "Number of Set bits from 1 to N: " << count << endl;
}