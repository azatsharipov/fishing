#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <game.h>

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
};

#endif // MAINWINDOW_H
