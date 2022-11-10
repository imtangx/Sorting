#include <stdio.h>
void swap(int *a,int *b) 
{
	int k=*a;
	*a=*b;
	*b=k;
}
void quicksort(int a[],int left,int right)
{
	if(left>=right)
	return;
	int target=a[right];
	int i=0,j=0,k=right-1;
	while(i<k)
	{
	if(a[i]<=target)
    swap(&a[i++],&a[j++]);
    else if(a[i]>target)
    swap(&a[i],&a[k--]);
    }
    k++;
	swap(&a[k],&a[right]);
	quicksort(a,left,k-1);
	quicksort(a,k+1,right);
}
int main()
{
	int a[]={4,5,2,1,};
	int length=sizeof(a)/sizeof(a[0]);
	quicksort(a,0,length-1);
	int i=0;
	for(i=0;i<length;i++)
	printf("%-5d",a[i]);
	return 0;
}
