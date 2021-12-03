// BubbleSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

template<typename T>
void swap(std::vector<T>& sortArray,int i,int j) {
    auto temp = sortArray[i];
    sortArray[i] = sortArray[j];
    sortArray[j] = temp;
}

template<typename T>
void bubbleSort(std::vector<T>& sortArray) {
    int len = sortArray.size();
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (sortArray[j] > sortArray[j + 1]) {
                swap(sortArray,j, j + 1);
            }
        }
    }
}

//improve bubble sort
template<typename T>
void bubbleSortImprove(std::vector<T>& sortArray) {
    int len = sortArray.size();
    //是否做过交换
    //如果本轮一次交换都没做过，说明是已排序的,isSwap = false
    bool isSwap = true;
    for (int i = 0; i < len && isSwap; ++i) {
        isSwap = false;
        for (int j = 0; j < len - i - 1; ++j) {
            if (sortArray[j] > sortArray[j + 1]) {
                swap(sortArray, j, j + 1);
                isSwap = true;
            }
        }
    }
}

int main() {
    std::vector<int> temp = { 8,2,6,8,0,1,2,7,5,10,5345,1313,7676,4 };
    bubbleSortImprove(temp);
    std::cout << "Hello World!\n";
}
