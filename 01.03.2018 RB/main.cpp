#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "RBset.h"
#include "operators.h"

const int MAXN(1e3);

pset root[MAXN];

void print(pset v, int p = 0, int tab = 0);

int main() {
	srand(92345);
	double v;
	int com, id1, id2, id3;
	puts("ID is int [0..999]\nKEY is double\nEnter command num:\n0. Print Set\n1. Add key in Set");
	puts("2. Erase key from Set\n3. Check key in Set\n4. Copy Set\n5. Union two Sets\n6. Intersection two Sets");
	for (;;) {
		scanf("%d", &com);
		switch(com) {
			case 0:
				puts("Print\nID");
				scanf("%d", &id1);
				if (root[id1])
					print(root[id1]);
				break;
			case 1:
				puts("Add\nID KEY");
				scanf("%d%lf", &id1, &v);
				if (!root[id1] || !root[id1]->check(v))
					root[id1] = root[id1] ? root[id1]->insert(v) : new RBset(v, false);
				break;
			case 2:
				puts("Erase\nID KEY");
				scanf("%d%lf", &id1, &v);
				if (root[id1] && root[id1]->check(v))
					root[id1] = root[id1] ? root[id1]->erase(v) : NULL;
				break;
			case 3:
				puts("Check\nID KEY");
				scanf("%d%lf", &id1, &v);
				puts(root[id1] && root[id1]->check(v) ? "Exist" : "Not exist");
				break;
			case 4:
				puts("Copy\nID_SOURCE ID_TO");
				scanf("%d%d", &id1, &id2);
				if (id1 != id2) {
					clear(root[id2]);
					root[id2] = NULL;
					if (root[id1])
						root[id2] = new RBset(*root[id1]);
				}
				break;
			case 5:
				puts("Union\nID_A ID_B ID_TO");
				scanf("%d%d%d", &id1, &id2, &id3);
				if (root[id1] && root[id2]) {
					if (id1 != id3 && id2 != id3)
						clear(root[id3]);
					root[id3] = new RBset(*root[id1] + *root[id2]);
				} else
					if (root[id1] && id1 != id3) {
						clear(root[id3]);
						root[id3] = new RBset(*root[id1]);
					} else
						if (root[id2] && id2 != id3) {
							clear(root[id3]);
							root[id3] = new RBset(*root[id2]);
						} else
							if (!root[id1] && !root[id2]) {
								clear(root[id3]);
								root[id3] = NULL;
							}
				break;
			case 6:
				puts("Intersection\nID_A ID_B ID_TO");
				scanf("%d%d%d", &id1, &id2, &id3);
				if (root[id1] && root[id2]) {
					if (id1 != id3 && id2 != id3)
						clear(root[id3]);
					root[id3] = new RBset(*root[id1] * *root[id2]);
				} else {
					clear(root[id3]);
					root[id3] = NULL;
				}
		}
		puts("--------------------");
	}
	return 0;
}

void print(pset v, int p, int tab) {
	if (v->right)
		print(v->right, 1, tab + 1);
	for (int i(0); i < tab - 1; ++i)
		printf("   ");
	if (p > 0)
		printf(" /=");
	if (p < 0)
		printf(" \\=");
	printf("[%c] %.0lf\n", v->color ? 'R' : 'B', v->key);
	if (v->left)
		print(v->left, -1, tab + 1);
}