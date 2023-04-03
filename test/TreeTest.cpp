#include <iostream>
#include <cassert>
#include "TreeNode.h"
#include "Tree.h"
#include "chess.h"
#include <iostream>

using namespace std;

int main(){
    // TreeNode *node1 = new TreeNode();
    // node1->set_piece_locations("A1","R");
    // node1->set_piece_locations("A2","N");
// // Create tree nodes
//     TreeNode* node1 = new TreeNode();
//     node1->set_piece_locations("location1", "value1");

//     TreeNode* node2 = new TreeNode();
//     node2->set_piece_locations("location2", "value2");

//     TreeNode* node3 = new TreeNode();
//     node3->set_piece_locations("location3", "value3");

//     // Create tree and set root node
//     Tree* tree = new Tree();
//     tree->setRoot(node1);

//     // Add child nodes
//     tree->addChild(node1, "move1", node2);
//     tree->addChild(node1, "move2", node3);

//     // Test getRoot()
//     assert(tree->getRoot() == node1);

//     // Test get_all_moves()
//     assert(tree->get_all_moves().size() == 3);

//     // Test add_future_move() and get_future_moves()
//     node1->add_future_move("move3", node2);
//     node1->add_future_move("move4", node3);
//     assert(node1->get_future_moves().size() == 4);

//     // Test set_piece_locations() and get_piece_locations()
//     node2->set_piece_locations("location4", "value4");
//     assert(node2->get_piece_locations().at("location4") == "value4");

//     // Print piece locations and possible moves
//     node1->print_piece_locations();
//     node1->print_possible_moves();

//     // Cleanup
//     delete node1;
//     delete node2;
//     delete node3;
//     delete tree;

//     std::cout << "All tests passed!" << std::endl;
//     return 0;
    const char initial_board[8][8] =
    {
        // This represents the pieces on the board.
        // Keep in mind that pieces[0][0] represents A1
        // pieces[1][1] represents B2 and so on.
        // Letters in CAPITAL are white
        { 'R',  'N',  'B',  'Q',  'K',  'B',  'N',  'R' },
        { 'P',  'P',  'P',  'P',  'P',  'P',  'P',  'P' },
        { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
        { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
        { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
        { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
        { 'p',  'p',  'p',  'p',  'p',  'p',  'p',  'p' },
        { 'r',  'n',  'b',  'q',  'k',  'b',  'n',  'r' },
    };

    Tree *currBoard = new Tree();
    // TreeNode *root = new TreeNode();
    // currBoard->setRoot = root;
    TreeNode *piece = new TreeNode();
    std::vector<std::string> moves;
    // Game *testGame = new Game();

    for(int i = 0; i<8;++i){
        // int x = i;
        for(int j = 0; j<8; ++j){
            // int y = j;
            char tempPiece = initial_board[i][j];
            if(isupper(tempPiece)){
                // TreeNode *piece = new TreeNode();
                string loc = "";
                // int x = (i + 'A');
                // int y = (j + '1');
                loc += (char) (i+'A');
                loc += (char) (j+'1');
                string p = "";
                p += tempPiece;
                // cout << loc << ": " << tempPiece << endl;
                piece->set_piece_locations(loc,p);
                moves = piece->get_three_rand_keys();
                // currBoard->addChild()
            }
        }
    }

    currBoard->setRoot(piece);
    const char* loc[3] = {"move1", "move2", "move3"};
    for(int i = 0; i<3;++i){
        
        TreeNode *node = new TreeNode();
        cout << moves[i] << endl;
        node->set_piece_locations(moves[i], "test");
        currBoard->addChild(piece,loc[i] , node);
    }
    piece->print_possible_moves();
    cout << piece->get_rand_move() << endl;
    // Chess::Position pawnPos;
    // pawnPos.iColumn = 0;
    // pawnPos.iRow = 6;
    // std::string pawnM = testGame->getPawnMove(pawnPos);

    // cout << pawnM << endl;
    // piece->print_possible_moves();


    // for(int i = 0; i<3;++i){
    //     cout << moves[i] << endl;
    // }

    // piece->print_piece_locations();
    // cout << piece->choose_rand_key() << endl;

    /*
    string location = "A1";
    int row;
    int col;
    row = location[0];
    col = location[1];

    row = row - 'A';
    col = col - '1';

    cout << row << col << endl;

    row = row + 'A';
    col = col + '1';

    cout << (char) row << (char) col << endl;
    */

    // TreeNode *test = new TreeNode();
    // int x = 0;
    // int y = 0;
    // y = (y + '1');
    // x = (x + 'A');
    // string location;
    // location += (char) x;
    // location += (char)y;
    // test->set_piece_locations(location,"R");
    // test->print_piece_locations();

}