#include "Widgets/mainwindow.hpp"
#include "Widgets/gameboard.hpp"
#include "celldelegate.hpp"

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

    board = new GameBoardModel;

    view->setModel(board);

    auto vertHeader = new QHeaderView(Qt::Orientation::Vertical);
    vertHeader->setMinimumSectionSize(15);
    vertHeader->setMaximumSectionSize(15);
    vertHeader->setDefaultSectionSize(15);
    vertHeader->hide();

    auto horHeader = new QHeaderView(Qt::Orientation::Horizontal);
    horHeader->setMinimumSectionSize(15);
    horHeader->setMaximumSectionSize(15);
    horHeader->setDefaultSectionSize(15);
    horHeader->hide();

    view->setVerticalHeader(vertHeader);
    view->setHorizontalHeader(horHeader);

    delegate = new CellDelegate(this);
    view->setItemDelegate(delegate);

    setupActions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupActions()
{
    connect(ui->actionPlay, &QAction::triggered, this, &MainWindow::onActionPlayTriggered);
    connect(ui->actionStop, &QAction::triggered, this, &MainWindow::onActionStopTriggered);
    connect(ui->actionRestart, &QAction::triggered, this, &MainWindow::onActionRestartTriggered);
    connect(ui->actionSave_Pattern, &QAction::triggered, this, &MainWindow::onActionSavePatternTriggered);
    connect(ui->actionClear_field, &QAction::triggered, this, &MainWindow::onActionClearFieldTriggered);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::onActionQuitTriggered);
}

void MainWindow::onActionPlayTriggered()
{

}


void MainWindow::onActionStopTriggered()
{

}


void MainWindow::onActionRestartTriggered()
{

}


void MainWindow::onActionSavePatternTriggered()
{

}


void MainWindow::onActionClearFieldTriggered()
{

}


void MainWindow::onActionQuitTriggered()
{
    QApplication::exit();
}
