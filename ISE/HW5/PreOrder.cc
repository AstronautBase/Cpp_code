#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

void buildPreorder(const vector<int> &inorder, const vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd, vector<int> &preorder)
{
    if (inStart > inEnd || postStart > postEnd)
    {
        return;
    }

    int root = postorder[postEnd];
    preorder.push_back(root);

    int rootIndex = find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, root) - inorder.begin();
    int leftSize = rootIndex - inStart;

    buildPreorder(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSize - 1, preorder);
    buildPreorder(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1, preorder);
}

int main()
{
    string inorderInput, postorderInput;

    getline(cin, inorderInput);
    getline(cin, postorderInput);

    stringstream ssIn(inorderInput);
    vector<int> inorder;
    int value;
    while (ssIn >> value)
    {
        inorder.push_back(value);
    }

    stringstream ssPost(postorderInput);
    vector<int> postorder;
    while (ssPost >> value)
    {
        postorder.push_back(value);
    }

    vector<int> preorder;
    buildPreorder(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, preorder);

    for (size_t i = 0; i < preorder.size(); ++i)
    {
        cout << preorder[i] << " ";
    }
    cout << endl;

    return 0;
}
