#include<stdio.h>
#include<stdlib.h>
int w[10], p[10], v[10][10];
int Max(int a,int b)
{
if(a>b) 
return a; 
else 
return b;
}
int knapsack(int n,int c)
{
int i,j;
for(i=0;i<=n;i++)
{
for(j=0;j<=c;j++)
{
if(i==0||j==0) 
v[i][j]=0;
else if(j-w[i]>=0)
v[i][j]=Max(v[i-1][j],p[i]+v[i-1][j-w[i]]);
else
v[i][j]=v[i-1][j];
}
}
return v[n][c];
}
void optimal_subset(int n,int c)
{
int i,j;
for(i=n,j=c;i>=1 && j>0;j--)
{
if(v[i][j]!=v[i-1][j])
{
printf("item %d\n",i); j=j-w[i];
}
}
}
int main( )
{
int n,c,mp,i,j;
printf("enter the number of items \n");
scanf("%d",&n);
printf("enter the weights of each item\n");
for(i=1;i<=n;i++) 
scanf("%d",&w[i]);
printf("enter the profit of each item\n"); 
for(i=1;i<=n;i++) 
scanf("%d",&p[i]);
printf("enter the knapsack capacity\n");
scanf("%d",&c); 
mp=knapsack(n,c);
printf("solution of the knapsack \n");
for(i=0;i<=n;i++)
{
for(j=0;j<=c;j++) 
printf("%d\t",v[i][j]); 
printf("\n");
}
printf("the maximal value is %d \n",mp); 
printf("the items of optimal subset are\n"); 
optimal_subset(n,c);
return 0;
}
