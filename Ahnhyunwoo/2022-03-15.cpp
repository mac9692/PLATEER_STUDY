#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int schoolMap[101][101];
void schoolMapSetting(vector<vector<int>> puddles) {
    for(int i = 0; i < puddles.size();i++) {
        int width = puddles[i][0];
        int height = puddles[i][1];
        schoolMap[height][width] = -1;
    }
}
int cntRoad(int width, int height) {
    queue<pair<int, int>>q;
    q.push(make_pair(1, 1));
    bool check = false;
    int cnt = 0;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        int rightY = y;
        int rightX = x + 1;
        if(rightY == height && rightX == width) {
            check = true;
            cnt ++;
        }else if(!check && rightX <= width && schoolMap[rightY][rightX] != -1) {
            q.push(make_pair(rightY, rightX));
        }
        int downX = x;
        int downY = y + 1;
        if(downY == height && downX == width) {
            check = true;
            cnt ++;
        }else if(!check && downY <= height && schoolMap[downY][downX] != -1) {
            q.push(make_pair(downY, downX));
        }
    }
    return cnt;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    memset(schoolMap, 0, sizeof(schoolMap));
    schoolMapSetting(puddles);
    answer = cntRoad(m, n);
    return answer;
}
