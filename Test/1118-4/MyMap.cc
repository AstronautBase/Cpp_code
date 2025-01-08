// MyMap.cpp
#include "MyMap.h"

// Map::Map() {}

// Map::~Map() {}

bool Map::insert(const string &key, int value)
{
    auto result = data.insert({key, value});
    return result.second;
}

bool Map::find(const string &key)
{
    return data.find(key) != data.end();
}

bool Map::erase(const string &key)
{
    return data.erase(key) > 0;
}

int &Map::operator[](const string &key)
{
    // int *useless = new int;
    // return *useless;
    return data[key];
}

int Map::size() const
{
    return data.size();
}