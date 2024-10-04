// jai shree ram

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> adj(n + 1);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    set<pair<int, int>> s;
    s.insert({0, 1});
    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    while (s.size())
    {
        auto it = *(s.begin());
        int node = it.second;
        int wt = it.first;
        // cout<<node<<endl;
        s.erase(it);
        for (auto i : adj[node])
        {
            int adjNode = i[0];
            int adjWt = i[1];
            // cout<<adjNode<<" "<<adjWt<<"\n";
            if (adjWt + wt < dist[adjNode])
            {
              // cout<<adjNode;
              if(dist[adjNode] != 1e9) 
              s.erase({dist[adjNode] , adjNode});
                dist[adjNode] = adjWt + wt;
                s.insert({dist[adjNode] , adjNode});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}
