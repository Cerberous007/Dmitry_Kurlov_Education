#include <iostream>
using namespace std;

int main()
{
	float a,b,c,d,e,f,x,y;
	bool xr = false, yr = false, none = false, inf = false;
	cin >> a >> b >> c >> d >> e >> f;

	if(d && e && a/d == b/e){
		if (d && f && a/d == c/f) inf = true;
		else
		none = true;
	}

	if(a){
		e -= b*d/a;
		f -= c*d/a;
		if (e){
			y = f/e;
			x = (c - b*y)/a;
		}
		else{
			if(!f){
			yr = true;
			x = c/a;
			}				
			else none = true;
		}
	}
		
	if(!a && b)	{
		y = c/b;
		if(d)
			x = (f - e*y)/d;
		else
			xr = true;
	}

	if (!a && !b){
		none = c;
		if(!none){
			if(d && e) inf = true;
	 		else{
				if(d)  x = f/d; yr = true;
            	if(e)  y = f/e; xr = true;
	            if(!d && !e && f) none = true;
    	        if(!d && !e && !f) inf = true;
        	}
		}	
	}
		
	if (inf) cout << "infinite solutions \r";
	if (none) cout << "no solution \r";
	if (xr && !inf && !none) cout << "x belongs to R \r";
	if (!xr && !inf && !none) cout << "x = " << x << "\r";
	if (yr && !inf && !none) cout << "y belongs to R \r";
	if (!yr && !inf && !none) cout << "y = " << y << "\r";
	return 0;
}    