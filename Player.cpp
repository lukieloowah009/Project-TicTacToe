//
//  Player.cpp
//  TicTacToe
//
//  Created by Saw Luke Loo Wah on 12/1/18.
//  Copyright © 2018 Saw Luke Loo Wah. All rights reserved.
//

#include "Player.hpp"

Player::Player(){}

void Player::SetGC(){
    for ( int i = 750 ; i <= 1030  ; i += 140){
        for ( int j = 500 ; j <= 780 ; j += 140 ){
            vector<int> temp;
            temp.push_back(i);
            temp.push_back(j);
            GridCoord.push_back(temp);
        }
    }
}
