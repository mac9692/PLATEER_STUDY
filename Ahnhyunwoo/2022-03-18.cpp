#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
bool correctCheck(string current, string word) {
    int cnt = 0;
    for(int i = 0;i < current.size();i++) {
        if(current[i] != word[i]) {
            cnt++;
        }
    }
    if(cnt == 1) {
        return true;
    }
    return false;
    
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<int, string>>q;
    q.push(make_pair(0, begin));
    bool check[51];
    memset(check, true, sizeof(check));
    while(!q.empty()) {
        int cnt = q.front().first;
        string currentWord = q.front().second;
        q.pop();
        if(currentWord == target) {
            answer = cnt;
            break;
        }
        for(int i = 0 ; i < words.size();i++) {
             if(check[i] && correctCheck(currentWord, words[i])) {
                check[i] = false;
                int k = cnt + 1;
                q.push(make_pair(k, words[i]));
            }
        }
        
    }
    return answer;
}
