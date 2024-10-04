#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
        int u,v,w;
        Edge(int u,int v,int w){
            this->u=u;
            this->v=v;
            this->w=w;
        }
};
int main(){
    int V,E,H,source,destination;
    cin>>V>>E>>H>>source>>destination;
    vector<Edge>edgelist;
    while(E--){
        int u,v;
        cin>>u>>v;
        edgelist.push_back(Edge(u,v,1));
        edgelist.push_back(Edge(v,u,1));
    }
    while(H--){        
        int u,v;
        cin>>u>>v;
        edgelist.push_back(Edge(u,v,2));
        edgelist.push_back(Edge(v,u,2));
    }
    int distance[V+1];
    for(int i=0;i<=V;i++)
        distance[i]=INT_MAX;
    distance[source]=0;
    for(int i=0;i<V;i++){
        for(auto e: edgelist){
            if(distance[e.u]<INT_MAX && distance[e.v]>distance[e.u]+e.w)
                distance[e.v]=distance[e.u]+e.w;
        }
    }
    distance[destination]=distance[destination]==INT_MAX?-1:distance[destination];
    cout<<distance[destination]<<endl;
    return 0;
}