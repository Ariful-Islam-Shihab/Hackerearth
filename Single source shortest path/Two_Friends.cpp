#include<bits/stdc++.h>
using namespace std;
int cost(){
    int V;
    cin>>V;
    vector<int>adjList[V+1];
    for(int i=0;i<V-1;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int Q;
    while(Q--){
        int 
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cout<<cost()<<endl;
    }
}