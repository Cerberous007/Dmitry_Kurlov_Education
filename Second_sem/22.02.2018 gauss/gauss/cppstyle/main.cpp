#include "parse_opt.h"
#include "gauss.h"

int main(int argc, const char *argv[]) 
{
	gauss g;
	g.read(parse_opt(argc, argv));
	g.write_ans();
	return 0;
}