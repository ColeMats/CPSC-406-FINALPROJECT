#ifndef TREENODE_H
#define TREENODE_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
private:
    std::unordered_map<std::string, std::string> piece_locations;
    std::unordered_map<std::string, TreeNode*> future_moves;
    int x;
    int y;

public:
    //Contructor and destructor
    TreeNode();
    TreeNode(int x, int y);

    // void set_piece_positions();
    // std::vector<std::string> get_piece_positions();
    // std::string get_position(int index);

    //piece location getter and setter
    void set_piece_locations(std::string key, std::string value);
    std::unordered_map<std::string, std::string> get_piece_locations();

    //future move getter and setter
    void add_future_move(std::string key, TreeNode* node);
    std::unordered_map<std::string, TreeNode*> get_future_moves();

    std::string choose_rand_key();
    std::vector<std::string> get_three_rand_keys();

    //print methods for debug
    void print_possible_moves();
    void print_piece_locations();

    std::string get_rand_move();

};

#endif /* TREENODE_H */
