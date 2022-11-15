#include <stdio.h>
#include <math.h>
#include <limits.h>
//取得最大位数 
int getdigit(int a[],int length)
{
	int i,max=INT_MIN,digit=0;
	for(i=0;i<length;i++)
	{
		max=(a[i]>max?a[i]:max);
	}
	while(max>0)
	{
		max/=10;
		digit++;
	}
	return digit;
}
//取得当前比较位 
int getd(int a,int d)
{
	return a/(int)pow(10,d-1)%10; //重点 
}
//基数排序入口 
void radixsort(int a[],int length,int digit)
{
	int *help=(int*)malloc(length*sizeof(int));
	int i,j,d;
	for(d=1;d<=digit;d++) //从个位开始比较 
	{
		int *count=(int*)malloc(10*sizeof(int));
		for(i=0;i<10;i++)
		{
			count[i]=0;
		}
		for(i=0;i<length;i++)
		{
			j=getd(a[i],d); //统计计数数组 
			count[j]++;
		}
		for(j=1;j<10;j++)
		{
			count[j]=count[j]+count[j-1]; //计数数组转换为前缀和 
		}
		//从右往左遍历每次放在对应前缀和的右边界<==>桶排序从左往右遍历时先入桶的放在左边界先出桶
		for(i=length-1;i>=0;i--)  
		{
			j=getd(a[i],d);
			help[count[j]-1]=a[i]; //放在对应前缀和的右边界
			count[j]--; //右边界缩减一位 
		}
		for(i=0;i<length;i++)
		{
			a[i]=help[i]; //赋值回原数组 
		}
	}
}
int main()
{
	int i,a[]={5,12,3,11};
	int length=sizeof(a)/sizeof(a[0]);
	radixsort(a,length,getdigit(a,length));
	//检验
	for(i=0;i<length;i++)
	printf("%5d",a[i]); 
	return 0;
}
