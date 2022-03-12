#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int map[252][252];
int ex[252][252];
vector<pair<int, int>>point;
int solution(int width, int height, vector<vector<int>> diagonals) {
    int answer = 0;
    memset(map, 0, sizeof(map));
    for(int i = 0 ;i < diagonals.size();i++) {
        int x = diagonals[i][0] + 1;
        int y = diagonals[i][1];
        point.push_back(make_pair(x, y));
        x -= 1;
        y += 1;
        point.push_back(make_pair(x, y));
    }
    for(int i = 1; i <= width + 1;i++) {
        map[1][i] = 1;
    }
    for(int j = 1; j <= height + 1;j++) {
        map[j][1] = 1;
    }
    for(int i = 2; i <= width + 1;i++) {
        for(int j =2; j<= height + 1;j++) {
            map[j][i] = map[j - 1][i] + map[j][i - 1];
        }
    }
    for(int i = 0; i < point.size();i++) {
        memset(ex, 0, sizeof(ex));
        int x = point[i].first;
        int y = point[i].second;
        int startX = x;
        int startY = y;
        ex[y][x] = map[y][x];
        x++;
        while(x != width + 2) {
            ex[startY][x] = map[startY][startX];
            x++;
        }
        y++;
        while(y != height + 2) {
            ex[y][startX] = map[startY][startX];
            y++;
        }
        for(int j = startX + 1; j <= width + 1;j++) {
            for(int k = startY + 1; k <= height + 1;k++) {
                ex[k][j] = ex[k -1][j] + ex[k][j - 1];
            }
        }
        cout<<ex[height + 1][width + 1]<<"\n";
        answer += ex[height + 1][width + 1];
        answer %= 10000019;
    }

    return answer;
}
