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
            return a.w<b.w;
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
int gcd(int a, int b) { 
    // Everything divides 0 
    if (a == 0) 
        return b; 
    if (b == 0) 
        return a; 
  
    // base case 
    if (a == b) 
        return a; 
  
    // a is greater 
    if (a > b) 
        return gcd(a - b, b); 
    return gcd(a, b - a); 
}
int main(){
    int V;
    cin>>V;
    int value[V];
    for(int i=0;i<V;i++)
        cin>>value[i];
    priority_queue<edge,vector<edge>,compare>myQ;
    for(int i=0;i<V-1;i++){
        for(int j=i+1;j<V;j++){
            int w=gcd(value[i],value[j]);
            myQ.push(edge(i,j,w));
            myQ.push(edge(j,i,w));
        }
    }
    for(int i=0;i<V;i++){
        parent[i]=-1;
        sz[i]=1;
    }
    int sum=0;
    while(!myQ.empty()){
        auto current=myQ.top();
        myQ.pop();
        if(unionbysize(current.u,current.v))
            sum+=current.w;
    }
    cout<<sum<<endl;
    return 0;
}