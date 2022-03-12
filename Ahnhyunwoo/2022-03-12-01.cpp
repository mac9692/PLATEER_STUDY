#include <string>
#include <vector>
#include <iostream>
using namespace std;
int map[1001][1001];
vector<vector<int>>num;
vector<pair<int, int>>clocks;
vector<pair<int, int>>direction;
vector<pair<int, int>>fClocks;
void directionSetting(int n) {
    clocks.push_back(make_pair(1, 0));
    clocks.push_back(make_pair(0, 1));
    clocks.push_back(make_pair(-1, 0));
    clocks.push_back(make_pair(0, -1));
    fClocks.push_back(make_pair(0, 1));
    fClocks.push_back(make_pair(-1, 0));
    fClocks.push_back(make_pair(0, -1));
    fClocks.push_back(make_pair(1, 0));
    direction.push_back(make_pair(1, 1));
    direction.push_back(make_pair(n, 1));
    direction.push_back(make_pair(n, n));
    direction.push_back(make_pair(1, n));
}
void correctDirect(int n) {
    for(int i = 0 ;i < 4;i++) {
        int x = direction[i].first;
        int y = direction[i].second;
        int k = n -1;
        int cnt = k;
        int dir = i;
        int total = 1;
        cnt--;
        map[y][x] = total;
        while(k > 0) {
            total++;
            cnt--;
            x += clocks[dir].first;
            y += clocks[dir].second;
            map[y][x] = total;
            if(cnt == 0) {
                k -= 2;
                if(k == 0) {
                    k = 1;
                }
                cnt = k;
                dir++;
                if(dir > 3) {
                    dir = 0;
                }
            }
        }
    }
  for(int i = 1 ; i <= n;i++) {
      vector<int>q;
      for(int j = 1; j <=n;j++){
          q.push_back(map[i][j]);
      }
      num.push_back(q);
  }
}
void noDirection(int n) {
    for(int i = 0 ;i < 4;i++) {
        int x = direction[i].first;
        int y = direction[i].second;
        int k = n -1;
        int cnt = k;
        int dir = i;
        int total = 1;
        cnt--;
        map[y][x] = total;
        while(k > 0) {
            total++;
            cnt--;
            x += fClocks[dir].first;
            y += fClocks[dir].second;
            map[y][x] = total;
            if(cnt == 0) {
                k -= 2;
                if(k == 0) {
                    k = 1;
                }
                cnt = k;
                dir--;
                if(dir < 0) {
                    dir = 3;
                }
            }
        }
    }
  for(int i = 1 ; i <= n;i++) {
      vector<int>q;
      for(int j = 1; j <=n;j++){
          q.push_back(map[i][j]);
      }
      num.push_back(q);
  }
}
vector<vector<int>> solution(int n, bool clockwise) {
    vector<vector<int>> answer;
    directionSetting(n);
    if(clockwise) {
        correctDirect(n);
    }else {
        noDirection(n);
    }
    answer = num;
    return answer;
}
