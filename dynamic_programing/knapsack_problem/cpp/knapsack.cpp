#include <iostream>

int mem[100][100];


int knapSackTopDown(int w, int wt[], int val[], int n){
if(n==0||w==0)return 0;
if(mem[w][n-1]!=0)return mem[w][n-1];

if(wt[n-1]>w) return mem[w][n-1] = knapSackTopDown(w, wt, val, n-1);

    return mem[w][n-1] = std::max( val[n-1] + knapSackTopDown(w-wt[n-1], wt, val, n-1),
                knapSackTopDown(w, wt, val, n-1));


}

int knapSackBottomUp(int W, int wt[], int val[], int n){
    int i, w;

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0)
                mem[i][w] = 0;
            else if (wt[i-1] > w)
                mem[i][w] = mem[i-1][w];
            else
                mem[i][w] = std::max(val[i-1] + mem[i-1][w-wt[i-1]],  mem[i-1][w]);
        }
    }

    return mem[n][W];
}

int main() {

    int val[] = {10, 40, 30, 50};
    int wt[] = {5, 4, 6, 3};
    int  w = 10;
    int n = sizeof(val)/sizeof(val[0]);
   // std::cout<<knapSackBottomUp(w, wt, val, n)<<std::endl;
    std::cout<<knapSackTopDown(w, wt, val, n)<<std::endl;
    return 0;


    return 0;
}