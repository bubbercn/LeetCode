#pragma once
#include "Common.h"

class Solution
{
public:
    string validIPAddress(const string &IP)
    {
        if (isIPv4(IP))
        {

            return "IPv4";
        }
        else if (isIPv6(IP))
        {
            return "IPv6";
        }
        else
        {
            return "Neither";
        }
    }

private:
    list<string> split(string_view input, string_view seperator)
    {
        if (input.empty() || seperator.empty())
            return {};
        int begin = 0;
        list<string> result;
        while (true)
        {
            size_t end = input.find(seperator, begin);
            if (end != string::npos)
            {
                result.emplace_back(input.substr(begin, end - begin));
                begin = end + seperator.length();
            }
            else
            {
                break;
            }
        }
        result.emplace_back(input.substr(begin));
        return result;
    }
    bool isIPv4(string_view IP)
    {
        list<string> valueStrings = split(IP, ".");
        if (valueStrings.size() != 4)
            return false;

        for (const auto &valueString : valueStrings)
        {
            if (valueString.empty() || valueString.length() > 3)
                return false;

            int value = 0;
            try
            {
                value = stoi(valueString);
            }
            catch (const std::exception &)
            {
                return false;
            }

            if (value > 255)
                return false;

            if (to_string(value).length() != valueString.length())
                return false;
        }

        return true;
    }
    bool isIPv6(string_view IP)
    {
        list<string> valueStrings = split(IP, ":");
        if (valueStrings.size() != 8)
            return false;

        for (const auto &valueString : valueStrings)
        {
            if (valueString.empty() || valueString.length() > 4)
                return false;

            for (auto c : valueString)
            {
                if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
                    return false;
            }
        }

        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.validIPAddress("172.16.254.1"), "IPv4");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334"), "IPv6");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.validIPAddress("256.256.256.256"), "Neither");
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:"), "Neither");
}

TEST_F(LeetCodeTest, Example5)
{
    EXPECT_EQ(solution.validIPAddress("1e1.4.5.6"), "Neither");
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.validIPAddress("20EE:FGb8:85a3:0:0:8A2E:0370:7334"), "Neither");
}