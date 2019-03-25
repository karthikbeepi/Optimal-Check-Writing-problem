//https://www.geeksforgeeks.org/program-to-convert-a-given-number-to-words-set-2/ for counting the words
//https://www.geeksforgeeks.org/subset-sum-problem-dp-25/ for subset problem 
//https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/ for subset problem

#include <iostream>
#include<vector>
#include<fstream>
#include<string.h>
using namespace std; 

/* arr[] ---> Input Array 
choose[] ---> Temporary array to store indices of 
				current combination 
start & end ---> Staring and Ending indes in arr[] 
r ---> Size of a combination to be printed */

string one[] = { "", "one", "two", "three", "four", 
				"five", "six", "seven", "eight", 
				"nine", "ten", "eleven", "twelve", 
				"thirteen", "fourteen", "fifteen", 
				"sixteen", "seventeen", "eighteen", 
				"nineteen"
			}; 

// strings at ind 0 and 1 are not used, they is to 
// make array inding simple 
string ten[] = { "", "", "twenty", "thirty", "forty", 
				"fifty", "sixty", "seventy", "eighty", 
				"ninety"
			}; 
int minimumFound = INT16_MAX;
int array[1001];
// n is 1- or 2-digit number 
string numToWords(int n, string s) 
{ 
	string str = ""; 
	// if n is more than 19, divide it 
	if(n==0)
		return str;
	if (n > 19) 
		str += ten[n / 10] + one[n % 10]; 
	else
		str += one[n]; 

	// if n is non-zero 
	if (n) 
		str += s; 

	return str; 
} 

void comboRepeatition(int [], int [], 
					int , int r, int , int , int , int &, int ) ;

// Function to print a given number in words 
string convertToWords(long n) 
{ 
	// stores word representation of given number n 
	string out; 

	// handles digits at ten millions and hundred 
	// millions places (if any) 
	out += numToWords((n / 10000000), "crore"); 

	// handles digits at hundred thousands and one 
	// millions places (if any) 
	out += numToWords(((n / 100000) % 100), "lakh"); 

	// handles digits at thousands and tens thousands 
	// places (if any) 
	out += numToWords(((n / 1000) % 100), "thousand"); 

	// handles digit at hundreds places (if any) 
	out += numToWords(((n / 100) % 10), "hundred"); 

	// if (n > 100 && n % 100) 
	// 	out += "and "; 

	// handles digits at ones and tens places (if any) 
	out += numToWords((n % 100), ""); 

	return out; 
} 

void comboRepetition(int arr[], int n, int r, int a, int &lowestCount, int b) 
{ 
	int choose[r+1]; 
	//cout<<n<<" "<<b<<endl;
	if(n!=(2*b)+1)
		return;
	comboRepeatition(choose, arr, 0, r, 0, n-1, a, lowestCount, b); 
} 

int findCount(int ar[], int len, int a)
{
	int sum =0;
	for(int i=0; i<len; i++)
	{
		string s = convertToWords(ar[i]+a);
	//	cout<<s;
		sum += s.length();
	}
	return sum;
}

void printArray(int temp[], int period, int amount)
{
	//cout<<amount<<","<<period<<":";
	for(int i=0; i<period; i++)
		cout<<temp[i]+amount<<" ";
	cout<<endl;
}

void copyArray(int temp[], int r)
{
	for(int i=0; i<r; i++)
		array[i] = temp[i];
}

void comboRepeatition(int choose[], int arr[], 
					int ind, int r, int start, int end, int a, int &lowestCost, int b) 
{ 
	int sum=0;
    for(int i=0; i<ind; i++)
    {
        sum+=arr[choose[i]];
        if(sum<0)
            return;
		else if(sum>b)
			return;
    }
	if (ind == r) 
	{ 
		if(sum==0)
		{
			int len = 2*(sizeof(arr)/sizeof(int));
			//To delete
			// if(choose[0]==0||choose[r-1]==len)
			{
				//for(int i=1; i<r-1; i++)
				// 	if(choose[i]==0||choose[i]==len)
				// 		return ;
				//Remember
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

	// One by one choose all elements (without considering 
	// the fact whether element is already choose or not) 
	// and recur 
	for (int i = start; i <= end; i++) 
	{ 
		choose[ind] = i; 
		comboRepeatition(choose, arr, ind + 1, 
											r, i, end, a, lowestCost, b); 
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
	fin>>noOfDataSets;
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