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
        if (smallHalf.empty() || num <= smallHalf.top())
        {
            smallHalf.emplace(num);
        }
        else
        {
            bigHalf.emplace(num);
        }
        
        if (bigHalf.size() > smallHalf.size())
        {
            smallHalf.emplace(bigHalf.top());
            bigHalf.pop();
        }
        else if (smallHalf.size() == bigHalf.size() + 2)
        {
            bigHalf.emplace(smallHalf.top());
            smallHalf.pop();
        }
    }

    double findMedian()
    {
        if (smallHalf.size() > bigHalf.size())
        {
            return smallHalf.top();
        }
        else
        {
            return static_cast<double>(smallHalf.top() + bigHalf.top()) / 2;
        }
    }

private:
    priority_queue<int, vector<int>> smallHalf;
    priority_queue<int, vector<int>, greater<int>> bigHalf;
};

// class MedianFinder
// {
// public:
//     /** initialize your data structure here. */
//     MedianFinder()
//     {
//     }

//     void addNum(int num)
//     {
//         if (num < 0)
//         {
//             lessThan0++;
//         }
//         else if (num > 100)
//         {
//             biggerThan100++;
//         }
//         else
//         {
//             count[num]++;
//         }
//         total++;
//     }

//     double findMedian()
//     {
//         int midIndex = (total - 1) / 2;
//         assert(lessThan0 <= midIndex);
//         int targetIndex = midIndex - lessThan0;
//         int left = 0, right = 0;
//         int i = 0;
//         for (; i < 101; i++)
//         {
//             targetIndex -= count[i];
//             if (targetIndex < 0)
//             {
//                 left = i;;
//                 break;
//             }
//         }

//         if (total % 2)
//             return left;
        
//         if (targetIndex < -1)
//         {
//             right = i;
//         }
//         else
//         {
//             for (i++; i < 101; i++)
//             {
//                 if (count[i] != 0)
//                 {
//                     right = i;
//                     break;
//                 }
//             }
//         }

//         assert(i < 101);
//         return static_cast<double>(left + right) / 2;
//     }

// private:
//     long lessThan0 = 0;
//     long biggerThan100 = 0;
//     vector<long> count = vector<long>(101, 0);
//     long total = 0;
// };

void Test()
{
    /**
    * Your MedianFinder object will be instantiated and called as such:
    */
    unique_ptr<MedianFinder> obj(new MedianFinder());
    obj->addNum(1);
    obj->addNum(2);
    assert(obj->findMedian() == 1.5);
    obj->addNum(3);
    assert(obj->findMedian() == 2);
}