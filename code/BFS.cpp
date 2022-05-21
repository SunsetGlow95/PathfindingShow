/**
 * @file BFS.cpp
 * @author mzx
 * @version 0.2
 * @date 2022-05-21
 */
#include "Maze.h"
using namespace maze;
using namespace std;

struct Stat {
  int x, y, steps;
  Stat(int _x = -1, int _y = -1, int _s = 0) : x(_x), y(_y), steps(_s) {}
};

int main() {
  init();
  queue<Stat> q;
  q.push(Stat(1, 1));
  graph[1][1] = CUR;
  while (!q.empty()) {
    Stat cur(q.front()), nxt;
    q.pop();
    if (cur.x == HEIGHT - 2 && cur.y == WIDTH - 2) {
      break;
    }
    nxt.steps = cur.steps + 1;
    for (int i(0); i != DIRs; ++i) {
      nxt.x = cur.x + Xs[i], nxt.y = cur.y + Ys[i];
      if (graph[nxt.x][nxt.y] == UNVST) {
        graph[nxt.x][nxt.y] = CUR;
        befx[nxt.x][nxt.y] = cur.x;
        befy[nxt.x][nxt.y] = cur.y;
        q.push(nxt);
      }
    }
    graph[cur.x][cur.y] = VST;
    print();
  }
  goback();
  return 0;
}
