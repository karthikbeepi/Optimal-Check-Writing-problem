// C++ implementation to count ways 
// to sum up to a given value N 
#include <bits/stdc++.h> 

using namespace std; 

// function to count the total 
// number of ways to sum up to 'N' 
int countWays(int arr[], int m, int N) 
{ 
	int count[N + 1]; 
	memset(count, 0, sizeof(count)); 
	
	// base case 
	count[0] = 1; 
	
	// count ways for all values up 
	// to 'N' and store the result 
	for (int i = 1; i <= N; i++) 
		for (int j = 0; j < m; j++) 

			// if i >= arr[j] then 
			// accumulate count for value 'i' as 
			// ways to form value 'i-arr[j]' 
			if (i >= arr[j]) 
				count[i] += count[i - arr[j]]; 
	
	// required number of ways 
	return count[N]; 
	
} 
void makeArray(int i, int arr[], int amount)
{
	int k = amount-i;
	for(int j=0; j<((2*i)+1); j++)
	{
		arr[j] = k;
		k++;
	}
}
// Driver code 
int main() 
{ 
	int i=2;
	int arr[2*i+1];
    int amount = 97;
    int periods = 3;
    makeArray(i , arr, amount); 
	int m = sizeof(arr) / sizeof(arr[0]); 
	int N = amount*periods; 
	cout << "Total number of ways = "
		<< countWays(arr, m, N)<<endl; 
	return 0; 
} 
