/*
字符串排序

描述
编写一个程序，将输入字符串中的字符按如下规则排序。

规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。

如，输入： Type 输出： epTy

规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。

如，输入： BabA 输出： aABb

规则 3 ：非英文字母的其它字符保持原来的位置。


如，输入： By?e 输出： Be?y

数据范围：输入的字符串长度满足 1 \le n \le 1000 \1≤n≤1000 

输入描述：
输入字符串
输出描述：
输出字符串
示例1
输入：
A Famous Saying: Much Ado About Nothing (2012/8).
输出：
A aaAAbc dFgghh: iimM nNn oooos Sttuuuy (2012/8).
*/



#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        vector<vector<char> > table(26);
        vector<int> index(s.length(), -1);
        for(int i = 0; i < s.length(); i++){
            if(s[i]>='a' && s[i]<='z'){
                index[i]=0;
                table[s[i]-'a'].push_back(s[i]);
            }
            if(s[i]>='A' && s[i]<='Z'){
                index[i]=0;
                table[s[i]-'A'].push_back(s[i]);
            }

        }
        int x = 0, y = 0; 
        for(int i = 0; i < index.size(); i++){
            if(index[i] == -1) continue;
            while(y==table[x].size()){
                x++;
                y=0;
            }
            s[i]=table[x][y];
            y++;
            
        }
        cout << s <<endl;
    }
    return 0;
}
