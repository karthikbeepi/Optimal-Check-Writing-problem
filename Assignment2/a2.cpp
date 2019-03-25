#include <iostream>
#include <vector>
using namespace std;

// Function to print the contents of the vector
void printVector(vector<int> const &out)
{
	for (auto it = out.begin(); it != out.end(); it++)
		cout << *it << " ";
	cout << '\n';
}

// Function to print all distinct combinations of length k where
// repetition of elements is allowed
void recurse(int arr[], vector<int> &out, int k, int i, int n)
{
	// int sum=0;
    // for (auto it = out.begin(); it != out.end(); it++)
	// 	    {
    //             if(sum<0)
    //                 return;
    //             else
    //             {
    //                 sum+=*it ;
    //             }
    //         }
    
    
    // base case: if combination size is k, print it
	
    
    if (out.size() == k)
	{
		printVector(out);
		return;
	}
    

	// start from previous element in the current combination
	// till last element
	for (int j = i; j < n; j++)
	{
		// add current element arr[j] to the solution and recurse with
		// same index j (as repeated elements are allowed in combinations)
		out.push_back(arr[j]);
		recurse(arr, out, k, j, n);
		// backtrack - remove current element from solution
		out.pop_back();
	}
}

// main function
int main()
{
	int arr[] = { 2, 1, 0, -1, -2 };
	int k = 3;

	int n = sizeof(arr) / sizeof(arr[0]);

	vector<int> out;
	recurse(arr, out, k, 0, n);

	return 0;
}