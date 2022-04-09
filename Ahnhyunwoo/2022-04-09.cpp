#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0;i < scoville.size();i++) {
        pq.push(scoville[i]);
    }
    while(!pq.empty()) {
        int first = pq.top();
        pq.pop();
        if(first >= K) {
            break;
        }
        if(pq.empty()) {
            answer = -1;
            break;
        }
        int second = pq.top();
        pq.pop();
        int next = first + (second * 2);
        pq.push(next);
        answer++;
    }
    return answer;
}
