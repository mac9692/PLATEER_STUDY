#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int timeSetting(string hour, string min) {
    int hourMin = stoi(hour) * 60;
    int minMin = stoi(min);
    return hourMin + minMin;
}
struct compare{
	bool operator()(pair<int, string>a, pair<int, string>b){
		return a.first>b.first;
	}
};

vector<string> solution(vector<vector<string>> booked, vector<vector<string>> unbooked) {
    vector<string> answer;
    priority_queue<pair<int, string>, vector<pair<int, string>>, compare>book;
    priority_queue<pair<int, string>, vector<pair<int, string>>, compare>unBook;
    for(int i = 0; i < booked.size();i++) {
        string hour = booked[i][0].substr(0, 2);
        string min = booked[i][0].substr(3, 2);
        int time = timeSetting(hour, min);
        book.push(make_pair(time, booked[i][1]));
    }
    for(int i = 0; i < unbooked.size();i++) {
        string hour = unbooked[i][0].substr(0, 2);
        string min = unbooked[i][0].substr(3, 2);
        int time = timeSetting(hour, min);
        unBook.push(make_pair(time, unbooked[i][1]));
    }
    int nowTime = -1;
    while(!book.empty() || !unBook.empty()) {
        int bookTime = 999999;
        int unBookTime = 999999;
        if(!book.empty()) {
            bookTime = book.top().first;
        }
        if(!unBook.empty()) {
            unBookTime = unBook.top().first;
        }
        if(nowTime >= bookTime) {
            nowTime = bookTime + 10;
            answer.push_back(book.top().second);
            book.pop();
            continue;
        }
        if(nowTime >= unBookTime && bookTime > unBookTime) {
            nowTime = unBookTime + 10;
            answer.push_back(unBook.top().second);
            unBook.pop();
            continue;
        }
        if(unBookTime < bookTime) {
            answer.push_back(unBook.top().second);
            unBook.pop();
            nowTime = unBookTime + 10;
        }else {
            answer.push_back(book.top().second);
            book.pop();
            nowTime = bookTime + 10;
        }
    }
    return answer;
}
