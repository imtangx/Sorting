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
	for(i=0;i<length-1;i++) //j=i+1�Ĵ��ڣ�length-1�Է�Խ�� 
	{
		for(j=i+1;a[j]<a[j-1]&&j>0;j--) //������j����Խ�� 
		{
			swap(a,j,j-1);
		}
	}
	//���� 
	for(i=0;i<length;i++)
	printf("%-3d",a[i]);
	return 0;
} 

