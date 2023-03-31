#include "TreeNode.h"

TreeNode::TreeNode() {}

void TreeNode::set_piece_locations(std::string key, std::string value) {
    piece_locations[key] = value;
}

/* 
* get_piece_locations function returns the entire data map and not just a single value.
* to access a single value, use:
* node->get_piece_locations().at("key")
*/
std::unordered_map<std::string, std::string> TreeNode::get_piece_locations() {
    return piece_locations;
}

void TreeNode::add_future_move(std::string key, TreeNode* node) {
    future_moves[key] = node;
}

/* 
* get_future_moves function returns the entire data map and not just a single value.
* to access a single value, use:
* node->get_future_moves().at("key")
*/
std::unordered_map<std::string, TreeNode*> TreeNode::get_future_moves() {
    return future_moves;
}

//debug print statements
void TreeNode::print_possible_moves() {
    cout << "Possible moves:\n";
    for (auto& pair : future_moves) {
        cout << pair.first << "\n";
    }
}

void TreeNode::print_piece_locations() {
    cout << "Piece locations:\n";
    for (auto& pair : piece_locations) {
        cout << pair.first << ": " << pair.second << "\n";
    }
}