//
// Created by bberk on 5/16/2023.
//
#include <iostream>
#include "Board.h"
using namespace std;

Node::Node(string o, Node *p) {
    owner = o;
    next = p;
}

Node::Node(void) : owner("None"), next(nullptr) {
}

Board::Board(int num_slot) {
    first = new Node("None", nullptr);
    Node * temp = first;
    for (int i = 1; i < num_slot; i ++){
        Node * ptr = new Node("None", nullptr);
        temp->next = ptr;
        temp = ptr;
        if (i == num_slot-1){ // handles last node in circular linked list;
            temp->next = first;
        }

    }
}

Board::~Board(){
    if (first == nullptr){
        return;
    }
    Node * current = first;

    while (current->next != first){
        current = current->next;
    }
    while (current != first){
        current->next = first->next;
        delete first;
        first = current->next;
    }
    if (current == first){
        delete first;
        first = nullptr;
    }
}

string Board::who_owns(const Node *n) const {
    return n->owner;
}
Node * Board::fnode() const
{
    return first;
}


void Board::display() {
    Node *ptr = first;
    int num_slots = 0;
    while (ptr->next != first) {
        ptr = ptr->next;
        num_slots++;
    }
    num_slots++;

    ptr = first;
    int nones = 4 * num_slots; // char count of none units
    int arrows = 2 * (num_slots - 1); // char count of arrows in the upper row
    int total_chars = nones + arrows;
    for (int j = 0; j < num_slots && ptr != nullptr; j++) {
        string owning = who_owns(ptr);
        if (owning != "None") {

            int space_cnt = 4 - owning.length();
            string extra_space = "";

            for (int i = 0; i < space_cnt; i++){
                extra_space += " ";
            }

            cout << owning;

            if (space_cnt > 0) {
                cout << extra_space;
            }

            if (j < num_slots - 1) {
                cout << "->";
            }
        } else {
            if (j == (num_slots - 1)) {
                cout << "None";// << endl;

            } else {
                cout << "None" << "->";

            }
        }

        ptr = ptr->next;

        if (ptr == first){
            break;
        }

    }
    string spaces = "\n";
    for (int k = 0; k < total_chars; k++) {
        if (k == 0) {
            spaces += "^";
        } else if (k < total_chars - 1) {
            spaces += " ";
        } else if (k == total_chars-1) {
            spaces += "|";
        }
    }
    string spaces2;
    for (int g = 0; g < total_chars - 1; g++) {
        if (g == 0){
            spaces2 += "|----";
            g += 4;
        }
        else if (g + 6 < total_chars){
            spaces2 += "<-----";
            g += 5;
        }
        else {

            spaces2 += "<";

            for (int i = 0; i < (total_chars - 2 - g); i++){
                spaces2 += "-";
            }

            spaces2 += "v";

            g += (total_chars - g) - 1;

        }

    }
    cout << spaces << endl;
    cout << spaces2 << endl;


    ptr = ptr->next;

}



