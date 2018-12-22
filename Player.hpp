//
//  Player.hpp
//  TicTacToe
//
//  Created by Saw Luke Loo Wah on 12/1/18.
//  Copyright © 2018 Saw Luke Loo Wah. All rights reserved.
//

#pragma once

#include <vector>
#include <stdio.h>
using namespace std;

class Player{
    
public:
    bool victory;
    vector<vector<int> > coord;
    bool playerturn;
    vector<vector<int>>GridCoord;
    
    
    Player();
    
    void SetGC();
    
};


