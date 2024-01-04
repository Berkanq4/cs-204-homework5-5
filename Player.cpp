//
// Created by bberk on 5/16/2023.
//
#include <iostream>
#include "Player.h"
using namespace std;

int Player::move(int steps) {
    bool indicate = false;
    Node * ptr = pos;
    for (int i =0; i < steps && ptr != nullptr; i++){
        ptr = ptr->next;
        if (ptr == b.fnode()){
            indicate = true;
        }
    }
    pos = ptr;
    if (indicate){
        return 1;
    }
    else{
        return 0;
    }
}

Node* Player::where_am_I() {
    // Node * temp = pos;
    return pos;
}
void Player::pay_to_player(Player & otherPlayer, int amount) {
    this->balance -= amount; // Note: two instances of the same class schema -> can access priv. fields of other instances of the same class
    otherPlayer.balance += amount;

    // IS BANKRUPT CHECK NEEDED???
}

int Player::get_balance() {
    return this->balance;
}

void Player::deposit_money(int geld) {
    this->balance += geld;
}

void Player::buy_slot(int price) {
    pos->owner = this->player_name;
    this->balance -= price;
}

bool Player::is_bankrupt() {
    if (this->balance < 0){
        return true;
    }
    else{
        return false;
    }
}

void Player::display()
{
    Node * current = b.fnode();
    while(pos != current)
    {
        cout<<"      ";
        current = current->next;

    }

    cout<<player_name<<" "<<balance << endl;
}