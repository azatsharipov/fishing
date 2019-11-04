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
    if (isServer) {
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
                spinbox->setValue(8);
            connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(updateHarbor(int)));
        }
}

void MainWindow::updateHarbor(int value) {
    game.updateHarbor(ui->InputTable, ui->DealTable);
}

void MainWindow::start() {
    int playersAmount = (ui->spinBox->text()).toInt();
    if (!playersAmount)
        return;
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

void MainWindow::nextPage() {
    if (ui->stackedWidget->currentIndex() == 5) {
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
        if (isServer) {
            sendToClient();
        }
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
    if (!game.checkShipsOk(ui->InputTable, ui->DealTable)) {
        ui->checkMessage->setVisible(true);
        return;
    }
    ui->checkMessage->setVisible(false);
    if (!isGameOver)
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

void MainWindow::endGame() {
    nextPage();
//    isGameOver = true;
//    calc();
    drawGraphs();
}

void MainWindow::back() {
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);
}

void MainWindow::drawGraphs() {
    //Рисуем график y=x*x

    //Сгенерируем данные
    //Для этого создадим два массива точек:
    //один для созранения x координат точек,
    //а второй для y соответственно

    double a = 0; //Начало интервала, где рисуем график по оси Ox
    double b = game.getYear() - 1; //Конец интервала, где рисуем график по оси Ox
    double h = 1; //Шаг, с которым будем пробегать по оси Ox

    int playersAmount = game.getPlayersAmount();
    int N = (b - a) / h + 1; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x[playersAmount], y[playersAmount]; //Массивы координат точек
    //Вычисляем наши данные
    for (int j = 0; j < playersAmount; j++) {
        int i = 0;
        for (double X = a; X <= b; X += h) {
            x[j].push_back(X);
            y[j].push_back((double)(comps[j].item(5, i)->text()).toInt());
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
    if (playersAmount > 1) {
        ui->graph_2->addGraph();
        ui->graph_2->graph(0)->setData(x[1], y[1]);
        ui->graph_2->xAxis->setRange(a, b);//Для оси Ox
        ui->graph_2->setVisible(true);
        ui->graph2Name->setVisible(true);
    }
    if (playersAmount > 2) {
        ui->graph_3->addGraph();
        ui->graph_3->graph(0)->setData(x[2], y[2]);
        ui->graph_3->xAxis->setRange(a, b);//Для оси Ox
        ui->graph_3->setVisible(true);
        ui->graph3Name->setVisible(true);
    }
    if (playersAmount > 3) {
        ui->graph_4->addGraph();
        ui->graph_4->graph(0)->setData(x[3], y[3]);
        ui->graph_4->xAxis->setRange(a, b);//Для оси Ox
        ui->graph_4->setVisible(true);
        ui->graph4Name->setVisible(true);
    }
    if (playersAmount > 4) {
        ui->graph_5->addGraph();
        ui->graph_5->graph(0)->setData(x[4], y[4]);
        ui->graph_5->xAxis->setRange(a, b);//Для оси Ox
        ui->graph_5->setVisible(true);
        ui->graph5Name->setVisible(true);
    }
    if (playersAmount > 5) {
        ui->graph_6->addGraph();
        ui->graph_6->graph(0)->setData(x[5], y[5]);
        ui->graph_6->xAxis->setRange(a, b);//Для оси Ox
        ui->graph_6->setVisible(true);
        ui->graph6Name->setVisible(true);
    }
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

void MainWindow::startServer() {
    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newUser()));
    if (!tcpServer->listen(QHostAddress::Any, 33333) && serverStatus == 0) {
        qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(tcpServer->errorString());
    } else {
        serverStatus = 1;
        qDebug() << tcpServer->isListening() << "TCPSocket listen on port";
        qDebug() << QString::fromUtf8("Сервер запущен!");
    }
    nextPage();
    isServer = true;
    ui->usersAmount->setVisible(true);
}

void MainWindow::newUser() {
    qDebug() << QString::fromUtf8("У нас новое соединение!");
    QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
    int idusersocs = clientSocket->socketDescriptor();
    SClients[idusersocs] = clientSocket;
    connect(SClients[idusersocs],SIGNAL(readyRead()), this, SLOT(slotReadClient()));
    usersAmount++;
    ui->usersAmount->setText("Количество подключенных " + QString::number(SClients.size()));
}

void MainWindow::slotReadClient() {
    qDebug() << "getting info from client";
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_4_2);
    for (;;) {
        /*
        if (!m_nNextBlockSize) {
            if (pClientSocket->bytesAvailable() < sizeof(quint16)) {
                break;
            }
            in >> m_nNextBlockSize;
        }
        */
        if (pClientSocket->bytesAvailable() < m_nNextBlockSize) {
            break;
        }
        QString str;
        for (int i = 0; i < 6; i++)
            in >> str;

        QString strMessage = "Client has sended - " + str;
        qDebug() << strMessage;

        m_nNextBlockSize = 0;

    }
}

void MainWindow::joinToServer() {
    user = new QTcpSocket(this);
    user->connectToHost(QHostAddress::Any, 33333);
    connect(user, SIGNAL(connected()), SLOT(slotConnected()));
    connect(user, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    initUserInputTable();
//    connect(user, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
    ui->waitMessage->setVisible(true);
    ui->send->setVisible(false);
}

void MainWindow::sendToClient() {
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
//    out << quint16(0) << " ";

//    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    for (auto a : SClients) {
        a->write(arrBlock);
    }
}

void MainWindow::sendToServer() {
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    out << quint16(0) << " ";

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    user->write(arrBlock);
    ui->waitMessage->setVisible(true);
    ui->send->setVisible(false);
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
        in >> str;

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
    }
}
