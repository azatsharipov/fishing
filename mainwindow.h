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
    int serverStatus = 0;
    int usersAmount = 0;
    int userNumber = 0;
    bool isServer = false;
    bool isGameOver = false;
    quint16 m_nNextBlockSize = 0;
    QMap<int, QTcpSocket *> SClients;

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
    void updateHarbor(int);
    void endGame();
    void drawGraphs();
    void back();

    void startServer();
    void newUser();
    void slotReadClient();
    void sendToClient();

    void joinToServer();
    void slotConnected();
    void sendToServer();
    void slotReadyRead();
    void initUserInputTable();
};

#endif // MAINWINDOW_H
