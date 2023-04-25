#include "Tree.h"

Tree::Tree() {}

//eventually change to standard starting board, and set in constructor
void Tree::setRoot(TreeNode* node) {
    root = node;
    all_moves.push_back(node);
}

void Tree::addChild(TreeNode* parent, std::string move, TreeNode* child) {
    parent->add_future_move(move, child);
    all_moves.push_back(child);
}


TreeNode* Tree::getRoot() {
    return root;
}

/* 
* get_all_moves function returns the entire data map and not just a single value.
* to access a single value, use:
* node->getData().at("key")
*/
std::vector<TreeNode*> Tree::get_all_moves() {
    return all_moves;
}


