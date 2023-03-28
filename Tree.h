#ifndef TREE_H
#define TREE_H

#include <string>
#include <vector>
#include <unordered_map>

class Tree {
public:
    explicit Tree(std::string data);

    std::string getData() const;
    int getHashmapValue(std::string key) const;
    Tree* getChild(int index) const;

    void setData(std::string data);
    void setHashmapValue(std::string key, int value);
    Tree* addChild(std::string childData);
    void removeChild(int index);

    void print(int depth = 0) const;

    ~Tree();

private:
    std::string data;
    std::unordered_map<std::string, int> hashmap;
    std::vector<Tree*> branches;
};

#endif // TREE_H
