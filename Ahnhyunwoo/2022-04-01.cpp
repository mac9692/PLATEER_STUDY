#include <string>
#include <vector>
#include<stdlib.h>
#include<queue>
#include <algorithm>
using namespace std;
vector<vector<int>> solution(vector<vector<int>> dist) {
    vector<vector<int>> answer;
    priority_queue<pair<int, int>>a;
    priority_queue<pair<int, int>>b;
    for(int j = 1; j < dist.size();j++) {
        int same = abs(dist[0][1] - dist[0][j]);
        int other = abs(dist[0][1] + dist[0][j]);
        if(same == dist[1][j] && same == dist[j][1]) {
            a.push(make_pair(dist[0][j], j));
        }else if(other == dist[1][j] && other == dist[j][1]) {
            b.push(make_pair(dist[0][j] * (-1), j));
        }
    }

    vector<int>v;
    while(!a.empty()) {
        int num = a.top().second;
        a.pop();
        v.push_back(num);
    }
    v.push_back(0);
    while(!b.empty()) {
        int num = b.top().second;
        b.pop();
        v.push_back(num);
    }
    answer.push_back(v);
    reverse(v.begin(), v.end());
    answer.push_back(v);
    sort(answer.begin(), answer.end());
    return answer;
}
