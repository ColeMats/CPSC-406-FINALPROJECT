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

void TreeNode::add_future_move(TreeNode* node) {
    future_moves[node->getData().begin()->second] = node;
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
void print_possible_moves() const {
    cout << "Possible moves:\n";
    for (const auto& pair : future_moves_) {
        cout << pair.first << "\n";
    }
}

void print_piece_locations() const {
    cout << "Piece locations:\n";
    for (const auto& pair : piece_locations_) {
        cout << pair.first << ": " << pair.second << "\n";
    }
}