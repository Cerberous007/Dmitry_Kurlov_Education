#include<cstdio>
#include"pair_vectors.h"
using namespace std;

int main()
{
	pair_vectors p;
	FILE *fin(fopen("in.txt", "r")), *fout(fopen("out.txt", "w")); 	
	fscanf(fin, "%d%d%d%d", &p.a, &p.b, &p.c, &p.d);	
	fprintf(fout, "dp: %d\n cp: %d", p.d_p(), p.c_p());
	fprintf(fout, "%d %d %d %d\n", p.a, p.b, p.c, p.d);
	fclose(fin), fclose(fout);
	return 0;
}