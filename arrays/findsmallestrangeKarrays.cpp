// C++ program to finds out smallest range that includes
// elements from each of the given sorted lists.
#include <bits/stdc++.h>

using namespace std;

#define N 5

// array for storing the current index of list i
// This function takes an k sorted lists in the form of
// 2D array as an argument. It finds out smallest range
// that includes elements from each of the k lists.
pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
{
	int min1 = INT_MAX, max1=INT_MIN, range=INT_MAX, lo=0, hi=0;
	priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> q;
	for(int i=0;i<k;i++)
	{
		q.push({KSortedArray[i][0], {i,0}});
		min1=min(min1, KSortedArray[i][0]);
		max1=max(max1, KSortedArray[i][0]);
	} 
	while(true)
	{
		auto x = q.top();
		q.pop();
		int m = x.first;

		if(max1-m<range)
		{
			min1 = m;
			range = max1-min1;
			lo = min1;
			hi = max1;
		}

		int a = x.second.first;
		int b = x.second.second;

		if(b == n-1)
			break;
		
		q.push({KSortedArray[a][b+1],{a,b+1}});
		if(KSortedArray[a][b+1]>max1)
		{
			max1 = KSortedArray[a][b+1];
		}
	}

	return {lo,hi};

}

// Driver program to test above function
int main()
{
	int KSortedArray[][N] = {
		{ 4, 7, 9, 12, 15 },
		{ 0, 8, 10, 14, 20 },
		{ 6, 12, 16, 30, 50 }
	};

	int k = sizeof(KSortedArray) / sizeof(KSortedArray[0]);

	findSmallestRange(KSortedArray, N, k);

	return 0;
}
// This code is contributed by Aditya Krishna Namdeo
