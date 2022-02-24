#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    int total=0;
    int total_to=0;
    for(int i=1;i<=s.size()/2;i++){
        int count=0;
        total=0;
        for(int j=i;j<s.size();j++){
            if(s[j]==s[j-i]){
                count++;
            }
            if(s[j]!=s[j-i]||j==s.size()-1){
                if(count/i>0){
                    count/=i;
                    count*=i;
                    string h=to_string((count+i)/i);
                    total+=count-(h.size());
                }
                count=0;
                while((j+1)%i!=0){
                    j++;
                }
            }
        }
        total_to=max(total_to,total);
    }
    answer=s.size()-total_to;
    return answer;
}
