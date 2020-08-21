int fun(string a, string b, int m , int n)
{
	if(m==0|| n==0)
		return 0;
	if(a[m-1]==b[n-1])
		return fun(a, b, m-1, n-1)+1;
	else 
		return max(fun(a, b, m-1, n), fun(a, b, m, n-1));
}


int coinchange(int coins, int n , int sum)
{
	if(n==0)
		return (sum==0);
	if(sum==0)
		return 1;
	int res = coinchange(coins, n-1, sum);
	if(sum>= coins[n-1])
		res += coinchange(coins, n, sum-coins[n-1]);
	return res;
}

int coinchangedp(int coins, int n, int sum)
{
	int dp[sum+1][n+1];
	for(int i=0;i<=sum;i++)
		dp[i][0]=0;
	for(int i=0;i<=n;i++)
		dp[0][i]=1;
	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i][j-1];
			if(i>=coins[j-1])
				dp[i][j]+=dp[i-coins[j-1]][j];
		}
	}
	return dp[sum][n];
}

int actualres = 1;
int lis(int arr[], int n)
{
	 if(n==0)
	 	return 1;
	 int res = INT_MIN;
	 for(int i=v;i<n;i++)
	 {
	 	if(arr[i]<arr[n])
	 		res = max(lis(arr, i), res);
	 }
	 if(actualres<res)
	 	actualres = res;
	 return actualres;
}


int lisOn(int arr[], int n)
{
	int tail[n];
	int len =1;
	tail[0]=0;
	for(int i=1;i<n;i++)
	{
		if(tail[len-1]<arr[i])
		{
			tail[len]=arr[i];
			len++;
		}
		else
		{
			int ceil = c(tail, len-1, arr[i]);
			tail[ceil] = arr[i];
		}
	}
	return len;
}


int optimalstrategy(int arr[], int i, int j)
{
	if(i+1==j)
		return max(arr[i],arr[j]);

	return max(arr[i]+min(optimalstrategy(arr,i+2,j), optimalstrategy(arr,i+1, j-1)),

				arr[j]+min(optimalstrategy(arr, i, j-2), optimalstrategy(arr, i+1, j-1)));
}


int eggdrop(int f, int e)
{
	if(f==0 || f==1)
		return f;
	if(e==1)
		return f;

	int res = INT_MAX;
	int x; 
	for(x=1;x<=f;x++)
	{
		res = min(res, max(eggdrop(f-1, e-1), eggdrop(f-x, e))+1);
	}
	return res;

}


int maxnoconsecutive(int arr, int n)
{
	if(n==1)
		return arr[n-1];
	if(n==2)
		return max(arr[n-1], arr[n-2]);
	return max(maxnoconsecutive(arr,n-1), arr[n-1]+maxnoconsecutive(arr ,n-2));
}

