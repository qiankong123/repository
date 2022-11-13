/*
字符串通配符

描述
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（注：能被*和?匹配的字符仅由英文字母和数字0到9组成，下同）
？：匹配1个字符

注意：匹配时不区分大小写。

输入：
通配符表达式；
一组字符串。
输出：

返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false
数据范围：字符串长度：1\le s\le 100\1≤s≤100 
进阶：时间复杂度：O(n^2)\O(n 
2
 ) ，空间复杂度：O(n)\O(n) 
输入描述：
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串

输出描述：
返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false

示例1
输入：
te?t*.*
txt12.xls
复制
输出：
false
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool match(const char *s,const char *p){

    if((*p=='\0')&&(*s=='\0'))
    {
        return true;
    }
    if((*p=='\0')||(*s=='\0'))
    {
        return false;
    }
    if(*p=='?')
    {
        if((isdigit(*s))||(isalpha(*s))){
            return match(s+1, p+1);
        }

        return false;
    }
    else if(*p=='*')
    {
        while(*p=='*'){
            p++;

        }
        p--;
        return match(s,p+1)||match(s+1,p+1)||match(s+1,p);

    }
    else if(tolower(*p)==tolower(*s))
    {
        return match(s+1,p+1);
    }


    return false;

}

int main() {
    string p,s;
    while(cin>>p>>s){
        bool res = match(s.c_str(),p.c_str());
        if(res){
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }
    }
    return 0;
}
