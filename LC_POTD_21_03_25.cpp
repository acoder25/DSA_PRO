class Solution {
public:
    vector<string> findAllRecipes(vector<string>& arr1, vector<vector<string>>& arr2, vector<string>& arr3) {
        int n=arr1.size();
        int m=arr3.size();

        unordered_map<string,int> mpp;
        int cnt=1;
        for(int i=0;i<n;i++){
             if(mpp.find(arr1[i])==mpp.end()){
                   mpp[arr1[i]]=cnt;
                   cnt++;
             }
        }
        for(int i=0;i<n;i++){
            for(auto it:arr2[i]){
                if(mpp.find(it)==mpp.end()){
                   mpp[it]=cnt;
                   cnt++;
                }

            }
             
        }
        for(int i=0;i<m;i++){
             if(mpp.find(arr3[i])==mpp.end()){
                   mpp[arr3[i]]=cnt;
                   cnt++;
             }
        }
        unordered_map<int,string> mpp2;
        for(auto it:mpp){
            mpp2[it.second]=it.first;
        }
        vector<pair<int,int>> edges;
        for(int i=0;i<n;i++){
            for(auto it:arr2[i]){
                edges.push_back({mpp[it],mpp[arr1[i]]});
            }
        }
        vector<vector<int>> adj(cnt);
        for(int i=0;i<edges.size();i++){
            adj[edges[i].first].push_back(edges[i].second);
        }
        vector<int> indegree(cnt,0);

        for(int i=0;i<adj.size();i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<cnt;i++){
            if(indegree[i]==0 && find(arr3.begin(),arr3.end(),mpp2[i])!=arr3.end()){
                q.push(i);
            }
        }
        vector<string> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }

            }
            if(find(arr1.begin(),arr1.end(),mpp2[node])!=arr1.end()){
                topo.push_back(mpp2[node]);
            }
        }
        return topo;
    }
};
