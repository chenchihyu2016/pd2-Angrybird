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
using namespace std;

namespace Ui {
class MainWindow;
}
class MyContactListener ;
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
    thing * thingPtr;
    shooter* shootPtr;
    bool keyP;
    piggy  * pig,*pig2;
    b2Fixture* GetFixtureA();
    b2Fixture* GetFixtureB();
    MyContactListener *myContactListenerInstance;
    QGraphicsTextItem *word;
    bool control;
    void hold(double x, double y){
         current ->g_body ->SetTransform(b2Vec2(x,y),0);
    }
    double x1,y1;
    int  number;
};
class MyContactListener : public b2ContactListener
  {
public:
    MyContactListener(piggy* Pig,piggy* Pig2):pig(Pig),pig2(Pig2){
        score = 0;
    }
    void BeginContact(b2Contact* contact) {
      bodyUserData* body1 = (bodyUserData*)contact->GetFixtureA()->GetBody()->GetUserData();
      bodyUserData* body2 = (bodyUserData*)contact->GetFixtureB()->GetBody()->GetUserData();
     if ( (body1->label == 0  && body2->label ==1)||(body1->label == 1  && body2->label == 0 ) ){
          pig->startContact();
          score+=100;
     }
     else if ( (body1->label == 1  && body2->label ==3)||(body1->label == 3  && body2->label ==1)){
         pig2->startContact();
         score+=100;
     }
    }
    int score;
private:
    piggy * pig,*pig2 ;
};

#endif // MAINWINDOW_H
