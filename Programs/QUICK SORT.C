#include<stdio.h>
#include<conio.h>
void quicksort(int arr[],int i,int j)
{
	int left,right,pivot,temp;
	if(i<j)
	{
		left=i;
		right=j;
		pivot=j;
	while(left<right)
	{
		while(left<right && arr[left]<=arr[pivot])
		{
			left++;
		}
		while(arr[right]>=arr[pivot])
		{
			right--;
		}
		if(left<right)
		{
			temp=arr[left];
			arr[left]=arr[right];
			arr[right]=temp;
		}
	}
		if(left>right)
		{
			temp=arr[pivot];
			arr[pivot]=arr[left];
			arr[left]=temp;
		}
		quicksort(arr,i,left-1);
		quicksort(arr,left+1,j);
	}
}
void main()
{
	int i,arr[10],n;
	clrscr();
	printf("Enter value of n:");
	scanf("%d",&n);
	printf("Enter value in array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n-1);
	printf("After Sorting:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	getch();
}                                                  