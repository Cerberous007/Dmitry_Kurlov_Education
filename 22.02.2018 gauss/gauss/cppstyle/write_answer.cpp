#include<stdio>
#include"gauss.h"

void gauss::write_ans()
{
	int ans(calc());
	if(ans)
	{
		puts(ans>0?"one slut:" : "a lot of solutions. Exam:");
		for(int i=0; i<n; i++)
		{
			printf("%f", x[i]);
		}
	}else
		puts("no solut");
}
