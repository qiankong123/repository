#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    string str2;
    cin>>str;
    unordered_set<char> set;
    for(auto i=str.rbegin();i!=str.rend();i++){
        if(set.count(*i)==1){
            continue;
        }
        set.insert(*i);
        cout<<*i;


    }
    
}
