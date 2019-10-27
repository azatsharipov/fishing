#include "player.h"

int Player::getShip() {
    return ship;
}

int Player::getBalance() const
{
    return balance;
}

int Player::getDeepShip() const
{
    return deepShip;
}

int Player::getCoastalShip() const
{
    return coastalShip;
}

int Player::getHarborShip() const
{
    return harborShip;
}

int Player::getRevenue() const
{
    return revenue;
}

void Player::setRevenue(int value)
{
    revenue = value;
}

int Player::getDeepCatch() const
{
    return deepCatch;
}

int Player::getCoastalCatch() const
{
    return coastalCatch;
}

void Player::setPercent(int value)
{
    percent = value;
}

void Player::setMoneyForNew(int value)
{
    moneyForNew = value;
}

int Player::getPercent() const
{
    return percent;
}

int Player::getMoneyForNew() const
{
    return moneyForNew;
}

void Player::setHarborShip(int value)
{
    harborShip = value;
}

Player::Player() {
    deepCatch = 0;
    coastalCatch = 0;
    fishSales = 0;
    interest = 0;
    percent = 15;
}

Player::Player(int n) {
    deepCatch = 0;
    coastalCatch = 0;
    fishSales = 0;
    interest = 0;
    deepShip = 0;
    coastalShip = 0;
    harborShip = 0;
    percent = 15;
    if (n == 5)
        ship = 5;
    else
        ship = 24 / n;
    balance = 200 * ship;
}

void Player::setShips(int deep, int coastal, int harbor) {
    deepShip = deep;
    coastalShip = coastal;
    harborShip = harbor;
}

void Player::setCatch(int deep, int coastal) {
    deepCatch = deep * deepShip;
    coastalCatch = coastal * coastalShip;
}


bool Player::endYear() {

}

void Player::addShip(int ship) {
    if (this->ship + ship >= 0)
        this->ship += ship;
    else
        ;// message can't take ship
}

void Player::addMoney(int money) {
//    if (this->balance + money >= 0)
        this->balance += money;
//    else
//        ;// message can't pay
}
