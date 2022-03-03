#include<iostream>
using namespace std;
long long func(int a,int b){
    if(a<b){
        int swap;
        swap=a;
        a=b;
        b=swap;
    }
    int start=b;
    while(1){
        if(a%start==0&&b%start==0){
            return start;
        }
        start--;
    }
}
long long solution(int w,int h) {
     long long answer =(long long)w*(long long)h;
     long long k=func(w,h);
     cout<<k;
     answer-=(w+h);
     answer+=k;
    return answer;
}
