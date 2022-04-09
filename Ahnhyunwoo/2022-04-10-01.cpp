#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool finish = false;
vector<string> answer;
vector<pair<vector<string>, bool>>ticket;
bool compare(pair<vector<string>, bool> a, pair<vector<string>, bool> b) {
    if(a.first[0] == b.first[0]) {
        return a.first[1] < b.first[1];
    }
    return a.first[0] < b.first[0];
}
void searchRoad(int cnt, vector<string>road, string now) {
    if(finish) {
        return ;
    }
    if(cnt == ticket.size()) {
        finish = true;
        answer = road;
        return ;
    }
    for(int i = 0; i < ticket.size();i++) {
        if(ticket[i].first[0] == now && ticket[i].second) {
            ticket[i].second = false;
            road.push_back(ticket[i].first[1]);
            searchRoad(cnt + 1, road, ticket[i].first[1]);
            road.pop_back();
            ticket[i].second = true;
        }
        
    }

}
vector<string> solution(vector<vector<string>> tickets) {
    for(int i = 0; i < tickets.size();i++) {
        ticket.push_back(make_pair(tickets[i], true));
    }
    sort(ticket.begin(), ticket.end(), compare);
    vector<string>road;
    for(int i = 0;i < ticket.size();i++) {
        if(ticket[i].first[0] == "ICN") {
            road.push_back(ticket[i].first[0]);
            road.push_back(ticket[i].first[1]);
            ticket[i].second = false;
            searchRoad(1, road, ticket[i].first[1]);
            if(answer.size() == tickets.size()) {
                break;
            }
            ticket[i].second = true;
            road.clear();
        }
        
    }
    
    return answer;
}
