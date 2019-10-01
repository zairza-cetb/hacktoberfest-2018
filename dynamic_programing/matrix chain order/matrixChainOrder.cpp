#include <iostream>
#include <utility>
#include <limits>
#include <string>
#include <vector>

void solution(std::vector<std::vector<int>>&brackets, char& name, std::string& s, int start, int end){
    if(start == end){
        s.push_back(name++);
        return;
    }
    s.push_back('[');
    solution(brackets, name, s, start, brackets[start][end]);
    solution(brackets, name, s, brackets[start][end]+1, end);
    s.push_back(']');
}

std::pair<int, std::string> matrixChainOrder(std::vector<int>&dims){
    ssize_t n = dims.size();
    std::vector<std::vector<int>> m(n, std::vector<int>(n)), brackets(n, std::vector<int>(n));
    for(int i = 1;i < n;i++)
        m[i][i] = brackets[i][i] = 0;
    for(int l = 2;l < n;l++){
        for(int i = 1;i < n-l+1;i++){
            int j = i+l-1;
            m[i][j] = std::numeric_limits<int>::max();
            for(int k = i;k < j;k++){
                int x = m[i][k] + m[k+1][j] + dims[i-1]*dims[k]*dims[j];
                if(x < m[i][j]){
                    m[i][j] = x;
                    brackets[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    std::string s;
    solution(brackets, name, s, 1, n-1);
    std::pair<int, std::string> res(m[1][n-1], s);
    return res;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> dims(n);
    for(int& x : dims)
    std::cin >> x;
    std::pair<int, std::string> res(matrixChainOrder(dims));
    std::cout << "Minimum no of operations = "  << res.first << std::endl;
    std::cout << "Matrix Order : " << res.second << std::endl;
    return 0;
}