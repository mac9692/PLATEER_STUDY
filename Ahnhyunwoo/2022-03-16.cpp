#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int schoolMap[101][101];
void schoolMapSetting(vector<vector<int>> puddles,int m, int n) {
    for(int i= 0; i < puddles.size();i++) {
        int x = puddles[i][0];
        int y = puddles[i][1];
        schoolMap[y][x] = 0;
        if(x == 1) {
            for(int j = y; j <=n; j++)
                schoolMap[j][1] = 0;
        }

        if(y == 1) {
            for(int j = x; j <= m; j++)
                schoolMap[1][j] = 0;
        }
    }
}


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    memset(schoolMap, -1 ,sizeof(schoolMap));
    for(int i = 1; i <= m;i++) {
        schoolMap[1][i] = 1;
    }
    for(int i = 1; i <= n;i++) {
        schoolMap[i][1] = 1;
    }
    schoolMapSetting(puddles, m, n);
    for(int i = 2; i <= n;i++) {
        for(int j = 2; j <= m;j++) {
            if(schoolMap[i][j] == 0) {
                continue;
            }
            schoolMap[i][j] = (schoolMap[i][j - 1] + schoolMap[i - 1][j]) % 1000000007;
            
        }
    }
    answer = schoolMap[n][m];
    return answer;
}
