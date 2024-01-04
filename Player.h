//
// Created by bberk on 5/16/2023.
//

#ifndef UNTITLED4_PLAYER_H
#define UNTITLED4_PLAYER_H

#include "Board.h"

class Player{

    Node * pos;
    int balance;
    string player_name;
    Board & b;
public:

    Player(Board & b_param, string s, int balanced) : b(b_param), player_name(s), balance(balanced){
        pos = b.fnode();
    }
    int move(int steps);
    Node * where_am_I();
    void pay_to_player(Player & otherPlayer, int amount);
    int get_balance();
    void deposit_money(int geld);
    void buy_slot(int price);
    bool is_bankrupt();
    void display();
};



#endif //UNTITLED4_PLAYER_H
