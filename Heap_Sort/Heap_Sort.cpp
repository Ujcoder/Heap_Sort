using namespace std;
#include<iostream>

void HeapSort(int num[], int ub); // not require to predecleration 
void ShiftDown(int num[], int root, int bottom);

void HeapSort(int num[], int ub)
{
	int i, temp;
	for (i = (int)ceil((ub / 2.0)) - 1; i >= 0; i--)
		ShiftDown(num, i, ub);
	for (i = ub; i >= 1; i--)
	{
		temp = num[0];
		num[0] = num[i];
		num[i] = temp;
		ShiftDown(num, 0, i - 1);
	}
}

void ShiftDown(int num[], int root, int bottom)
{
	int done,temp, MaxChild;
	done = 0;
	while ((root * 2 + 1 <= bottom) && (!done))
	{
		if (root * 2 + 1 == bottom || num[root * 2 + 1] > num[root * 2 + 2])
			MaxChild = root * 2 + 1;
		else
			MaxChild = root * 2 + 2;
		if (num[root] < num[MaxChild])
		{
			temp = num[root];
			num[root] = num[MaxChild];
			num[MaxChild] = temp;
			root = MaxChild;
		}
		else
			done = 1;
	}
}

int main()
{
	int i,n,num[20];
	cout << "Enter Size of Array :  "; cin >> n;
	cout << "Enter Element in Array  :" << endl;
	for (i = 0; i < n; i++)
		cin >> num[i];
	cout << "After Sorting Elem : " << endl;
	HeapSort(num, n - 1);
	for (i = 0; i < n; i++)
		cout << num[i] << endl;
	return 0;
}