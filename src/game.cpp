#include "game.h"

Game::Game(QGraphicsRectItem *PP1, QGraphicsRectItem *PP2, QGraphicsEllipseItem *B):
    P1(PP1) , P2(PP2), ball(B)
{
   point = false;
   UD = true;
   LR = true;
}

void Game::run(){
    while(!point){
        QPointF ballpos = ball->scenePos();
        break;
    }
}

void Game::swSide(){
    if(LR)
        LR = false;
    if(!LR)
        LR = true;
}

void Game::swUpDown(){
    if(UD)
        UD = false;
    if(!UD)
        UD = true;
}
