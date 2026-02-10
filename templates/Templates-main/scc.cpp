class Kosaraju{
    // FOR DIRECTED GRAPHS
public:
    vector<vector<int>> adj, r_adj;
    vector<int> order;
    int n;
    int size;
    vector<vector<int>> components;
    vector<int> id;

    Kosaraju(const vector<vector<int>> &adj, int n){
        this->adj = adj;
        r_adj.assign(n + 1, {});
        this->n = n;
        id.assign(n + 1, -1);
        size = 0;
        for (int i = 0; i <= n; ++i) {
            for (auto u: adj[i]) r_adj[u].push_back(i);
        }
        vector<bool> vis(n + 1);
        for (int i = 0; i <= n; ++i) {
            if (!vis[i]) dfs1(i, vis);
        }
        reverse(order.begin(), order.end());
        std::fill(vis.begin(), vis.end(), false);
        for (int v: order){
            if (!vis[v]){
                components.push_back({});
                dfs2(v, size++, vis);
            }
        }
    }

    vector<vector<int>> getComponentsGraph(){
        // Returns adjacency list of components in adj[c1] = components adjacent to c1
        vector<vector<int>> ret(size);
        for (int i = 0; i < size; ++i) {
            set<int> nxt;
            for (auto u: components[i]){
                for (auto v: adj[u]) {
                    if (id[v] != i)
                        nxt.insert(id[v]);
                }
            }
            ret[i] = vector<int>{nxt.begin(), nxt.end()};
        }
        return ret;
    }

private:
    void dfs1(int s, vector<bool> &vis){
        if (vis[s]) return;
        vis[s] = true;
        for (auto u: adj[s]) dfs1(u, vis);
        order.push_back(s);
    }

    void dfs2(int s, int component, vector<bool> &vis){
        if (vis[s]) return;
        vis[s] = true;
        components[component].push_back(s);
        id[s] = component;
        for (auto u: r_adj[s]) dfs2(u, component, vis);
    }
};


class TarjanSolver {
    // FOR DIRECTED GRAPHS
    // Same as Kosaraju, but slightly faster
private:
    vector<vector<int>> rev_adj;
    vector<int> post;
    vector<int> comp;

    vector<bool> visited;
    int timer = 0;
    int id = 0;

    void fill_post(int at) {
        visited[at] = true;
        for (int n: rev_adj[at]) {
            if (!visited[n]) { fill_post(n); }
        }
        post[at] = timer++;
    }

    void find_comp(int at) {
        visited[at] = true;
        comp[at] = id;
        for (int n: adj[at]) {
            if (!visited[n]) { find_comp(n); }
        }
    }

public:
    const vector<vector<int>> &adj;

    TarjanSolver(const vector<vector<int>> &adj)
            : adj(adj), rev_adj(adj.size()), post(adj.size()), comp(adj.size()),
              visited(adj.size()) {
        vector<int> nodes(adj.size());
        for (int n = 0; n < adj.size(); n++) {
            nodes[n] = n;
            for (int next: adj[n]) { rev_adj[next].push_back(n); }
        }

        for (int n = 0; n < adj.size(); n++) {
            if (!visited[n]) { fill_post(n); }
        }
        std::sort(nodes.begin(), nodes.end(),
                  [&](int n1, int n2) { return post[n1] > post[n2]; });

        visited.assign(adj.size(), false);
        for (int n: nodes) {
            if (!visited[n]) {
                find_comp(n);
                id++;
            }
        }
    }

    vector<vector<int>> getNodesPerComponent() {
        vector<vector<int>> components(id);
        for (int i = 0; i < rev_adj.size(); ++i) {
            components[get_comp(i)].push_back(i);
        }
        return components;
    }

    vector<vector<int>> getComponentsGraph() {
        // Returns adjacency list of components in adj[c1] = components adjacent to c1
        vector<vector<int>> ret(id);
        auto components = getNodesPerComponent();
        for (int i = 0; i < id; ++i) {
            set<int> nxt;
            for (auto u: components[i]) {
                for (auto v: adj[u]) {
                    if (get_comp(v) != i)
                        nxt.insert(get_comp(v));
                }
            }
            ret[i] = vector<int>{nxt.begin(), nxt.end()};
        }
        return ret;
    }


    int comp_num() const { return id; }

    int get_comp(int n) const { return comp[n]; }
};


class TarjanSolver {
    // FOR WEIGHTED DIRECTED GRAPHS
private:
    vector<vector<ii>> rev_adj;
    vector<int> post;
    vector<int> comp;

    vector<bool> visited;
    int timer = 0;
    int id = 0;

    void fill_post(int at) {
        visited[at] = true;
        for (auto [n, w]: rev_adj[at]) {
            if (!visited[n]) { fill_post(n); }
        }
        post[at] = timer++;
    }

    void find_comp(int at) {
        visited[at] = true;
        comp[at] = id;
        for (auto [n, w]: adj[at]) {
            if (!visited[n]) { find_comp(n); }
        }
    }

    void dfs_edges_sum(int s, vector<ll> &sum, vector<bool> &vis){
        if (vis[s]) return;
        vis[s] = true;
        for (auto [u, w]: adj[s]){
            if (get_comp(u) == get_comp(s)) sum[get_comp(s)] += w;
            dfs_edges_sum(u, sum, vis);
        }
    }

public:
    const vector<vector<ii>> &adj;

    TarjanSolver(const vector<vector<ii>> &adj)
            : adj(adj), rev_adj(adj.size()), post(adj.size()), comp(adj.size()),
              visited(adj.size()) {
        vector<int> nodes(adj.size());
        for (int n = 0; n < adj.size(); n++) {
            nodes[n] = n;
            for (auto [next, w]: adj[n]) { rev_adj[next].push_back({n, w}); }
        }

        for (int n = 0; n < adj.size(); n++) {
            if (!visited[n]) { fill_post(n); }
        }
        std::sort(nodes.begin(), nodes.end(),
                  [&](int n1, int n2) { return post[n1] > post[n2]; });

        visited.assign(adj.size(), false);
        for (int n: nodes) {
            if (!visited[n]) {
                find_comp(n);
                id++;
            }
        }
    }

    vector<vector<int>> getNodesPerComponent() {
        vector<vector<int>> components(id);
        for (int i = 0; i < rev_adj.size(); ++i) {
            components[get_comp(i)].push_back(i);
        }
        return components;
    }

    vector<vector<ii>> getComponentsGraph() {
        // Returns adjacency list of components in adj[c1] = components adjacent to c1
        vector<vector<ii>> ret(id);
        auto components = getNodesPerComponent();
        for (int i = 0; i < id; ++i) {
            set<ii> nxt;
            for (auto u: components[i]) {
                for (auto [v, w]: adj[u]) {
                    if (get_comp(v) != i)
                        nxt.insert({get_comp(v), w});
                }
            }
            ret[i] = vector<ii>{nxt.begin(), nxt.end()};
        }
        return ret;
    }

    vector<ll> getComponentsEdgesSum(){
        vector<bool> vis(adj.size());
        vector<ll> sums(id);

        for (int i = 0; i < adj.size(); ++i) {
            if (!vis[i]) dfs_edges_sum(i, sums, vis);
        }

        return sums;
    }

    int comp_num() const { return id; }

    int get_comp(int n) const { return comp[n]; }
};


class TarjanBridges {
    // For undirected graphs
    // A bridge is an edge if removed the graph becomes disconnected
    // two nodes are in the SCC if no matter which edge you delete they remain connected
private:
    const vector<vector<int>> &adj;
    int n;
    vector<bool> visited;
    vector<int> tin, low;
    vector<pair<int, int>> bridges;
    int timer = 0;
    vector<int> comp;
    vector<bool> visited_comp;
    vector<vector<int>> compTree;
    int size = 0;
 
    void dfsBridge(int u, int parent) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        for (int v: adj[u]) {
            if (v == parent) continue;
            if (visited[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfsBridge(v, u);
                low[u] = min(low[u], low[v]);
                // To handle duplicate edges, ADJ MUST BE SORTED
//                int cnt = upper_bound(adj[u].begin(), adj[u].end(), v) - lower_bound(adj[u].begin(), adj[u].end(), v);
                if (low[v] > tin[u]/* && cnt == 1*/) {
                    bridges.emplace_back(u, v);
                }
            }
        }
    }
 
    void dfsComponent(int u, int cid, const set<pair<int, int>> &bridgeSet) {
        visited_comp[u] = true;
        comp[u] = cid;
        for (int v: adj[u]) {
            if (bridgeSet.count({u, v}) || bridgeSet.count({v, u}))
                continue;
            if (!visited_comp[v]) {
                dfsComponent(v, cid, bridgeSet);
            }
        }
    }
 
public:
    TarjanBridges(const vector<vector<int>> &graph)
            : adj(graph), n(graph.size()) {
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        comp.assign(n, -1);
        visited_comp.assign(n, false);
        findBridges();
        compTree = buildBridgeTree();
        size = compTree.size();
    }
 
 
    vector<pair<int, int>> findBridges() {
        if (!bridges.empty()) return bridges;
        fill(visited.begin(), visited.end(), false);
        timer = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfsBridge(i, -1);
            }
        }
        return bridges;
    }
 
    vector<vector<int>> buildBridgeTree() {
        // A tree for where each node represents an SCC and every edge represents a bridge
        if (!compTree.empty()) return compTree;
        vector<pair<int, int>> br = findBridges();
        set<pair<int, int>> bridgeSet(br.begin(), br.end());
        int cid = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited_comp[i]) {
                dfsComponent(i, cid++, bridgeSet);
            }
        }
        vector<set<int>> treeSet(cid);
        for (auto &e: br) {
            int u = comp[e.first];
            int v = comp[e.second];
            treeSet[u].insert(v);
            treeSet[v].insert(u);
        }
        vector<vector<int>> tree(cid);
        for (int i = 0; i < cid; ++i) {
            tree[i] = vector<int>(treeSet[i].begin(), treeSet[i].end());
        }
        return tree;
    }
 
    int getComp(int x) {
        return comp[x];
    }
 
    int comp_num() const { return size; }
};


class TarjanBridges {
    // For weighted undirected graphs
    // Same as above but weighted
private:
    const vector<vector<ii>> &adj;
    int n;
    vector<bool> visited;
    vector<int> tin, low;
    vector<array<int, 3>> bridges;
    int timer = 0;
    vector<int> comp;
    vector<bool> visited_comp;
    vector<vector<ii>> compTree;
    int size = 0;

    void dfsBridge(int u, int parent) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        for (auto [v, w]: adj[u]) {
            if (v == parent) continue;
            if (visited[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfsBridge(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    bridges.emplace_back(array<int, 3>{u, v, w});
                }
            }
        }
    }

    void dfsComponent(int u, int cid, const set<array<int, 3>> &bridgeSet) {
        visited_comp[u] = true;
        comp[u] = cid;
        for (auto [v, w]: adj[u]) {
            if (bridgeSet.count({u, v, w}) || bridgeSet.count({v, u, w}))
                continue;
            if (!visited_comp[v]) {
                dfsComponent(v, cid, bridgeSet);
            }
        }
    }

public:
    TarjanBridges(const vector<vector<ii>> &graph)
            : adj(graph), n(graph.size()) {
        visited.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        comp.assign(n, -1);
        visited_comp.assign(n, false);
        findBridges();
        compTree = buildBridgeTree();
        size = compTree.size();
    }

    vector<array<int, 3>> findBridges() {
        bridges.clear();
        fill(visited.begin(), visited.end(), false);
        timer = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfsBridge(i, -1);
            }
        }
        return bridges;
    }

    vector<vector<ii>> buildBridgeTree() {
        vector<array<int, 3>> br = findBridges();
        set<array<int, 3>> bridgeSet(br.begin(), br.end());
        int cid = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited_comp[i]) {
                dfsComponent(i, cid++, bridgeSet);
            }
        }
        vector<set<ii>> treeSet(cid);
        for (auto &[e, f, w]: br) {
            int u = comp[e];
            int v = comp[f];
            treeSet[u].insert({v, w});
            treeSet[v].insert({u, w});
        }
        vector<vector<ii>> tree(cid);
        for (int i = 0; i < cid; ++i) {
            tree[i] = vector<ii>(treeSet[i].begin(), treeSet[i].end());
        }
        return tree;
    }

    int getComp(int x) {
        return comp[x];
    }
    
    int comp_num() const { return bridges.size() + 1; }
};


/* USACO's template till I write my own
 an articulation point is a node that the graph becomes disconnected when removed
 Two nodes are in the same SCC if removal of any node does not affect their connectivity
 A block-cut tree is the tree connecting SCCs based of articulation points
 */
/** @return the block-cut tree of a graph */
vector<vector<int>> biconnected_components(vector<vector<int>> &g,
                                           vector<bool> &is_cutpoint, vector<int> &id) {
    int n = (int)g.size();

    vector<vector<int>> comps;
    vector<int> stk;
    vector<int> num(n);
    vector<int> low(n);

    is_cutpoint.resize(n);

    // Finds the biconnected components
    function<void(int, int, int &)> dfs = [&](int node, int parent, int &timer) {
        num[node] = low[node] = ++timer;
        stk.push_back(node);
        for (int son : g[node]) {
            if (son == parent) { continue; }
            if (num[son]) {
                low[node] = min(low[node], num[son]);
            } else {
                dfs(son, node, timer);
                low[node] = min(low[node], low[son]);
                if (low[son] >= num[node]) {
                    is_cutpoint[node] = (num[node] > 1 || num[son] > 2);
                    comps.push_back({node});
                    while (comps.back().back() != son) {
                        comps.back().push_back(stk.back());
                        stk.pop_back();
                    }
                }
            }
        }
    };

    int timer = 0;
    dfs(0, -1, timer);
    id.resize(n);

    // Build the block-cut tree
    function<vector<vector<int>>()> build_tree = [&]() {
        vector<vector<int>> t(1);
        int node_id = 0;
        for (int node = 0; node < n; node++) {
            if (is_cutpoint[node]) {
                id[node] = node_id++;
                t.push_back({});
            }
        }

        for (auto &comp : comps) {
            int node = node_id++;
            t.push_back({});
            for (int u : comp)
                if (!is_cutpoint[u]) {
                    id[u] = node;
                } else {
                    t[node].push_back(id[u]);
                    t[id[u]].push_back(node);
                }
        }
        return t;
    };

    return build_tree();
}

