#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "Variable.h"

using namespace std;

void showElement(vector<string> &vStr)
{
    for(auto ele:vStr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> vStr)
{
    sort(vStr.begin(), vStr.end());
    showElement(vStr);

    auto end_unique = unique(vStr.begin(), vStr.end());
    vStr.erase(end_unique, vStr.end());
    showElement(vStr);
}

bool isShorterThenTargetValue(const string &s1)
{
    return s1.size() >= 5;
}

void divide(vector<string> &vStr)
{
    elimDups(vStr);

    auto partVecStr = partition(vStr.begin(), vStr.end(), isShorterThenTargetValue);
    vStr.erase(partVecStr, vStr.end());
    showElement(vStr);
}

void biggies(vector<string> &vStr, vector<string>::size_type sz)
{
    elimDups(vStr);

    stable_sort(vStr.begin(), vStr.end(), 
                [](const string &a, const string &b)
                {return a.size() < b.size();});
    showElement(vStr);

    /* 获取第一个指向满足size() >= sz的元素 */
    auto wc = find_if(vStr.begin(), vStr.end(),
                [sz](const string &a)
                {return a.size() >=sz;});

    /* 计算满足大于sz的元素的个数 */
    auto count = vStr.end() - wc;
    
    /* 打印长度大于给定值得单词，每个单词后面接一个空格 */
    for_each(wc, vStr.end(),
            [](const string &a)
            {cout << a << " ";});
    cout << endl;
}

int main(int argc, char* argv[])
{
    string input;
    vector<string> vStr;

    while(cin >> input)
    {
        vStr.push_back(input);
    }
    showElement(vStr);

    biggies(vStr, 5);



}
