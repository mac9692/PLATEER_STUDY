#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct compare{
    bool operator()(vector<int>a, vector<int>b) {
    return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    priority_queue<vector<int>, vector<vector<int>>, compare>pq;
    int cntTime = 0;
    int totalTime = 0;
    int answer = 0;
    int jobCnt = 0;
    sort(jobs.begin(), jobs.end());
    while(jobCnt < jobs.size() || !pq.empty()) {
        if(jobCnt < jobs.size() && cntTime >= jobs[jobCnt][0]) {
            pq.push(jobs[jobCnt++]);
            continue;
        }
        if(!pq.empty()) {
            cntTime += pq.top()[1];
            totalTime += cntTime - pq.top()[0];
            pq.pop();
        }else {
            cntTime = jobs[jobCnt][0];
        }
    }
    
    return totalTime/jobs.size();
}
