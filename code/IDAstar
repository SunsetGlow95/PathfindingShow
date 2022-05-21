/**
 * @file IDAstar.cpp
 * @author mzx
 * @version 0.1
 * @date 2022-05-20
 */
#include "Maze.h"
using namespace maze;
using namespace std;

bool dfs(int x, int y, int st) {
  if (x == HEIGHT - 2 && y == WIDTH - 2) return true;
  if ((HEIGHT - 2 - x) + (WIDTH - 2 - y) > st) return false;
  graph[x][y] = CUR;
  print();
  for (int i(0); i != DIRs; ++i) {
    int nx(x + Xs[i]), ny(y + Ys[i]);
    if (graph[nx][ny] == UNVST || graph[nx][ny] == DNE) {
      if (graph[nx][ny] == UNVST) {
        befx[nx][ny] = x;
        befy[nx][ny] = y;
      }
      if (dfs(nx, ny, st - 1)) {
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
  int lim(1);
  while (!dfs(1, 1, lim)) lim += 7, ckdne();
  goback();
  return 0;
}
