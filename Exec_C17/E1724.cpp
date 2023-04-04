#include "Headfile.h"

using namespace std;

void replace_valid(istream &in) 
{
    string patternOfPhone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex pattern(patternOfPhone);
    string fmt = "$2.$5.$7 ";
    smatch match;
    string str;
    

    while(getline(in, str))
    {
        cout << regex_replace(str, pattern, fmt, std::regex_constants::format_no_copy) << endl;
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


