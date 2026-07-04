#include "queen_attack.h"
#include <stdio.h>
attack_status_t can_attack(position_t queen_1, position_t queen_2){
    // Check if queens are on the board
    if (queen_1.row >= 8 || queen_1.column >= 8 || queen_2.row >= 8 || queen_2.column >= 8){
        return INVALID_POSITION;
    }

    // Check if two queen overlap which is impossible
    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column){
        return INVALID_POSITION;
    }
    
    //Check if the two queens are in the same row or column
    if (queen_1.row == queen_2.row || queen_1.column == queen_2.column){
        return CAN_ATTACK;
    }

    //Check for upper and lower left diagonals for the queen that is to the left
    if (queen_1.column < queen_2.column){
        // Lower left
        if (queen_2.column-queen_1.column == queen_2.row-queen_1.row){
            return CAN_ATTACK;
        }
        // Upper left
        if (queen_2.column-queen_1.column == queen_1.row-queen_2.row){
            return CAN_ATTACK;
        }
    } else {
        //Lower left
        if (queen_1.column-queen_2.column == queen_1.row-queen_2.row){
            return CAN_ATTACK;
        }
        // Upper left
        if (queen_1.column-queen_2.column == queen_2.row-queen_1.row){
            return CAN_ATTACK;
        }
    }

    return CAN_NOT_ATTACK;
}