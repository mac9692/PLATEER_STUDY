#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
    if(a.first == b.first) {
        return a.second.first > b.second.first;
    }
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string, pair<int, int>>>genreAndPlay;
    for(int i = 0; i < genres.size();i++) {
        string genre = genres[i];
        int play = plays[i];
        genreAndPlay.push_back(make_pair(genre, make_pair(play, i)));
    }
    sort(genreAndPlay.begin(), genreAndPlay.end(), compare);
    map<string, vector<int>>m;
    string nowGenre = genreAndPlay[0].first;
    int nowIndex = genreAndPlay[0].second.second;
    vector<int>index;
    index.push_back(nowIndex);
    int sum = genreAndPlay[0].second.first;
    priority_queue<pair<int, string>>pq;
    for(int i = 1;i < genreAndPlay.size();i++) {
        string genre = genreAndPlay[i].first;
        int play = genreAndPlay[i].second.first;
        int num = genreAndPlay[i].second.second;
        if(genre == nowGenre) {
           index.push_back(num);
            sum += play;
        }else {
            m.insert(make_pair(nowGenre, index));
            index.clear();
            pq.push(make_pair(sum, nowGenre));
            nowGenre = genre;
            sum = play;
            index.push_back(num);
        }
    }
    m.insert(make_pair(nowGenre, index));
    pq.push(make_pair(sum, nowGenre));
    while(!pq.empty()) {
        string genre = pq.top().second;
        pq.pop();
        vector<int>k = m[genre];
        for(int i = 0; i < k.size();i++) {
            if(i == 2) {
                break;
            }
    
            answer.push_back(k[i]);
        }
       
    }
    return answer;
}
