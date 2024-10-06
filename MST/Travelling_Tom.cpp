#include<bits/stdc++.h>
using namespace std;
int parent[int(1e5+5)];
int sz[int(1e5+5)];
class edge{
    public:
        int u,v,w;
        edge(int u,int v,int w){
            this->u=u;
            this->v=v;
            this->w=w;
        }
};
class compare{
    public:
        bool operator()(edge a,edge b){
            return a.w>b.w;
        }
};
int parentFind(int a){
    if(parent[a]==-1)
        return a;
    return parent[a]=parentFind(parent[a]);
}
bool unionbysize(int a,int b){
    int parA=parentFind(a);
    int parB=parentFind(b);
    if(parA==parB)
        return false;
    if(sz[parA]>=sz[parB]){
        parent[parB]=parA;
        sz[parA]+=sz[parB];
    }else{
        parent[parA]=parB;
        sz[parB]+=sz[parA];
    }
    return true;
}
int main(){
    int V,E,K;
    cin>>V>>E>>K;
    int value[K];
    for(int i=0;i<K;i++)
        cin>>value[i];
    priority_queue<edge,vector<edge>,compare>myQ;
    for(int i=1;i<=E;i++){
        int u,v,l;
        cin>>u>>v>>l;
        int sum=0;
        for(int j=1;j<=l;j++){
            int x;
            cin>>x;
            sum+=x;
        }
        cout<<u<<" "<<v<<" "<<sum<<endl;
        myQ.push(edge(u,v,sum));
        // myQ.push(edge(v,u,sum));
    }
    for(int i=0;i<=V;i++){
        parent[i]=-1;
        sz[i]=1;
    }
    int val=INT_MIN;
    while(!myQ.empty()){
        auto current=myQ.top();
        myQ.pop();
        if(unionbysize(current.u,current.v))
            val=max(current.w,val);
    }
    int sum=0;
    cout<<val<<endl;
    val=min(val,K);
    for(int i=0;i<val;i++)
        sum+=value[i];
    cout<<sum<<endl;
    return 0;
}