#include <stdio.h>
void process(int a[],int help[],int left,int right);
void merge(int a[],int help[],int left,int mid,int right);
int main()
{
	int a[]={3,4,9,2,1,100,};
	int length=sizeof(a)/sizeof(a[0]);
	int help[length]; //������ʱ���� 
	process(a,help,0,length-1);
	int i=0;
	for(i=0;i<length;i++)
	printf("%-5d",a[i]);
	return 0;
}

void process(int a[],int help[],int left,int right)
{
	if(left==right) //ֻ��һ��Ԫ�أ��ݹ黮�ֽ������� ����ʼ���Ϲ鲢 
	return;
	int mid=left+(right-left)/2;
	process(a,help,left,mid);
	process(a,help,mid+1,right);
	merge(a,help,left,mid,right);
}

void merge(int a[],int help[],int left,int mid,int right)
{ 
	int i=left;
	int p1=left;
	int p2=mid+1;
	while(p1<=mid && p2<=right)
	{
		help[i++]=(a[p1]<a[p2]?a[p1++]:a[p2++]);
	}
	while(p1<=mid)
		help[i++]=a[p1++];
	while(p2<=right)
		help[i++]=a[p2++]; 
	while (left <= right)
    {
        a[left] = help[left]; //help����ʱ���飬��Ҫ��ֵ��ԭ�������� 
        left++;
    }
}
