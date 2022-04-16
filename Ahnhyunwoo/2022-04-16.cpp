#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
using namespace std;
bool check[21][21];
int checkNum[21][21];
int m, mr, mc;
void nextTurn() {
    memset(check, true, sizeof(check));
}
void action(int row, int col) {
    queue<pair<int, int>>q;
    q.push(make_pair(row, col));
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if(!check[r][c]) {
            continue;
        }
        check[r][c] = false;
        if(checkNum[r][c] == m) {
            if(r - 1 > 0 && check[r - 1][c]) {
                q.push(make_pair(r - 1, c));
            }
            if(r + 1 <= mr && check[r + 1][c]) {
                q.push(make_pair(r + 1, c));
            }
            if(c - 1 > 0 && check[r][c - 1]) {
                q.push(make_pair(r, c - 1));
            }
            if(c + 1 <= mc && check[r][c + 1]) {
                q.push(make_pair(r, c + 1));
            }
        }else {
            checkNum[r][c]++;
        }

    }
}
vector<vector<int>> solution(int rows, int columns, int max_virus, vector<vector<int>> queries) {
    vector<vector<int>> answer;
    m = max_virus;
    mr = rows;
    mc = columns;
    for(int i = 0; i < queries.size();i++) {
        int row = queries[i][0];
        int col = queries[i][1];
        nextTurn();
        action(row, col);
    }
    for(int i = 1;i <= mr;i++) {
        vector<int>v;
        for(int j =1; j<= mc;j++) {
            v.push_back(checkNum[i][j]);
        }
        answer.push_back(v);
    }
    return answer;
}
