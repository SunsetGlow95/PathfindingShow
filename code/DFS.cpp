/**
 * @file DFS.cpp
 * @author mzx
 * @version 0.2
 * @date 2022-05-21
 */
#include "Maze.h"
using namespace maze;
using namespace std;

bool dfs(int x, int y) {
  if (x == HEIGHT - 2 && y == WIDTH - 2) return true;
  graph[x][y] = CUR;
  print();
  for (int i(0); i != DIRs; ++i) {
    int nx(x + Xs[i]), ny(y + Ys[i]);
    if (graph[nx][ny] == UNVST) {
      befx[nx][ny] = x;
      befy[nx][ny] = y;
      if (dfs(nx, ny)) {
        return true;
      }
    }
  }
  graph[x][y] = VST;
  print();
  return false;
}

int main() {
  init();
  dfs(1, 1);
  goback();
  return 0;
}
