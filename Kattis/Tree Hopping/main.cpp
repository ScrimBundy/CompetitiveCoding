#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<int>> table;
int n;

int bfs(int v) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(v);
    visited[v] = true;
    int last = v;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        last = u;
        for (int w : table[u]) {
            if (!visited[w]) {
                visited[w] = true;
                q.push(w);
            }
        }
    }
    return last;
}

int findCenter() {
    int n = table.size();
    // Choose an arbitrary node as the root
    int root = 1;
    // Find the farthest node from the root
    int u = bfs(root);
    // Find the farthest node from u
    int v = bfs(u);
    // Find the path between u and v
    vector<int> path;
    while (v != u) {
        path.push_back(v);
        for (int w : table[v]) {
            if (w != v && w != path[path.size()-2]) {
                v = w;
                break;
            }
        }
    }
    path.push_back(u);
    // Find the center of the tree
    int k = path.size();
    if (k % 2 == 0) {
        return path[k/2-1];
    } else {
        return path[k/2];
    }
}

vector<int> costArray(int center) {
	
	vector<int> cost(n+1);
	cost[0] = -1;
	
	queue<pair<int,int>> q;
	q.push(make_pair(center, 0));
	
	while(!q.empty()) {
		pair<int,int> node = q.front();
		q.pop();
		cost[node.first] = cost[node.second] + 1;
		for(int i = 0; i < table[node.first].size(); i++) {
			int next = table[node.first][i];
			if(next != node.second) {
				q.push(make_pair(next, node.first));
			}
		}
	}
	
	return cost;
}

int main() {
    cin >> n;
    table.resize(n+1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        table[u].push_back(v);
        table[v].push_back(u);
    }
	
	int center = findCenter();
	
	cout << center << endl;
	
	vector<int> costToCenter = costArray(center);
	
	for(int i = 0; i < costToCenter.size(); i++) {
		cout << costToCenter[i] << ", ";
	}
	cout << endl;
    return 0;
}