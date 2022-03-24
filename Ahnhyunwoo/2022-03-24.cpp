
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};
string solution(string number, int k) {
    string answer = "";

    int startNum = 0;
    while(k != 0) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;
        int exK = k;
        for(int i = startNum; i < number.size();i++) {
            exK--;
            pq.push(make_pair(number[i] - '0', i));
            if(exK == -1) {
                int index = pq.top().second;
                k += startNum - index;
                startNum = index + 1;
                answer += number[index];
                cout<<index<<" ";
            }
        }
    }
    for(int i = startNum; i < number.size();i++) {
        answer += number[i];
    }

    return answer;
}
