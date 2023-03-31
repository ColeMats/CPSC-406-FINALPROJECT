#ifndef TREENODE_H
#define TREENODE_H

#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class TreeNode {
private:
    std::unordered_map<std::string, std::string> piece_locations;
    std::unordered_map<std::string, TreeNode*> future_moves;

public:
    //Contructor and destructor
    TreeNode();

    //piece location getter and setter
    void set_piece_locations(std::string key, std::string value);
    std::unordered_map<std::string, std::string> get_piece_locations();

    //future move getter and setter
    void add_future_move(std::string key, TreeNode* node);
    std::unordered_map<std::string, TreeNode*> get_future_moves();

    //print methods for debug
    void print_possible_moves();
    void print_piece_locations();

};

#endif /* TREENODE_H */
