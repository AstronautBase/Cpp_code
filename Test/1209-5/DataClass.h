#include <map>
#include <string>
#include <unordered_map>
#include <vector>

class DataClass
{
private:
    std::vector<std::string> data_;

public:
    DataClass(const std::vector<std::string> &data) : data_(data) {}

    std::string HashKey() const
    {
        // Your code here
        std::string hashKey;
        for (const auto &str : data_)
        {
            hashKey += str + '#';
        }
        return hashKey;
    }

    bool operator==(const DataClass &dc) const
    {
        // Your code here
        return data_ == dc.data_;
    }
};

// 不需要修改
struct DataClassHash
{
    size_t operator()(const DataClass &dc) const
    {

        std::string str = dc.HashKey();

        return std::hash<std::string>()(str);
    }
};
