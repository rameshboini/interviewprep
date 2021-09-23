#include <array.h>
#include <utils.h>


void selectionsort(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        int idx=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                idx=j;
            }
        }
        if(i!=idx)
        {
            swap(a[i],a[idx]);
        }
    }
}

int main()
{
    int a[]={1,5,4,3,7,2};
    int n = sizeof(a)/sizeof(a[0]);
    print(a,n);
    selectionsort(a,n);
    print(a,n);

    return 0;
}