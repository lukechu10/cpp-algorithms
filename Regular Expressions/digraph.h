#pragma once

#include <unordered_set>
#include <vector>

class Digraph {
  unsigned V_;                                         // number of vertices
  unsigned E_;                                         // number of edges
  std::vector<std::unordered_multiset<unsigned>> adj_; // adjacent vertices

public:
  explicit Digraph(unsigned V);
  // get values
  unsigned V() { return V_; }
  unsigned E() { return E_; }
  std::unordered_multiset<unsigned> adj(unsigned v) { return adj_[v]; };

  void addEdge(unsigned v, unsigned w); // add edge to digraph

  Digraph reverse(); // digraph with all edges in opposite direction
};