#include <iostream>
#include <stack>
using namespace std;

stack <char> pre_string,back_string;


void L_command(){
    if(!pre_string.empty()){
        back_string.push(pre_string.top());
        pre_string.pop();
    }
    else
        return;
}
void D_command(){
    if(!back_string.empty()){
        pre_string.push(back_string.top());
        back_string.pop();
    }
    else
        return;
}
void B_command(){
    if(!pre_string.empty()){
        pre_string.pop();
    }
    else
        return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; cin>>s;
    for(int i=0;i<s.length();i++){
        pre_string.push(s[i]);
    }
    int n;cin>>n;
    for(int i=0;i<n;i++){
        char a;cin>>a;
        if(a=='L') L_command();
        if(a=='D') D_command();
        if(a=='B') B_command();
        if(a=='P'){
            char c; cin>> c;
            pre_string.push(c);
            
        }
    }
    while(!pre_string.empty())
    {
        back_string.push(pre_string.top());
        pre_string.pop();
    }
    while (!back_string.empty()) {
        cout << back_string.top();
        back_string.pop();
    }
    cout << '\n';
    
    return 0;
}
