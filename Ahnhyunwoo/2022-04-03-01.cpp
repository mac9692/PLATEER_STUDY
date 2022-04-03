#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(int a, int b) {
    return a > b;
}
int solution(vector<int> people, vector<int> tshirts) {
    int answer = 0;
    sort(people.begin(), people.end(), compare);
    sort(tshirts.begin(), tshirts.end(), compare);
    int tshirtsNum = 0;
    for(int i = 0; i < people.size();i++) {
        if(tshirtsNum == tshirts.size()) {
            break;
        }
        if(people[i] <= tshirts[tshirtsNum]) {
            answer++;
            tshirtsNum++;
        }
    }
    return answer;
}
