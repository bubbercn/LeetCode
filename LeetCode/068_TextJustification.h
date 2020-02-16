#pragma once
#include "Common.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        this->maxWidth = maxWidth;
        vector<string> result;
        string line;
        vector<string>::const_iterator iterator = words.begin();
        while((line = getLine(words, iterator)) != "")
        {
            result.emplace_back(line);
        }
        
        return result;
    }
    
private:
    string getLine(const vector<string>& words, vector<string>::const_iterator& begin)
    {
        if (begin == words.end())
            return "";
        
        vector<string> temp;
        temp.emplace_back(*begin);
        int left = maxWidth - (*begin).size();
        size_t wordsTotalLen = (*begin).size();
        assert(left >= 0);
        begin++;
        
        while(begin != words.end())
        {
            left -= ((*begin).size() + 1);
            if (left >= 0)
            {
                temp.emplace_back(*begin);
                wordsTotalLen += (*begin).size();
                begin++;
            }
            else
            {
                break;
            }
        }
        
        size_t spaceTotalLen = maxWidth - wordsTotalLen;
        auto iterator = temp.begin();
        string result = *(iterator++);
        
        if (begin == words.end())
        {
            while (iterator != temp.end())
            {
                result += ' ';
                result += *(iterator++);
                spaceTotalLen--;
            }
            result += string(spaceTotalLen, ' ');
        }
        else
        {
            size_t numOfSlot = temp.size() - 1;
            if (numOfSlot == 0)
                numOfSlot = 1;
            
            size_t average = spaceTotalLen / numOfSlot;
            size_t leftSpace = spaceTotalLen % numOfSlot;
            
            while (numOfSlot > 0)
            {
                size_t len = average;
                if (leftSpace > 0)
                {
                    len++;
                    leftSpace--;
                }
                result += string(len, ' ');
                if (iterator != temp.end())
                {
                    result += *(iterator++);
                }
                numOfSlot--;
            }
        }
        
        assert(result.size() == maxWidth);
        
        return result;
    }
    size_t maxWidth;
};

void Test()
{
    Solution solution;
    vector<string> input1 = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> output1 = {
        "This    is    an",
        "example  of text",
        "justification.  "
    };
    assert(solution.fullJustify(input1, 16) == output1);
    
    vector<string> input2 = {"What","must","be","acknowledgment","shall","be"};
    vector<string> output2 = {
        "What   must   be",
        "acknowledgment  ",
        "shall be        "
    };
    assert(solution.fullJustify(input2, 16) == output2);

    vector<string> input3 = {"Science","is","what","we","understand","well","enough","to","explain",
        "to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> output3 = {
        "Science  is  what we",
        "understand      well",
        "enough to explain to",
        "a  computer.  Art is",
        "everything  else  we",
        "do                  "
    };
    assert(solution.fullJustify(input3, 20) == output3);
}
