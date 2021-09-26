#include <basic.h>
#include <unordered_map>

int largestSumZeroSubarray(int A[], int n)
{
    int sum = 0;
    int len = 0;
    unordered_map<int, int> data;
    int startInd = -1;
    int lastInd = -1;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];

        //special case to handle zero in the array
        if (A[i] == 0 && len == 0)
        {
            len = 1;
            startInd = 0;
            lastInd = 0;
        }

        if (sum == 0)
        {
            if (startInd != 0)
                startInd = 0;
            lastInd = i;

            len = i + 1;
        }

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
    int a[] = {2, 8, -3, -5, 2, 0, -4, 6, 1, 2, 1, -3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int x = largestSumZeroSubarray(a, n);
    cout << "\nSubArray length: " << x << endl;
    ;
}