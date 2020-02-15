#pragma once
#include "Common.h"

class Solution {
public:
    bool isNumber(string s)
    {
        State state = State::Default;
        State preState = State::Default;
        for (auto i = s.begin(); i != s.end(); i++)
        {
            switch (state) {
                case State::Default:
                {
                    if (*i == ' ')
                    {
                        ;
                    }
                    else if (*i >= '0' && *i <= '9')
                    {
                        state = State::Integer;
                    }
                    else if (*i == '+' || *i == '-')
                    {
                        state = State::Sign;
                    }
                    else if (*i == '.')
                    {
                        preState = state;
                        state = State::Point;
                    }
                    else
                    {
                        return false;
                    }
                }
                    break;
                    
                case State::Sign:
                {
                    if (*i >= '0' && *i <= '9')
                    {
                        state = State::Integer;
                    }
                    else if (*i == '.')
                    {
                        preState = state;
                        state = State::Point;
                    }
                    else
                    {
                        return false;
                    }
                }
                    break;
                    
                case State::Integer:
                {
                    if (*i >= '0' && *i <= '9')
                    {
                        ;
                    }
                    else if (*i == '.')
                    {
                        preState = state;
                        state = State::Point;
                    }
                    else if (*i == 'e')
                    {
                        state = State::Exponent;
                    }
                    else if (*i == ' ')
                    {
                        state = State::End;
                    }
                    else
                    {
                        return false;
                    }
                }
                    break;
                    
                case State::Point:
                {
                    if (*i >= '0' && *i <= '9')
                    {
                        state = State::Float;
                    }
                    else if (*i == ' ' && preState == State::Integer)
                    {
                        state = State::End;
                    }
                    else if (*i == 'e' && preState == State::Integer)
                    {
                        state = State::Exponent;
                    }
                    else
                    {
                        return false;
                    }
                }
                    break;
                    
                case State::Float:
                {
                    if (*i >= '0' && *i <= '9')
                    {
                        ;
                    }
                    else if (*i == 'e')
                    {
                        state = State::Exponent;
                    }
                    else if (*i == ' ')
                    {
                        state = State::End;
                    }
                    else
                    {
                        return false;
                    }
                }
                    break;
                    
                case State::Exponent:
                {
                    if (*i >= '0' && *i <= '9')
                    {
                        state = State::ExponentInteger;
                    }
                    else if (*i == '+' || *i == '-')
                    {
                        state = State::ExponentSign;
                    }
                    else
                    {
                        return false;
                    }
                }
                    break;
                    
                case State::ExponentSign:
                {
                    if (*i >= '0' && *i <= '9')
                    {
                        state = State::ExponentInteger;
                    }
                    else
                    {
                        return false;
                    }
                }
                    break;
                    
                case State::ExponentInteger:
                {
                    if (*i >= '0' && *i <= '9')
                    {
                        ;
                    }
                    else if (*i == ' ')
                    {
                        state = State::End;
                    }
                    else
                    {
                        return false;
                    }
                }
                    break;

                case State::End:
                {
                    if (*i == ' ')
                    {
                        ;
                    }
                    else
                    {
                        return false;
                    }
                }
                    break;

                    
                default:
                    break;
            }
        }
        
        if (state == State::Default || state == State::Sign || state == State::Exponent || state == State::ExponentSign || (state == State::Point && preState != State::Integer))
            return false;

        
        return true;
    }
private:
    enum class State
    {
        Default,
        Sign,
        Integer,
        Point,
        Float,
        Exponent,
        ExponentSign,
        ExponentInteger,
        End
    };
};

void Test()
{
    Solution solution;
    assert(solution.isNumber("0"));
    assert(solution.isNumber(" 0.1 "));
    assert(!solution.isNumber("abc"));
    assert(!solution.isNumber("1 a"));
    assert(solution.isNumber("2e10"));
    assert(solution.isNumber(" -90e3   "));
    assert(!solution.isNumber(" 1e"));
    assert(!solution.isNumber("e3"));
    assert(solution.isNumber(" 6e-1"));
    assert(!solution.isNumber(" 99e2.5 "));
    assert(solution.isNumber("53.5e93"));
    assert(!solution.isNumber(" --6 "));
    assert(!solution.isNumber("-+3"));
    assert(!solution.isNumber("95a54e53"));
    assert(solution.isNumber("46.e3"));
    assert(!solution.isNumber(".e1"));
}
