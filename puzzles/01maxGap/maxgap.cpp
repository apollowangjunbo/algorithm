#include <iostream>
#include <vector>
#include <algorithm>

/*给定一个数组，求如果排序之后，相邻两数的最大差值，要求时间复杂度O(N)，
且要求不能用非基于比较的排序（不能用桶排序）*/
using namespace std;
#include <cstdlib>
const int nCcount = 10;
std::vector<int> nums()
{
	std::vector<int> result;
	for (int i = 0; i < nCcount; i++)
	{
		result.emplace_back(std::rand());
	}
	return result;
}

using namespace std;

int maxgap(vector<int>& nums)
{
	if (nums.size()<2)
	{
		return 0;
	}
	//最大值最小值
	int max = INT32_MIN;//别写反
	int min = INT32_MAX;
	for (auto num : nums)
	{
		if (num>max)max = num;
		if (num <min)min = num;
	}
	if (max<=min)
		return 0;
	//分N+1个桶 开闭->[] (](](]
	double bucketSize = ((double)max - (double)min) / (nums.size() + 1);
	std::vector<std::pair<int, int>> buckets = { nums.size() + 1,{ INT32_MAX ,INT32_MIN} };
	//怎么设置初值呢？设置个bool量更合适吧,左神的做法
//	std::vector<int> mins(nums.size() + 1 ,0);
//	std::vector<int> maxs(nums.size() + 1, 0);
//	std::vector<bool> hasValue(nums.size() + 1, false);
	//分到桶里
	for (auto num : nums)
	{//不进行比较直接扔到对应的桶里面

		int bucketNum = std::ceil((double)(num - min) / bucketSize)-1;
		auto& pair = buckets[std::max(0,bucketNum)];
		if (num > pair.second)pair.second = num;
		if (num < pair.first)pair.first = num;
	}
	//遍历各个桶之间的差值得出结果
	int  result = 0;
	//怎么找出所有非空桶？
	int index = 1;
	int lastmax = buckets[0].second;
	while (index< buckets.size())
	{
		if (buckets[index].second>= buckets[index].first)
		{
			result = std::max(result, buckets[index].first - lastmax);
			lastmax = buckets[index].second;
		}
		index++;
	}
	return result;
}


int main()
{
	vector<int> vec = { 1,2,3,4,8,9,10,9,0 };//nums();
	int answer = maxgap(vec);
	cout << "maxGap:" << answer << endl;

	cin.get();
	return 0;
}

//对数器
int maxgap_slow(vector<int>& nums)
{
	auto nums_copy = nums;
	std::sort(nums_copy.begin(), nums_copy.end());
	int result = 0;
	for (int i = 0; i < nums_copy.size() - 1; i++)
	{
		int diff = nums_copy[i + 1] - nums_copy[i];
		if (diff>result)
		{
			result = diff;
		}
	}
	return result;
}

