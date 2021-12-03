// MergeSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

template<typename T>
void merge(std::vector<T>& arraySort, int left, int mid, int right) {
    std::vector<T> arrTemp;

    auto leftTemp = left,rightTemp = mid + 1;
    while (leftTemp <= mid && rightTemp <= right) {
        if (arraySort[leftTemp] <= arraySort[rightTemp]) arrTemp.push_back(arraySort[leftTemp++]);
        else arrTemp.push_back(arraySort[rightTemp++]);
    }

    if (leftTemp <= mid) 
        arrTemp.insert(arrTemp.end(), arraySort.begin() + leftTemp, arraySort.begin() + mid + 1);
    if (rightTemp <= right) 
        arrTemp.insert(arrTemp.end(), arraySort.begin() + rightTemp, arraySort.begin() + right);

    for (auto&& it : arrTemp) {
        arraySort[left++] = it;
    }
}

template<typename T>
void mergeSort(std::vector<T>& arraySort,int left,int right) {
    if (left < right) {
        auto mid = left + ((right - left) >> 1);
        mergeSort(arraySort, left, mid);
        mergeSort(arraySort, mid + 1, right);
        merge(arraySort, left, mid, right);
    }
}


template<typename T>
void Sort(std::vector<T>& arraySort) {
    mergeSort(arraySort, 0, arraySort.size() - 1);
}

template<typename T>
void mergePass(std::vector<T>& arraySort, int k, int len) {

    int i;
    for (i = 0; i < len - 2 * k; i += 2 * k) {
        //归并
        merge(arraySort, i, i + k - 1, i + 2 * k - 1);
    }
    //归并最后两个序列
    if (i + k < len) {
        merge(arraySort, i, i + k - 1, len - 1);
    }

}


//迭代方式
template<typename T>
void Sort2(std::vector<T>& arraySort) {
    //代表子集合大小，1，2，4，8，16.....
    int k = 1;
    int len = arraySort.size();
    while (k < len) {
        mergePass(arraySort, k, len);
        k *= 2;
    }
}

int main() {
    std::vector<int> temp = { 8,2,6,8,0,1,2,7,5,10,5345,1313,7676,4 };
    Sort2(temp);
    std::cout << "Hello World!\n";
}

