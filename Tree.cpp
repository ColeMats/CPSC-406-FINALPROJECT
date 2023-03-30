#include "Tree.h"

Tree::Tree() {}

//eventually change to standard starting board, and set in constructor
void Tree::setRoot(TreeNode* node) {
    root = node;
    all_moves[node->getData().begin()->second] = node;
}

void Tree::addChild(TreeNode* parent, TreeNode* child) {
    parent->addChild(child);
    all_moves[child->getData().begin()->second] = child;
}

TreeNode* Tree::getRoot() {
    return root;
}

/* 
* get_all_moves function returns the entire data map and not just a single value.
* to access a single value, use:
* node->getData().at("key")
*/
std::unordered_map<std::string, TreeNode*> Tree::get_all_moves() {
    return all_moves;
}
