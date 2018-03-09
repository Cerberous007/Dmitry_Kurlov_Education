#include <cstdio>
#include <cstring>

bool parse_opt(int argc, const char *argv[]) 
{
	bool res(false);
	switch (argc)
	{
		case 1:
			puts("Options:\n\t-fin FILE\tread from FILE\n\t-fout FILE\twrite answer to FILE");
			res = true;
			break;
		case 3:
			if (!strcmp(argv[1], "-fin"))
				freopen(argv[2], "r", stdin);
			if (!strcmp(argv[1], "-fout"))
				freopen(argv[2], "w", stdout);
			break;
		case 5:
			if (!strcmp(argv[1], "-fin"))
				freopen(argv[2], "r", stdin);
			if (!strcmp(argv[1], "-fout"))
				freopen(argv[2], "w", stdout);
			if (!strcmp(argv[3], "-fin"))
				freopen(argv[4], "r", stdin);
			if (!strcmp(argv[3], "-fout"))
				freopen(argv[4], "w", stdout);
	}
	return res;
}