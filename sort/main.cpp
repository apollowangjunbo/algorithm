#include <iostream>
#include <cstdlib>
#include <vector>

#include <chrono>
#include <thread>
#include <algorithm>


using namespace std::chrono;
const int count = 100000;
const bool printnum = false;
std::vector<int> nums()
{
	std::vector<int> result;
	for (int i = 0; i < count; i++)
	{
		result.emplace_back( std::rand());
	}
	return result;
}

void printNums(const std::vector<int>& nums)
{
	if (printnum)
	{
		for (auto i : nums)
		{
			std::cout << i << std::endl;
		}
	}

}

void  BubbleSort(std::vector<int>& nums)
{
	//冒泡
	for (auto size = nums.size() - 1; size > 0; size--)
	{
		for (auto i = 0ul; i < size; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				std::swap(nums[i], nums[i + 1]);
			}
		}
	}
	//1w debug 6.1s release 0.168
	//1k debug 0.072 release 0.002
	//结论O(N^2)
	//推测N(logN)
	//1w debug 0.0081 release 0.00022
	//1k debug 0.00007 release 0.00002
}

void quicksort(std::vector<int>& nums,int begin,int end)
{
	if (end <= begin)
		return;
	int target = nums[begin];
	int i = begin;
	int j = end;
	while (j > i) {
		while (nums[j] >= target && j > i)
		{
			j--;
		}
		while (nums[i] <= target && j > i)
		{
			i++;
		}
		if (i < j)
		{
			std::swap(nums[i], nums[j]);
		}
	}
	nums[begin] = nums[i];
	nums[i] = target;
	quicksort(nums, begin, i-1);
	quicksort(nums, i+1, end);
	//10w debug 0.16 release 0.011
	//1w debug 0.0136 release 0.001278
	//1k debug 0.00146 release 0.000212
	//结论：N*Log(N,2)
}

void quicksort1(int left,int right,std::vector<int>& nums)
{
	if (left >= right)
		return;
	int target = nums[left];
	int i = left, j = right;
	while (j>i)
	{
		while (j > i && nums[j] >= target)
		{
			j--;
		}
		while (j > i && nums[i] <= target)//此处必须有等号！20201116
		{
			i++;
		}
		if (j > i)
		{
			std::swap(nums[i], nums[j]);
		}
	}
	nums[left] = nums[i];
	nums[i] = target;
	quicksort1(left,i-1, nums);
	quicksort1(i+1, right, nums);
}


void merge(std::vector<int>& nums, int L,int mid,int R)
{
	std::vector<int> help;
	help.resize(R-L+1);//help.resize(nums.size());太长了，浪费，R-L+1就够用
	int helpIndex = 0;
	int index1 = L, index2 = mid + 1;
	while (index1 <= mid && index2 <= R)
	{
		help[helpIndex++] = nums[index1] < nums[index2] ? nums[index1++] : nums[index2++];
	}
	while (index1 <= mid)
	{
		help[helpIndex++] =  nums[index1++] ;
	}
	while (index2 <= R)
	{
		help[helpIndex++] = nums[index2++];
	}
	for (int i = 0; i < help.size(); i++)
	{
		nums[L+i] = help[i];
	}
}
void mergeSort(std::vector<int>& nums,int L,int R)
{//非递归版本
	if (L == R)
		return;
	int mid = (L + R) / 2;
	mergeSort(nums,L, mid);
	mergeSort(nums, mid+1, R);
	merge(nums,L,mid,R);
	//10w debug 0.578 release 0.035
	//1w debug 0.06386 release 0.00269

	//结论：N*Log(N,2),实验中没有快排速度快
}

void selectSort(std::vector<int>& nums)
{
	if (nums.size() < 2)
		return;
	int minj;
	for (auto i = 0; i < nums.size() - 1; i++)
	{
		minj = i;
		for (auto j = i + 1; j < nums.size(); j++)
		{
			minj = nums[j] < nums[minj] ? j : minj;
		}
		std::swap(nums[i], nums[minj]);
	}
	//1w debug 3.75s release 0.133
	//1k debug 0.04 release 0.00153
}//选择排序

void insertSort(std::vector<int>& nums)
{
	if (nums.size() < 2)
		return;
	for (auto i = 1; i < nums.size() ; i++)
	{
		for (auto j = i-1; j >=0&&nums[j]>nums[j+1]; j--)//j >=0
		{
			std::swap(nums[j], nums[j+1]);
		}
	}
	//1w debug 4.9s release 0.037
	//1k debug 0.058 release 0.00153
}//插入排序:优点，数据本身有序的时候可以O(N)直接结束

void heapInsert(std::vector<int>& nums,int index)
{
	while (nums[index] > nums[(index - 1) / 2])
	{
		std::swap(nums[index], nums[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
	return;
}
void heapify(std::vector<int>& nums, int index)
{
	int top = 0;
	std::swap(nums[0], nums[index]);
	int left = top * 2 + 1;
	while (left<index)
	{//有子节点
		int largest = left + 1 < index && nums[left + 1] > nums[left] ?
			left + 1 : left;
		largest = nums[largest] > nums[top]?largest:top;
		if (largest == top)
		{
			return;
		}
		std::swap(nums[top],nums[largest]);
		top = largest;
		left = top * 2 + 1;
	}
}
void heapSort(std::vector<int>& nums)
{
	if (nums.size() < 2)
		return;
	//建立大根堆
	for (int i = 0; i < nums.size(); i++)
	{
		heapInsert(nums, i);
	}
	for (int i = nums.size()-1; i >0; i--)
	{
		heapify(nums,i);
	}
	//10w debug 0.47 release 0.02
}
std::string isOrdered(const std::vector<int>& nums)
{
	for (int i = 0; i < nums.size()-1; i++)
	{
		if (nums[i] > nums[i + 1])
			return "错误";
	}
	return "正确";
}

void sort(std::vector<int>&& nums)
{
	printNums(nums);
	std::cout << "=====================" << std::endl;
	auto _start = high_resolution_clock::now();
	//std::this_thread::sleep_for(seconds(1));
	//quicksort(nums，0, nums.size() - 1);

	//quicksort1(0, nums.size() - 1,nums);
	//mergeSort(nums);
	//selectSort(nums);
	//insertSort(nums);
	//BubbleSort(nums);
	heapSort(nums);
	//mergeSort(nums,0, nums.size() - 1);
	std::cout << "=====================" << std::endl;
	auto time = duration_cast<microseconds>(high_resolution_clock::now() - _start).count()/1000000.0;
	std::cout << time << std::endl;
	std::cout << "排序" << isOrdered(nums) << std::endl;
	printNums(nums);
}

int main()
{
	auto num = nums();
	//num = { 1,2,3,4,5,6,7,8,9,10 };
	sort(std::move(num));
#if 0
	std::vector<int> a = {10,9,8,7,5,3,2,1};
	merge_sort(a);
	for (int i = 0; i < 8; i++)
	{
		std::cout << a[i] << std::endl;
	}
#endif // 0
	std::cin.get();
	return 0;
}