#include <iostream>
#include "tree.h"

Tree::Tree(std::string data) : data(data) {}

std::string Tree::getData() const {
    return data;
}

int Tree::getHashmapValue(std::string key) const {
    auto it = hashmap.find(key);
    if (it != hashmap.end()) {
        return it->second;
    } else {
        return 0;
    }
}

Tree* Tree::getChild(int index) const {
    if (index < branches.size()) {
        return branches[index];
    } else {
        return nullptr;
    }
}

void Tree::setData(std::string data) {
    this->data = data;
}

void Tree::setHashmapValue(std::string key, int value) {
    hashmap[key] = value;
}

Tree* Tree::addChild(std::string childData) {
    Tree* child = new Tree(childData);
    branches.push_back(child);
    return child;
}

void Tree::removeChild(int index) {
    if (index < branches.size()) {
        Tree* child = branches[index];
        branches.erase(branches.begin() + index);
        delete child;
    }
}

void Tree::print(int depth) const {
    for (int i = 0; i < depth; i++) {
        std::cout << "\t";
    }
    std::cout << "- " << data << std::endl;
    for (const auto& p : hashmap) {
        for (int i = 0; i < depth; i++) {
            std::cout << "\t";
        }
        std::cout << "\t[" << p.first << "] = " << p.second << std::endl;
    }
    for (const auto& child : branches) {
        child->print(depth + 1);
    }
}

Tree::~Tree() {
    for (Tree* child : branches) {
        delete child;
    }
}
