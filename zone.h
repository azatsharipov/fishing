#ifndef ZONE_H
#define ZONE_H
#include "player.h"
#include <random>
#include <QTableWidget>

class Zone {
public:
    std::string name;
    double density, weather, fishEfficiency;
    int initFish, maxFish, newFish, fish, area, catchPerPlayer, totalCatch, ships;
    Zone();
    Zone(int initFish, std::string name);
    void calcCatch(Player players[], int playersAmount);
    void updateShips(Player players[], int playersAmount);
    void updateWaterTable(QTableWidget *water);
};

#endif // ZONE_H
