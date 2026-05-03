class Solution {
public:

    class DSU{

        public:
            vector<int> parent;
            vector<int> rank;
            DSU(int n){
                parent.resize(n+1);
                rank.resize(n+1);

                for(int i=0;i<=n;i++){
                    parent[i] = i;
                }
            }

            int find(int x){

                if(parent[x]!=x){
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            }

            bool unite(int x,int y){
                int px = find(x);
                int py = find(y);


                if(px==py) return false; //cycle found

                if(rank[px]<rank[py]){
                    parent[px] = py;
                }
                else if(rank[px] > rank[py]){
                    parent[py] = px;
                }
                else{
                    parent[py] = px;
                    rank[px]++;
                }

                return true;

            }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        DSU dsu(n+1);

        for(auto e:edges){
            int u = e[0];
            int v = e[1];

            if(!dsu.unite(u,v)){
                return e;
            }

        }
        return {};
    }
};