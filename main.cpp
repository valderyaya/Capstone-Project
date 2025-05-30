#include<bits/stdc++.h>
using namespace std;
#include "Bag.h"
#include "Graph.h"
#include "TreeDecomposition.h"
#include "NiceTreeDecomposition.h"
#include "ImproveTreeDecomposition.h"
#include "Debug_func.h"
#include "DCSGQ.h"


int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    bool debug = 0;

    if(debug) cout << "------------Start--------------"<<endl;


    int n, m;
    vector<int> UpBound, LowBound, weight;
    map<pair<int, int>, int> edge_weight, edge_id;
    vector<pair<int, int>> edge;
    Graph<int> ori;
    cin >> n >> m;
    UpBound.resize(n + 1);
    LowBound.resize(n + 1);
    weight.resize(n + 1);
    edge.resize(m + 1);
    for(int i = 1; i <= n; ++i) cin >> weight[i];
    for(int i = 1; i <= n; ++i) cin >> UpBound[i];
    for(int i = 1; i <= n; ++i) cin >> LowBound[i];
    for(int x, y, z, i = 1; i <= m; ++i){
        cin >> x >> y >> z;
        ori.add_edge(x, y);
        edge_weight[{x, y}] = z;
        edge_weight[{y, x}] = z;
        edge[i] = {x, y};
        edge_id[{x, y}] = i;
        edge_id[{y, x}] = i;
    }
    TreeDecomposition<int> td(ori);

    if(debug) cout << "---------Start Imporve--------------"<<endl;
    
    // ImproveTreeDecomposition itd(td);
    // itd.Impore_Decomposition();
    
    set<int> s;
    for(int i = 1; i <= n; ++i) s.insert(i);
    td.create_Bag(s);

    auto start = std::chrono::high_resolution_clock::now();

    ImproveTreeDecomposition itd(td);
    itd.improve_decomposition();

    // cout<< itd.treeDecomposition.isValid() << endl;
    // print_graph_bag(itd.treeDecomposition.tree);

    if(!itd.treeDecomposition.isValid()){
        return 1;
    }
    if(debug) cout << "-----------end Imporve--------------"<<endl;

    if(debug) cout << "---------Start Nice Tree--------------"<<endl;
    NiceTreeDecomposition ntd(itd.treeDecomposition);
    ntd.root = ntd.make_nice(ntd.findSuitableRoot());
    ntd.classify_bags();
    // print_graph_bag(ntd.treeDecomposition.tree);

    if(!ntd.treeDecomposition.isValid()){
        // cout<< ntd.treeDecomposition.isValid() << endl;
        return 1;
    }
    // print_bags_type(ntd);
    // ntd.compute_tree_index();

    if(debug) cout << "----------end Nice Tree-------------"<<endl;


    if(debug) cout << "----------Start solve--------------"<<endl;
    DCSGQ<int> solver(ntd);
    solver.n = n;
    solver.UpBound = UpBound;
    solver.LowBound = LowBound;
    solver.weight = weight;
    solver.edge = edge;
    solver.edge_id = edge_id;

    solver.solve();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << "Time: " << duration.count() << "\n";

    if(debug) cout << "------------Finish--------------"<<endl;
    return 0;
}



// g++ -mcmodel=medium -Ofast -o solver ./main.cpp