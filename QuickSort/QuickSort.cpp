// QuickSort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>

template<typename T>
void swap(std::vector<T>& arraySort, int low, int hight) {
    auto temp = arraySort[low];
    arraySort[low] = arraySort[hight];
    arraySort[hight] = temp;
}

namespace simple {
template<typename T>
int partition(std::vector<T>& arraySort, int low, int hight) {
    //获取基准数
    auto pivot = arraySort[low];
    while (low < hight) {
        while (low < hight && arraySort[hight] > pivot) --hight;

        if (low < hight) arraySort[low] = arraySort[hight];

        while (low < hight && arraySort[low] <= pivot) ++low;

        if (low < hight) arraySort[hight] = arraySort[low];
    }

    arraySort[low] = pivot;

    return low;
}

template<typename T>
void quickSort(std::vector<T>& arraySort, int low, int hight) {
    if (low < hight) {
        auto index = partition(arraySort, low, hight);
        quickSort(arraySort, low, index - 1);
        quickSort(arraySort, index + 1, hight);
    }
}

template<typename T>
void quickSort(std::vector<T>& arraySort) {
    quickSort(arraySort, 0, arraySort.size() - 1);
}

template<typename T>
int partition2(std::vector<T>& arraySort, int low, int hight) {

    //获取基准数

    auto pivot = arraySort[low];
    auto start = low;
    while (low < hight) {
        while (low < hight && arraySort[hight] > pivot) --hight;
        while (low < hight && arraySort[low] <= pivot) ++low;

        if (low >= hight) break;
        swap(arraySort, low, hight);
    }

    swap(arraySort, start, low);
    return low;
}

template<typename T>
void quickSort2(std::vector<T>& arraySort, int low, int hight) {
    if (low < hight) {
        auto index = partition2(arraySort, low, hight);
        quickSort2(arraySort, low, index - 1);
        quickSort2(arraySort, index + 1, hight);
    }
}

template<typename T>
void quickSort2(std::vector<T>& arraySort) {
    quickSort2(arraySort, 0, arraySort.size() - 1);
}


}

namespace advance_0 {
template<typename T>
int partition(std::vector<T>& arraySort, int low, int hight) {

    //获取基准数
    auto pivot = arraySort[low];
    auto start = low;
    while (low < hight) {
        while (low < hight && arraySort[hight] > pivot) --hight;
        while (low < hight && arraySort[low] <= pivot) ++low;

        if (low >= hight) break;
        swap(arraySort, low, hight);
    }

    swap(arraySort, start, low);
    return low;
}

//迭代写法
template<typename T>
void quickSort(std::vector<T>& arraySort) {
    std::stack<int> stash;
    stash.push(0);
    stash.push(arraySort.size() - 1);

    while (!stash.empty()) {
        auto hight = stash.top();
        stash.pop();
        auto low = stash.top();
        stash.pop();
        if (low < hight) {
            auto index = partition(arraySort, low, hight);
            stash.push(low);
            stash.push(index - 1);
            stash.push(index + 1);
            stash.push(hight);
        }
    }
}

}
namespace advance_1 {
    
//增加三数取中
template<typename T>
int partition(std::vector<T>& arraySort, int low, int hight) {

    //三数取中
    int mid = low + ((hight - low) >> 1);
    if (arraySort[low] > arraySort[hight]) swap(arraySort, low, hight);
    if (arraySort[mid] > arraySort[hight]) swap(arraySort, mid, hight);
    if (arraySort[mid] > arraySort[low]) swap(arraySort, mid, low);

    //获取基准数
    auto pivot = arraySort[low];
    auto start = low;
    while (low < hight) {
        while (low < hight && arraySort[hight] > pivot) --hight;
        while (low < hight && arraySort[low] <= pivot) ++low;

        if (low >= hight) break;
        swap(arraySort, low, hight);
    }

    swap(arraySort, start, low);
    return low;
}

//迭代写法
template<typename T>
void quickSort(std::vector<T>& arraySort) {
    std::stack<int> stash;
    stash.push(0);
    stash.push(arraySort.size() - 1);

    while (!stash.empty()) {
        auto hight = stash.top();
        stash.pop();
        auto low = stash.top();
        stash.pop();
        if (low < hight) {
            auto index = partition(arraySort, low, hight);
            stash.push(low);
            stash.push(index - 1);
            stash.push(index + 1);
            stash.push(hight);
        }
    }
}

}

namespace advance_2 {
//数组少的时候用插入排序比较快

constexpr int INSERTION_SORT_MAX_LENGTH = 47;

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

template<typename T>
void quickSort(std::vector<T>& arraySort) {
    if (arraySort.size() > INSERTION_SORT_MAX_LENGTH) {
        advance_1::quickSort(arraySort);
    }
    else {
        StraightInsertionSort(arraySort);
    }
}

}

//没有或少重复元素用这个
namespace final_use_no_repeat {

constexpr int INSERTION_SORT_MAX_LENGTH = 47;

template<typename T>
void StraightInsertionSort(std::vector<T>& arraySort,int low,int hight) {
    for (int i = low + 1; i <= hight; ++i) {
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

template<typename T>
int partition(std::vector<T>& arraySort, int low, int hight) {
    //三数取中
    int mid = low + ((hight - low) >> 1);
    if (arraySort[low] > arraySort[hight]) swap(arraySort, low, hight);
    if (arraySort[mid] > arraySort[hight]) swap(arraySort, mid, hight);
    if (arraySort[mid] > arraySort[low]) swap(arraySort, mid, low);

    //获取基准数
    auto pivot = arraySort[low];
    auto start = low;
    while (low < hight) {
        while (low < hight && arraySort[hight] > pivot) --hight;
        while (low < hight && arraySort[low] <= pivot) ++low;

        if (low >= hight) break;
        swap(arraySort, low, hight);
    }

    swap(arraySort, start, low);
    return low;
}

template<typename T>
void quickSort(std::vector<T>& arraySort, int low, int hight) {
        //数量少的时候使用插入排序
   if (hight - low <= INSERTION_SORT_MAX_LENGTH) {
       StraightInsertionSort(arraySort, low, hight);
       return;
   }

   auto index = partition(arraySort, low, hight);
   quickSort(arraySort, low, index - 1);
   quickSort(arraySort, index + 1, hight);  
}

template<typename T>
void quickSort(std::vector<T>& arraySort) {
    quickSort(arraySort, 0, arraySort.size() - 1);
}

}


//多重复元素用这个,加入三向切分
namespace final_use_repeat {

constexpr int INSERTION_SORT_MAX_LENGTH = 47;

template<typename T>
void StraightInsertionSort(std::vector<T>& arraySort, int low, int hight) {
    for (int i = low + 1; i <= hight; ++i) {
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

template<typename T>
int partition(std::vector<T>& arraySort, int low, int hight) {
    

    //获取基准数
    auto pivot = arraySort[low];
    auto start = low;
    while (low < hight) {
        while (low < hight && arraySort[hight] > pivot) --hight;
        while (low < hight && arraySort[low] <= pivot) ++low;

        if (low >= hight) break;
        swap(arraySort, low, hight);
    }

    swap(arraySort, start, low);
    return low;
}

template<typename T>
void quickSort(std::vector<T>& arraySort, int low, int hight) {
   //数量少的时候使用插入排序
   if (hight - low <= INSERTION_SORT_MAX_LENGTH) {
       StraightInsertionSort(arraySort, low, hight);
       return;
   }
   
   //三数取中
   int mid = low + ((hight - low) >> 1);
   if (arraySort[low] > arraySort[hight]) swap(arraySort, low, hight);
   if (arraySort[mid] > arraySort[hight]) swap(arraySort, mid, hight);
   if (arraySort[mid] > arraySort[low]) swap(arraySort, mid, low);

   //三向切分
   auto povid = arraySort[low];
   int left = low, i = low + 1, right = hight;
   while (i <= right) {
       if (povid < arraySort[i]) {
           swap(arraySort, i, right);
           --right;
       }
       else if (povid == arraySort[i]) {
           ++i;
       }
       else {
           swap(arraySort, i, left);
           ++left;
           ++i;
       }
   }

   quickSort(arraySort, low, left - 1);
   quickSort(arraySort, right + 1, hight);
}

template<typename T>
void quickSort(std::vector<T>& arraySort) {
    quickSort(arraySort, 0, arraySort.size() - 1);
}

}
int main()
{
    std::vector<int> temp = { 8,2,6,8,0,1,2,7,5,10,5345,1313,7676,4,8,2,6,8,0,1,2,7,5,10,5345,1313,7676,4,8,2,6,8,0,1,2,7,5,10,5345,1313,7676,4,8,2,6,8,0,
        1,2,7,5,10,5345,1313,7676,4,8,2,6,8,0,1,2,7,5,10,5345,1313,7676,4,8,2,6,8,0,1,2,7,5,10,5345,1313,7676,4 };
    final_use_repeat::quickSort(temp);
    std::cout << "Hello World!\n";
}

