#include <stdio.h>
void swap(int a[],int i,int j)
{
	int k=a[i];
	a[i]=a[j];
	a[j]=k;
}
int main()
{
	int a[]={};
	int length=sizeof(a)/sizeof(a[0]);
	int i,j;
	for(i=length-1;i>0;i--) //j+1的存在,i=length-1以防越界
	{
		for(j=0;j<i;j++) 
		{
			if(a[j+1]<a[j]) 
			swap(a,j,j+1); //大的数往右沉 
		}
	}	
	//检验 
	for(i=0;i<length;i++)
	printf("%-3d",a[i]);
	return 0;
}

