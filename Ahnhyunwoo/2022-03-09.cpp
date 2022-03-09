#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <iostream>
using namespace std;
bool check[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    memset(check, false, sizeof(check));
    for(int i = 0; i < results.size();i++){
        check[results[i][0]][results[i][1]] = true;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1; j<= n;j++) {
            for(int k =1;k <=n;k++) {
                if(check[j][i] && check[i][k]) {
                    check[j][k] = true;
                }
            }
        }
    }
    for(int i = 1; i <= n;i++) {
        int cnt = 0;
        for(int j = 1; j<=n;j++) {
            if(check[i][j] || check[j][i]) {
                cnt++;
            }
        }
        if(cnt == n-1) {
            answer++;
        }
    }
    return answer;
}
