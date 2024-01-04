//
// Created by bberk on 5/16/2023.
//

#ifndef UNTITLED4_BOARD_H
#define UNTITLED4_BOARD_H
#include <iostream>
using namespace std;

struct Node{
    string owner;
    Node * next;
    Node();
    Node(string o, Node * p);
};

class Board{
private:
    Node * first;
    //int zort;
public:
    Board(int num_slot);
    string who_owns(const Node * n) const;
    ~Board();
    int returner();
    void display();
    Node * fnode() const;
};


#endif //UNTITLED4_BOARD_H