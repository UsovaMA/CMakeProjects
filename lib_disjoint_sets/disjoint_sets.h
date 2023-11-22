#include <iostream>

class DSU {
    int size;
    int* data;
    int* rank;
 public:
    DSU();
    DSU(int _size);
    int find (int val);
    void _union (int x, int y);
    friend std::ostream& operator<<(std::ostream& out, const DSU& set);
};