#include <array.h>
#include <utils.h>

void bubblesort(int a[], int n){
    for(int i=0;i<n-1;i++)
    {
        bool swapped = false;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
        {
            break;
        }
    }

}

int main()
{
    int a[] = {1,5,4,3,7,2};
    int n = sizeof(a)/sizeof(a[0]);
    print(a,n);
    bubblesort(a,n);
    print(a,n);
}
