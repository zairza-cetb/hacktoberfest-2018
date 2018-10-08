#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lpsH(string s, int start, int end, int **output){
	if(start > end){
		return 0;
	}

	if(s.length() == 1 || start == end){
		return 1;
	}
	
	if(output[start][end] > -1){
		return output[start][end];
	}
	if(s[start] == s[end]){
		output[start][end] = 2 + lpsH(s, start+1, end-1, output);
		return output[start][end];
	}
	output[start][end] = max(lpsH(s, start+1, end, output), lpsH(s, start, end-1, output));
	return output[start][end];
}
int lcs(string s1, string s2){
  int n1 = s1.length();
  int **output = new int*[n1+1];
  
  for(int i = 0; i <= s1.length(); i++){
    output[i] = new int[s2.length()+1];
    for(int j = 0; j <= s2.length(); j++){
      output[i][j] = -1;
    }
  }
  return lpsH(s1, 0, s1.length()-1, output);
}
int main(){
	string s1, s2;
	cin >> s1 >> s2;
	cout << lcs(s1, s2);
}
