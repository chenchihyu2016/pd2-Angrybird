#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <QGraphicsTextItem>
#include <contactListener.h>
#include <boxes.h>
#include<wallAndShooter.h>
using namespace std;

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void keyPressEvent(QKeyEvent* event);
    void closeEvent(QCloseEvent *);
signals:
    // Signal for closing the game
    void quitGame();
private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    Bird * current;
    Box * boxPtr;
    shooter* shootPtr;
    bool keyP;
    piggy  * pig,*pig2;
    b2Fixture* GetFixtureA();
    b2Fixture* GetFixtureB();
    MyContactListener *myContactListenerInstance;
    QGraphicsTextItem *word;
    bool control;
    double x1,y1;
    int  number;
    QPoint cursor;
    double x,y;
};
#endif // MAINWINDOW_H
