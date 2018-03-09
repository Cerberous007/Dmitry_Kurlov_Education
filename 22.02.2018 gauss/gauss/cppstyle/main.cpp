#include "parse_opt.h"
#include "gauss.h"

gauss g;

int main(int argc, const char *argv[]) {
	g.read(parse_opt(argc, argv));
	g.write_ans();
	return 0;
}