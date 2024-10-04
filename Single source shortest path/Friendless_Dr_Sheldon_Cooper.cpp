#include<bits/stdc++.h>
using namespace std;
#define max int(1e5)
int sz[max];
int par[max];
class edge{
    public:
        int u,v;
        edge(int u,int v){
            this->u=u;
            this->v=v;
        }
};
int parent(int a){
    if(par[a]==-1)
        return a;
    return par[a]=parent(par[a]);
}
void dsu_unioun(int a,int b){
    int parentofa=parent(a);
    int parentofb=parent(b);
    if(sz[parentofa]>=sz[parentofb]){
        par[parentofb]=parentofa;
        sz[parentofa]+=sz[parentofb];
    }else{
        par[parentofa]=parentofb;
        sz[parentofb]+=sz[parentofa];
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int V,E;
        cin>>V>>E;
        vector<edge>edgeList;
        while(E--){
            int u,v;
            cin>>u>>v;
            edgeList.push_back(edge(u,v));
        }
        for(int i=0;i<=V;i++){
            sz[i]=0;
            par[i]=-1;
        }
        int count=0;
        for(auto e:edgeList){
            if(parent(e.u)!=parent(e.v)){
                dsu_unioun(e.u,e.v);
                count++;
            }
        }
        cout<<count<<endl;
    }

}