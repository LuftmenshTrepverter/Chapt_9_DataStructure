#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100;
int heap[maxn], n = 10;

//在[low，high]区间内调整，high为堆的最后一个元素的数组下标
void downAdjust(int low, int high)
{
    int i = low;
    int j = i * 2; //左孩子的下标

    //存在左孩子
    while (j < high)
    {
        //可能存在左孩子不存在右孩子但不可能存在右孩子不存在左孩子
        //右孩子存在且右孩子大于左孩子，将j改成右孩子的下标
        if (j+1<high && heap[j+1] > heap[j])
        {
            j = j + 1;
        }

        if (heap[j] > heap[i])
        {
            swap(heap[j], heap[i]);
            i = j; //保持i为需要调整的结点
            j = i * 2; //保持j为i的左孩子
        }
        else
        {
            break;
        }
    }

}

//low一般是1，high一般是需要调整的结点
void upAdjust(int low, int high)
{
    int i = high;
    int j = i / 2;

    while (j >= low)
    {
        if (heap[i] > heap[j])
        {
            swap(heap[i], heap[j]);
            i = j; //保持i是动点
            j = i / 2;
        }
        else
        {
            break;
        }
    }
    
}

void createHeap()
{
    for (int i = n / 2; i > 1; i--)
    {
        downAdjust(i, n);
    }
}

void delHeapTop()
{
    heap[1] = heap[n--]; //用最后一个元素覆盖第一个元素，并且元素数量减一
    downAdjust(1, n); //向下调整堆顶元素
}

void Insert(int x)
{
    heap[++n] = x;
    upAdjust(1, n);
}

void heapSort()
{
    createHeap();
    for (int i = n; i >= 1; i--)
    {
        swap(heap[1], heap[i]);
        downAdjust(1, i - 1);
    }
}

int main()
{
    std::cout << "Hello World!\n";
}

  