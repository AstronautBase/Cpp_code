#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <stack>
using namespace std;

struct Employee
{
    string name;
    vector<Employee *> subordinates;
    Employee() : name() {}
    Employee(string n) : name(n) {}
};

void encode(Employee *root, vector<string> &employeeList, string &binaryCode)
{
    employeeList.push_back(root->name);
    if (!root->subordinates.empty())
    {
        binaryCode += '0'; // 有下属，编码为0
        for (int i = 0; i < root->subordinates.size(); ++i)
        {
            encode(root->subordinates[i], employeeList, binaryCode);
        }
        binaryCode += '1';
    }
    else
    {
        binaryCode += '0';
        binaryCode += '1';
    }
}

Employee *decode(const vector<string> &employeeList, const string &binaryCode, int &index)
{
    stack<Employee *> nodeStack;

    // 创建根节点
    Employee *root = nullptr;
    Employee *currentNode = nullptr;
    for (char bit : binaryCode)
    {
        if (bit == '0')
        {
            if (index < employeeList.size())
            {
                Employee *newNode = new Employee(employeeList[index++]);
                if (!nodeStack.empty())
                    currentNode = nodeStack.top();
                nodeStack.push(newNode);
                if (index == 1)
                {
                    root = newNode;
                    continue;
                }
                currentNode->subordinates.push_back(newNode);
            }
        }
        else if (bit == '1')
        {
            if (!nodeStack.empty())
            {
                nodeStack.pop();
            }
        }
    }

    // 返回根节点
    return root;
}

void printStructure(Employee *root)
{
    if (root != nullptr && root->subordinates.size() != 0)
    {
        cout << root->name << ": ";
        for (int i = 0; i < root->subordinates.size(); ++i)
        {
            cout << root->subordinates[i]->name;
            if (i < root->subordinates.size() - 1)
                cout << " ";
        }
        cout << endl;
        for (int i = 0; i < root->subordinates.size(); ++i)
        {
            printStructure(root->subordinates[i]);
        }
    }
}

int main()
{
    string command;
    cin >> command;
    cin.ignore(); // 忽略换行符

    if (command == "ENCODE")
    {
        unordered_map<string, Employee *> employeeMap;
        string line;
        Employee *root = nullptr;
        while (getline(cin, line))
        {
            stringstream ss(line);
            string leader;
            ss >> leader;
            leader.pop_back();
            ss.ignore(1); // 忽略 ": "
            Employee *leaderNode;
            if (employeeMap.find(leader) == employeeMap.end())
            {
                leaderNode = new Employee();
                leaderNode->name = leader;
                if (employeeMap.size() == 0)
                    root = leaderNode;
                employeeMap[leader] = leaderNode;
            }
            else
            {
                leaderNode = employeeMap[leader];
            }

            string subordinateName;
            while (ss >> subordinateName)
            {
                Employee *subordinateNode;
                if (employeeMap.find(subordinateName) == employeeMap.end())
                {
                    subordinateNode = new Employee();
                    subordinateNode->name = subordinateName;
                    employeeMap[subordinateName] = subordinateNode;
                }
                else
                {
                    subordinateNode = employeeMap[subordinateName];
                }
                leaderNode->subordinates.push_back(subordinateNode);
            }
        }

        vector<string> employeeList;
        string binaryCode;
        encode(root, employeeList, binaryCode);

        // 输出员工名字
        for (const auto &name : employeeList)
        {
            cout << name << endl;
        }
        cout << binaryCode << endl;
    }
    else if (command == "DECODE")
    {
        vector<string> employeeNames;
        string binaryCode;
        string name;

        while (getline(cin, name))
        {
            employeeNames.push_back(name);
        }
        binaryCode = employeeNames[employeeNames.size() - 1];
        employeeNames.pop_back();
        int index = 0;
        Employee *root = decode(employeeNames, binaryCode, index);

        printStructure(root);
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <map>
// #include <string>
// #include <sstream>
// #include <algorithm>

// using namespace std;

// map<string, vector<string>> relations;

// void parseInput(istream &in)
// {
//     string line;
//     while (getline(in, line))
//     {
//         size_t coPos = line.find(':');
//         string manager = line.substr(0, coPos);
//         string subordinates = line.substr(coPos + 2);

//         if (subordinates.empty())
//         {
//             continue;
//         }
//         else
//         {
//             stringstream ss(subordinates);
//             string subordinate;
//             while (getline(ss, subordinate, ' '))
//             {
//                 relations[manager].push_back(subordinate);
//             }
//         }
//     }
// }

// struct TreeNode
// {
//     string name;
//     vector<TreeNode *> children;
//     TreeNode(string n) : name(n) {}
//     ~TreeNode()
//     {
//         for (auto child : children)
//         {
//             delete child;
//         }
//     }
// };

// void encode(TreeNode *node, string &binary)
// {
//     if (!node)
//         return;
//     binary += "0";
//     for (TreeNode *child : node->children)
//     {
//         encode(child, binary);
//     }
//     binary += "1";
// }

// void decode(const string &binary, int &index, TreeNode *&node, const vector<string> &names)
// {
//     if (index >= binary.size())
//         return;
//     if (binary[index] == '0')
//     {
//         node = new TreeNode(names[index++]);
//         while (index < binary.size() && binary[index] == '0')
//         {
//             TreeNode *child = nullptr;
//             decode(binary, index, child, names);
//             node->children.push_back(child);
//         }
//         if (index < binary.size() && binary[index] == '1')
//         {
//             index++;
//         }
//     }
// }

// void printAll(TreeNode *node)
// {
//     if (!node)
//         return;
//     cout << node->name << endl;
//     for (auto &child : node->children)
//     {
//         printAll(child);
//     }
// }

// void printTree(TreeNode *node)
// {
//     if (!node || node->children.empty())
//         return;
//     cout << node->name;
//     if (!node->children.empty())
//     {
//         cout << ":";
//     }
//     for (const auto &child : node->children)
//     {
//         cout << " " << child->name;
//     }
//     cout << endl;
//     for (auto child : node->children)
//     {
//         printTree(child);
//     }
// }

// int main()
// {
//     string command;
//     cin >> command;
//     cin.ignore();

//     if (command == "ENCODE")
//     {
//         // map<string, vector<string>> relations;
//         // string line;
//         parseInput(cin);

//         // while (getline(cin, line) && !line.empty())
//         // {
//         //     size_t coPos = line.find(':');
//         //     string manager = line.substr(0, coPos);
//         //     string subordinates = line.substr(coPos + 2);
//         //     if (!subordinates.empty())
//         //     {
//         //         stringstream ss(subordinates);
//         //         string sub;
//         //         while (getline(ss, sub, ' '))
//         //         {
//         //             relations[manager].push_back(sub);
//         //         }
//         //     }
//         // }

//         map<string, TreeNode *> nodes;
//         for (const auto &relation : relations)
//         {
//             if (nodes.count(relation.first) == 0)
//             {
//                 nodes[relation.first] = new TreeNode(relation.first);
//             }
//             for (const auto &child : relation.second)
//             {
//                 if (nodes.count(child) == 0)
//                 {
//                     nodes[child] = new TreeNode(child);
//                 }
//                 nodes[relation.first]->children.push_back(nodes[child]);
//             }
//         }

//         TreeNode *root = nodes.begin()->second;
//         string binary;
//         encode(root, binary);
//         printAll(root);
//         cout << binary << endl;

//         for (auto &pair : nodes)
//         {
//             delete pair.second;
//         }
//     }
//     else if (command == "DECODE")
//     {
//         vector<string> names;
//         string name;
//         while (cin >> name)
//         {
//             names.push_back(name);
//         }
//         string binary = names[names.size() - 1];
//         names.pop_back();
//         int index = 0;
//         TreeNode *root = nullptr;
//         decode(binary, index, root, names);
//         printTree(root);
//         delete root;
//     }

//     return 0;
// }