#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int dis[20001];
int ar[20001][20001] = {0,};
void func(vector<vector<int>> edge) {
    for(int i = 0 ; i < edge.size(); i++) {
        int cost1 = edge[i][0];
        int cost2 = edge[i][1];
        ar[cost1][cost2] = 1;
        ar[cost2][cost1] = 1;
    }
}
void func1(int n) {
    for(int i = 1;i <= n; i++) {
        dis[i] = 99999;
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    func1(n);
    func(edge);
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    dis[1] = 0;
    p.push(make_pair(0,1));
    vector<int>v;
    while(!p.empty()) {
        int cost = p.top().first;
        int start = p.top().second;
        p.pop();
        for(int i = 1; i <= n; i++) {
            if(start == i || ar[start][i] == 0 || ar[i][start] == 0) {
                continue;
            }
            if(cost + 1 < dis[i]) {
                dis[i] = cost + 1;
                p.push(make_pair(dis[i], i));
            }
        }
    }
    for(int i = 2; i <= n ; i++) {
        if(answer < dis[i]) {
            v.clear();
            v.push_back(i);
            answer = dis[i];
        }else if(answer == dis[i]) {
            v.push_back(i);
        }
    }
    answer = v.size();
    return answer;
}
