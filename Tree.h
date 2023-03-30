#ifndef TREE_H
#define TREE_H

#include <string>
#include <unordered_map>
#include "TreeNode.h"

class Tree {
private:
    TreeNode* root;
    std::unordered_map<std::string, TreeNode*> all_moves;

public:
    Tree();
    void setRoot(TreeNode* node);
    void addChild(TreeNode* parent, TreeNode* child);
    TreeNode* getRoot();
    std::unordered_map<std::string, TreeNode*> get_all_moves();
};

#endif /* TREE_H */
