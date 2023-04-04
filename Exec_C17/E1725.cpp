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

void replace_valid(istream &in) 
{
    string patternOfPhone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex pattern(patternOfPhone);
    string fmt = "$2.$5.$7 ";
    string str;
    smatch match;


    while(getline(in, str))
    {
        if(regex_search(str, match, pattern))
        {
            cout << regex_replace(match[0].str(), pattern, fmt)<< endl;
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

    replace_valid(ifs);

    
    return 0;
}


