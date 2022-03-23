#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool reserveNum[31];
void settingReserveNum(vector<int> reserve) {
    memset(reserveNum, false, sizeof(reserveNum));
    for(int i = 0; i < reserve.size();i++) {
        reserveNum[reserve[i]] = true;
    }
}
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(reserve.begin(), reserve.end());
    sort(lost.begin(), lost.end());
    settingReserveNum(reserve);
    int getCloth = 0;
    vector<int>newReserve;
    for(int i = 0; i < lost.size();i++) {
        if(reserveNum[lost[i]]) {
            reserveNum[lost[i]] = false;
            getCloth++;
        }else {
            newReserve.push_back(lost[i]);
        }
    }
    for(int i = 0;i < newReserve.size();i++) {
        if(reserveNum[newReserve[i] - 1]) {
            reserveNum[newReserve[i] - 1] = false;
            getCloth++;
        }else if(reserveNum[newReserve[i] + 1]) {
            reserveNum[newReserve[i] + 1] = false;
            getCloth++;
        }
    }
    answer = n - (lost.size() - getCloth);
    return answer;
}
