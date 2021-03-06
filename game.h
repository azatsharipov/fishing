#ifndef GAME_H
#define GAME_H
#include <QPixmap>
#include <QTableView>
#include <QTableWidgetItem>
#include <player.h>
#include <zone.h>

class Game {
    int year, playersAmount, shipsAmount, fishDeep, fishCoastal, initFishDeep, initFishCoastal;
    int maxFishDeep, maxFishCoastal, areaDeep, areaCoastal;
    Player players[6];
    Zone deep, coastal;
public:
    Game();
    Game(int);
    Game(int, QTableWidget *init);
    int getPlayersAmount() const;
    bool checkShipsOk(QTableWidget *input, QTableWidget *deal);
    void endYear(QTableWidget *deal, QTableWidget *t, QTableWidget *compsInfo);
    void setPlayersAmount(int value);
    void setShips(QTableWidget *t);
    void setCatch();
    int getShips();
    void calcCatch(QTableWidget *t, QTableWidget *water);
    void updateCompsTable(QTableWidget *comps);
    void updateWaterInfoTable(QTableWidget *t, QTableWidget *water);
    void updateYearTable(QTableWidget *t, QTableWidget *years);
    void updateHarbor(QTableWidget *t, QTableWidget *deal, int serverStatus);
    int getYear() const;
};

#endif // GAME_H
