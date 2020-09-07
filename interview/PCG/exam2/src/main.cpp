#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int* a, int left, int right)
{
	int key = left;
	while (left < right)
	{
		while (left < right && a[key] <= a[right])
		{
			right--;
		}	
		while (left < right && a[key] >= a[left])
		{
			left++;
		}	
		swap(a[left],a[right]);
	}
	swap(a[key],a[left]);
	return left;
}

void quickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int key = partition(a,left,right);
	quickSort(a,left,key - 1);
	quickSort(a,key + 1,right);
}

void print_a(int* a, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

string addString(string s1, string s2)
{
	if (s1.empty() || s2.empty())
		return s1.empty() ? s2 : s1;
	int ind1 = s1.length() - 1, ind2 = s2.length() - 1;
	int add = 0;
	string res;
	while (ind1 >= 0 || ind2 >= 0 || add)
	{
		int sum = add;
		if (ind1 >= 0)
		{
			sum += s1[ind1--] - '0';
		}
		if (ind2 >= 0)
		{
			sum += s2[ind2--] - '0';
		}
		add = sum / 10;
		res.push_back(sum % 10 + '0');
	}
	return string(res.rbegin(),res.rend());
}

int main()
{
	// int a[10] = {3,5,4,2,6,7,3,9,10,1};
	// print_a(a,10);
	// quickSort(a,0,9);
	// print_a(a,10);

	printf("%s\n",addString("123","456").c_str());
	printf("%s\n",addString("123","458").c_str());
	printf("%s\n",addString("999","1").c_str());
	printf("%s\n",addString("999","0").c_str());
	printf("%s\n",addString("999","999").c_str());
	printf("%s\n",addString("10000000000000000","10000000000000000").c_str());
	printf("%s\n",addString("0","0").c_str());
}