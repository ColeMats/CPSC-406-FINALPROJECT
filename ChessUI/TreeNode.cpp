#include "TreeNode.h"

TreeNode::TreeNode() {}

// void TreeNode::set_piece_positions(){
//     for(auto i: piece_locations){
//         positions_on_board.push
//     }
// }

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

/*
* choose_rand_key() function gets the first key (location of random computer piece)
* returns location as a string (i.e. "E4", "A1", etc.)
*/
string TreeNode::choose_rand_key(){
    auto it = piece_locations.begin();
    return it->first;
}

std::vector<std::string> TreeNode::get_three_rand_keys(){
    std::vector<std::string> moves;
    std::unordered_map<std::string, std::string> :: iterator it;
    int count = 0;
    for(it = piece_locations.begin(); it!=piece_locations.end(); ++it){
        if(count == 3){
            return moves;
        }
        if((it->second != "q") && (it->second != "k") && (it->second != "n")){
            moves.push_back(it->first);
        }
        count++;
    }
    return moves;
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
std::string TreeNode::get_rand_move(){
    auto it = future_moves.begin();
    return it->first;
}