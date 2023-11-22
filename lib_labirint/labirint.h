// Copyright (c) Mezhuev Maksim

#ifndef INCLUDE_DSU_H_
#define INCLUDE_DSU_H_

class DSU {
    int* data;
    int size;
    int* ranks;
public:
    explicit DSU(int _size) : size(_size) { 
        data = new int[size + 1];
        ranks = new int[size + 1];
        data[0] = -1;
        ranks[0] = -1;
        for (int i = 1; i <= size; i++) {
            data[i] = i;
            ranks[i] = 0;
        }
    }

    int find(int val) {
        if (val == data[val]) {
            return val;
        }
        return find(data[val]);
    }

    int rank(int val) {
        return ranks[find(val)];
    }

    void union_dsu(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);
    }
};

#endif  // INCLUDE_DSU_H_
