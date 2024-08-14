#include <fstream>
#include <iostream>

void walk(int from, int citiesN, bool* citiesVisited, bool** matrixMap) {
  for (int i = from; i < citiesN; i++) {
    if (matrixMap[from][i] && !citiesVisited[i]) {
      citiesVisited[i] = true;
      std::cout << "build road between " << from + 1 << " and " << i + 1
                << '\n';
      walk(i, citiesN, citiesVisited, matrixMap);
    }
  }
}

int main() {
  std::fstream ifile("input.txt");
  int citiesN, roads, libCost, roadCost;
  ifile >> citiesN >> roads >> libCost >> roadCost;
  if (libCost < roadCost) {
    std::cout << "build lib at every city\n";
    std::cout << "min cost: " << libCost * citiesN;
  } else {
    bool** matrixMap = new bool*[citiesN];
    for (int i = 0; i < citiesN; ++i) matrixMap[i] = new bool[citiesN]();
    for (int i = 0; i < roads; i++) {
      int c1, c2;
      ifile >> c1 >> c2;
      matrixMap[c1 - 1][c2 - 1] = true;
      matrixMap[c2 - 1][c1 - 1] = true;
    }
    bool* citiesVisited = new bool[citiesN]();
    int group = 0;
    for (int i = 0; i < citiesN; i++) {
      if (!citiesVisited[i]) {
        std::cout << "build lib at " << i + 1 << '\n';
        group++;
        citiesVisited[0] = true;
        walk(0, citiesN, citiesVisited, matrixMap);
      }
    }
    std::cout << "min cost: " << (citiesN - group) * roadCost + group * libCost;
  }
  return 0;
}