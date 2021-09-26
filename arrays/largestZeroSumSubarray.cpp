#include <basic.h>
#include <unordered_map>

int largestSumZeroSubarray(int A[], int n)
{
    int i = -1;
    int sum = 0;
    int len = 0;
    
    unordered_map<int, int> data;
    data[sum]=i;

    int startInd = -1;
    int lastInd = -1;

    for (; i < n; i++)
    {
        sum += A[i];

        //if sum already exists in map, update len for that sum
        if (data.find(sum) != data.end())
        {
            int x = len;
            len = max(len, i - data[sum]);
            if (len > x)
            {
                startInd = data[sum] + 1;
                lastInd = i;
            }
        }
        else
        {
            //store sum at the index in map
            data[sum] = i;
        }
    }

    if (startInd!=-1 && lastInd!=-1)
    {
        cout << "Printig array: ";
        for(int i = startInd;i<=lastInd;i++)
        {
            cout<<A[i]<<" ";
        }
    }

    return len;
}

int main()
{
    int a[] = {1,2,3};
    int n = sizeof(a) / sizeof(a[0]);
    int x = largestSumZeroSubarray(a, n);
    cout << "\nSubArray length: " << x << endl;
    ;
}