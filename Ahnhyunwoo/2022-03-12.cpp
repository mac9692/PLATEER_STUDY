#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int money, vector<int> costs) {
    int answer = 0;
    int bill[6] = {1, 5, 10, 50, 100, 500};
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int i = 0; i < costs.size();i++) {
        int k = 500 / bill[i];
        q.push(make_pair(k*costs[i], bill[i]));
    }
    while(money != 0) {
        int fiveHundrendCost = q.top().first;
        int billCost = q.top().second;
        int k = 500/billCost;
        fiveHundrendCost /= k;
        q.pop();
        int w = money / billCost;
        if(w > 0) {
            answer += w * fiveHundrendCost;
            money -= w * billCost;
            cout<< money<< "\n";
        }
    }
    return answer;
}
