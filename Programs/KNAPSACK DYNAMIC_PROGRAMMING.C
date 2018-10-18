#include<stdio.h>
#include<conio.h>
int tab[10][10];
void item(int n, int wt[],int u);
int knap(int wt[],int va[],int n,int u)
{
	int i,j,s[10];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=u;j++)
		{
			if(i==0||j==0)
			{
				tab[i][j]=0;
			}
			else if(j<wt[i-1])
			{
				tab[i][j]=tab[i-1][j];
			}
			else
			{
				tab[i][j]=max(tab[i-1][j],va[i-1]+tab[i-1][j-wt[i-1]]);
			}
		}
	}
	printf("\n Table \n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=u;j++)
		{
			printf("%d\t",tab[i][j]);
		}
		printf("\n");
	}
	return tab[n][u];
}
void item(int n, int wt[],int u)
{
	int i=n,j=u,s;
	while(i>0)
	{
		if(i==0||j==0)
		return ;
		if(tab[i][j]==tab[i-1][j])
		{
			i--;
		}
		else
		{
			s=i;
			printf("\n Item Number %d is Selected",s);
			i--;
			j=j-wt[i];
		}
	}
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{
	int i,n,wt[10],va[10],u,ans;
	clrscr();
	printf("Enter value of n:");
	scanf("%d",&n);
	printf("Enter total Weight of Knapsack:");
	scanf("%d",&u);
	printf("Enter Weight of Item's \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("Enter values of Item's \n");
	for(i=0;i<n;i++)
	{
	scanf("%d",&va[i]);
	}
	ans=knap(wt,va,n,u);
	printf("Max value of knapsack is %d",ans);
	item(n,wt,u);
	getch();
	return 0;
}