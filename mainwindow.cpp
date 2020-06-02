#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>
#include <fstream>
#include <string>
#include <locale>
#include <QDebug>
#include <QFileDialog>
#include <QDesktopWidget>
#include <QScreen>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(6);

    int d_width = 1366;
    int d_height = 768;
//    setMinimumWidth(d_width);
//    setMinimumHeight(d_height);

    QRect avail(QDesktopWidget().availableGeometry());
    int width = avail.width();
    int height = avail.height();

    QRect geom(avail.x() + (avail.width() - width) / 2, avail.y() + (avail.height() - height) / 2, width, height);
    setGeometry(geom);

    double k_w = 1.0 * width / d_width;
    double k_h = 1.0 * height / d_height;
//    QList<QWidget *> widgets = ui->centralWidget::findChildren<QWidget *>();
    QList<QWidget *> widgets = ui->centralWidget->findChildren<QWidget *>();
//    QList<QWidget *> widgets = findChildren<QWidget *>();
    for (auto a : widgets) {
        qDebug() << a;
        qDebug() << k_w << k_h;
        a->setGeometry(int(a->x() * k_w), int(a->y() * k_h), int(a->width() * k_w), int(a->height() * k_h));
    }
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
    item = new QTableWidgetItem(QString::number(0));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(1, 0, item);
    item = new QTableWidgetItem(QString::number(0));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(2, 0, item);
    item = new QTableWidgetItem(QString::number(0));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(3, 0, item);
    item = new QTableWidgetItem(QString::number(0));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(4, 0, item);
    item = new QTableWidgetItem(QString::number(0));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(5, 0, item);
    item = new QTableWidgetItem(QString::number(0));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(6, 0, item);

    sp = (QSpinBox*) ui->InitInfoTable->cellWidget(5, 0);
    initFish = sp->value();
    item = new QTableWidgetItem(QString::number(initFish));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(0, 1, item);
    item = new QTableWidgetItem(QString::number(0));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(1, 1, item);
    item = new QTableWidgetItem(QString::number(0));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(2, 1, item);
    item = new QTableWidgetItem(QString::number(0));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(3, 1, item);
    item = new QTableWidgetItem(QString::number(0));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(4, 1, item);
    item = new QTableWidgetItem(QString::number(0));
    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
    ui->WaterInfoTable->setItem(5, 1, item);
    item = new QTableWidgetItem(QString::number(0));
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
        item = new QTableWidgetItem(QString::number(0));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(0, i, item);
        item = new QTableWidgetItem(QString::number(0));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(1, i, item);
        item = new QTableWidgetItem(QString::number(0));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(2, i, item);
        item = new QTableWidgetItem(QString::number(0));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(3, i, item);
        item = new QTableWidgetItem(QString::number(0));
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(4, i, item);
        item = new QTableWidgetItem(ui->CompaniesInfoTable->item(0, 1)->text());
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(5, i, item);
        item = new QTableWidgetItem(ui->CompaniesInfoTable->item(0, 2)->text());
        item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
        ui->YearTable->setItem(6, i, item);
    }
}

void MainWindow::initInputTableServer(int n) {
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
            spinbox->setMaximum(100000);
            if (i == 5)
                spinbox->setValue((ui->CompaniesInfoTable->item(0, 2)->text()).toInt());
            if (i != 0 && i != 1) {
                spinbox->setMaximum(spinbox->value());
                spinbox->setMinimum(spinbox->value());
            } else {
                connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(updateHarbor(int)));
            }
        }
}

void MainWindow::initInputTable(int n) {
    if (isServer) {
        initInputTableServer(n);
        return;
    }
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
            spinbox->setMaximum(100000);
            if (i == 5)
                spinbox->setValue((ui->CompaniesInfoTable->item(0, 2)->text()).toInt());
            connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(updateHarbor(int)));
        }
}

void MainWindow::updateHarbor(int value) {
    game.updateHarbor(ui->InputTable, ui->DealTable, serverStatus);
    if (serverStatus == 1)
        sendToClient();
}

void MainWindow::start() {
    int playersAmount = (ui->spinBox->text()).toInt();
    if (!playersAmount)
        return;
    QTableWidgetItem *item;

    ui->checkMessage->setVisible(false);
    gameName = ui->gameName->text() + ".txt";
    //  Init Info Table
    ui->InitInfoTable->setRowCount(6);
    ui->InitInfoTable->setColumnCount(1);
    QStringList horizontalHeader;
    horizontalHeader.append("");
    QStringList verticalHeader;
    verticalHeader.append(QString::fromUtf8("Компании"));
    verticalHeader.append(QString::fromUtf8("Корабли"));
    verticalHeader.append(QString::fromUtf8("Кораблей на компанию"));
    verticalHeader.append(QString::fromUtf8("Баланс на компанию"));
    verticalHeader.append(QString::fromUtf8("Глубоководная рыба"));
    verticalHeader.append(QString::fromUtf8("Прибрежная рыба"));
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
    spinbox->setMaximum(100000);
    spinbox->setValue(2500);
    ui->InitInfoTable->setCellWidget(4, 0, spinbox);
    spinbox = new QSpinBox;
    spinbox->setMaximum(100000);
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

void MainWindow::toGamePage() {
    if (isClient)
        ui->stackedWidget->setCurrentIndex(8);
    else
        ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::toGraphBalancePage() {
    if (isClient) {
        drawGraphsUser();
        ui->stackedWidget->setCurrentIndex(4);
        return;
    }
    if (!downloaded)
        updateCompsTables();
    drawGraphs();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::toGraphShipsPage() {
    if (isClient) {
        drawGraphsShipsUser();
        ui->stackedWidget->setCurrentIndex(5);
        return;
    }
    if (!downloaded)
        updateCompsTables();
    drawGraphShips();
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::toGraphPropertyPage() {
    if (isClient) {
        drawGraphsPropertyUser();
        ui->stackedWidget->setCurrentIndex(6);
        return;
    }
    if (!downloaded)
        updateCompsTables();
    drawGraphProperty();
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::nextPage() {
    if (ui->stackedWidget->currentIndex() == 7) {
        ui->stackedWidget->setCurrentIndex(0);
        ui->usersAmount->setVisible(false);
        return;
    }
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
        qDebug() << "ok1";
        ui->savedMessage->setVisible(false);
        int year = game.getYear();
        int ships = game.getShips();
        int lowerShips[] = {21, 32, 41, 46, 55, 68, 88, 110};
        int upperShips[] = {27, 35, 47, 57, 72, 98, 125, 125};
        int i = year;
        if (i > 8)
            i = 8;
        if (ships < lowerShips[i - 1])
            ui->recomend->setText(QString::fromUtf8("рекомендуется судов на аукцион: 5"));
        else if (ships > upperShips[i])
            ui->recomend->setText(QString::fromUtf8("рекомендуется судов на аукцион: 0"));
        else
            ui->recomend->setText(QString::fromUtf8("рекомендуется судов на аукцион: 2-4"));
        qDebug() << "ok2";
        if (year == 1) {
            qDebug() << "ok3";
            ui->CompanyTable->setRowCount(7);
            ui->CompanyTable->setColumnCount(year);
            QStringList verticalHeader;
            verticalHeader.append(QString::fromUtf8("Глубоководный улов"));
            verticalHeader.append(QString::fromUtf8("Прибрежный улов"));
            verticalHeader.append(QString::fromUtf8("Цена за рыбу"));
            verticalHeader.append(QString::fromUtf8("Объем продаж"));
            verticalHeader.append(QString::fromUtf8("Процент"));
            verticalHeader.append(QString::fromUtf8("Банк"));
            verticalHeader.append(QString::fromUtf8("Флот"));
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
            QStringList horizontalHeader;
            for (int i = 0; i < year; i++) {
                horizontalHeader.append(QString::number(i));
            }
            for (int k = 0; k < game.getPlayersAmount(); k++)
                ui->CompanyTable->setHorizontalHeaderLabels(horizontalHeader);
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
            qDebug() << "ok4";
            ui->CompanyTable->setColumnCount(year);
            qDebug() << "ok5";
            int act = getActiveCompany();
            for (int j = 0; j < game.getPlayersAmount(); j++) {
                for (int i = 0; i < 7; i++) {
                    QTableWidgetItem *item;
                    item = new QTableWidgetItem(ui->YearTable->item(i, j)->text());
                    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
                    comps[j].setItem(i, year - 1, item);
                }
            }
            qDebug() << "ok6";
            QStringList horizontalHeader;
            for (int i = 0; i < year; i++) {
                horizontalHeader.append(QString::number(i));
            }
            for (int k = 0; k < game.getPlayersAmount(); k++)
                ui->CompanyTable->setHorizontalHeaderLabels(horizontalHeader);
            qDebug() << "ok7";
            for (int i = 0; i < 7; i++) {
                qDebug() << i << year << ui->CompanyTable->rowCount() << ui->CompanyTable->columnCount();
                qDebug() << act << ui->YearTable->rowCount() << ui->YearTable->columnCount();
                QTableWidgetItem *item;
                item = new QTableWidgetItem(ui->YearTable->item(i, act)->text());
                item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
                ui->CompanyTable->setItem(i, year - 1, item);
            }
            qDebug() << "ok8";
        }
        if (isServer == true) {
            sendToClient();
        }
        qDebug() << "ok9";
    }
}

void MainWindow::unsizeCompanies() {
    if (2 > game.getPlayersAmount())
        ui->company2->setVisible(false);
    if (3 > game.getPlayersAmount())
        ui->company3->setVisible(false);
    if (4 > game.getPlayersAmount())
        ui->company4->setVisible(false);
    if (5 > game.getPlayersAmount())
        ui->company5->setVisible(false);
    if (6 > game.getPlayersAmount())
        ui->company6->setVisible(false);
}

void MainWindow::calc() {
//    updateCompany(getActiveCompany());
    game.setShips(ui->InputTable);
    if (!game.checkShipsOk(ui->InputTable, ui->DealTable)) {
        ui->checkMessage->setVisible(true);
        return;
    }
    ui->checkMessage->setVisible(false);
    if (!isGameOver)
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < game.getPlayersAmount(); j++) {
            QSpinBox *sp;
            sp = (QSpinBox*) ui->InputTable->cellWidget(i, j);
            sp->setMinimum(0);
            sp->setMaximum(10000);
        }
    }
    game.calcCatch(ui->InputTable, ui->WaterInfoTable);//1
    game.setCatch();//2
    game.endYear(ui->DealTable, ui->InputTable, ui->CompaniesInfoTable);
    game.updateWaterInfoTable(ui->InputTable, ui->WaterInfoTable);//1
    game.updateYearTable(ui->InputTable, ui->YearTable);
    game.updateCompsTable(ui->CompaniesInfoTable);
    if (serverStatus == 1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < game.getPlayersAmount(); j++) {
                QSpinBox *sp;
                sp = (QSpinBox*) ui->InputTable->cellWidget(i, j);
                int val = sp->value();
                if (i != 0 && i != 1) {
                    sp->setMinimum(val);
                    sp->setMaximum(val);
                }
            }
        }
    }
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

void MainWindow::updateCompsTables() {
    int year = game.getYear();
    for (int j = 0; j < game.getPlayersAmount(); j++) {
        for (int i = 0; i < 7; i++) {
            comps[j].setColumnCount(year + 1);
            QTableWidgetItem *item;
            item = new QTableWidgetItem(ui->YearTable->item(i, j)->text());
            item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
            comps[j].setItem(i, year, item);
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
            spinbox->setMaximum(100000);
        }
        ui->DealTable->setCellWidget(ui->DealTable->rowCount() - 1, i, spinbox);
        connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(updateHarbor(int)));
    }
}

void MainWindow::activeCompany() {
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString buttonText = buttonSender->text();
    QCharRef b = buttonText[buttonText.size() - 1];
    int mi = ui->company1->height();
    if (mi > ui->company2->height())
        mi = ui->company2->height();
    if (mi > ui->company3->height())
        mi = ui->company3->height();
    if (mi > ui->company4->height())
        mi = ui->company4->height();
    if (mi > ui->company5->height())
        mi = ui->company5->height();
    if (mi > ui->company6->height())
        mi = ui->company6->height();
    int ma = ui->company1->height();
    if (ma < ui->company2->height())
        ma = ui->company2->height();
    if (ma < ui->company3->height())
        ma = ui->company3->height();
    if (ma < ui->company4->height())
        ma = ui->company4->height();
    if (ma < ui->company5->height())
        ma = ui->company5->height();
    if (ma < ui->company6->height())
        ma = ui->company6->height();
    ui->company1->setFixedHeight(mi);
    ui->company2->setFixedHeight(mi);
    ui->company3->setFixedHeight(mi);
    ui->company4->setFixedHeight(mi);
    ui->company5->setFixedHeight(mi);
    ui->company6->setFixedHeight(mi);
    unsizeCompanies();
    if (b == '1') {
        ui->company1->setFixedHeight(ma);
        activedCompany = 0;
        //update table
    } else if (b == '2') {
        ui->company2->setFixedHeight(ma);
        activedCompany = 1;
    } else if (b == '3') {
        ui->company3->setFixedHeight(ma);
        activedCompany = 2;
    } else if (b == '4') {
        ui->company4->setFixedHeight(ma);
        activedCompany = 3;
    } else if (b == '5') {
        ui->company5->setFixedHeight(ma);
        activedCompany = 4;
    } else if (b == '6') {
        ui->company6->setFixedHeight(ma);
        activedCompany = 5;
    }
    int year;
    if (!downloaded)
        year = game.getYear();
    else
        year = this->year;
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
    return activedCompany;
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

void MainWindow::endGame() {
    nextPage();
//    isGameOver = true;
//    calc();
    drawGraphs();
}

void MainWindow::back() {
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);
}

void MainWindow::saveGame() {
    /*
     * playersAmount
     * years
     * InitInfoTable ?
     * WaterInfoTable ?
     * CompaniesInfoTable ?
     * YearTable ?
     * CompanyTable ?
     * comps[n]
    */
    QFile *f1 = new QFile(gameName);
//    QDir dir("/games");
//    f1->setFileName(dir.absoluteFilePath(gameName));
    f1->open(QFile::WriteOnly); // открываем файл
    QDataStream out(f1);

    int playersAmount = game.getPlayersAmount();
    out << playersAmount;

    int year = game.getYear();
    out << year;

    for (int k = 0; k < playersAmount; k++) {
        for (int j = 0; j < year; j++) {
            for (int i = 0; i < 7; i++) {
                qDebug() << "saved" << k << i << j;
                QTableWidgetItem *item;
                item = comps[k].item(i, j);
                QString itemstr = item->text();
                out << itemstr;
            }
        }
    }

    f1->close(); // закрываем файл
    ui->savedMessage->setVisible(true);
}

void MainWindow::downloadGame() {
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    qDebug() << str;
    QFile *f1 = new QFile(str);
    f1->open(QFile::ReadOnly); // открываем файл
    QDataStream in(f1);

    int playersAmount = 1;
    in >> playersAmount;
    qDebug() << "downloaded" << playersAmount;
    this->playersAmount = playersAmount;

    if (playersAmount < 2)
        ui->company2->setVisible(false);
    if (playersAmount < 3)
        ui->company3->setVisible(false);
    if (playersAmount < 4)
        ui->company4->setVisible(false);
    if (playersAmount < 5)
        ui->company5->setVisible(false);
    if (playersAmount < 6)
        ui->company6->setVisible(false);
    int year = 1;
    in >> year;
    this->year = year;
    qDebug() << "downloaded" << year;

    // set headers
    ui->CompanyTable->setRowCount(7);
    ui->CompanyTable->setColumnCount(year);
    QStringList verticalHeader;
    verticalHeader.append(QString::fromUtf8("Глубоководный улов"));
    verticalHeader.append(QString::fromUtf8("Прибрежный улов"));
    verticalHeader.append(QString::fromUtf8("Цена за рыбу"));
    verticalHeader.append(QString::fromUtf8("Объем продаж"));
    verticalHeader.append(QString::fromUtf8("Процент"));
    verticalHeader.append(QString::fromUtf8("Банк"));
    verticalHeader.append(QString::fromUtf8("Флот"));
    ui->CompanyTable->setVerticalHeaderLabels(verticalHeader);
    for (int l = 0; l < playersAmount; l++) {
        comps[l].setRowCount(7);
        comps[l].setColumnCount(year);
        comps[l].setVerticalHeaderLabels(verticalHeader);
    }
    QStringList horizontalHeader;
    for (int i = 0; i < year; i++) {
        horizontalHeader.append(QString::number(i));
    }
    for (int k = 0; k < playersAmount; k++)
        ui->CompanyTable->setHorizontalHeaderLabels(horizontalHeader);

    for (int k = 0; k < playersAmount; k++) {
        for (int j = 0; j < year; j++) {
            for (int i = 0; i < 7; i++) {
                QTableWidgetItem *item;
                QString itemstr;
                in >> itemstr;

                item = comps[k].item(i, j);
                item = new QTableWidgetItem(itemstr);
                item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
                comps[k].setItem(i, j, item);
                if (k == 0) {
                    item = new QTableWidgetItem(itemstr);
                    item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
                    ui->CompanyTable->setItem(i, j, item);
                }
            }
        }
    }
    unsizeCompanies();
    downloaded = true;
    ui->checkMessage->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_16->setVisible(false);
    ui->addButton->setVisible(false);
    ui->recomend->setVisible(false);
    ui->savedMessage->setVisible(false);
    ui->hideYearTable->setVisible(false);
    ui->YearTable->setVisible(false);
    ui->DealTable->setVisible(false);
    ui->InputTable->setVisible(false);
    toGamePage();

    f1->close(); // закрываем файл
}

void MainWindow::hideWaterInfoTable() {
    ui->WaterInfoTable->setVisible(!ui->WaterInfoTable->isVisible());
}

void MainWindow::hideYearTable() {
    ui->YearTable->setVisible(!ui->YearTable->isVisible());
}

void MainWindow::drawGraphs() {
    //Рисуем график y=x*x

    //Сгенерируем данные
    //Для этого создадим два массива точек:
    //один для созранения x координат точек,
    //а второй для y соответственно

    int year;
    if (!downloaded)
        year = game.getYear();
    else
        year = this->year;
    double a = 0; //Начало интервала, где рисуем график по оси Ox
    double b = year - 1; //Конец интервала, где рисуем график по оси Ox
    double h = 1; //Шаг, с которым будем пробегать по оси Ox

    int playersAmount;
    if (!downloaded)
        playersAmount = game.getPlayersAmount();
    else
        playersAmount = this->playersAmount;
    int N = (b - a) / h + 1; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x[playersAmount], y[playersAmount]; //Массивы координат точек
    //Вычисляем наши данные
    for (int j = 0; j < playersAmount; j++) {
        int i = 0;
        for (double X = a; X <= b; X += h) {
            x[j].push_back(X);
            y[j].push_back((double)(comps[j].item(5, i)->text()).toInt());
            qDebug() << "i =" << i << "j =" << j;
            i++;
        }
    }
    ui->graph->clearGraphs();//Если нужно, но очищаем все графики
    ui->graph_2->clearGraphs();//Если нужно, но очищаем все графики
    ui->graph_3->clearGraphs();//Если нужно, но очищаем все графики
    ui->graph_4->clearGraphs();//Если нужно, но очищаем все графики
    ui->graph_5->clearGraphs();//Если нужно, но очищаем все графики
    ui->graph_6->clearGraphs();//Если нужно, но очищаем все графики
    //Добавляем один график в widget
//    ui->graph->addGraph();
    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    double minY = y[0][0], maxY = y[0][0];
    for (int j = 0; j < playersAmount; j++) {
        for (int i = 1; i < N; i++) {
            if (y[j][i] < minY)
                minY = y[j][i];
            if (y[j][i] > maxY)
                maxY = y[j][i];
        }
    }
    ui->graph_2->setVisible(false);
    ui->graph_3->setVisible(false);
    ui->graph_4->setVisible(false);
    ui->graph_5->setVisible(false);
    ui->graph_6->setVisible(false);
    ui->graph2Name->setVisible(false);
    ui->graph3Name->setVisible(false);
    ui->graph4Name->setVisible(false);
    ui->graph5Name->setVisible(false);
    ui->graph6Name->setVisible(false);
    ui->graph->addGraph();
    ui->graph->graph(0)->setData(x[0], y[0]);

    ui->graph->xAxis->setRange(a, b);//Для оси Ox
    ui->graph->xAxis->setLabel(QString::fromUtf8("год"));
    ui->graph->yAxis->setLabel(QString::fromUtf8("баланс"));
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (int i = 0; i < year; i++) {
        textTicker->addTick(i, QString::number(i));
    }
    ui->graph->xAxis->setTicker(textTicker);
    if (playersAmount > 1) {
        ui->graph_2->addGraph();
        ui->graph_2->graph(0)->setData(x[1], y[1]);
        ui->graph_2->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graph_2->yAxis->setLabel(QString::fromUtf8("баланс"));
        ui->graph_2->xAxis->setRange(a, b);//Для оси Ox
        ui->graph_2->setVisible(true);
        ui->graph2Name->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graph_2->xAxis->setTicker(textTicker);
    }
    if (playersAmount > 2) {
        ui->graph_3->addGraph();
        ui->graph_3->graph(0)->setData(x[2], y[2]);
        ui->graph_3->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graph_3->yAxis->setLabel(QString::fromUtf8("баланс"));
        ui->graph_3->xAxis->setRange(a, b);//Для оси Ox
        ui->graph_3->setVisible(true);
        ui->graph3Name->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graph_3->xAxis->setTicker(textTicker);
    }
    if (playersAmount > 3) {
        ui->graph_4->addGraph();
        ui->graph_4->graph(0)->setData(x[3], y[3]);
        ui->graph_4->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graph_4->yAxis->setLabel(QString::fromUtf8("баланс"));
        ui->graph_4->xAxis->setRange(a, b);//Для оси Ox
        ui->graph_4->setVisible(true);
        ui->graph4Name->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graph_4->xAxis->setTicker(textTicker);
    }
    if (playersAmount > 4) {
        ui->graph_5->addGraph();
        ui->graph_5->graph(0)->setData(x[4], y[4]);
        ui->graph_5->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graph_5->yAxis->setLabel(QString::fromUtf8("баланс"));
        ui->graph_5->xAxis->setRange(a, b);//Для оси Ox
        ui->graph_5->setVisible(true);
        ui->graph5Name->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graph_5->xAxis->setTicker(textTicker);
    }
    if (playersAmount > 5) {
        ui->graph_6->addGraph();
        ui->graph_6->graph(0)->setData(x[5], y[5]);
        ui->graph_6->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graph_6->yAxis->setLabel(QString::fromUtf8("баланс"));
        ui->graph_6->xAxis->setRange(a, b);//Для оси Ox
        ui->graph_6->setVisible(true);
        ui->graph6Name->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graph_6->xAxis->setTicker(textTicker);
    }
    ui->graph->xAxis->setTicker(textTicker);
    ui->graph->yAxis->setRange(minY, maxY);//Для оси Oy
    ui->graph_2->yAxis->setRange(minY, maxY);//Для оси Oy
    ui->graph_3->yAxis->setRange(minY, maxY);//Для оси Oy
    ui->graph_4->yAxis->setRange(minY, maxY);//Для оси Oy
    ui->graph_5->yAxis->setRange(minY, maxY);//Для оси Oy
    ui->graph_6->yAxis->setRange(minY, maxY);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->graph->replot();
    ui->graph_2->replot();
    ui->graph_3->replot();
    ui->graph_4->replot();
    ui->graph_5->replot();
    ui->graph_6->replot();
}

void MainWindow::drawGraphShips() {
    //Рисуем график y=x*x

    //Сгенерируем данные
    //Для этого создадим два массива точек:
    //один для созранения x координат точек,
    //а второй для y соответственно

    int year;
    if (!downloaded)
        year = game.getYear();
    else
        year = this->year;
    double a = 0; //Начало интервала, где рисуем график по оси Ox
    double b = year - 1; //Конец интервала, где рисуем график по оси Ox
    double h = 1; //Шаг, с которым будем пробегать по оси Ox

    int playersAmount;
    if (!downloaded)
        playersAmount = game.getPlayersAmount();
    else
        playersAmount = this->playersAmount;
    int N = (b - a) / h + 1; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x[playersAmount], y[playersAmount]; //Массивы координат точек
    //Вычисляем наши данные
    for (int j = 0; j < playersAmount; j++) {
        int i = 0;
        for (double X = a; X <= b; X += h) {
            x[j].push_back(X);
            y[j].push_back((double)(comps[j].item(6, i)->text()).toInt());
            i++;
        }
    }
    ui->graphShips_1->clearGraphs();//Если нужно, но очищаем все графики
    ui->graphShips_2->clearGraphs();//Если нужно, но очищаем все графики
    ui->graphShips_2->clearGraphs();//Если нужно, но очищаем все графики
    ui->graphShips_4->clearGraphs();//Если нужно, но очищаем все графики
    ui->graphShips_5->clearGraphs();//Если нужно, но очищаем все графики
    ui->graphShips_6->clearGraphs();//Если нужно, но очищаем все графики
    //Добавляем один график в widget
//    ui->graph->addGraph();
    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    double minY = y[0][0], maxY = y[0][0];
    for (int j = 0; j < playersAmount; j++) {
        for (int i = 1; i < N; i++) {
            if (y[j][i] < minY)
                minY = y[j][i];
            if (y[j][i] > maxY)
                maxY = y[j][i];
        }
    }
    ui->graphShips_2->setVisible(false);
    ui->graphShips_3->setVisible(false);
    ui->graphShips_4->setVisible(false);
    ui->graphShips_5->setVisible(false);
    ui->graphShips_6->setVisible(false);
    ui->graph2Name_2->setVisible(false);
    ui->graph3Name_2->setVisible(false);
    ui->graph4Name_2->setVisible(false);
    ui->graph5Name_2->setVisible(false);
    ui->graph6Name_2->setVisible(false);
    ui->graphShips_1->addGraph();
    ui->graphShips_1->graph(0)->setData(x[0], y[0]);
    ui->graphShips_1->xAxis->setLabel(QString::fromUtf8("год"));
    ui->graphShips_1->yAxis->setLabel(QString::fromUtf8("суда"));
    ui->graphShips_1->xAxis->setRange(a, b);//Для оси Ox
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (int i = 0; i < year; i++) {
        textTicker->addTick(i, QString::number(i));
    }
    ui->graphShips_1->xAxis->setTicker(textTicker);
    QSharedPointer<QCPAxisTickerText> textTicker2(new QCPAxisTickerText);
    int tmp = (maxY - minY) / 15 + 1;
    for (int i = (int)minY - 1; i <= (int)maxY + 1; i += tmp) {
        textTicker2->addTick(i, QString::number(i));
    }
    ui->graphShips_1->yAxis->setTicker(textTicker2);
    if (playersAmount > 1) {
        ui->graphShips_2->addGraph();
        ui->graphShips_2->graph(0)->setData(x[1], y[1]);
        ui->graphShips_2->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graphShips_2->yAxis->setLabel(QString::fromUtf8("суда"));
        ui->graphShips_2->xAxis->setRange(a, b);//Для оси Ox
        ui->graphShips_2->setVisible(true);
        ui->graph2Name_2->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graphShips_2->xAxis->setTicker(textTicker);
        QSharedPointer<QCPAxisTickerText> textTicker2(new QCPAxisTickerText);
        for (int i = (int)minY - 1; i <= (int)maxY + 1; i += tmp) {
            textTicker2->addTick(i, QString::number(i));
        }
        ui->graphShips_2->yAxis->setTicker(textTicker2);
    }
    if (playersAmount > 2) {
        ui->graphShips_3->addGraph();
        ui->graphShips_3->graph(0)->setData(x[2], y[2]);
        ui->graphShips_3->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graphShips_3->yAxis->setLabel(QString::fromUtf8("суда"));
        ui->graphShips_3->xAxis->setRange(a, b);//Для оси Ox
        ui->graphShips_3->setVisible(true);
        ui->graph3Name_2->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graphShips_3->xAxis->setTicker(textTicker);
        QSharedPointer<QCPAxisTickerText> textTicker2(new QCPAxisTickerText);
        for (int i = (int)minY - 1; i <= (int)maxY + 1; i += tmp) {
            textTicker2->addTick(i, QString::number(i));
        }
        ui->graphShips_3->yAxis->setTicker(textTicker2);
    }
    if (playersAmount > 3) {
        ui->graphShips_4->addGraph();
        ui->graphShips_4->graph(0)->setData(x[3], y[3]);
        ui->graphShips_4->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graphShips_4->yAxis->setLabel(QString::fromUtf8("суда"));
        ui->graphShips_4->xAxis->setRange(a, b);//Для оси Ox
        ui->graphShips_4->setVisible(true);
        ui->graph4Name_2->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graphShips_4->xAxis->setTicker(textTicker);
        QSharedPointer<QCPAxisTickerText> textTicker2(new QCPAxisTickerText);
        for (int i = (int)minY - 1; i <= (int)maxY + 1; i += tmp) {
            textTicker2->addTick(i, QString::number(i));
        }
        ui->graphShips_4->yAxis->setTicker(textTicker2);
    }
    if (playersAmount > 4) {
        ui->graphShips_5->addGraph();
        ui->graphShips_5->graph(0)->setData(x[4], y[4]);
        ui->graphShips_5->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graphShips_5->yAxis->setLabel(QString::fromUtf8("суда"));
        ui->graphShips_5->xAxis->setRange(a, b);//Для оси Ox
        ui->graphShips_5->setVisible(true);
        ui->graph5Name_2->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graphShips_5->xAxis->setTicker(textTicker);
        QSharedPointer<QCPAxisTickerText> textTicker2(new QCPAxisTickerText);
        for (int i = (int)minY - 1; i <= (int)maxY + 1; i += tmp) {
            textTicker2->addTick(i, QString::number(i));
        }
        ui->graphShips_5->yAxis->setTicker(textTicker2);
    }
    if (playersAmount > 5) {
        ui->graphShips_6->addGraph();
        ui->graphShips_6->graph(0)->setData(x[5], y[5]);
        ui->graphShips_6->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graphShips_6->yAxis->setLabel(QString::fromUtf8("суда"));
        ui->graphShips_6->xAxis->setRange(a, b);//Для оси Ox
        ui->graphShips_6->setVisible(true);
        ui->graph6Name_2->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graphShips_6->xAxis->setTicker(textTicker);
        QSharedPointer<QCPAxisTickerText> textTicker2(new QCPAxisTickerText);
        for (int i = (int)minY - 1; i <= (int)maxY + 1; i += tmp) {
            textTicker2->addTick(i, QString::number(i));
        }
        ui->graphShips_6->yAxis->setTicker(textTicker2);
    }
    ui->graphShips_1->yAxis->setRange(minY - 1, maxY + 1);//Для оси Oy
    ui->graphShips_2->yAxis->setRange(minY - 1, maxY + 1);//Для оси Oy
    ui->graphShips_3->yAxis->setRange(minY - 1, maxY + 1);//Для оси Oy
    ui->graphShips_4->yAxis->setRange(minY - 1, maxY + 1);//Для оси Oy
    ui->graphShips_5->yAxis->setRange(minY - 1, maxY + 1);//Для оси Oy
    ui->graphShips_6->yAxis->setRange(minY - 1, maxY + 1);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->graphShips_1->replot();
    ui->graphShips_2->replot();
    ui->graphShips_3->replot();
    ui->graphShips_4->replot();
    ui->graphShips_5->replot();
    ui->graphShips_6->replot();
}

void MainWindow::drawGraphProperty() {
    //Рисуем график y=x*x

    //Сгенерируем данные
    //Для этого создадим два массива точек:
    //один для созранения x координат точек,
    //а второй для y соответственно

    int year;
    if (!downloaded)
        year = game.getYear();
    else
        year = this->year;
    double a = 0; //Начало интервала, где рисуем график по оси Ox
    double b = year - 1; //Конец интервала, где рисуем график по оси Ox
    double h = 1; //Шаг, с которым будем пробегать по оси Ox

    int playersAmount;
    if (!downloaded)
        playersAmount = game.getPlayersAmount();
    else
        playersAmount = this->playersAmount;
    int N = (b - a) / h + 1; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x[playersAmount], y[playersAmount]; //Массивы координат точек
    //Вычисляем наши данные
    for (int j = 0; j < playersAmount; j++) {
        int i = 0;
        for (double X = a; X <= b; X += h) {
            x[j].push_back(X);
            y[j].push_back((double)(comps[j].item(6, i)->text()).toInt() * 250 + (double)(comps[j].item(5, i)->text()).toInt());
            i++;
        }
    }
    ui->graphProperty_1->clearGraphs();//Если нужно, но очищаем все графики
    ui->graphProperty_2->clearGraphs();//Если нужно, но очищаем все графики
    ui->graphProperty_3->clearGraphs();//Если нужно, но очищаем все графики
    ui->graphProperty_4->clearGraphs();//Если нужно, но очищаем все графики
    ui->graphProperty_5->clearGraphs();//Если нужно, но очищаем все графики
    ui->graphProperty_6->clearGraphs();//Если нужно, но очищаем все графики
    //Добавляем один график в widget
//    ui->graph->addGraph();
    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    double minY = y[0][0], maxY = y[0][0];
    for (int j = 0; j < playersAmount; j++) {
        for (int i = 1; i < N; i++) {
            if (y[j][i] < minY)
                minY = y[j][i];
            if (y[j][i] > maxY)
                maxY = y[j][i];
        }
    }
    ui->graphProperty_2->setVisible(false);
    ui->graphProperty_3->setVisible(false);
    ui->graphProperty_4->setVisible(false);
    ui->graphProperty_5->setVisible(false);
    ui->graphProperty_6->setVisible(false);
    ui->graph2Name_3->setVisible(false);
    ui->graph3Name_3->setVisible(false);
    ui->graph4Name_3->setVisible(false);
    ui->graph5Name_3->setVisible(false);
    ui->graph6Name_3->setVisible(false);
    ui->graphProperty_1->addGraph();
    ui->graphProperty_1->graph(0)->setData(x[0], y[0]);
    ui->graphProperty_1->xAxis->setLabel(QString::fromUtf8("год"));
    ui->graphProperty_1->yAxis->setLabel(QString::fromUtf8("имущество"));
    ui->graphProperty_1->xAxis->setRange(a, b);//Для оси Ox
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (int i = 0; i < year; i++) {
        textTicker->addTick(i, QString::number(i));
    }
    ui->graphProperty_1->xAxis->setTicker(textTicker);
    if (playersAmount > 1) {
        ui->graphProperty_2->addGraph();
        ui->graphProperty_2->graph(0)->setData(x[1], y[1]);
        ui->graphProperty_2->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graphProperty_2->yAxis->setLabel(QString::fromUtf8("имущество"));
        ui->graphProperty_2->xAxis->setRange(a, b);//Для оси Ox
        ui->graphProperty_2->setVisible(true);
        ui->graph2Name_3->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graphProperty_2->xAxis->setTicker(textTicker);
    }
    if (playersAmount > 2) {
        ui->graphProperty_3->addGraph();
        ui->graphProperty_3->graph(0)->setData(x[2], y[2]);
        ui->graphProperty_3->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graphProperty_3->yAxis->setLabel(QString::fromUtf8("имущество"));
        ui->graphProperty_3->xAxis->setRange(a, b);//Для оси Ox
        ui->graphProperty_3->setVisible(true);
        ui->graph3Name_3->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graphProperty_3->xAxis->setTicker(textTicker);
    }
    if (playersAmount > 3) {
        ui->graphProperty_4->addGraph();
        ui->graphProperty_4->graph(0)->setData(x[3], y[3]);
        ui->graphProperty_4->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graphProperty_4->yAxis->setLabel(QString::fromUtf8("имущество"));
        ui->graphProperty_4->xAxis->setRange(a, b);//Для оси Ox
        ui->graphProperty_4->setVisible(true);
        ui->graph4Name_3->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graphProperty_4->xAxis->setTicker(textTicker);
    }
    if (playersAmount > 4) {
        ui->graphProperty_5->addGraph();
        ui->graphProperty_5->graph(0)->setData(x[4], y[4]);
        ui->graphProperty_5->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graphProperty_5->yAxis->setLabel(QString::fromUtf8("имущество"));
        ui->graphProperty_5->xAxis->setRange(a, b);//Для оси Ox
        ui->graphProperty_5->setVisible(true);
        ui->graph5Name_3->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graphProperty_5->xAxis->setTicker(textTicker);
    }
    if (playersAmount > 5) {
        ui->graphProperty_6->addGraph();
        ui->graphProperty_6->graph(0)->setData(x[5], y[5]);
        ui->graphProperty_6->xAxis->setLabel(QString::fromUtf8("год"));
        ui->graphProperty_6->yAxis->setLabel(QString::fromUtf8("имущество"));
        ui->graphProperty_6->xAxis->setRange(a, b);//Для оси Ox
        ui->graphProperty_6->setVisible(true);
        ui->graph6Name_3->setVisible(true);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        for (int i = 0; i < year; i++) {
            textTicker->addTick(i, QString::number(i));
        }
        ui->graphProperty_6->xAxis->setTicker(textTicker);
    }
    ui->graphProperty_1->yAxis->setRange(minY, maxY);//Для оси Oy
    ui->graphProperty_2->yAxis->setRange(minY, maxY);//Для оси Oy
    ui->graphProperty_3->yAxis->setRange(minY, maxY);//Для оси Oy
    ui->graphProperty_4->yAxis->setRange(minY, maxY);//Для оси Oy
    ui->graphProperty_5->yAxis->setRange(minY, maxY);//Для оси Oy
    ui->graphProperty_6->yAxis->setRange(minY, maxY);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->graphProperty_1->replot();
    ui->graphProperty_2->replot();
    ui->graphProperty_3->replot();
    ui->graphProperty_4->replot();
    ui->graphProperty_5->replot();
    ui->graphProperty_6->replot();
}

void MainWindow::startServer() {
    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newUser()));
    if (!tcpServer->listen(QHostAddress::Any, 33333) && serverStatus == 0) {
        ui->usersAmount->setText(QString::fromUtf8("Порт занят. Перезайдите в игру."));
        qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(tcpServer->errorString());
    } else {
        serverStatus = 1;
        qDebug() << tcpServer->isListening() << "TCPSocket listen on port";
        qDebug() << QString::fromUtf8("Server started!");
    }
    nextPage();
    isServer = true;
    ui->usersAmount->setVisible(true);
    ui->spinBox->setMaximum(0);
}

void MainWindow::newUser() {
    qDebug() << QString::fromUtf8("New user");
    QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
    int idusersocs = clientSocket->socketDescriptor();
    qDebug() << clientSocket << idusersocs;
    SClients[idusersocs] = clientSocket;
    connect(SClients[idusersocs],SIGNAL(readyRead()), this, SLOT(slotReadClient()));
    ids[usersAmount] = idusersocs;
    usersAmount++;
    ui->usersAmount->setText(QString::fromUtf8("Количество подключенных: ") + QString::number(SClients.size()));
    ui->spinBox->setMinimum(usersAmount);
    ui->spinBox->setMaximum(usersAmount);

}

void MainWindow::slotReadClient() {
    qDebug() << "getting info from client";
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    quint16 idusersocs = pClientSocket->socketDescriptor();
    int playerNumber = 0;
    for (int i = 0; i < 6; i++)
        if (idusersocs == ids[i]) {
            playerNumber = i;
            break;
        }
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_4_2);
    for (;;) {
        if (!m_nNextBlockSize) {
            if (pClientSocket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }
        if (pClientSocket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }
        QString str;
        qint16 int16;
        for (int i = 0; i < 6; i++) {
            qDebug() << i;
            in >> int16;
            QSpinBox *sp;
            qDebug() << i;
            sp = (QSpinBox*)ui->InputTable->cellWidget(i, playerNumber);
            qDebug() << i;
            if (i != 0 && i != 1) {
                sp->setMaximum(int16);
                sp->setMinimum(int16);
                sp->setValue(int16);
            }
//            ui->InputTable->setCellWidget(0, i, sp);
        }

        QString strMessage = QString::fromUtf8("Client has sended - ") + str;
        qDebug() << strMessage;
        qDebug() << int16;
        qDebug() << m_nNextBlockSize;
        qDebug() << pClientSocket->bytesAvailable();

        m_nNextBlockSize = 0;

    }
}

void MainWindow::joinToServer() {
    user = new QTcpSocket(this);
    user->connectToHost(QHostAddress::Any, 33333);
    connect(user, SIGNAL(connected()), SLOT(slotConnected()));
    connect(user, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    initUserInputTable();
    isClient = true;
//    connect(user, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
    ui->waitMessage->setVisible(true);
    ui->send->setVisible(false);
}

void MainWindow::sendToClient() {
    for (int i = 0; i < game.getPlayersAmount(); i++) {
        QByteArray  arrBlock;
        QDataStream out(&arrBlock, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_2);
        out << quint16(0);

        out << quint16(i + 1);
        QSpinBox *sp;
        quint16 harbor;
        sp = (QSpinBox*) ui->InputTable->cellWidget(5, i);
        harbor = sp->value();
        out << harbor;

        for (int j = 0; j < game.getYear(); j++) {
            for (int k = 0; k < 7; k++) {
                QTableWidgetItem *item;
                item = comps[i].item(k, j);
                out << (QString)item->text();
            }
        }

        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16));
        QTcpSocket *clientSocket = SClients[ids[i]];
        clientSocket->write(arrBlock);
    }
}

void MainWindow::sendToServer() {
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);

    out << quint16(0);
    for (int i = 0; i < 6; i++) {
        QSpinBox *sp;
        quint16 harbor;
        sp = (QSpinBox*) ui->UserInputTable->cellWidget(i, 0);
        harbor = sp->value();
        out << quint16(harbor);
    }

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    qDebug() << arrBlock;

    user->write(arrBlock);
    ui->waitMessage->setVisible(true);
    ui->send->setVisible(false);
    for (int i = 0; i < ui->UserInputTable->rowCount(); i++) {
        QSpinBox *spinbox = new QSpinBox;
        ui->UserInputTable->setCellWidget(i, 0, spinbox);
        spinbox = (QSpinBox*) ui->UserInputTable->cellWidget(i, 0);
        spinbox->setMaximum(100000);
        spinbox->setValue(0);
        if (i == 5)
            spinbox->setValue(harborUser);
        if (i == 0 || i == 1)
            spinbox->setMaximum(0);
        spinbox->setValue(0);
        connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(updateHarborUser(int)));
    }
}

void MainWindow::slotReadyRead() {
    QDataStream in(user);
    in.setVersion(QDataStream::Qt_4_2);
    for (;;) {
        if (!m_nNextBlockSize) {
            if (user->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }

        if (user->bytesAvailable() < m_nNextBlockSize) {
            break;
        }
        QString str;
        quint16 int16;
        in >> int16;
        userNumber = int16;
        QStringList horizontalHeader;
        horizontalHeader.append(QString::number(userNumber));
        ui->UserInputTable->setHorizontalHeaderLabels(horizontalHeader);
        in >> int16;
        qDebug() << "userNumber:" << userNumber << "harborShip" << int16;
        harborUser = int16;
        QSpinBox *sp = new QSpinBox;
        quint16 noHarbor = 0;
        sp = (QSpinBox*) ui->UserInputTable->cellWidget(3, 0);
        noHarbor += sp->value();
        sp = (QSpinBox*) ui->UserInputTable->cellWidget(4, 0);
        noHarbor += sp->value();
        sp = (QSpinBox*) ui->UserInputTable->cellWidget(5, 0);
        harborUser -= noHarbor;
        shipsUser = int16;
        sp->setValue(harborUser);

        year++;
        comp.setColumnCount(year);
        comp.setRowCount(7);
        for (int j = 0; j < year; j++) {
            for (int k = 0; k < 7; k++) {
                QString str;
                in >> str;
                QTableWidgetItem *item;
                item = new QTableWidgetItem(str);
                item->setFlags(item->flags()^(Qt::ItemIsSelectable|Qt::ItemIsEditable));
                comp.setItem(k, j, item);
            }
        }

        qDebug() << "imp" << harborUser << shipsUser << noHarbor;
//        ui->UserInputTable->setCellWidget(5, 0, sp);

        m_nNextBlockSize = 0;
    }
    ui->waitMessage->setVisible(false);
    ui->send->setVisible(true);
}

void MainWindow::slotConnected() {
    qDebug() << "connected";
}

void MainWindow::initUserInputTable() {
    ui->UserInputTable->setColumnCount(1);
    QStringList horizontalHeader;
    horizontalHeader.append(QString::number(userNumber));
    ui->UserInputTable->setHorizontalHeaderLabels(horizontalHeader);
    for (int i = 0; i < ui->UserInputTable->rowCount(); i++) {
        QSpinBox *spinbox = new QSpinBox;
        ui->UserInputTable->setCellWidget(i, 0, spinbox);
        spinbox = (QSpinBox*) ui->UserInputTable->cellWidget(i, 0);
        spinbox->setMaximum(100000);
        if (i == 0 || i == 1)
            spinbox->setMaximum(0);
        spinbox->setValue(0);
        connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(updateHarborUser(int)));
    }
}

void MainWindow::updateHarborUser(int v) {
    int noHarbor = 0;
    QSpinBox *sp = new QSpinBox;
    sp = (QSpinBox*)ui->UserInputTable->cellWidget(3, 0);
    noHarbor += sp->value();
    int deepShip = sp->value();
    sp = (QSpinBox*)ui->UserInputTable->cellWidget(4, 0);
    noHarbor += sp->value();
    int coastalShip = sp->value();
    sp = (QSpinBox*)ui->UserInputTable->cellWidget(5, 0);
    qDebug() << shipsUser << noHarbor;
    sp->setValue(shipsUser - noHarbor);
    sp = (QSpinBox*)ui->UserInputTable->cellWidget(3, 0);
    sp->setMaximum(shipsUser - coastalShip);
    sp = (QSpinBox*)ui->UserInputTable->cellWidget(4, 0);
    sp->setMaximum(shipsUser - deepShip);
//    ui->UserInputTable->setCellWidget(5, 0, sp);
}

void MainWindow::drawGraphsUser() {
    double a = 0; //Начало интервала, где рисуем график по оси Ox
    double b = year - 1; //Конец интервала, где рисуем график по оси Ox
    double h = 1; //Шаг, с которым будем пробегать по оси Ox

    int playersAmount = 1;
    int N = (b - a) / h + 1; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x[playersAmount], y[playersAmount]; //Массивы координат точек
    //Вычисляем наши данные
    for (int j = 0; j < playersAmount; j++) {
        int i = 0;
        for (double X = a; X <= b; X += h) {
            x[j].push_back(X);
            y[j].push_back((double)(comp.item(5, i)->text()).toInt());
            qDebug() << "i =" << i << "j =" << j;
            i++;
        }
    }
    ui->graph_2->setVisible(false);
    ui->graph_3->setVisible(false);
    ui->graph_4->setVisible(false);
    ui->graph_5->setVisible(false);
    ui->graph_6->setVisible(false);
    ui->graph2Name->setVisible(false);
    ui->graph3Name->setVisible(false);
    ui->graph4Name->setVisible(false);
    ui->graph5Name->setVisible(false);
    ui->graph6Name->setVisible(false);
    ui->graph->clearGraphs();//Если нужно, но очищаем все графики

    double minY = y[0][0], maxY = y[0][0];
    for (int j = 0; j < playersAmount; j++) {
        for (int i = 1; i < N; i++) {
            if (y[j][i] < minY)
                minY = y[j][i];
            if (y[j][i] > maxY)
                maxY = y[j][i];
        }
    }

    ui->graph->addGraph();
    ui->graph->graph(0)->setData(x[0], y[0]);

    ui->graph->xAxis->setRange(a, b);//Для оси Ox
    ui->graph->xAxis->setLabel(QString::fromUtf8("год"));
    ui->graph->yAxis->setLabel(QString::fromUtf8("баланс"));
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (int i = 0; i < year; i++) {
        textTicker->addTick(i, QString::number(i));
    }
    ui->graph->xAxis->setTicker(textTicker);

    ui->graph->yAxis->setRange(minY - 1, maxY + 1);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->graph->replot();
}

void MainWindow::drawGraphsShipsUser() {
    double a = 0; //Начало интервала, где рисуем график по оси Ox
    double b = year - 1; //Конец интервала, где рисуем график по оси Ox
    double h = 1; //Шаг, с которым будем пробегать по оси Ox

    int playersAmount = 1;
    int N = (b - a) / h + 1; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x[playersAmount], y[playersAmount]; //Массивы координат точек
    //Вычисляем наши данные
    for (int j = 0; j < playersAmount; j++) {
        int i = 0;
        for (double X = a; X <= b; X += h) {
            x[j].push_back(X);
            y[j].push_back((double)(comp.item(6, i)->text()).toInt());
            i++;
        }
    }
    ui->graphShips_1->clearGraphs();//Если нужно, но очищаем все графики
    double minY = y[0][0], maxY = y[0][0];
    for (int j = 0; j < playersAmount; j++) {
        for (int i = 1; i < N; i++) {
            if (y[j][i] < minY)
                minY = y[j][i];
            if (y[j][i] > maxY)
                maxY = y[j][i];
        }
    }
    ui->graphShips_2->setVisible(false);
    ui->graphShips_3->setVisible(false);
    ui->graphShips_4->setVisible(false);
    ui->graphShips_5->setVisible(false);
    ui->graphShips_6->setVisible(false);
    ui->graph2Name_2->setVisible(false);
    ui->graph3Name_2->setVisible(false);
    ui->graph4Name_2->setVisible(false);
    ui->graph5Name_2->setVisible(false);
    ui->graph6Name_2->setVisible(false);
    ui->graphShips_1->addGraph();
    ui->graphShips_1->graph(0)->setData(x[0], y[0]);
    ui->graphShips_1->xAxis->setLabel(QString::fromUtf8("год"));
    ui->graphShips_1->yAxis->setLabel(QString::fromUtf8("суда"));
    ui->graphShips_1->xAxis->setRange(a, b);//Для оси Ox
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (int i = 0; i < year; i++) {
        textTicker->addTick(i, QString::number(i));
    }
    ui->graphShips_1->xAxis->setTicker(textTicker);
    QSharedPointer<QCPAxisTickerText> textTicker2(new QCPAxisTickerText);
    int tmp = (maxY - minY) / 15 + 1;
    for (int i = (int)minY - 1; i <= (int)maxY + 1; i += tmp) {
        textTicker2->addTick(i, QString::number(i));
    }
    ui->graphShips_1->yAxis->setTicker(textTicker2);

    ui->graphShips_1->yAxis->setRange(minY - 1, maxY + 1);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->graphShips_1->replot();
}

void MainWindow::drawGraphsPropertyUser() {
    double a = 0; //Начало интервала, где рисуем график по оси Ox
    double b = year - 1; //Конец интервала, где рисуем график по оси Ox
    double h = 1; //Шаг, с которым будем пробегать по оси Ox

    int playersAmount = 1;
    int N = (b - a) / h + 1; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x[playersAmount], y[playersAmount]; //Массивы координат точек
    //Вычисляем наши данные
    for (int j = 0; j < playersAmount; j++) {
        int i = 0;
        for (double X = a; X <= b; X += h) {
            x[j].push_back(X);
            y[j].push_back((double)(comp.item(6, i)->text()).toInt() * 250 + (double)(comp.item(5, i)->text()).toInt());
            i++;
        }
    }
    ui->graphProperty_2->setVisible(false);
    ui->graphProperty_3->setVisible(false);
    ui->graphProperty_4->setVisible(false);
    ui->graphProperty_5->setVisible(false);
    ui->graphProperty_6->setVisible(false);
    ui->graph2Name_3->setVisible(false);
    ui->graph3Name_3->setVisible(false);
    ui->graph4Name_3->setVisible(false);
    ui->graph5Name_3->setVisible(false);
    ui->graph6Name_3->setVisible(false);
    ui->graphProperty_1->clearGraphs();//Если нужно, но очищаем все графики
    double minY = y[0][0], maxY = y[0][0];
    for (int j = 0; j < playersAmount; j++) {
        for (int i = 1; i < N; i++) {
            if (y[j][i] < minY)
                minY = y[j][i];
            if (y[j][i] > maxY)
                maxY = y[j][i];
        }
    }
    ui->graphProperty_1->addGraph();
    ui->graphProperty_1->graph(0)->setData(x[0], y[0]);
    ui->graphProperty_1->xAxis->setLabel(QString::fromUtf8("год"));
    ui->graphProperty_1->yAxis->setLabel(QString::fromUtf8("имущество"));
    ui->graphProperty_1->xAxis->setRange(a, b);//Для оси Ox
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (int i = 0; i < year; i++) {
        textTicker->addTick(i, QString::number(i));
    }
    ui->graphProperty_1->xAxis->setTicker(textTicker);

    ui->graphProperty_1->yAxis->setRange(minY, maxY);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->graphProperty_1->replot();
}

