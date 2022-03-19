#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
struct compare {
    bool operator() (const string &a, const string &b) const{
        if(a.size() == b.size()) {
            return a < b;
        }
        return a.size() < b.size();
    }
};
set<string, compare>c;
set<string>delC;
set<string>current;
vector<string>ans[101];
void insertAndErase(string word) {
     if(c.find(word) == c.end()) {
         if(delC.find(word) == delC.end()) {
             c.insert(word);
             current.insert(word);
         }
     } else {
         if(current.find(word) != current.end()) {
             return ;
         }
         delC.insert(word);
         c.erase(c.find(word));
     }
}
void goodsSetting(vector<string> good) {
    for(int i = 0;i < good.size();i++) {
        current.clear();
        for(int j = 0;j < good[i].size();j++) {
            string word;
            word += good[i][j];
            insertAndErase(word);
            for(int k = j + 1;k <good[i].size();k++) {
                word += good[i][k];
                insertAndErase(word);
            }
        }
    }
}

vector<string> solution(vector<string> goods) {
    vector<string> answer;
    goodsSetting(goods);
    for(auto str:c) {
        cout<< str <<"\n";
        for(int i =0; i < goods.size();i++) {
            string s = goods[i];
            if(s.find(str) != string::npos) {
                if(ans[i].empty()) {
                    ans[i].push_back(str);
                }else {
                    int ansSize = ans[i][0].size();
                    if(ansSize < str.size()) {
                        break;
                    }
                    ans[i].push_back(str);
                }
            }
        }
    }
    for(int i = 0; i < goods.size();i++) {
        string s;
        for(int j = 0; j < ans[i].size();j++) {
            s += ans[i][j];
            if(j + 1 != ans[i].size()) {
                s += " ";
            }
        }
        answer.push_back(s);
    }
    for(int i = 0; i < goods.size();i++) {
        if(answer[i] == "") {
            answer[i] = "None";
        }
    }
    return answer;
}
