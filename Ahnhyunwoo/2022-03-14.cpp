#include <string>
#include <set>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    string word = "";
    char side = ' ';
    char inner = ' ';
    set<char>s;
    int cnt = 0;
    bool check = true;
    for(int i = 0; i < sentence.size();i++) {
        char c = sentence[i];
        if(c >= 'a' && c <= 'z') {
            if(word == "") {
                if(s.find(c) != s.end()) {
                    check = false;
                    break;
                }
                s.insert(c);
                cout<<"1";
                side = c;
            }else if(inner == ' ' && side == ' ') {
                if(s.find(c) != s.end()) {
                    check = false;
                    break;
                }
                inner = c;
                s.insert(c);
            }else if(side == c) {
                side = ' ';
                answer += word + " ";
                word = "";
                inner = ' ';
            }else if(inner != c && side == ' ') {
                if(s.find(c) != s.end()) {
                    check = false;
                    break;
                }
                if(cnt == 1) {
                    side = c;
                    answer += word + " ";
                    word = "";
                } else {
                    inner = c;
                    char a = word[word.size() - 1];
                    answer += word.substr(0, word.size() - 1) + " ";
                    word = a;
                 }
                s.insert(c);
            }
            cnt = 0;
        }else {
            cnt ++;
            word += c;
            if(i == sentence.size() -1) {
                 answer += word +" ";
                if(side != ' ') {
                check =false;
                }
            }
            
        }
    }
    answer = answer.substr(0, answer.size() -1);
    if(!check) {
        answer = "invalid";
    }
    return answer;
}
