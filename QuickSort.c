#include <stdio.h>
void swap(int a[],int i,int j)
{
	int k=a[i];
	a[i]=a[j];
	a[j]=k;
}
void quicksort(int a[],int left,int right)
{
	if(left>=right) //i-1����Խ�磬����Ϊ>=���� 
	return;
	int target=a[right]; //ÿ��ѡ����Ԫ����Ŀ��ֵ
	//����ָ�� 
	int i=left;
	int j=left;
	int k=right-1; //����Ԫ���Ȳ����� 
	while(i<=k)
	{
		if(a[i]==target)
	    {
	    	i++;
	    }
		else if(a[i]<target)
		{
	    	swap(a,i++,j++);
	    }
	    else if(a[i]>target)
	    {
	   		swap(a,i,k--);
	   	}
    }
	swap(a,i,right); //�˳�ѭ����i�ض�Ϊ(k+1)��������һ��Ԫ����Ŀ��ֵ���� 
	//�ݹ���� 
	quicksort(a,left,i-1);
	quicksort(a,i,right);
}
int main()
{
	int i,a[]={};
	int length=sizeof(a)/sizeof(a[0]);
	quicksort(a,0,length-1);
	//���� 
	for(i=0;i<length;i++)
	printf("%-3d",a[i]);
	return 0;
}
