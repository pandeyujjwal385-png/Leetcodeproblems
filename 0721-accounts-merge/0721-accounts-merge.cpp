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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        disjoint ds(n);
        unordered_map<string,int> mapmail;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail= accounts[i][j];
                if(mapmail.find(mail)==mapmail.end()){
                    mapmail[mail]=i;
                }
                else{
                    ds.unionbysize(i,mapmail[mail]);
                    }
            }
        }
        vector<string> mailfinal[n];
        for(auto it:mapmail){
            string mail=it.first;
            int node= ds.findPar(it.second);
            mailfinal[node].push_back(mail);
        }
 vector<vector<string>> ans;
 for(int i=0;i<n;i++){
    if(mailfinal[i].size()==0) continue;
    sort(mailfinal[i].begin(),mailfinal[i].end());
    vector<string>temp;
    temp.push_back(accounts[i][0]);
    for(auto it:mailfinal[i]){
        temp.push_back(it);
    }
    ans.push_back(temp);
 }
        return ans;

    }
};