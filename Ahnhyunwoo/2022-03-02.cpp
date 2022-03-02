#include <string>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    deque<char>de;
    for(int i=0;i<s.size();i++){
        de.push_back(s[i]);
    }
    for(int i=0;i<s.size();i++){
        stack<char>s;
        bool check=true;
        for(int j=0;j<de.size();j++){
            if(de[j]=='['||de[j]=='{'||de[j]=='('){
                s.push(de[j]);
            }else {
                if(s.empty()){
                    check=false;
                    break;
                }
                if(de[j]==']'&&s.top()!='['){
                    check=false;
                    break;
                }else if(de[j]==']'&&s.top()=='['){
                    s.pop();
                }
                if(de[j]=='}'&&s.top()!='{'){
                    check=false;
                    break;
                }else if(de[j]=='}'&&s.top()=='{'){
                    s.pop();
                }
                if(de[j]==')'&&s.top()!='('){
                    check=false;
                    break;
                }else if(de[j]==')'&&s.top()=='('){
                    s.pop();
                }
            }
            
        }
        if(check&&s.empty()){
            answer++;
        }
        char lastGo=de.front();
        de.pop_front();
        de.push_back(lastGo);
    }
    return answer;
}
