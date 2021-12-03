// SimpleSelectionSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
template<typename T>
void swap(std::vector<T>& sortArray, int i, int j) {
    auto temp = sortArray[i];
    sortArray[i] = sortArray[j];
    sortArray[j] = temp;
}

template<typename T>
void sampleSelectionSort(std::vector<T>& arraySort) {
    int len = arraySort.size();
    for (int i = 0; i < len; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (arraySort[min] > arraySort[j]) min = j;
        }
        if (min != i) swap(arraySort, min, i);
    }
}

int main()
{
    std::vector<int> temp = { 8,2,6,8,0,1,2,7,5,10,5345,1313,7676,4 };
    sampleSelectionSort(temp);
    std::cout << "Hello World!\n";
}

