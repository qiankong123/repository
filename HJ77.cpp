/*

火车进站

描述
给定一个正整数N代表火车数量，0<N<10，接下来输入火车入站的序列，一共N辆火车，每辆火车以数字1-9编号，火车站只有一个方向进出，同时停靠在火车站的列车中，只有后进站的出站了，先进站的才能出站。
要求输出所有火车出站的方案，以字典序排序输出。
数据范围：1\le n\le 10\1≤n≤10 
进阶：时间复杂度：O(n!)\O(n!) ，空间复杂度：O(n)\O(n) 
输入描述：
第一行输入一个正整数N（0 < N <= 10），第二行包括N个正整数，范围为1到10。

输出描述：
输出以字典序从小到大排序的火车出站序列号，每个编号以空格隔开，每个输出序列换行，具体见sample。

示例1
输入：
3
1 2 3
输出：
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
说明：
第一种方案：1进、1出、2进、2出、3进、3出
第二种方案：1进、1出、2进、3进、3出、2出
第三种方案：1进、2进、2出、1出、3进、3出
第四种方案：1进、2进、2出、3进、3出、1出
第五种方案：1进、2进、3进、3出、2出、1出
注意，[3,1,2]这个序列是不可能实现的。
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void dfs(const vector<int>& in,int index,stack<int>& st,vector<int>& path,vector<vector<int>>& allpath){
    if(index>=in.size()&&st.empty()){
        allpath.push_back(path);
        return;
    }
    if(index<in.size()){
        st.push(in[index]);
        dfs(in,index+1,st,path,allpath);
        st.pop();
    }

    if(!st.empty()){
        path.push_back(st.top());
        st.pop();
        dfs(in,index,st,path,allpath);
        st.push(path.back());
        path.pop_back();

    }


}


int main() {
    int n;

    while(cin>>n){
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        stack<int> st;
        vector<int> onepath;
        vector<vector<int>> allpath;
        dfs(nums,0,st,onepath,allpath);
        sort(allpath.begin(),allpath.end());
        for(auto i:allpath){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }


    }

    return 0;
}
