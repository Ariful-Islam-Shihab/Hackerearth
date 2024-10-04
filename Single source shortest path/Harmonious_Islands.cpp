#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
        long long int v,w;
        char from,to;
        Edge(long long int v,long long int w,char from,char to){
            this->v=v;
            this->w=w;
            this->from=from;
            this->to=to;
        }
};
class custom{
    public:
        long long int v,d;
        char c;
        custom(long long int v,long long int d,char c){
            this->c=c;
            this->d=d;
            this->v=v;
        }
};
class compare{
    public:
        bool operator()(custom a,custom b){
            return a.d>b.d;
        }
};
long long int cost(){
    long long int V,E;
    cin>>V>>E;
    long long int arrayA[V+1];
    for(int i=1;i<=V;i++)
        cin>>arrayA[i];
    long long int arrayB[V+1];
    for(int i=1;i<=V;i++)
        cin>>arrayB[i];
    vector<Edge>adjList[V+1];
    for(int i=0;i<E;i++){
        long long int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back(Edge(v,w,'a','a'));
        adjList[v].push_back(Edge(u,w,'a','a'));
    }
    for(int i=0;i<E;i++){
        long long int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back(Edge(v,w,'b','b'));
        adjList[v].push_back(Edge(u,w,'b','b'));
    }
    long long int source,destination;
    cin>>source>>destination;
    for(int i=1;i<=V;i++){
        for(int j=i;j<=V;j+=i){
            long long int w=arrayA[i]*arrayB[j];
            adjList[i].push_back(Edge(j,w,'a','b'));
        }
    }
    priority_queue<custom,vector<custom>,compare>myQ;
    myQ.push(custom(source,0,'a'));
    bool vis[2][V+1];
    for(int i=1;i<=V;i++){
        vis[0][i]=false;
        vis[1][i]=false;
    }
    while(!myQ.empty()){
        auto parent=myQ.top();
        myQ.pop();
        long long int U=parent.v;
        long long int W=parent.d;
        int C=parent.c=='a'?0:1;
        if (vis[C][U]) continue; 
        vis[C][U]=true;
        if(U==destination && C==1)
            return W;
        for(auto child:adjList[U]){
            if(child.from==parent.c && !vis[child.to=='a'?0:1][child.v]){
                long long int v=child.v;
                long long int w=child.w;
                char to=child.to;
                myQ.push(custom(v,w+W,to));
            }

        }
    }
    return -1;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        // cout<<T<<endl;
        cout<<cost()<<endl;
    }
}