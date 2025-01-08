#include "Class.h"

void Class::add_function(const Function &f)
{
    funcs.push_back(f);
}

void Class::inherit(const Class &c)
{
    parent = &c;
}

void call(CallSite cs)
{
    bool found = false;
    const Class *cur = &cs.base;
    while (cur != nullptr)
    {
        bool isSameName = false;
        // 直接匹配
        for (auto &func : cur->funcs)
        {
            if (func.name == cs.function_name)
            {
                isSameName = true;
                if (func.arg == cs.arg)
                {
                    cout << cur->get_name() << "::" << func.name << "(" << func.arg.get_name() << ")" << endl;
                    found = true;
                    return;
                }
            }
        }

        // 子类匹配
        string match_arg_name = "";
        int min = 100001;
        for (auto &func : cur->funcs)
        {
            if (func.name == cs.function_name)
            {
                if (cs.arg.is_ancestor(func.arg) != 0)
                {
                    min = min < cs.arg.is_ancestor(func.arg) ? min : cs.arg.is_ancestor(func.arg);
                    match_arg_name = func.arg.name;
                    found = true;
                }
            }
        }
        if (found)
        {
            cout << cur->name << "::" << cs.function_name << "(" << match_arg_name << ")" << endl;
            return;
        }
        if (isSameName)
        {
            break;
        }
        cur = cur->parent;
    }
    if (!found)
        cout << "Function not found." << endl;
}

int Class::is_ancestor(const Class &c) const
{
    int depth = 1;
    const Class *current = parent;
    while (current != nullptr)
    {
        if (*current == c)
            return depth;
        current = current->parent;
        depth++;
    }

    return 0;
}
