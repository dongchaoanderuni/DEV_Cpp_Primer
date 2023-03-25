#include "Headfile.h"
#include "TemplateBlob.h"

using namespace std;

int main()
{

    Blob<int> ia;
    Blob<int> ia2={0, 1, 2, 3, 4};
    Blob<string> ariticles = {"a", "an", "the"};
    vector<string> vecStr{"a", "an", "the"};
    Blob<string> articlesEins(vecStr.begin(), vecStr.end());

    print(ia);
    print(ia2);
    print(ariticles);
    print(articlesEins);

    return 0;
}   