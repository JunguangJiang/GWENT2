#ifndef DIALOG_H
#define DIALOG_H

#include <QHostAddress>
#include <QTcpSocket>

#include <QDialog>
#include <QGraphicsScene>
#include <QResizeEvent>
#include "graphicsitem.h"
#include "battle.h"
#include "carddatabase.h"
#include "user.h"
#include "game.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

    //---------------网络传输相关----------------
private:
    bool status;
    int port;
    QHostAddress *serverIP;
    QString userName;
    QTcpSocket *tcpSocket;
public slots:
    void slotEnter();
    void slotConnected();
    void slotDisconnected();
    void dataReceived();
    void slotSend();






    //----------------游戏相关-------------------

public:
    explicit Dialog(int userId, QWidget *parent = 0);
    ~Dialog();

    void login(int userId);//登陆

    void chooseDeck(int deckId);//选择牌组

    void editDeck(int deckId);//编辑一个新的牌组

    void playGameWith(int enemyId, int myDeckId);//与玩家enemyId玩游戏

    void acceptGame(int enemyId, int myDeckId);//接受另外一个玩家，与其玩游戏

    void exitDialog();//退出



    void playGame(long long gameId, int playerId1, int playerId2);//由服务器发送来的信号开始游戏

public slots:
    //void on_cardHover(Card* card);
    void uploadGame();//上传游戏
signals:
    void downloadGame();//下载游戏

private:
    Ui::Dialog *ui;
    QGraphicsScene *mainGameScene;//游戏主界面
    GraphicsItem *mainGameBackground;//游戏主界面的背景


    int m_myUserId;

    Game *game1;


    GraphicsItem* modifyDeck;//修改卡组的界面



protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // DIALOG_H
