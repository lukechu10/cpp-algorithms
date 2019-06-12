#include "digraph.h"

using namespace std;

Digraph::Digraph(unsigned V) {
  this->V_ = V;
  this->E_ = 0;
  adj_ = vector<unordered_multiset<unsigned>>(V);
}

void Digraph::addEdge(unsigned v, unsigned w) {
  adj_[v].insert(w);
  E_++;
}

Digraph Digraph::reverse() {
  Digraph R(V_);
  for (unsigned v = 0; v < V_; v++) {
    for (int w : adj_[v]) {
      R.addEdge(w, v);
    }
  }

  return R;
}