#include "game.h"
#include <QDebug>
#include <QPainter>
#include <QTime>
#include <QMessageBox>
#include <QPixmap>


void Game::setDELAY(int newDELAY)
{
    DELAY = newDELAY;
}

Game::Game()
{
    this->resize(WIDTH * WIDTH, HEIGHT * HEIGHT);
    this->setWindowTitle("Snake");
}

void Game::Setup()
{
    game_over = false;
    mov_dir = STOP;
    snake.resize(1);
    snake[0].rx() = WIDTH / 2;
    snake[0].ry() = HEIGHT / 2;
    init_walls();
    QTime time = QTime::currentTime();
    srand((uint) time.msec());
    apple.rx() = rand() % WIDTH;
    apple.ry() = rand() % HEIGHT;
    timerId = startTimer(DELAY);
}

void Game::draw()
{
    QPainter qp(this);
    if(!game_over && snake.size()<10){
        //PRINTING FRUIT
        QPixmap pix(":/imj/Picture/apple.jpg");
        qp.drawPixmap(apple.x() * WIDTH, apple.y() * HEIGHT, WIDTH, HEIGHT,pix);
        //END OF PRINTING FRUIT

        //PRINTING SNAKE
        draw_snake();
        //END OF PRINTING SNAKE
    }
    else if(!game_over && snake.size()>=10){
        //PRINTING WALLS IF SIZE>=10
        QPixmap pix(":/imj/Picture/apple.jpg");
        qp.drawPixmap(apple.x() * WIDTH, apple.y() * HEIGHT, WIDTH, HEIGHT,pix);
        if(snake.size()>=15){
            QPoint temp;
            for(int i=0;i<2;++i){
                temp.rx()=-5+i+WIDTH/2;
                temp.ry()=i+HEIGHT/2;
                walls.push_back(temp);
            }
        }
        //PRINTING WALLS IF SIZE>=20
        if(snake.size()>=20){
            QPoint temp;
            for(int i=0;i<2;++i){
                temp.rx()=5+i+WIDTH/2;
                temp.ry()=-8+HEIGHT/2;
                walls.push_back(temp);
            }
        }
        for(int i=0;i<walls.size();++i){
            qp.setBrush(Qt::black);
            qp.drawRect(walls[i].x() * WIDTH ,walls[i].y() * HEIGHT, WIDTH, HEIGHT);
        }
        //END OF PRINTING WALLS

        //PRINTING SNAKE
        draw_snake();
        //END OF PRINTING SNAKE
    }
    else{
        gameOver();
    }
}

void Game::move()
{
    for(int i = snake.size() - 1; i > 0; --i)
    {
        snake[i] = snake[i - 1];
    }

    switch (mov_dir) {
            case LEFT:
                snake[0].rx()--;
                break;
            case UP:
                snake[0].ry()--;
                break;
            case DOWN:
                snake[0].ry()++;;
                break;
            case RIGHT:
                snake[0].rx()++;;
                break;
            default:
                break;
    }
}

void Game::check_field()
{
    for(int i = 1; i < snake.size(); ++i) {
       if(snake[0] == snake[i] && mode_flag==false) {
             game_over = true;
       }
       else if(snake[0]==snake[i] && mode_flag==true){
             snake.erase(snake.begin()+i,snake.end());
             snake.shrink_to_fit();
       }
    }
    if(snake.size()>=10){
        for(int i=0;i<walls.size();++i){
            if(snake[0].x()==walls[i].x() && snake[0].y()==walls[i].y()){
                game_over=true;
            }
        }
    }

    if(!mode_flag){
       if(snake[0].x() >= WIDTH) {game_over = true;}
       if(snake[0].y() >= HEIGHT) {game_over = true;}
       if(snake[0].x() < 0) {game_over = true;}
       if(snake[0].y() < 0) {game_over = true;}
    }
    else{
       if (snake[0].x() >= WIDTH){
          snake[0].rx() = 0;
       }
       else if (snake[0].x() < 0) {
          snake[0].rx() = WIDTH - 1;
       }
       if (snake[0].y() >= HEIGHT){
          snake[0].ry() = 0;
       }
       else if (snake[0].y() < 0){
          snake[0].ry() = HEIGHT - 1;
       }
    }
    if(game_over) {
        killTimer(timerId);
    }
}

void Game::check_apple()
{
    if(apple == snake[0]) {
        snake.push_back(QPoint(0, 0));
        QTime time = QTime::currentTime();
        srand((uint) time.msec());
        int p,q;
        p = rand() % WIDTH;
        q = rand() % HEIGHT;
        while(true){
         for(int i=1;i<snake.size();++i){
            if(p!=snake[i].x() && q!=snake[i].y()){
                break;
            }
            p = rand() % WIDTH;
            q = rand() % HEIGHT;
         }
        break;
        }
        if(snake.size()>=10){
          for(int i=0;i<walls.size();++i){
            if(p==walls[i].x() && q==walls[i].y()){
                p = rand() % WIDTH;
                q = rand() % HEIGHT;
            }
          }
        }
        apple.rx()=p;
        apple.ry()=q;
    }
}

void Game::gameOver()
{
      hide();
      gameoverwindow* g = new gameoverwindow();
      int score=snake.size()*10;
      g->set_score(score);
      g->show();
}

void Game::init_walls()
{
    QPoint temp;
    for(int i=0;i<5;++i){
       temp.rx()=i+WIDTH/2;
       temp.ry()=i+HEIGHT/2;
       walls.push_back(temp);
    }
    for(int i=0;i<2;++i){
        temp.rx()=-5+i+WIDTH/2;
        temp.ry()=-5+i+HEIGHT/2;
        walls.push_back(temp);
    }

}

void Game::draw_snake()
{
    QPainter qp(this);
    for(int i = 0; i < snake.size(); ++i)
            {
                if(i == 0)
                {
                    qp.setBrush(Qt::white);
                    qp.drawRect(snake[i].x() * WIDTH, snake[i].y() * HEIGHT, WIDTH, HEIGHT);
                }
                else
                {
                    qp.setBrush(Qt::green);
                    qp.drawRect(snake[i].x() * WIDTH, snake[i].y() * HEIGHT, WIDTH, HEIGHT);
                }
            }
}


Game* Game::shared_instance=nullptr;
Game *Game::get_instance()
{
   if(Game::shared_instance==nullptr){
       Game::shared_instance=new Game();
   }
   return Game::shared_instance;
}

void Game::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    if(!game_over) {
        check_apple();
        move();
        check_field();
    }
    this->repaint();
}

void Game::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    if ((key == Qt::Key_Left) && mov_dir != RIGHT) {
        mov_dir=LEFT;
        }
    if ((key == Qt::Key_Right) && mov_dir != LEFT) {

            mov_dir = RIGHT;
        }
    if ((key == Qt::Key_Up) && mov_dir != DOWN) {

            mov_dir = UP;
        }
    if ((key == Qt::Key_Down) && mov_dir != UP) {

            mov_dir = DOWN;
        }
//    if(key==Qt::Key_Escape){
//        mov_dir = STOP;
//    }


}

void Game::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    draw();
}


