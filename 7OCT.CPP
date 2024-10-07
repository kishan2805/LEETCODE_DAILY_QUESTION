
#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int minLength(string s) {
    stack<char>st;
    // int n=s.length();
    int top=-1;

    for(int i=0;i<s.length();i++){
        
        if(top==-1 ){
            st.push(s[i]);
            top++;
        }
        else{
            // if b comes check the top is not a 
            char a=st.top();
            char b=s[i];
            if(b=='B'&& a=='A'){
                st.pop();
                top--;
            }
            else if(b=='D'&&a=='C'){
                st.pop();
                top--;
            }
            else{
                st.push(b);
                top++;
            }
        }
        
        // if d comes check top is not c
    }
    return top+1;
}

int main(){
    string s="ABFCACDB";
    cout<<"ans is : "<<minLength(s)<<endl;
}