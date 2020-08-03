#pragma once
#include "Common.h"

class Solution
{
public:
    string numberToWords(int num)
    {
        list<int> nums;
        while (num > 0)
        {
            nums.emplace_front(num % 1000);
            num /= 1000;
        }

        if (nums.empty())
            return "Zero";

        list<string> tokens;
        int unitIndex = 0;
        for (auto it = nums.rbegin(); it != nums.rend(); it++)
        {
            string temp = number2Token(*it);
            if (temp.empty())
            {
                unitIndex++;
                continue;
            }
            tokens.emplace_front(temp + units[unitIndex++]);
        }

        auto it = tokens.begin();
        string result = *it++;
        while (it != tokens.end())
        {
            result += " ";
            result += *it++;
        }
        return result.empty() ? "zero" : result;
    }

private:
    vector<string> units = {"", " Thousand", " Million", " Billion"};
    string number2Token(int num)
    {
        if (num >= 0 && num < 20)
        {
            switch (num)
            {
            case 0:
                return "";
                break;
            case 1:
                return "One";
                break;
            case 2:
                return "Two";
                break;
            case 3:
                return "Three";
                break;
            case 4:
                return "Four";
                break;
            case 5:
                return "Five";
                break;
            case 6:
                return "Six";
                break;
            case 7:
                return "Seven";
                break;
            case 8:
                return "Eight";
                break;
            case 9:
                return "Nine";
                break;
            case 10:
                return "Ten";
                break;
            case 11:
                return "Eleven";
                break;
            case 12:
                return "Twelve";
                break;
            case 13:
                return "Thirteen";
                break;
            case 14:
                return "Fourteen";
                break;
            case 15:
                return "Fifteen";
                break;
            case 16:
                return "Sixteen";
                break;
            case 17:
                return "Seventeen";
                break;
            case 18:
                return "Eighteen";
                break;
            case 19:
                return "Nineteen";
                break;
            default:
                return "";
                break;
            }
        }
        else if (num >= 20 && num <= 99)
        {
            int ten = num / 10;
            string ten_s;
            switch (ten)
            {
            case 2:
                ten_s = "Twenty";
                break;
            case 3:
                ten_s = "Thirty";
                break;
            case 4:
                ten_s = "Forty";
                break;
            case 5:
                ten_s = "Fifty";
                break;
            case 6:
                ten_s = "Sixty";
                break;
            case 7:
                ten_s = "Seventy";
                break;
            case 8:
                ten_s = "Eighty";
                break;
            case 9:
                ten_s = "Ninety";
                break;
            }
            string rest = number2Token(num % 10);
            if (!rest.empty())
                rest = string(" ") + rest;
            return ten_s + rest;
        }
        else
        {
            int hundred = num / 100;
            string hundred_s = number2Token(hundred);
            string rest = number2Token(num % 100);
            if (!rest.empty())
                rest = string(" ") + rest;
            return hundred_s + " Hundred" + rest;
        }
    }
};

void Test()
{
    Solution solution;
    assert(solution.numberToWords(123) == "One Hundred Twenty Three");
    assert(solution.numberToWords(1234567891) == "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One");
}