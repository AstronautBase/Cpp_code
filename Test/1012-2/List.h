#include <iostream>

struct Element
{
    int num;
    // 可以添加任何你需要的数据类型,但与本关测评无关
    bool operator==(const Element e) const;
};
class ListNode
{
    Element e;
    ListNode *back = nullptr;
    ListNode *next = nullptr;
    ListNode();
    ListNode(const Element &e_);
    friend class List; // 为便于测评，这里设置为友元
};

class List
{
    ListNode head; // 加入默认头节点,使得代码逻辑更统一
                   // 在进行链表操作时,你需要对head取地址
    size_t size_;  // 可以自行使用,不做要求
public:
    // 构造和析构
    List();               // 默认构造函数,head的next和back应该指向自己
    List(const List &l_); // 拷贝构造函数,内部深拷贝
    ~List();              // 析构函数,要求释放空间,析构后的head和size变量不做要求

    size_t size() { return size_; };

    // 访问和更改,返回访问或更改是否成功
    bool push_front(const Element &e); // 在头节点的next处插入e,分配空间失败时返回false
    bool push_back(const Element &e);
    bool pop_front(); // 弹出头节点的next节点并释放,不可弹出时返回false
    bool pop_back();
    bool remove(const Element &e);               // 删除链表中所有值为e的节点并释放,成功删除返回true
    bool insert(const Element &e, ListNode *ln); // 在节点ln后插入e,分配空间失败时返回false,测试用例中给定的ln均合法
    void erase(ListNode *ln);                    // 从链表中删除节点ln,释放ln的空间,测试用例中给定的ln均合法

    ListNode *get_item(size_t i); // 获取正向第i个节点(从0开始,不包括head)的指针,不存在则返回空

    // 遍历输出
    void print(); // 正向(next)输出链表中的元素num,不包括head,空格分隔,换行符结尾;空则输出换行符
};
