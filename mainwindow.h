#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <game.h>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Game game;
    QTableWidget comps[6];
    QTcpServer *tcpServer;
    QTcpSocket *user;
    quint16 ids[6];
    int activedCompany = 0;
    int serverStatus = 0;
    int usersAmount = 0;
    int userNumber = 0;
    bool isServer = false;
    bool isGameOver = false;
    QString gameName;
    quint16 m_nNextBlockSize = 0;
    QMap<int, QTcpSocket *> SClients;
    quint16 harborUser;
    bool downloaded = false;
    int year = 0;
    int playersAmount;
    bool isClient = false;

    QTableWidget comp;
    int shipsUser;

public slots:
    void start();
    void nextPage();
    void calc();
    void addDeal();
    void updateCompany(int n);
    void activeCompany();
    int getActiveCompany();
    void unsizeCompanies();
    void initCompaniesInfoTable(int n);
    void initWaterInfoTable();
    void initYearTable(int n);
    void initInputTable(int n);
//    void updateHarbor(int row, int column);
    void updateCompsTables();
    void updateHarbor(int);
    void endGame();
    void drawGraphs();
    void drawGraphShips();
    void drawGraphProperty();
    void back();
    void toGraphBalancePage();
    void toGamePage();
    void toGraphShipsPage();
    void toGraphPropertyPage();
    void saveGame();
    void downloadGame();
    void hideWaterInfoTable();
    void hideYearTable();
    void updateHarborUser(int);

    void startServer();
    void newUser();
    void slotReadClient();
    void sendToClient();
    void initInputTableServer(int n);


    void joinToServer();
    void slotConnected();
    void sendToServer();
    void slotReadyRead();
    void initUserInputTable();
    void drawGraphsUser();
    void drawGraphsShipsUser();
    void drawGraphsPropertyUser();
};

#endif // MAINWINDOW_H
