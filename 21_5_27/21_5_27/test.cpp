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
    // ����С���� ����ϴ��һ��Ԫ��
    priority_queue<int, vector<int>, less<int>> min_heap;
    // �����󶥶� �����С��һ��Ԫ��
    priority_queue<int, vector<int>, greater<int>> max_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    void addNum(int num) {
        /*
            Ԫ����Ŀ��ͬʱ, �� С���Ѳ�������
                1. �����ݲ��� �����,
                2. �ڽ� ����� �Ѷ�Ԫ�ز��� С����
            Ԫ����Ŀ��ͬʱ, �� ����Ѳ�������
                ����ԭ����������ͬ
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