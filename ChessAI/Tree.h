#ifndef TREE_H
#define TREE_H

#include <string>
#include <vector>
#include "TreeNode.h"

class Tree {
private:
    TreeNode* root;
    std::vector<TreeNode*> all_moves;

public:
    Tree();
    void setRoot(TreeNode* node);
    void addChild(TreeNode* parent, std::string move, TreeNode* child);
    // void addChild(TreeNode* parent, TreeNode* child);
    TreeNode* getRoot();
    // TreeNode* get_rand_move();
    std::vector<TreeNode*> get_all_moves();
};

#endif /* TREE_H */