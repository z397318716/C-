#include<iostream>
#include<queue>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        y = 0;
        while (x) {
            //if(x & 1 == 1)
            //    y++;
            //x >>= 1;
            x &= x - 1;
            y++;
        }
        return y;
    }
};
class MedianFinder {
    // 建立小顶堆 保存较大的一半元素
    priority_queue<int, vector<int>, less<int>> min_heap;
    // 建立大顶堆 保存较小的一半元素
    priority_queue<int, vector<int>, greater<int>> max_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    void addNum(int num) {
        /*
            元素数目相同时, 向 小根堆插入数据
                1. 将数据插入 大根堆,
                2. 在将 大根堆 堆顶元素插入 小根堆
            元素数目不同时, 向 大根堆插入数据
                操作原理与上述相同
        */
        if (min_heap.size() == max_heap.size()) {
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else {
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        if (min_heap.size() == max_heap.size()) {
            return (min_heap.top() + max_heap.top()) / 2.0;
        }
        else
            return min_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */