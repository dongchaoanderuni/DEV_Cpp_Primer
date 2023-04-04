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

void test_valid(istream &in) 
{
    string patternOfPhone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex pattern(patternOfPhone);
    string str;

    while(getline(in, str))
    {
        for(sregex_iterator iter(str.begin(), str.end(), pattern), endIter;
            iter != endIter; ++iter)
        {
            if(valid(*iter))
            {
                cout << "Valid: " << iter->str() << endl;
            }
            else
            {
                cout << "Not Valid: " << iter->str() << endl;
            }
        }
    }
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

    test_valid(ifs);

    
    return 0;
}


