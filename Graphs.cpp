#include <iostream>
#include <vector>
#include <list>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int output(vector<int> adj[],int val, int k,int v) {
    int out = 0;
    list<int> Q;
    bool visited[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < adj[val].size(); i++) {
        if (!visited[adj[val][i]]) {
            Q.push_back(adj[val][i]);
            visited[adj[val][i]] = true;
        }
    }
    while (k > 1) {
        int n = Q.size();
        for (int i = 0; i < n; i++) {
            int temp = Q.front();
            for (int i = 0; i < adj[temp].size(); i++) {
                if (!visited[adj[temp][i]]) {
                    Q.push_back(adj[temp][i]);
                    visited[adj[temp][i]] = true;
                }
            }
            Q.pop_front();
            Q.remove(val);
        }
        k--;
    }
    out = Q.size();
    return out;

}
int main() {
    int Nv, n, u, v,start,k;
    cout << "Enter number of vertices" << endl;
    cin >> Nv;
    vector<int> adj[Nv+1];
    cout << "Enter number of edges" << endl;
    cin >> n;
    cout << "Enter u,v" << endl;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    cout << "Enter starting vertex" << endl;
    cin >> start;
    cout << "Enter K" << endl;
    cin >> k;
    int out = output(adj, start, k,Nv);
    cout << "there are " << out << " people with " << k << " connections away starting from " << start << endl;

    return 0;
}
