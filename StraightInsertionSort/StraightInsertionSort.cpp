// StraightInsertionSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

template<typename T>
void StraightInsertionSort(std::vector<T>& arraySort) {
    int len = arraySort.size();
    for (int i = 1; i < len; ++i) {
        auto temp = arraySort[i];
        int j = i - 1;
        for (; j >= 0; --j) {
            if (temp < arraySort[j]) {
                arraySort[j + 1] = arraySort[j];
                continue;
            }
            break;
        }
        arraySort[j + 1] = temp;
    }
}

int main()
{
    std::vector<int> temp = { 8,2,6,8,0,1,2,7,5,10,5345,1313,7676,4 };
    StraightInsertionSort(temp);
    std::cout << "Hello World!\n";
}