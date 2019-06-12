#include <iostream>

#include "directed-dfs.h"

using namespace std;

int main() {
  Digraph G(10);
  DirectedDFS dfs(G, 10);
  return 0;
}