#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),keyP(true),control(false),x1(5.0),y1(6.05)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(36,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(5.0,8.5,0.001,0.001,QPixmap(":/shooter.png").scaled(width()/20,height()/3.0),world,scene));
    itemList.push_back(new Land(16,1.0,32,3,QPixmap(":/ground.png").scaled(width(),height()/6),world,scene));
    itemList.push_back(new Box(37,1.0,3,100,QPixmap(":/box.png").scaled(width()/5,height()/5),world,scene)); //it's the right wall
    itemList.push_back(new Box(-5,1.0,3,100,QPixmap(":/box.png").scaled(width()/5,height()/5),world,scene)); //it's the left wall
    itemList.push_back(new Box(16,23,32,3,QPixmap(":/box.png").scaled(width()/5,height()/5),world,scene)); //it's the ceiling
    itemList.push_back(new thing(31.5f,2.5f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(31.5f,5.0f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(31.5f,9.0f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(31.5f,11.5f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(26.5f,2.5f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(26.5f,5.0f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(26.5f,9.0f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(26.5f,11.5f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(24.5f,2.5f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(24.5f,5.0f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(24.5f,9.0f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(22.5f,2.5f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(22.5f,5.0f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    itemList.push_back(new thing(20.5f,2.5f,&timer,QPixmap(":/box.png").scaled(width()/18,height()/8.75),world,scene,2));
    // Create bird (You can edit here)
    //current = new redBird(5.0f,8.55.0f,0.26f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene,1);
    //current = new whiteBird(5.0f,8.55f,0.35f,&timer,QPixmap(":/whiteBird.png").scaled(height()/9.0,height()/9.0),world,scene,1);
    //current = new blackBird(5.0f,8.55f,0.49f,&timer,QPixmap(":/blackBird.png").scaled(height()/8.0,height()/9.0),world,scene,1);
    current = new blueBird(5.0f,8.55f,0.25f,&timer,QPixmap(":/blueBird.png").scaled(height()/8.5,height()/9.0),world,scene,1);
    pig = new  piggy(29.5f,4.5f,0.495f,&timer,QPixmap(":/greenPigs.png").scaled(height()/9.0,height()/8.0),world,scene,0);
    pig = new  piggy(26.5f,13.0f,0.495f,&timer,QPixmap(":/greenPigs.png").scaled(height()/9.0,height()/8.0),world,scene,0);
    // Setting the Velocity
    //current->setLinearVelocity(b2Vec2(25,0));
    itemList.push_back(current);
    itemList.push_back(pig);
    myContactListenerInstance = new MyContactListener(pig);
    world->SetContactListener(myContactListenerInstance);
    word = new QGraphicsTextItem;
    word->setPos(800,80);
    word->setPlainText(QString::number(pig->score));
    scene->addItem(word);
    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
   if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here*/
       //std::cout << "Move !" << std::endl;
        QPoint cursor = QCursor::pos();
        double x = cursor.x() *(  current->g_worldsize.width()/current->g_windowsize.width() )-3.8;
        double y =  (current->g_worldsize.height())- cursor.y() *((  current->g_worldsize.height()/current->g_windowsize.height()))+2.5;
        if( x>=4.5&& x <=5.5 && y >=8.0&& y <=9.0 )
            control = true;
        return true;
    }
   if(event->type() == QEvent::MouseMove && control == true )
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
        QPoint cursor = QCursor::pos();
        double x = cursor.x() *(  current->g_worldsize.width()/current->g_windowsize.width() )-3.8;
        double y =  (current->g_worldsize.height())- cursor.y() *((  current->g_worldsize.height()/current->g_windowsize.height()))+2.5;
        if( x < -1.0 ) x = -0.5;
        else if( x > 10 ) x = 10;
        if( y < 4 ) y = 4;
        else if( y >15 ) y = 15;
        current ->g_body ->SetTransform(b2Vec2(x,y),0);
        current->g_body->SetGravityScale(0);
        return true;
    }
    if(event->type() == QEvent::MouseButtonRelease && control == true )
    {
        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
        current->g_body->SetGravityScale(1);
        double x = current->getPositionX();
        double y = current->getPositionY();
        current->setLinearVelocity(b2Vec2((-x+x1)*5,(-y+y1)*10));
        control = false;
        return true;
    }
    return false;
}
void MainWindow::keyPressEvent(QKeyEvent* event){
    if((event->key() == Qt::Key_D||event->key() == Qt::Key_S)&&(keyP == true)){
            current->specialFunc();
            keyP = false;
     }
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
        emit quitGame();
}

void MainWindow::tick()
{
    //cout << pig->state() << endl;
    world->Step(1.0/60.0,6,2);
    word->setPlainText(QString::number(pig->score) );
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
