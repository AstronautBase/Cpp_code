// 请在测评文件的Class.cpp中完成你的实现
#include <string>
#include <iostream>
#include <vector>

/* 加入你需要的头文件 */
#include <vector>

using namespace std;

class Class;
struct Function;
struct CallSite;
void call(CallSite cs);

struct CallSite
{
    const Class &base;
    string function_name;
    const Class &arg;
};

class Class
{
private:
    string name;
    const Class *parent;
    /* 你可以使用其他的数据结构来存储成员函数，也可以添加其他成员变量 */
    vector<Function> funcs;

public:
    Class(const string &name_) : name(name_), parent(nullptr) {}
    bool operator==(const Class &c) const { return name == c.name; }
    string get_name() const { return name; };

    /* 需要实现的接口,不可修改 */
    void add_function(const Function &f);
    void inherit(const Class &c); // 在构造Class时,如果有父类,那么inherit是第一步
    int is_ancestor(const Class &c) const;
    friend void call(CallSite cs);
};

struct Function
{
    string name;
    const Class &arg;
    bool operator==(const Function &f_) const
    {
        return name == f_.name && arg.get_name() == f_.arg.get_name();
    }
    bool operator<(const Function &f_) const
    {
        return name < f_.name || (name == f_.name && arg.get_name() < f_.arg.get_name());
    }
};
