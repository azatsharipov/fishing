#include "game.h"
#include <QTableWidgetItem>
#include <QDebug>
#include <QSpinBox>

int Game::getYear() const
{
    return year;
}

Game::Game() {

}

Game::Game(int n) {
    year = 1;
    playersAmount = n;
    if (playersAmount == 5)
        shipsAmount = 25;
    else
        shipsAmount = 24;
    initFishDeep = 2500;
    initFishCoastal = 1200;
    fishDeep = initFishDeep;
    fishCoastal = initFishCoastal;
    maxFishDeep = initFishDeep * 6 / 5;
    maxFishCoastal = initFishCoastal * 4 / 5;
    areaDeep = initFishDeep / 50;
    areaCoastal = initFishCoastal / 40;
    Player p(playersAmount);
    for (int i = 0; i < playersAmount; i++) {
        players[i] = p;
    }
    Zone z(2500, "Deep");
    deep = z;
    Zone z2(1200, "Coastal");
    coastal = z2;
}

Game::Game(int n, QTableWidget *init) {
    QSpinBox *sp;
    year = 1;
    playersAmount = n;
    if (playersAmount == 5)
        shipsAmount = 25;
    else
        shipsAmount = 24;
    sp = (QSpinBox*) init->cellWidget(4, 0);
    initFishDeep = sp->value();
    sp = (QSpinBox*) init->cellWidget(5, 0);
    initFishCoastal = sp->value();
    fishDeep = initFishDeep;
    fishCoastal = initFishCoastal;
    maxFishDeep = initFishDeep * 6 / 5;
    maxFishCoastal = initFishCoastal * 4 / 5;
    areaDeep = initFishDeep / 50;
    areaCoastal = initFishCoastal / 40;
    Player p(playersAmount);
    for (int i = 0; i < playersAmount; i++) {
        players[i] = p;
    }
    Zone z(initFishDeep, "Deep");
    deep = z;
    Zone z2(initFishCoastal, "Coastal");
    coastal = z2;
}

int Game::getPlayersAmount() const {
    return playersAmount;
}

void Game::setPlayersAmount(int value) {
    playersAmount = value;
}

bool Game::checkShipsOk(QTableWidget *input, QTableWidget *deal) {
    for (int i = 0; i < playersAmount; i++) {
        QSpinBox *sp;
        int ships = players[i].getDeepShip() + players[i].getCoastalShip() + players[i].getHarborShip();
        int newShip = players[i].getShip();
        sp = (QSpinBox*) input->cellWidget(0, i);
        newShip += sp->value();
        for (int j = 0; j < deal->rowCount(); j++) {
            sp = (QSpinBox*) deal->cellWidget(j, 0);
            int numb = sp->value();
            if (numb == i + 1) {
                sp = (QSpinBox*) deal->cellWidget(j, 2);
                newShip -= sp->value();
            }
            sp = (QSpinBox*) deal->cellWidget(j, 1);
            numb = sp->value();
            if (numb == i + 1) {
                sp = (QSpinBox*) deal->cellWidget(j, 2);
                newShip += sp->value();
            }
        }
        if (ships > newShip)
            return false;
        players[i].setHarborShip(players[i].getHarborShip() + players[i].getShip() - ships);//edit
    }
    return true;
}

void Game::setShips(QTableWidget *input) {
    QTableWidgetItem *item;
    int deep, coastal, harbor;
    QSpinBox *sp;
    for (int i = 0; i < playersAmount; i++) {
        deep = 0;
        coastal = 0;
        harbor = 0;
        sp = (QSpinBox*) input->cellWidget(3, i);
        deep += sp->value();
        sp = (QSpinBox*) input->cellWidget(4, i);
        coastal += sp->value();
        sp = (QSpinBox*) input->cellWidget(5, i);
        harbor += sp->value();
        players[i].setShips(deep, coastal, harbor);
    }
}

void Game::setCatch() {
    for (int i = 0; i < playersAmount; i++) {
        players[i].setCatch(deep.catchPerPlayer, coastal.catchPerPlayer);
        int money = players[i].getDeepShip() * 250 + players[i].getCoastalShip() * 150 + players[i].getHarborShip() * 50;
        players[i].addMoney(-money);
    }
}

void Game::updateCompsTable(QTableWidget *comps) {
    QTableWidgetItem *item;
    for (int i = 0; i < playersAmount; i++) {
        item = new QTableWidgetItem(QString::number(players[i].getShip() * 250 + players[i].getBalance()));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        comps->setItem(i, 3, item);
        item = new QTableWidgetItem(QString::number(players[i].getShip()));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        comps->setItem(i, 2, item);
        item = new QTableWidgetItem(QString::number(players[i].getBalance()));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        comps->setItem(i, 1, item);
    }
}

void Game::updateHarbor(QTableWidget *t, QTableWidget *deal) {
    for (int i = 0; i < playersAmount; i++) {
        QSpinBox *spinbox = new QSpinBox;
        QSpinBox *sp = new QSpinBox;
        int harbor = players[i].getShip();

        for (int j = 0; j < deal->rowCount(); j++) {
            int from = 0;
            int to = 0;
            sp = (QSpinBox*) deal->cellWidget(j, 0);
            from = sp->value();
            sp = (QSpinBox*) deal->cellWidget(j, 1);
            to = sp->value();
            if (from - 1 == i) {
                sp = (QSpinBox*) deal->cellWidget(j, 2);
                harbor -= sp->value();
            } else if (to - 1 == i) {
                sp = (QSpinBox*) deal->cellWidget(j, 2);
                harbor += sp->value();
            }
        }
        sp = (QSpinBox*) t->cellWidget(0, i);
        harbor += sp->value();
        sp = (QSpinBox*) t->cellWidget(3, i);
        harbor -= sp->value();
        sp = (QSpinBox*) t->cellWidget(4, i);
        harbor -= sp->value();
        spinbox->setMaximum(100000);
        spinbox->setValue(harbor);
        t->setCellWidget(5, i, spinbox);
    }
}

void Game::endYear(QTableWidget *deal, QTableWidget *input, QTableWidget *compsInfo) {
    year++;
    QSpinBox *sp;
    // аукцион
    for (int i = 0; i < playersAmount; i++) {
        int shipToAdd = 0, moneyToAdd = 0;
        sp = (QSpinBox*) input->cellWidget(0, i);
        shipToAdd += sp->value();
        players[i].addShip(shipToAdd);
        //if can't pay ........

        sp = (QSpinBox*) input->cellWidget(1, i);
        moneyToAdd += sp->value();
        players[i].addMoney(-moneyToAdd);
    }
    // сделки
    for (int i = 0; i < deal->rowCount(); i++) {
        int shipToAdd = 0;
        int from = 0;
        int to = 0;
        int moneyToAdd = 0;
        sp = (QSpinBox*) deal->cellWidget(i, 0);
        from = sp->value();
        sp = (QSpinBox*) deal->cellWidget(i, 1);
        to = sp->value();
        sp = (QSpinBox*) deal->cellWidget(i, 2);
        shipToAdd = sp->value();
        players[from - 1].addShip(-shipToAdd);
        players[to - 1].addShip(shipToAdd);
        //can't pay ..........

        sp = (QSpinBox*) deal->cellWidget(i, 3);
        moneyToAdd += sp->value();
        players[from - 1].addMoney(moneyToAdd);
        players[to - 1].addMoney(-moneyToAdd);
    }
    for (int i = 0; i < playersAmount; i++) {
        if (players[i].endYear()) {
            ;
        } else {
            ;//"check player" message
        }
    }
    for (int i = 0; i < playersAmount; i++) {
        if (players[i].getBalance() >= 0) {
            players[i].setPercent(0.15 * players[i].getBalance());
            players[i].addMoney(0.15 * players[i].getBalance());
        } else {
            players[i].setPercent(-0.1 * players[i].getBalance());
            players[i].addMoney(-0.1 * players[i].getBalance());
        }
    }
    // новые суда
    for (int i = 0; i < playersAmount; i++) {
        int shipToAdd = 0;
        sp = (QSpinBox*) input->cellWidget(2, i);
        shipToAdd = sp->value();
        players[i].addShip(shipToAdd);
        players[i].setMoneyForNew(-300 * shipToAdd);
//        players[i].addMoney(-300 * shipToAdd);
    }
    for (int i = 0; i < input->rowCount(); i++) {
        for (int j = 0; j < playersAmount; j++) {
            sp = (QSpinBox*) input->cellWidget(i, j);
            sp->setValue(0);
            if (i == 5)
                sp->setValue(players[j].getShip());
        }
    }
}

void Game::calcCatch(QTableWidget *input, QTableWidget *water) {
    deep.calcCatch(players, playersAmount);
    coastal.calcCatch(players, playersAmount);
}

void Game::updateWaterInfoTable(QTableWidget *input, QTableWidget *water) {
    deep.updateWaterTable(water);
    coastal.updateWaterTable(water);
    for (int i = 0; i < playersAmount; i++) {
        players[i].addMoney(players[i].getMoneyForNew());
    }
}

void Game::updateYearTable(QTableWidget *input, QTableWidget *years) {
    QTableWidgetItem *item;
    for (int i = 0; i < playersAmount; i++) {
        item = new QTableWidgetItem(QString::number(players[i].getDeepShip() * deep.catchPerPlayer));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        years->setItem(0, i, item);
        item = new QTableWidgetItem(QString::number(players[i].getCoastalShip() * coastal.catchPerPlayer));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        years->setItem(1, i, item);
        item = new QTableWidgetItem(QString::number(20));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        years->setItem(2, i, item);
        int catchMoney = (players[i].getDeepCatch() + players[i].getCoastalCatch()) * 20;
        players[i].addMoney(catchMoney);
        item = new QTableWidgetItem(QString::number(catchMoney));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        years->setItem(3, i, item);
        item = new QTableWidgetItem(QString::number(players[i].getPercent()));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        years->setItem(4, i, item);
        item = new QTableWidgetItem(QString::number(players[i].getBalance()));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        years->setItem(5, i, item);
        item = new QTableWidgetItem(QString::number(players[i].getShip()));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        years->setItem(6, i, item);
    }
}
