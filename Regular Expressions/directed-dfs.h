#pragma once

#include "digraph.h"

class DirectedDFS : Digraph {
public:
  DirectedDFS(Digraph G, std::vector<unsigned> sources);
  DirectedDFS(Digraph G, unsigned source);

private:
  std::vector<bool> marked; // array of vertices on tree
  void dfs(unsigned v);
};
