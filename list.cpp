#include <stdexcept>
#include <vector>
class MyList {
private:
	int* arr;
	int arrCapacity = 10;
	int arrSize = 0;
	int extendRatio = 2; //每次扩容比例
public:
	MyList() {
		arr = new int[arrCapacity];
	}
	~MyList() {
		delete[] arr;
	}
	int size() {
		return arrSize;
	}
	int capacity() {
		return arrCapacity;
	}
	int get(int index) {
		if (index < 0 || index >= size()) {
			throw std::out_of_range("索引越界");
		}
		return arr[index];
	}
	void set(int index, int num) {
		if (index < 0 || index >= size()) {
			throw std::out_of_range("索引越界");
		}
		arr[index] = num;
	}
	void add(int num) {
		if (size() == capacity()) extendCapacity();
		arr[size()] = num;
		arrSize++;
	}
	void insert(int index, int num) {
		if (index < 0 || index >= arrSize) {
			throw std::out_of_range("索引越界");
		}
		if (size() == capacity()) extendCapacity();
		for (int j = size() - 1; j >= index; j--) {
			arr[j + 1] = arr[j];
		}
		arr[index] = num;
		arrSize++;
	}
	int remove(int index) {
		if (index < 0 || index >= arrSize) {
			throw std::out_of_range("索引越界");
		}
		int num = arr[index];
		for (int j = index; j < size()-1; j++) arr[j] = arr[j + 1];
		arrSize--;
		return num;
	}
	void extendCapacity() {
		int newCapacity = capacity() * extendRatio;
		int* tmp = arr;
		arr = new int[newCapacity];
		for (int j = 0; j < size(); j++) arr[j] = tmp[j];
		delete[] tmp;
		arrCapacity = newCapacity;
	}
	std::vector<int> toVector() {
		std::vector<int> vec(size());
		for (int j = 0; j < size(); j++) vec[j] = arr[j];
		return vec;
	}
};