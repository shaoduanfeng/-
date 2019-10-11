#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//快排
int division(vector<int> &list, int left, int right)
{
	//以左边的元素为基准
	int base = list[left];
	while (left < right)
	{
		//从右向左寻找比基准小的数
		while (left < right && list[right] >= base)
			right--;
		//找到这样的元素后交换元素
		list[left] = list[right];

		//从左向右寻找比基准大的元素
		while (left < right && list[left] <= base)
			left++;
		//找到后交换元素
		list[right] = list[left];
	}

	//复位，将base元素放在left位置
	list[left] = base;
	//返回left
	return left;

}
void quickSort(vector<int>& list, int left, int right)
{
	if (left < right)
	{
		//划分成两部分
		int base = division(list, left, right);
		//左侧
		quickSort(list,left,base - 1);
		//右侧
		quickSort(list,base + 1,right);
	}
}

//swap
void swap(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
//冒泡排序
void BubbleSort(vector<int>& list)
{
	auto len = list.size();
	for (auto i = 0; i < len; ++i)
	{
		for (auto j = 0; j < len - i - 1; ++j)
		{
			if (list[j] > list[j + 1])
				swap(list[j], list[j + 1]);
		}
	}
}
//选择排序
void SelectionSort(vector<int>& list)
{
	auto len = list.size();
	for (auto i = 0; i < len - 1; ++i)
	{
		auto min = i;
		for (auto j = i + 1; j < len; ++j)
		{
			if (list[j] < list[min])
				min = j;
		}
		if (min != i)
			swap(list[i], list[min]);
	}
}

//二分查找
int BinarySearch(vector<int>& list, int value, int low, int high)
{
	if (list.size() < 0) return -1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (list[mid] == value) return mid;
		else if (list[mid] < value) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}



int main()
{
	vector<int> v1 = { 75,6,20,18,3,43 };
	cout << "排序前：" << '\n';
	for (auto& t : v1)
	{
		cout << t << ' ';
	}
	cout << '\n' << "排序后" << '\n';
	SelectionSort(v1);
	for (auto& t : v1)
	{
		cout << t << ' ';
	}
	cout << endl;
	return 0;
}