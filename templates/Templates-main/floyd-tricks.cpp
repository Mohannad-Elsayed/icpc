void TransitiveClosure(int n, vector<vector<int>>& adj) {
	// 0 = disconnected, 1 = connected
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				adj[i][j] |= (adj[i][k] & adj[k][j]);
}

void minimax(int n, vector<vector<int>>& adj) {
	// Path such that max value on road is minimized
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
}

void maximin(int n, vector<vector<int>>& adj) {
	// Path such that min value on road is maximized
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]));
}

void longestPathDAG(int n, vector<vector<int>>& adj) {
	// Only works for DAGs (no positive cycles)
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				adj[i][j] = max(adj[i][j], max(adj[i][k], adj[k][j]));
}

void countPaths(int n, vector<vector<int>>& adj) {
	// Floyd-Warshall for counting number of paths
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				adj[i][j] += adj[i][k] * adj[k][j];
}

bool isNegativeCycle(int n, const vector<vector<int>>& adj) {
	// run warshal first
	for (int i = 0; i < n; ++i)
		if (adj[i][i] < 0)
			return true;
	return false;
}

bool anyEffectiveCycle(int n, const vector<vector<int>>& adj, int src, int dest, int OO) {
	// run warshal first
	for (int i = 0; i < n; ++i)
		if (adj[i][i] < 0 && adj[src][i] < OO && adj[i][dest] < OO)
			return true;
	return false;
}