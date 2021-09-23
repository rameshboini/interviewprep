#include <array.h>
#include <utils.h>
void insertionsort(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key = a[i];
        int j =i-1;
        for(;j>=0 && a[j]>key;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1] = key;
    }
}

int main()
{
    int a[] = {1,5,4,3,7,2};
    int n = sizeof(a)/sizeof(a[0]);
    print(a,n);
    insertionsort(a,n);
    print(a,n);
}