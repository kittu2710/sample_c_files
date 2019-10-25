#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
	        return ( *(int*)a - *(int*)b );
}






int main() {
	int n,d;
	scanf("%d %d",&n,&d);
	int a[10004][3];
	int i,j;


	for (i=1;i<=n;i++) 
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);

printf("\n");


	 qsort(&a[1][0], n, 3*sizeof(int), cmpfunc);

	 for (i=1;i<=n;i++) 
		 printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);

}
