#include "Widgets/mainwindow.hpp"
#include "Widgets/gameboard.hpp"

#include <QTableView>
#include <QHeaderView>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    view(new QTableView)
{
    ui->setupUi(this);
    setCentralWidget(view);

    setWindowTitle(tr("Conway's Game of Life"));

    board = new GameBoard;

    view->setModel(board);

    auto vertHeader = new QHeaderView(Qt::Orientation::Vertical);
    vertHeader->setDefaultSectionSize(1);
    vertHeader->hide();

    auto horHeader = new QHeaderView(Qt::Orientation::Horizontal);
    horHeader->setDefaultSectionSize(1);
    horHeader->hide();

    view->setVerticalHeader(vertHeader);
    view->setHorizontalHeader(horHeader);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPlay_triggered()
{

}


void MainWindow::on_actionStop_triggered()
{

}


void MainWindow::on_actionRestart_triggered()
{

}


void MainWindow::on_actionSave_Pattern_triggered()
{

}


void MainWindow::on_actionClear_field_triggered()
{

}

