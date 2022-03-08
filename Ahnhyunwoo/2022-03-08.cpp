#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
vector<string>change(string re){
    vector<string>a;
    string s="";
    for(int i=0;i<re.size();i++){
        if(re[i]==' '){
            a.push_back(s);
            s="";
            continue;
        }
        s+=re[i];
        if(i==re.size()-1){
            a.push_back(s);
        }
    }
    return a;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string>cord[100001];
    for(int i=0;i<record.size();i++){
        cord[i]=change(record[i]);
    }
    map<string,string>m;
    queue<string>ans;
    for(int i=0;i<record.size();i++){
        string action=cord[i][0];
        if(action=="Enter"){
            if(m.find(cord[i][1])!=m.end()){
                 m[cord[i][1]]=cord[i][2];
            }
            else{
               m.insert(make_pair(cord[i][1],cord[i][2])); 
            }
            
        }else if(action=="Change"){
            m[cord[i][1]]=cord[i][2];
        }
    }
    for(int i=0;i<record.size();i++){
        string action=cord[i][0];
        if(action=="Enter"){
            answer.push_back(m[cord[i][1]]+"님이 들어왔습니다.");
        }else if(action=="Leave"){
            answer.push_back(m[cord[i][1]]+"님이 나갔습니다.");
        }
    }
    return answer;
}
