#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
bool check[201];
vector<vector<int>> computer;
int answer;
void func(int k) {
    check[k] = true;
    for(int i = 0; i < computer[k].size(); i++) {
        if(i == k) {
            continue;
        }
        if(computer[k][i] == 1 && !check[i]) {
            func(i);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    answer = 0;
    memset(check, false, sizeof(check));
    computer = computers;
    for(int i = 0; i < computers.size(); i++) {
        if(!check[i]) {
            answer++;
            func(i);
        }
        
    }
   
    return answer;
}
