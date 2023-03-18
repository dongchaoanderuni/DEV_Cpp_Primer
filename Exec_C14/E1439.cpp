#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "StaticLengthinArticle.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
        return EXIT_FAILURE;
    }

    // 打开输入文件
    std::ifstream ifs(argv[1]);
    if (!ifs) {
        std::cerr << "Can't open file " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }


    vector<string> vecStr;
    // 统计每种长度的单词数量
    std::vector<std::size_t> cnt(11);
    for (std::string word; ifs >> word;) 
    {
        vecStr.push_back(word);
    }

    // 输出结果
    for (std::size_t i = 1; i <= 10; ++i) 
    {
        StaticLength stl(i);
        cout << "len: " << i << ", count: " << count_if(vecStr.begin(), vecStr.end(), stl)<< endl;
    }

    return 0;
}