#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int>startTime;
    vector<int>endTime;
    for(int i =0; i < lines.size(); i++) {
        lines[i].pop_back();
        int hour;
        int min;
        int sec;
        int msec;
        int time;
        hour = stoi(lines[i].substr(11, 2)) * 3600 * 1000;
        min = stoi(lines[i].substr(14, 2)) * 60 * 1000 ;
        sec = stoi(lines[i].substr(17, 2)) * 1000;
        msec = stoi(lines[i].substr(20, 3));
        time = stof(lines[i].substr(24, 5)) * 1000;
        startTime.push_back(hour + min + sec + msec - time + 1);
        endTime.push_back(hour + min + sec + msec);
    }
    for (int i = 0; i < startTime.size(); i++) {
        int cnt = 0;
        int et = endTime[i] + 1000;
        for(int j = i; j< startTime.size(); j++) {
            if(startTime[j] < et) {
                cnt++;
            }
        }
        answer = max(answer, cnt);
    }
    return answer;
}
