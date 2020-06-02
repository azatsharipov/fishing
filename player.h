#ifndef PLAYER_H
#define PLAYER_H
#include <QTableView>


class Player {
    int ship, deepShip, coastalShip, harborShip, deepCatch, coastalCatch,
        fishSales, interest, balance, revenue, percent, moneyForNew;
public:
    Player();
    Player(int n);
    void setShips(int deep, int coastal, int harbor);
    void setCatch(int deep, int coastal);
    void addShip(int ship);
    void addMoney(int money);
    bool endYear();
    int getShip();
    int getBalance() const;
    int getDeepShip() const;
    int getCoastalShip() const;
    int getHarborShip() const;
    int getRevenue() const;
    void setRevenue(int value);
    int getDeepCatch() const;
    int getCoastalCatch() const;
    void setPercent(int value);
    void setMoneyForNew(int value);
    int getPercent() const;
    int getMoneyForNew() const;
    void setHarborShip(int value);
};

#endif // PLAYER_H
