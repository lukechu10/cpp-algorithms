#include "directed-dfs.h"
#include <iostream>
#include <vector>

using namespace std;

DirectedDFS::DirectedDFS(Digraph G, vector<unsigned> sources) : Digraph(G) {}

DirectedDFS::DirectedDFS(Digraph G, unsigned source) : Digraph(G) {
  dfs(source);
}

void DirectedDFS::dfs(unsigned V) {
  marked[V] = true;
  for (auto &w : adj(V)) {
    if (!marked[w])
      dfs(w);
  }
}
