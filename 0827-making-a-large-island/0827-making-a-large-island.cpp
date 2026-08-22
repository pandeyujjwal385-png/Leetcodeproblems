class disjoint{
public:
  vector<int> rank,parent,size;
    disjoint(int n){
      rank.resize(n+1,0);
            size.resize(n+1);

      parent.resize(n+1);
      for(int i=0;i<=n;i++){
        parent[i]=i;
        size[i]=1;
      }

    }
    int findPar(int node){
      if(node==parent[node])
        return node;
        return parent[node]= findPar(parent[node]);

      
    }
    
    void unionbysize(int u,int v){
      int ulp_u=findPar(u);
      int ulp_v=findPar(v);
      if(ulp_u==ulp_v) return;
      if(size[ulp_u]<size[ulp_v]){
        parent[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
      }
      else{
        parent[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
      }

    }
    
    };
class Solution {
    bool isValid(int nrow,int ncol,int n){
        return nrow>=0 && nrow<n && ncol>=0 && ncol<n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disjoint ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                for(int ind=0;ind<4;ind++){
                    int nrow=row+dr[ind];
                    int ncol=col+dc[ind];
                    if(isValid(nrow,ncol,n)&& grid[nrow][ncol]==1){
                        int nodeno=row*n+col;
                        int adjnode=nrow*n+ncol;
                        ds.unionbysize(nodeno,adjnode);
                    }
                }
            }
        }
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
               if(grid[row][col]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                set<int>comp;
                for(int ind=0;ind<4;ind++){
                    int nrow=row+dr[ind];
                    int ncol=col+dc[ind];
                    if(isValid(nrow,ncol,n)){
                        if(grid[nrow][ncol]==1){
                            comp.insert(ds.findPar(nrow*n+ncol));
                        }
                    }
               
            }
            int sizetotal=0;
            for(auto it: comp){
                sizetotal+=ds.size[it];
            }
           mx=max(mx,sizetotal+1);
            }
        }
        for(int cellno=0;cellno<n*n;cellno++){
            mx=max(mx,ds.size[ds.findPar(cellno)]);
        }
    
            return mx;

    }
};