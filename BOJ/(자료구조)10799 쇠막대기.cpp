#include <iostream>
using namespace std;

int cnt=0;
int pre_bar=0;

int main(){
    string bar; cin>>bar;
    for(int i=0;i<bar.length();i++){
        if(bar[i]=='('){
            if(bar[i+1]==')'){
                cnt += pre_bar;
                i++;
                continue;
            }
            pre_bar++;
        }
        if(bar[i]==')'&& bar[i-1]==')')
        {
            cnt +=1;
            pre_bar--;
            
        }
    }
    cout <<cnt;
}
