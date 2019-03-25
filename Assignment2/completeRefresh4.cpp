//https://www.geeksforgeeks.org/program-to-convert-a-given-number-to-words-set-2/ for counting the words
//https://www.geeksforgeeks.org/subset-sum-problem-dp-25/ for subset problem 
//https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/ for subset problem

#include <iostream>
#include<vector>
#include<fstream>
#include<string.h>
using namespace std; 


int minimumFound = INT16_MAX;
int array[1001];
char * fileToRead;
int allSizes[10001];

//function declaration
void comboRepeatition(int [], int [], 
					int , int r, int , int , int , int &, int, int ) ;

//to convert the number to number of characters
int convertToWords(int v)
{
    return allSizes[v];
}

//calling function
int findCount(int ar[], int len, int a)
{
	int sum =0;
	for(int i=0; i<len; i++)
	{
		int s = convertToWords(ar[i]+a);
	//	cout<<s;
		sum += s;
	}
	return sum;
}

//find the combinations
void comboRepetition(int arr[], int n, int r, int a, int &lowestCount, int b) 
{ 
	int choose[r+1]; 
	//cout<<n<<" "<<b<<endl;
	if(n!=(2*b)+1)
		return;
	comboRepeatition(choose, arr, 0, r, 0, n-1, a, lowestCount, b, 0); 
} 

//get the number values from file cost.txt
void getCountOfValues()
{
	ifstream fout;
    fout.open(fileToRead);
    int temp1, temp2;
    for(int i=0; i<=10000; i++)
    {
        fout>>temp1>>temp2;
		allSizes[temp1]=temp2;
    }
}

//print the array found to be optimum
void printArray(int temp[], int period, int amount)
{
	//cout<<amount<<","<<period<<":";
	for(int i=0; i<period; i++)
		cout<<temp[i]+amount<<" ";
	cout<<endl;
}

//copy the array
void copyArray(int temp[], int r)
{
	for(int i=0; i<r; i++)
		array[i] = temp[i];
}

//find all the different combinations
void comboRepeatition(int choose[], int arr[], 
					int ind, int r, int start, int end, int a, int &lowestCost, int b, int sum) 
{ 

    sum+=arr[choose[ind-1]];
    //to check if the balance is not going to negative at all times
    if(sum<0)
        return;
	//to check if the balance is not going overboard everytime
	else if(sum>b)
		return;
	if (ind == r) 
	{ 
		if(sum==0)
		{
			int len = 2*(sizeof(arr)/sizeof(int));
			{
				int temp1[r];
				for (int i = 0; i < r; i++) 
				{
					temp1[i]=arr[choose[i]];
				}
				int cCount = findCount(temp1, r, a);
				if(lowestCost>cCount)
				{
					lowestCost = cCount;
					//printArray(temp1, r, a);
					if(minimumFound>lowestCost)
					{
						minimumFound = lowestCost;
						copyArray(temp1, r);
					}
					//cout<<cCount<<endl;
				}
			}
		}
		return; 
	} 

	for (int i = start; i <= end; i++) 
	{ 
		choose[ind] = i; 
		comboRepeatition(choose, arr, ind + 1, 
											r, i, end, a, lowestCost, b, sum); 
	} 
	return; 
} 

void makeArray(int i, int arr[])
{
	int k = i;
	for(int j=0; j<((2*i)+1); j++)
	{
		arr[j] = k;
		k--;
	}
}

void iArray(int p)
{
	for(int i=0; i<p;i++)
		array[i] = 0;
	minimumFound = INT16_MAX;
}

int findVal(int periods, int amount, int balance)
{ 
	int cost[balance+1];
	iArray(periods);
	for(int i=0; i<=balance; i++)
	{
		int arr[2*i+1];
		makeArray(i, arr);
		int n = sizeof(arr)/sizeof(arr[0]);  
		cost[i] = INT16_MAX;
		comboRepetition(arr, n, periods, amount, cost[i], balance); 
		if(i>0)
			if(cost[i-1]<cost[i])
				{
					cost[i] = cost[i-1];	
				}
	}

	// int i=balance;
	// int arr[2*i+1];
	// makeArray(i, arr);
	// int n = sizeof(arr)/sizeof(arr[0]);  
	// cost[i] = INT16_MAX;
	// comboRepetition(arr, n, periods, amount, cost[i], balance); 
	printArray(array, periods, amount);
	return cost[balance];
	
} 

int main(int argc, char* argv[])
{
	int periods, amount, balance, noOfDataSets;
	
    ifstream fin;
    ofstream fout;

    if(argc!=4)
    {
        cout<<"Error";
        return -1;
    }

	fin.open(argv[1]);
	fout.open(argv[2]);
    fileToRead = argv[3];
	fin>>noOfDataSets;
	getCountOfValues();
	// noOfDataSets = 1;

	for(int i=0; i<noOfDataSets; i++)
	{
		fin>>periods>>amount>>balance;
		// periods = 3;
		// amount = 97;
		// balance = 6;
		fout<<findVal(periods, amount, balance);
		if(i!=noOfDataSets-1)
			fout<<"\n";
	}
	
	
}