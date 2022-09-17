class DSU{
  private:
int N;
vector<int> parent;
vector<int> a;
vector<int> Rank;
  public:
    DSU(int n){
     N = n;
     a.resize(N);
     parent.resize(N);
     Rank.resize(N,0);
   }

void makeset(){
   for(int i = 0; i < N; i++){
      parent[i] = i;
     
   }
}

int Find(int node){
   if(node == parent[node]) return node;
   return parent[node] = Find(parent[node]);
}

void Union(int u,int v){
    u = Find(u);
    v = Find(v);
    
    if(Rank[u] < Rank[v]) parent[u] = v;
    else if(Rank[u] > Rank[v]) parent[v] = u;
    else  parent[v] = u,Rank[u]++;
}

};

const int N = 1e5;
vector<int> parent(N);
vector<int> rank(N);


int Find(int u){
    if(parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u,int v){
    u = Find(u);
    v = Find(v);
    
   if(rank[u] > rank[v])
      parent[v] = u;
   else if(rank[u] < rank[v])      
       parent[u] = v;
  else parent[v] = u,rank[u]++;       
}

int main(){
    
    int v,e;
    cin >> v >> e;
    vector<int> cost(v + 1,0);
    for(int i = 0;i <= v; i++){
        parent[i] = i;
    }
    vector<vector<int>> adj[v + 1];
    
    for(int i = 1; i <= e; i++){
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    for(int i = 0;i < v; i++){
         adj[0].push_back({i + 1,cost[i]});
         adj[i + 1].push_back({0,cost[i]});
    }
    
    sort(adj.begin(),adj.end(),[&](vector<int> a,vector<int> b){
        return a[2] < b[2];
    });
    int ans = 0;
    for(auto &vec : adj){
        if(Find(vec[0]) != Find(vec[1]))
             ans += vec[2];
    }
    
    cout << ans;
}