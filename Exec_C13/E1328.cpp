#include "Print.h"
#include <cstring>

using namespace std;

#define LegalInput (2)

class TreeNode
{
public:    
    TreeNode(const string &str=string(), int input=0, TreeNode *lhs=nullptr, TreeNode *rhs=nullptr):value(str),count(input),left(lhs),right(rhs) {} 
    TreeNode(const TreeNode &rhs):value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) {}
    TreeNode &operator=(const TreeNode &rhs);

private:
    string      value;
    int         count;
    TreeNode    *left;
    TreeNode    *right;
};

inline TreeNode &TreeNode::operator=(const TreeNode &rhs)
{
    value = rhs.value;
    count = rhs.count;
    left  = rhs.left;
    right = rhs.right; 

    return *this;
}

class BinStrTree
{
public:
    BinStrTree(TreeNode *treeNode=nullptr):root(treeNode) {}
    BinStrTree(const BinStrTree &rhs):root(rhs.root) {}
    BinStrTree &operator=(const BinStrTree &rhs) {root = rhs.root; return *this;}    
private:
    TreeNode    *root;
};

int main(int argc, char* argv[])
{


    return 0;
}
