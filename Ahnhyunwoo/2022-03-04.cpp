#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int dis[501][501];
vector<vector<int>> triangles;
int func(int y, int x) {
    int &re = dis[y][x];
    if(re != -1) {
        return re;
    }
    re = triangles[y][x];
    if(y + 1 >= triangles.size()) {
        return re;
    }
    re = max(re + func(y + 1, x), re + func(y + 1, x + 1));
    return re;
    
}

int solution(vector<vector<int>> triangle) {
    triangles = triangle;
    int answer = 0;
    memset(dis, -1 ,sizeof(dis));
    answer = func(0, 0);
    return answer;
}
