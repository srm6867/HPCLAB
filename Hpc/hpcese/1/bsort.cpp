#include <omp.h>
#include <stdio.h>
#include<stdlib.h>

void swap(int &x,int &y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
void bsort(int *a ,int n)
{
	for(int i=0;i<n;i++)
	{
		int first=i%2;
		#pragma opm parallel for shared(a,first)
		for(int j=first;j<n-1;j=j+2)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
}

 int main()
 {
 	int a[]={9,4,1,8,5,10,20};
 	bsort(a,7);
 	for(int i=0;i<7;i++)
 	{
 		printf("%d , ",a[i]);	
	}
 }
