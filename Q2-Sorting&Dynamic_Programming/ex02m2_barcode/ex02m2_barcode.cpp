#include<stdio.h>
int i,j,k,n,c,m,dp[33][33][33];
int r(int n,int k,int s){
	if(k<0||m<s)return 0;
    if(n==1)if(k)return 0;
            else return 1;
    return r(n-1,k-1,1)+r(n-1,k,s+1);}
main(){
	scanf("%d%d%d",&n,&m,&c);

	for(i=1;i<=m;i++)dp[1][0][i]=1;

	for(i=2;i<=n;i++)
	for(j=0;j<=c;j++)
	for(k=1;k<=m;k++)
	dp[i][j][k]=dp[i-1][j-1][1]+dp[i-1][j][k+1];

	printf("%d",dp[n][c][1]);
}

/*
(n-1,k-1,1) + (n-1,k,s+1)

               521
         411              422
      301   312       311      323
          201 213   201 212
          102       102 102


*/

