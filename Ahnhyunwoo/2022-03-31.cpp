#include <string>
#include <vector>
#include <cstring>
using namespace std;

char name[8]={'A','C','F','J','M','N','R','T'};
bool check[8];
vector<string>info;
int count=0;
vector<char>ans;
bool game2(char a,char b,char c,int d){
    int anum=0;
    int bnum=0;
    for(int i=0;i<ans.size();i++){
        if(ans[i]==a){
            anum=i;
        }
        if(ans[i]==b){
            bnum=i;
        }
    }
    int k=abs(anum-bnum);
    if(c=='='&&k!=d+1){
        return false;
    }
    if(c=='>'&&k<=d+1){
        return false;
    }
    if(c=='<'&&k>=d+1){
        return false;
    }
    return true;
}
void game(){
    bool che=true;
    for(int i=0;i<info.size();i++){
        char a=info[i][0];
        char b=info[i][2];
        char c=info[i][3];
        int d=info[i][4]-'0';
        che=game2(a,b,c,d);
        if(!che){
            break;
        }
    }
    if(che){
        count++;
    }
}
void choice(int k){
    if(k==8){
        
        game();
        return ;
    }
    for(int i=0;i<8;i++){
        if(check[i]){
            ans.push_back(name[i]);
            check[i]=false;
            choice(k+1);
            ans.pop_back();
            check[i]=true;
        }
    }
}
int solution(int n, vector<string> data) {
    int answer = 0;
    memset(check,true,sizeof(check));
    info=data;
    count=0;
    choice(0);
    answer=count;
    return answer;
}
