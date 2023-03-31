#include <iostream>
#include <cassert>
#include "TreeNode.h"
#include "Tree.h"

int main() {
    // Create tree nodes
    TreeNode* node1 = new TreeNode();
    node1->set_piece_locations("location1", "value1");

    TreeNode* node2 = new TreeNode();
    node2->set_piece_locations("location2", "value2");

    TreeNode* node3 = new TreeNode();
    node3->set_piece_locations("location3", "value3");

    // Create tree and set root node
    Tree* tree = new Tree();
    tree->setRoot(node1);

    // Add child nodes
    tree->addChild(node1, "move1", node2);
    tree->addChild(node1, "move2", node3);

    // Test getRoot()
    assert(tree->getRoot() == node1);

    // Test get_all_moves()
    assert(tree->get_all_moves().size() == 3);

    // Test add_future_move() and get_future_moves()
    node1->add_future_move("move3", node2);
    node1->add_future_move("move4", node3);
    assert(node1->get_future_moves().size() == 4);

    // Test set_piece_locations() and get_piece_locations()
    node2->set_piece_locations("location4", "value4");
    assert(node2->get_piece_locations().at("location4") == "value4");

    // Print piece locations and possible moves
    node1->print_piece_locations();
    node1->print_possible_moves();

    // Cleanup
    delete node1;
    delete node2;
    delete node3;
    delete tree;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
