#include "sort.cpp"
#include <iostream>

int main() {
	vector<int> nums{ 3,4,5,9,20,54,77,0,12, };
	insertionSort(nums);
	for (int i = 0; i < nums.size();i++ ){
		cout << nums[i] << " ";
	}
	return 0;
}