#ifndef BOXES_H
#define BOXES_H
#define BOX_DENSITY 10.0f
#define BOX_FRICTION 0.1f
#define BOX_RESTITUTION 0.35f
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
class Box : public GameItem
{
public:
    Box(float x, float y, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int input);
};

#endif // BOXES_H
