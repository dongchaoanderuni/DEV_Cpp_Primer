#include "Print.h"

using namespace std;

#define LegalInput (3)


unordered_map<string, string> buildMap(ifstream &map_file)
{   
    unordered_map<string, string> trans_map;  // 转换规则
    string key;
    string value;

    while(map_file >> key && getline(map_file, value))
    {
        if(1 < value.size())
        {
            trans_map[key] = value.substr(1); // 跳过前导空格
        }
        else
        {
            throw runtime_error("no rule for" + key);
        }
    }

    return trans_map;
}

const string & 
transform(const string &str, const unordered_map<string, string> &transMap)
{
    auto mapIter = transMap.find(str);
    if(mapIter != transMap.end())
    {
        return mapIter->second;
    }
    return str;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto transMap = buildMap(map_file);
    string text;
    while(getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool firstword = true;          // 控制是否打印空格
        while(stream >> word)
        {
            if(firstword)
            {
                firstword = false;
            }
            else
            {
                cout << " ";
            }
            cout << transform(word,transMap);
        }
        cout << endl;
    }

    return;
}

int main(int argc, char* argv[])
{

    if(LegalInput != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream mapFile(argv[1]);
    ifstream inputFile(argv[2]);
    if(!mapFile||!inputFile)
    {
        cerr << "Input File parse failed." << endl;
    }

    word_transform(mapFile,inputFile);

}
