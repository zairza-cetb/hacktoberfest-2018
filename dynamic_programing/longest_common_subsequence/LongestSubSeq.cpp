#include<bits/stdc++.h>

using namespace std;

int lis(vector<int> &A) {
     if(A.size() == 0){
        return 0;
    }
    
    vector<int> val(A.size(), 1);
    
    int sol = 1;
    
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]){
                val[i] = max(val[j]+1, val[i]);
                if(val[i] > sol){
                    sol = val[i];
                }
            }
        }
    }
    
    return sol;
}

int main(void)
{
	vector<int> A;
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		A.push_back(k);
	}
	cout<<lis(A)<<endl;
	return 0;
}
