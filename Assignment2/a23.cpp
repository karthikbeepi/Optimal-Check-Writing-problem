#include <iostream>
#include <vector>
using namespace std;

class Combo
{
	int* arr;
	public:
	
	Combo(int ar[])
	{
		arr = ar;
	}
	
	void printCombo(int amt, int period)
	{
		for(int i=0; i<period; i++)
			cout<<arr[i]+amt<<" ";
		cout<<"\n";
	}
};

class ComboUtil
{
    public:
    vector<Combo> c; 
    void findCombo(int chosen[], int arr[], int index, int r, int start, int end)
    {
        int sum=0;
            for(int i=0; i<index; i++)
            {
                sum+=arr[chosen[i]];
                if(sum<0)
                    return;
            }
            if (index == r ) { 
                if(sum==0)
                {
                    int temp[r];
                    int len = sizeof(arr)/sizeof(int);
                    if(arr[chosen[0]]==arr[0]||arr[chosen[r-1]]==arr[len]) 
                    {
                        for (int i = 0; i < r; i++) { 
                            temp[i] = arr[chosen[i]];	
                            cout<<temp[i]<<" ";					
                        } 
                        cout<<"\n";
                        // c.push_back(dc);
                        // for(int j = 0; j<c.size(); j++)
                        // {
                        //     Combo diff = c.at(j);
                        //     diff.printCombo(5, 3);
                        // }
                        // cout<<"\n";
                    }
                }
                return; 
            } 

            for (int i = start; i <= end; i++) { 
                chosen[index] = i; 
                findCombo(chosen, arr, index + 1,r, i, end); 
            } 
            return; 
    }

    void comboRepeatition(int arr[], int length, int r)
    {
        int chosen[r+1];
        findCombo(chosen, arr, 0, r, 0, length-1);
    }
};


void makeArray(int i, int arr[])
{
	int k = i;
	for(int j=0; j<((2*i)+1); j++)
	{
		arr[j] = k;
		// cout<<k;
		k--;
	}
	// cout<<"\n";
}

void findVal(int p, int a, int b)
{
    // ComboUtil obj[b+1];
	// for(int i=0; i<=b; i++)
	// {
	// 	int arr[2*i+1];
	// 	makeArray(i, arr);
	// 	obj[i].comboRepeatition(arr, (2*i)+1, p);
	// 	for(int j = 0; j<obj[i].c.size(); j++)
	// 	{
	// 		Combo dc = obj[i].c.at(j);
	// 		dc.printCombo(a, p);
	// 	}
	// }

	int i=3;
	int arr[2*i+1];
	makeArray(i, arr);
    ComboUtil obj;
	obj.comboRepeatition(arr, (2*i)+1, p);
	for(int j = 0; j<obj.c.size(); j++)
	{
		Combo c = obj.c.at(j);
		//c.printCombo(a, p);
	}
}

int main(int argc, char * argv[])
{
	int periods, amount, balance, noOfDataSets;

	//cin>>noOfDataSets;
	noOfDataSets = 1;

	for(int i=0; i<noOfDataSets; i++)
	{
		//cin>>periods>>amount>>balance;
		periods = 3;
		amount = 5;
		balance = 2;
		findVal(periods, amount, balance);
	}
	
}