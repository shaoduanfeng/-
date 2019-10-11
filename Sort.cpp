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
