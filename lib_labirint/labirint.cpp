#include "labirint.h"

void Island(DSU a, int** d, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (j != y - 1) {
				if (d[i][j] == 1 && d[i][j + 1] == 1) { a.union_dsu((j + i * y) + 1, ((j + 1) + i * y) + 1); }
			}
			if (i != x - 1)
				if (d[i][j] == 1 && d[i + 1][j] == 1)
					a.union_dsu((j + i * y) + 1, (j + (i + 1) * y) + 1);
		}
	}
}

int CountOfIslands(DSU a, int** d, int x, int y) {
	int n = 0;
	for (int i = 1; i <= x * y; i++) {
		if (a.getParent(i) == i)
			n++;
	}
	return n;
}


int main() {
	DSU b(12);
	int data[3][4]{
		{1, 0, 1, 0},
		{1, 1, 0, 0},
		{0, 1, 0, 1}
	};

	Island(b, reinterpret_cast<int*>(data), 3, 4);
	CountOfIslands(b, reinterpret_cast<int*>(data), 3, 4);
}
