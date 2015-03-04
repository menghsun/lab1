#include <iostream>
#include <stack>
using namespace std;

const long long int maxN = 2000000;
long long int cl_table[maxN];
stack <long long int> stk;

long long int cycle_length(long long int n)
{
//	long long int count = 1;
	long long int index, cl_len, x;
//	cout << x << endl;

	if (cl_table[n] !=0) 
	{
		return cl_table[n];
	}

	x = n ;

	while (x != 1)
	{
		if(x%2 == 1) 
		{
			if ((3 * x + 1< maxN) && (cl_table[3*x + 1] != 0))
			{
				cl_table[x] = cl_table[3*x+1] +1;
				cl_len = cl_table[x] + 1;
				while(!stk.empty())
				{
					index = stk.top();
					stk.pop();
					if(index<maxN)
						cl_table[index] = cl_len++;
					else
						cl_len++;
				}
				break;
			}
			else
			{
				stk.push(x);
				x = 3 * x + 1;
			}
		}
		else 
		{
			if ((x<maxN) && (cl_table[x/2] != 0))
			{
				cl_table[x] = cl_table[x/2] +1;
				cl_len = cl_table[x] + 1;
				while(!stk.empty())
				{
					index = stk.top();
					stk.pop();
					if(index<maxN)
						cl_table[index] = cl_len++;
					else
						cl_len++;
				}
				break;
			}
			else
			{
				stk.push(x);
				x = x / 2;
			}
		}
//		cout << x << ' '  ; // debug
//		count++;	
	}
//	cout << endl;
//	return count ;
//	return cl_table[n];
	return --cl_len;

}

int main()
{
	long long int i, j;
	long long int lower_bound, upper_bound;

	long long int length=1;
	for(long long int x = 1; x < maxN; x *=2)
		cl_table[x] = length++;
	
	while (cin >> i >> j)
	{
		if (i > j)
		{
			upper_bound = i;
			lower_bound = j;
		}
		else
		{
			upper_bound = j;
			lower_bound = i;
		}

		long long int largest_cycle_length = 0;

		for(long long int index = lower_bound; index <= upper_bound; index++)
		{
			long long int tmp;
			if ((tmp = cycle_length(index)) > largest_cycle_length)
				largest_cycle_length = tmp;
		}
		cout << i << ' ' << j << ' ' << largest_cycle_length << endl;
	}

}
