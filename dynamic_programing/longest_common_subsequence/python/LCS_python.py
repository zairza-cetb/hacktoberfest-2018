def lcs(s,t):
    #s,t are strings to be compared. returns integer containing lenth of LCS
    #complexity is O(n*m)
    n=len(s)
    m=len(t)
    dp=[[0 for i in range(m)] for i in range(n)]
    
    for i in range(n):
        for j in range(m):
            if(s[i]==t[j]):
                if(i==0 or j==0):
                    dp[i][j]=1
                else:
                    dp[i][j]=dp[i-1][j-1]+1
            
            else:
                if(i==0 or j==0):
                    dp[i][j]=0
                else:
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j])
    #print(dp)
    return dp[n-1][m-1]
    

if __name__== "__main__":
    print(lcs("AGGTAB","GXTXAYB"))
    print(lcs("abcdefg","bcdfg"))
    