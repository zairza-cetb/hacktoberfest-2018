/*
author: orthodoxparadox
*/

#include <bits/stdc++.h>

using namespace std;
#define int ll
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
#define mll map<ll, ll>
#define mii map<int, int>
#define msi map<string, int>
#define msl map<string, ll>
#define umll unordered_map<ll, ll>
#define umii unordered_map<int, int>
#define umsi unordered_map<string, int>
#define umsl unordered_map<string, ll>
#define fup(i, a, n) for (ll i = a; i < n; i++)
#define fdw(i, a, n) for (ll i = n-1; i >= a; i--)
#define fnu for(ll i = 0; i < n; i++)
#define fnd for(ll i = n-1; i >= 0; i--)
#define fau(i, v) for(auto i:v)
#define rev(s) reverse(all(s))
#define oill ostream_iterator<ll>(cout, " ")
#define oiint ostream_iterator<int>(cout, " ") 
#define pb emplace_back
#define push_back emplace_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define all(a) a.begin(), a.end()
#define zero(a) memset(a, 0, sizeof(a))
// #define x real()
// #define y imag()
typedef complex<double> point;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#ifdef __APPLE__
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)

    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1)
    {
        cerr << name << " : " << arg1 << endl;
    }

    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args)
    {
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1 << "  ";
        __f(comma + 1, args...);
    }

#else
#define dbg(...)
#endif

const int mod = 1e9 + 7;

int fast_exp(int base, int expo) 
{
    int res=1;
    while(expo>0) 
    {
	if(expo&1) 
	{
		res=(res*base)%mod;
	}
	base=(base*base)%mod;
	expo>>=1;
    }
    return res;
}

const int N = 1e5+10;
vector<pair<int, int>> adj[N];
bool vis[N] = {0};
void dijkstra(int v, int d[], int n)
{
	// fill(vis, vis+n, false);
	fill(d, d+n, 1e18+10);
	d[v] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({d[v], v});
	while(!pq.empty())
	{
		int u = pq.top().ss;
		pq.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u] = true;
		for(auto it : adj[u])
		{
			if(d[it.ff] > d[u] + it.ss)
			{
				d[it.ff] = d[u] + it.ss;
				pq.push({d[it.ff], it.ff});
			}
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	#ifdef __APPLE__
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    	freopen("error.txt", "w", stderr);
	#endif
	
	
	return 0;
}