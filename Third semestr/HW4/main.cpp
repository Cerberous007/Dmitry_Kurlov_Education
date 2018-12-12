#include<thread>
#include<algorithm>
#include<iostream>
using namespace std;

int n=1000;
void srt(int *a){
	sort(a, a+n);	
}

int main(){	
	srand(23917);
	int *a= new int[n];
    for(int i=0; i<n; ++i)
    {
    	a[i]=rand();
    }
    thread T1(&srt, a);
    thread T2(&srt, a);
    T1.join();
    T2.join();
    for(int i=0; i<n; i++){
    	if(a[i]>a[i+1])
    		cout<<"a["<<i<<"] > a["<<i+1<<"] !!! \n"; 
    }
}

