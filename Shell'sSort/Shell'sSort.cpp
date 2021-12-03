// Shell'sSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

template<typename T>
void ShellsSort(std::vector<T>& arraySort) {
    int increment = arraySort.size();
    while (increment > 1) {
        increment = increment >> 1;
        for (int i = 0; i < increment; ++i) {
            for (int j = i + increment; j < arraySort.size(); j += increment) {
                auto temp = arraySort[j];
                int k = j - increment;
                for (; k >= 0; k -= increment) {
                    if (temp < arraySort[k]) {
                        arraySort[k + increment] = arraySort[k];
                        continue;
                    }
                    break;
                }
                arraySort[k + increment] = temp;
            }
        }
    }
}
int main()
{
    std::vector<int> temp = { 8,2,6,8,0,1,2,7,5,10,5345,1313,7676,4 };
    ShellsSort(temp);
    std::cout << "Hello World!\n";
}

