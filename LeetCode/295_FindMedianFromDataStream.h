#pragma once
#include "Common.h"

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
    }

    double findMedian()
    {
        return 0;
    }

private:
    map<int, long> nums;
    long count = 0;
};

void Test()
{
    /**
    * Your MedianFinder object will be instantiated and called as such:
    */
    MedianFinder *obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    assert(obj->findMedian() == 1.5);
    obj->addNum(3);
    assert(obj->findMedian() == 2);
}