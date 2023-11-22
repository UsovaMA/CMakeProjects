#include <iostream>
#include "disjoint_sets.h"


DSU::DSU(): size(0), rank(nullptr), data(nullptr) {}
DSU::DSU(int _size): size(_size) {
    for (int i = 1; i < size; i++) {
        rank[i] = 0;
    }
    for (int i = 1; i < size; i++) {
        data[i] = i;
    }
}
int DSU::find(int val) {
    if (val == data[val])
        return val;
    return find(data[val]);
}
void DSU::_union(int x, int y) {
    int parent_x = find(x), parent_y = find(y);
    if (rank[x] == rank[y]) {
        data[parent_x] = parent_y;
        rank[y]++;
    }
    else if (rank[x] > rank[y])
        data[parent_y] = parent_x;
}
std::ostream& operator<<(std::ostream& out, const DSU& set) {
    for (int i = 1; i < set.size; i++) {
        std::cout << set.data[i] << " ";
    }
    return out;
}