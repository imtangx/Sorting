#include <stdio.h>
#include <stdlib.h>
void merge(int a[],int left,int mid,int right)
{
	int *help=(int*)malloc((right-left+1)*sizeof(int)); //������ʱ���� 
	int i=0;
	//˫ָ�뻬�� 
	int p1=left;
	int p2=mid+1;
	while(p1<=mid&&p2<=right)
	{
		help[i++]=(a[p1]<a[p2]?a[p1++]:a[p2++]);
	}
	while(p1<=mid)
	{
		help[i++]=a[p1++];
	}	
	while(p2<=right)
	{
		help[i++]=a[p2++];
	}
	for(i=0;i<right-left+1;i++)
	{
		a[left+i]=help[i]; //�ص㣺a[left+i]������a[i],ÿ�ι鲢a����߽粻һ��Ϊ0 
	}
	free(help);
}

void process(int a[],int left,int right)
{
	if(left==right) //ֻ��һ��Ԫ�أ���ʼ���Ϲ鲢 
	return;
	int mid=left+(right-left)/2;
	process(a,left,mid); //�����ݹ黮�� 
	process(a,mid+1,right); //�����ݹ黮�� 
	merge(a,left,mid,right);
}

int main()
{
	int i,a[]={};
	int length=sizeof(a)/sizeof(a[0]);
	process(a,0,length-1);
	//���� 
	for(i=0;i<length;i++)
	printf("%-3d",a[i]);
	return 0;
} 
