#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(6);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::initCompaniesInfoTable(int n) {
    ui->CompaniesInfoTable->setRowCount(n);
    QTableWidgetItem *item;
    QStringList verticalHeader;
    QStringList horizontalHeader;
    for (int i = 0; i < n; i++) {
        verticalHeader.append(QString::number(i + 1));
    }
    ui->CompaniesInfoTable->setVerticalHeaderLabels(verticalHeader);
    for (int i = 0; i < n; i++) {
        item = new QTableWidgetItem(QString::number(i + 1));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->CompaniesInfoTable->setItem(i, 0, item);
    }
    for (int i = 0; i < n; i++) {
        if (n == 5) {
            item = new QTableWidgetItem(QString::number(200 * (25 / n)));
            item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
            ui->CompaniesInfoTable->setItem(i, 1, item);
        } else {
            item = new QTableWidgetItem(QString::number(200 * (24 / n)));
            item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
            ui->CompaniesInfoTable->setItem(i, 1, item);
        }
    }
    for (int i = 0; i < n; i++) {
        if (n == 5) {
            item = new QTableWidgetItem(QString::number(25 / n));
            item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
            ui->CompaniesInfoTable->setItem(i, 2, item);
        } else {
            item = new QTableWidgetItem(QString::number(24 / n));
            item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
            ui->CompaniesInfoTable->setItem(i, 2, item);
        }
    }
    for (int i = 0; i < n; i++) {
        if (n == 5) {
            item = new QTableWidgetItem(QString::number(450 * 25 / n));
            item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
            ui->CompaniesInfoTable->setItem(i, 3, item);
        } else {
            item = new QTableWidgetItem(QString::number(450 * 24 / n));
            item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
            ui->CompaniesInfoTable->setItem(i, 3, item);
        }
    }
}

void MainWindow::initWaterInfoTable() {
    QSpinBox *sp;
    sp = (QSpinBox*) ui->InitInfoTable->cellWidget(4, 0);
    int initFish = sp->value();
    QTableWidgetItem *item;
    item = new QTableWidgetItem(QString::number(initFish));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(0, 0, item);
    item = new QTableWidgetItem(QString::number(41));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(1, 0, item);
    item = new QTableWidgetItem(QString::number(506));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(2, 0, item);
    item = new QTableWidgetItem(QString::number(525));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(3, 0, item);
    item = new QTableWidgetItem(QString::number(21));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(4, 0, item);
    item = new QTableWidgetItem(QString::number(25));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(5, 0, item);
    item = new QTableWidgetItem(QString::number(1));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(6, 0, item);

    sp = (QSpinBox*) ui->InitInfoTable->cellWidget(5, 0);
    initFish = sp->value();
    item = new QTableWidgetItem(QString::number(initFish));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(0, 1, item);
    item = new QTableWidgetItem(QString::number(40));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(1, 1, item);
    item = new QTableWidgetItem(QString::number(201));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(2, 1, item);
    item = new QTableWidgetItem(QString::number(45));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(3, 1, item);
    item = new QTableWidgetItem(QString::number(3));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(4, 1, item);
    item = new QTableWidgetItem(QString::number(15));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(5, 1, item);
    item = new QTableWidgetItem(QString::number(1));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(6, 1, item);
}

void MainWindow::initYearTable(int n) {
    ui->YearTable->setColumnCount(n);
    QTableWidgetItem *item;
    QStringList horizontalHeader;
    for (int i = 0; i < n; i++) {
        horizontalHeader.append(QString::number(i + 1));
    }
    ui->YearTable->setHorizontalHeaderLabels(horizontalHeader);
    for (int i = 0; i < n; i++) {
        item = new QTableWidgetItem(QString::number(175));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(0, i, item);
        item = new QTableWidgetItem(QString::number(15));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(1, i, item);
        item = new QTableWidgetItem(QString::number(20));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(2, i, item);
        item = new QTableWidgetItem(QString::number(3800));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(3, i, item);
        item = new QTableWidgetItem(QString::number(-30));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(4, i, item);
        item = new QTableWidgetItem(QString::number(1600));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(5, i, item);
        item = new QTableWidgetItem(QString::number(8));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(6, i, item);
    }
}

void MainWindow::initInputTable(int n) {
    ui->InputTable->setColumnCount(n);
    QStringList horizontalHeader;
    for (int i = 0; i < n; i++) {
        horizontalHeader.append(QString::number(i + 1));
    }
    ui->InputTable->setHorizontalHeaderLabels(horizontalHeader);
    for (int i = 0; i < ui->InputTable->rowCount(); i++)
        for (int j = 0; j < ui->InputTable->columnCount(); j++) {
            QSpinBox *spinbox = new QSpinBox;
            ui->InputTable->setCellWidget(i, j, spinbox);
            spinbox = (QSpinBox*) ui->InputTable->cellWidget(i, j);
            spinbox->setMaximum(10000);
        }
}

void MainWindow::start() {
    int playersAmount = (ui->spinBox->text()).toInt();
    QTableWidgetItem *item;

    ui->checkMessage->setVisible(false);
    //  Init Info Table
    ui->InitInfoTable->setRowCount(6);
    ui->InitInfoTable->setColumnCount(1);
    QStringList horizontalHeader;
    horizontalHeader.append("");
    QStringList verticalHeader;
    verticalHeader.append("Компании");
    verticalHeader.append("Корабли");
    verticalHeader.append("Кораблей на компанию");
    verticalHeader.append("Баланс на компанию");
    verticalHeader.append("Глубоководная рыба");
    verticalHeader.append("Прибрежная рыба");
    ui->InitInfoTable->setVerticalHeaderLabels(verticalHeader);
    ui->InitInfoTable->setHorizontalHeaderLabels(horizontalHeader);

    item = new QTableWidgetItem(QString::number(playersAmount));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->InitInfoTable->setItem(0, 0, item);
    if (playersAmount == 5) {
        item = new QTableWidgetItem(QString::number(25));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->InitInfoTable->setItem(1, 0, item);
        item = new QTableWidgetItem(QString::number(5));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->InitInfoTable->setItem(2, 0, item);
    } else {
        item = new QTableWidgetItem(QString::number(24));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->InitInfoTable->setItem(1, 0, item);
        item = new QTableWidgetItem(QString::number(24 / playersAmount));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->InitInfoTable->setItem(2, 0, item);
    }
    item = new QTableWidgetItem(QString::number(1600));
    ui->InitInfoTable->setItem(3, 0, item);

    QSpinBox *spinbox = new QSpinBox;
    spinbox->setMaximum(10000);
    spinbox->setValue(2500);
    ui->InitInfoTable->setCellWidget(4, 0, spinbox);
    spinbox = new QSpinBox;
    spinbox->setMaximum(10000);
    spinbox->setValue(1200);
    ui->InitInfoTable->setCellWidget(5, 0, spinbox);

    ui->stackedWidget->setCurrentIndex(1);

/*
    item = new QTableWidgetItem(QString::number(2500));
    ui->InitInfoTable->setItem(4, 0, item);
    item = new QTableWidgetItem(QString::number(1200));
    ui->InitInfoTable->setItem(5, 0, item);
    */
}

void MainWindow::nextPage() {
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
    ui->DealTable->setRowCount(0);
    if (ui->stackedWidget->currentIndex() == 2) {
        int playersAmount = (ui->spinBox->text()).toInt();
        Game g(playersAmount, ui->InitInfoTable);
        game = g;
        initCompaniesInfoTable(playersAmount);
        initWaterInfoTable();
        initYearTable(playersAmount);
        initInputTable(playersAmount);
    }
    if (ui->stackedWidget->currentIndex() == 3) {
        if (game.getYear() == 1) {
            ui->CompanyTable->setRowCount(7);
            int year = game.getYear();
            ui->CompanyTable->setColumnCount(year);
            QStringList verticalHeader;
            verticalHeader.append("Глубоководный улов");
            verticalHeader.append("Прибрежный улов");
            verticalHeader.append("Цена за рыбу");
            verticalHeader.append("Объем продаж");
            verticalHeader.append("Процент");
            verticalHeader.append("Банк");
            verticalHeader.append("Флот");
            ui->CompanyTable->setVerticalHeaderLabels(verticalHeader);
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < year; j++) {
                    QTableWidgetItem *item;
                    item = new QTableWidgetItem(ui->YearTable->item(i, 0)->text());
                    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
                    ui->CompanyTable->setItem(i, j, item);
                }
            }
            for (int l = 0; l < game.getPlayersAmount(); l++) {
                comps[l].setRowCount(7);
                comps[l].setColumnCount(year);
                comps[l].setVerticalHeaderLabels(verticalHeader);
            }
            for (int l = 0; l < game.getPlayersAmount(); l++) {
                for (int j = 0; j < year; j++) {
                    for (int i = 0; i < 7; i++) {
                        QTableWidgetItem *item;
                        item = new QTableWidgetItem(ui->CompanyTable->item(i, j)->text());
                        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
                        comps[l].setItem(i, j, item);
                    }
                }
            }
            unsizeCompanies();
        } else {
            int year = game.getYear();
            ui->CompanyTable->setColumnCount(year);
            int act = getActiveCompany();
            for (int j = 0; j < game.getPlayersAmount(); j++) {
                for (int i = 0; i < 7; i++) {
                    QTableWidgetItem *item;
                    item = new QTableWidgetItem(ui->YearTable->item(i, j)->text());
                    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
                    comps[j].setItem(i, year - 1, item);
                }
            }
            for (int i = 0; i < 7; i++) {
                QTableWidgetItem *item;
                item = new QTableWidgetItem(ui->YearTable->item(i, act)->text());
                item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
                ui->CompanyTable->setItem(i, year - 1, item);
            }
        }
    }
}

void MainWindow::unsizeCompanies() {
    if (2 > game.getPlayersAmount())
        ui->company2->setFixedHeight(0);
    if (3 > game.getPlayersAmount())
        ui->company3->setFixedHeight(0);
    if (4 > game.getPlayersAmount())
        ui->company4->setFixedHeight(0);
    if (5 > game.getPlayersAmount())
        ui->company5->setFixedHeight(0);
    if (6 > game.getPlayersAmount())
        ui->company6->setFixedHeight(0);
}

void MainWindow::calc() {
//    updateCompany(getActiveCompany());
    game.setShips(ui->InputTable);
    if (!game.checkShipsOk()) {
        ui->checkMessage->setVisible(true);
        return;
    }
    ui->checkMessage->setVisible(false);
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);
    game.calcCatch(ui->InputTable, ui->WaterInfoTable);//1
    game.setCatch();//2
    game.endYear(ui->DealTable, ui->InputTable, ui->CompaniesInfoTable);
    game.updateWaterInfoTable(ui->InputTable, ui->WaterInfoTable);//1
    game.updateYearTable(ui->InputTable, ui->YearTable);
    game.updateCompsTable(ui->CompaniesInfoTable);
    int year = game.getYear();
    for (int j = 0; j < game.getPlayersAmount(); j++) {
        for (int i = 0; i < 7; i++) {
            comps[j].setColumnCount(year + 1);
            QTableWidgetItem *item;
            item = new QTableWidgetItem(ui->YearTable->item(i, j)->text());
            item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
            comps[j].setItem(i, year - 1, item);
        }
    }
}

void MainWindow::addDeal() {
    ui->DealTable->setRowCount(ui->DealTable->rowCount() + 1);
    for (int i = 0; i < 4; i++) {
        QSpinBox *spinbox = new QSpinBox;
        if (i <= 1) {
            spinbox->setMinimum(1);
            spinbox->setMaximum(game.getPlayersAmount());
        } else {
            spinbox->setMaximum(10000);
        }
        ui->DealTable->setCellWidget(ui->DealTable->rowCount() - 1, i, spinbox);
    }
}

void MainWindow::activeCompany() {
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString buttonText = buttonSender->text();
    QCharRef b = buttonText[buttonText.size() - 1];
    ui->company1->setFixedHeight(31);
    ui->company2->setFixedHeight(31);
    ui->company3->setFixedHeight(31);
    ui->company4->setFixedHeight(31);
    ui->company5->setFixedHeight(31);
    ui->company6->setFixedHeight(31);
    unsizeCompanies();
    if (b == '1') {
        ui->company1->setFixedHeight(41);
        //update table
    } else if (b == '2') {
        ui->company2->setFixedHeight(41);
    } else if (b == '3') {
        ui->company3->setFixedHeight(41);
    } else if (b == '4') {
        ui->company4->setFixedHeight(41);
    } else if (b == '5') {
        ui->company5->setFixedHeight(41);
    } else if (b == '6') {
        ui->company6->setFixedHeight(41);
    }
    int year = game.getYear();
    ui->CompanyTable->setColumnCount(year);
    int act = getActiveCompany();
    for (int j = 0; j < year; j++) {
        for (int i = 0; i < 7; i++) {
            QTableWidgetItem *item;
            item = new QTableWidgetItem(comps[act].item(i, j)->text());
            item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
            ui->CompanyTable->setItem(i, j, item);
        }
    }
}

void MainWindow::updateCompany(int n) {
    int year = game.getYear();
    for (int j = 0; j < year; j++) {
        for (int i = 0; i < 7; i++) {
            QTableWidgetItem *item;
            item = new QTableWidgetItem(ui->CompanyTable->item(i, j)->text());
            item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
            comps[n].setItem(i, j, item);
        }
    }
}

int MainWindow::getActiveCompany() {
    if (ui->company1->height() == 41)
        return 0;
    if (ui->company2->height() == 41)
        return 1;
    if (ui->company3->height() == 41)
        return 2;
    if (ui->company4->height() == 41)
        return 3;
    if (ui->company5->height() == 41)
        return 4;
    if (ui->company6->height() == 41)
        return 5;
}