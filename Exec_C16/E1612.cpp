#include "Headfile.h"
#include "TemplateBlob.h"

using namespace std;

int main() 
{

    Blob<int> ia;
    Blob<int> ia2={0, 1, 2, 3, 4};
    Blob<string> ariticles = {"a", "an", "the"};

    // for(auto ele:ia)
    // {
    //     cout <<ele << endl;
    // }

    // for(size_t i = 0; i != ia.size(); i++)
    // {
    //     cout << ia[i] << " ";
    // }
    // cout << endl;

    // for(size_t i = 0; i < ia2.size(); i++)
    // {
    //     cout << ia2[i] << " ";
    // }
    // cout << endl;

    print(ia);
    print(ia2);
    print(ariticles);

    return 0;
}
