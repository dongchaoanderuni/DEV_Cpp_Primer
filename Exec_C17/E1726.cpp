#include "Headfile.h"

using namespace std;

bool valid(const smatch& matches)
{
    if(matches[1].matched)
    {
        return ((matches[3].matched)
                &&((0 == matches[4].matched)||(" " == matches[4].str())));
    }
    else
    {
        return ((!matches[3].matched)
                &&(matches[4].str() == matches[6].str()));
    }

}

vector<vector<string>> replace_valid(istream &in) 
{
    string patternOfPhone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex pattern(patternOfPhone);
    string fmt = "$2.$5.$7 ";
    string str;
    vector<string> phones;
    vector<vector<string>> namePhones;
    while(in >> str)
    {
        for(sregex_iterator iter(str.begin(), str.end(), pattern), endIter; 
                (iter != endIter)&&(valid(*iter)); ++iter)
        {
            phones.push_back(regex_replace(iter->str(), pattern, fmt));
        }
        namePhones.push_back(phones);
    }
    return namePhones;


}


int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
        return EXIT_FAILURE;
    }

    // 打开输入文件
    std::ifstream ifs(argv[1]);
    if (!ifs) 
    {
        std::cerr << "Can't open file " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }

    vector<vector<string>> phones;

    phones = replace_valid(ifs);
    for(auto &elem: phones)
    {
        for(size_t index = 1; index != elem.size(); ++index)

        cout << elem[index] << " ";
    }
    cout << endl;

    return 0;
}


