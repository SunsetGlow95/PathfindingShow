/**
 * @file Maze.h
 * @author mzx
 * @version 0.2
 * @date 2022-05-21
 */
#ifndef MAZE_H
#define MAZE_H

#include <algorithm>
#include <iostream>
#include <queue>
#include <random>
#include <stack>
#include <utility>
#include <vector>

namespace maze {

const int HEIGHT = 21;
const int WIDTH = 47;
const int MXHS = 230;
const int RDTMS = 30;
const char WALL = '+';
const char UNVST = ' ';
const char VST = '.';
const char CUR = '%';
const char GONE = '$';
const char DNE = '?';
const int DIRs = 4;
const int Xs[] = {0, 1, 0, -1};
const int Ys[] = {1, 0, -1, 0};
const int ID_STW = 28;
char graph[HEIGHT][WIDTH];
int befx[HEIGHT][WIDTH], befy[HEIGHT][WIDTH];
inline int hs(int x, int y) { return (x >> 1) * (WIDTH >> 1) + (y >> 1); }
inline std::pair<int, int> rhs(int v) {
  return std::make_pair((v / (WIDTH >> 1)) << 1 | 1,
                        (v % (WIDTH >> 1)) << 1 | 1);
}
int fa[MXHS];

void print() {
  system("clear");
  for (int i(0); i != HEIGHT; ++i) {
    for (int j(0); j != WIDTH; ++j) std::cout << graph[i][j];
    std::cout << '\n';
  }
  std::cout << std::endl;
  system("sleep 0.005");
}
int find(int x) { return x ^ fa[x] ? fa[x] = find(fa[x]) : x; }
void init() {
  std::ios::sync_with_stdio(false);
  for (int i(0); i != HEIGHT; ++i)
    for (int j(0); j != WIDTH; ++j) graph[i][j] = WALL;
  srand(time(0));
  std::vector<std::pair<int, int> > edges;
  for (int i(1); i < HEIGHT; i += 2)
    for (int j(1); j < WIDTH; j += 2) {
      graph[i][j] = UNVST;
      if (i + 2 < HEIGHT)
        edges.push_back(std::make_pair(hs(i, j), hs(i + 2, j)));
      if (j + 2 < WIDTH)
        edges.push_back(std::make_pair(hs(i, j), hs(i, j + 2)));
    }
  std::mt19937 gen(19260817);
  shuffle(edges.begin(), edges.end(), gen);
  for (int i(0); i != MXHS; ++i) fa[i] = i;
  for (std::vector<std::pair<int, int> >::const_iterator i(edges.begin());
       i != edges.end(); ++i) {
    if (find(i->first) != find(i->second)) {
      fa[find(i->first)] = find(i->second);
      std::pair<int, int> a(rhs(i->first)), b(rhs(i->second));
      graph[(a.first + b.first) >> 1][(a.second + b.second) >> 1] = UNVST;
    }
  }
  for (int i(0), x, y; i != RDTMS; ++i) {
    x = gen() % (HEIGHT - 2) + 1, y = gen() % (HEIGHT - 2) + 1;
    graph[x][y] = UNVST;
  }
}

void goback() {
  int x(HEIGHT - 2), y(WIDTH - 2), bx, by;
  while (x || y)
    graph[x][y] = GONE, bx = x, by = y, x = befx[bx][by], y = befy[bx][by],
    print();
  for (int i(0); i != HEIGHT; ++i)
    for (int j(0); j != WIDTH; ++j)
      if (graph[i][j] != GONE && graph[i][j] != WALL) graph[i][j] = UNVST;
  print();
}

void ckdne() {
  for (int i(0); i != HEIGHT; ++i)
    for (int j(0); j != WIDTH; ++j)
      if (graph[i][j] == VST) graph[i][j] = DNE;
  print();
}

}  // namespace maze

#endif
