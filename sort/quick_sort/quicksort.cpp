/*
author: Madhav Sainanee
*/
// Sorts array in expected O(nlogn) time
// Also includes randomized version of quicksort (commented) which almost guarantees the expected O(nlogn) time complexity instead of the worst case running time of O(n^2) regardless of input
/*
INPUT:
15
1 2 23 43 23 39 92 293 38 930 76 87 54 45 56
OUTPUT:
1 2 23 23 38 39 43 45 54 56 76 87 92 293 930 (Sorted array)
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vl vector<long long>
#define vvi vector<vector<int> >
#define vvl vector<vector<long long> >
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpii vector<pair<int, int> >
#define vpll vector<pair<long long, long long> >
#define fup(i, a, n) for (ll i = a; i < n; i++)
#define fdw(i, a, n) for (ll i = n; i > a; i--)
#define fnu for(ll i = 0; i < n; i++)
#define fnd for(ll i = n-1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define cend cout << endl;

const ll mod = 1e9 + 7;


int partition(int a[], int p, int r)
{
	int x = a[r];
	int y = p-1;
	int i = p;
	for(;i < r; i++)
	{
		if(a[i] <= x)
		{
			// cout << "y" << endl;
			y++;
			swap(a[i], a[y]);
			// cout << "checker" << endl;
		}
	}
	swap(a[y+1], a[r]);
	return y+1;
}
/*
int randomizedpartition(int a[], int p, int r)
{
	int i = p + (rand() % (r-p+1));
	swap(a[i], a[r]);
	int x = partition(a, p, r);
	return x;
}

int randomizedquicksort(int a[], int p, int r){
	if(p < r)
	{
		int q = randomizedpartition(a, p, r);
		randomizedquicksort(a, p, q-1);
		randomizedquicksort(a, q+1, r);
	}
	return 0;
}
*/
int quicksort(int a[], int p, int r)
{
	// cout << p << " " << r << " x" << endl;
	if(p < r)
	{
		int q = partition(a, p, r);
		quicksort(a, p, q-1);
		quicksort(a, q+1, r);
	}
	return 0;
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	quicksort(a, 0, n-1);
	// randomizedquicksort(a, 0, n-1);
	copy(a, a+n, ostream_iterator<int>(cout, " "));
	return 0;
}
