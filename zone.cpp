#include "zone.h"
#include <QDebug>

Zone::Zone() {

}

Zone::Zone(int initFish, std::string name) {
    this->initFish = initFish;
    this->name = name;
    fish = initFish;
    if (initFish > 2000) {
        maxFish = (int)(initFish * 6 / 5);
        area = initFish / 50;
    } else {
        maxFish = (int)(initFish * 5 / 4);
        area = initFish / 40;
    }
    density = (double)fish / maxFish;
    if (density >= 0 && density <= 0.5)
        fishEfficiency = area * density;
    else if (density > 0.5)
        fishEfficiency = area * 0.5;
    else
        fishEfficiency = 0;
    weather = 1.0;
    newFish = 0; //?????????????
}

void Zone::updateShips(Player players[], int playersAmount) {
    ships = 0;
    for (int i = 0; i < playersAmount; i++) {
        if (name == "Deep") {
            ships += players[i].getDeepShip();
        } else if (name == "Coastal") {
            ships += players[i].getCoastalShip();
        }
    }
}

void Zone::calcCatch(Player players[], int playersAmount) {
    updateShips(players, playersAmount);
    totalCatch = ships * fishEfficiency * weather;
    if (totalCatch > fish) {
        fishEfficiency *= (double)fish / totalCatch;
        totalCatch = fish;
    }
    fish -= totalCatch;
    density = (double)fish / maxFish;
    if (density >= 0 && density <= 0.2) {
        newFish = (int)(10 * density);
    } else if (density > 0.2 && density <= 0.3) {
        newFish = (int)(20 * density - 2);
    } else if (density > 0.3 && density <= 0.5) {
        newFish = (int)(30 * density - 5);
    } else if (density > 0.5 && density <= 0.6) {
        newFish = (int)(10 * density + 5);
    } else if (density > 0.6 && density <= 0.7) {
        newFish = (int)(-15 * density + 20);
    } else if (density > 0.7 && density <= 0.8) {
        newFish = (int)(-40 * density + 37.5);
    } else if (density > 0.8 && density <= 0.9) {
        newFish = (int)(-25 * density + 25.5);
    } else if (density > 0.9 && density <= 1) {
        newFish = (int)(-30 * density + 30);
    }
    newFish *= area;
    fish += newFish;
    if (maxFish < fish)
        fish = maxFish;
    if (ships > 0)
        catchPerPlayer = totalCatch / ships;
    else
        catchPerPlayer = 0;
    weather = 0.8 + (double)(rand() % 5) / 10;
}

void Zone::updateWaterTable(QTableWidget *water) {
    int k = 1;
    if (name == "Deep")
        k = 0;
    QTableWidgetItem *item;
    item = new QTableWidgetItem(QString::number(fish));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    water->setItem(0, k, item);
    item = new QTableWidgetItem(QString::number(density));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    water->setItem(1, k, item);
    item = new QTableWidgetItem(QString::number(newFish));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    water->setItem(2, k, item);
    item = new QTableWidgetItem(QString::number(totalCatch));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    water->setItem(3, k, item);
    item = new QTableWidgetItem(QString::number(ships));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    water->setItem(4, k, item);
    item = new QTableWidgetItem(QString::number(catchPerPlayer));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    water->setItem(5, k, item);
    item = new QTableWidgetItem(QString::number(weather));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    water->setItem(6, k, item);
}
