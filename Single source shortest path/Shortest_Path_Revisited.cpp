#include<bits/stdc++.h>
using namespace std;
class custom{
    public:
        int v,d,k;
        custom(int v,int d,int k){
            this->v=v;
            this->d=d;
            this->k=k;
        }
};
class compare{
    public:
        bool operator()(custom a,custom b){
            return a.d>b.d;
        }
};
void dijkstra(vector<pair<int,int>>adj[],int V,int k){
    bool vis[V+1];
    int dis[V+1];
    for(int i=1;i<=V;i++){
        vis[i]=false;
        dis[i]=INT_MAX;
    }
    // vis[1]=true;
    dis[1]=0;
    priority_queue<custom,vector<custom>,compare>myQ;
    myQ.push(custom(1,0,k));
    while(!myQ.empty()){
        auto parent=myQ.top();
        myQ.pop();
        vis[parent.v]=true;
        dis[parent.v]=min(parent.d,dis[parent.v]);
        for(auto child:adj[parent.v]){
            if(!vis[child.first]){
                myQ.push(custom(child.first,child.second+parent.d,parent.k));
                if(parent.k>0)
                    myQ.push(custom(child.first,parent.d,parent.k-1));
            }
        }
    }
    for(int i=1;i<=V;i++)
        cout<<dis[i]<<" ";
    cout<<endl;
}
int main(){
    int V,E,K;
    cin>>V>>E>>K;
    vector<pair<int,int>>adj[V+1];
    while(E--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(adj,V,K);
}