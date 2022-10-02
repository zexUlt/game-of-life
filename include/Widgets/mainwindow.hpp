#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QTableView;
class GameBoardModel;
class CellDelegate;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onActionPlayTriggered();
    void onActionStopTriggered();
    void onActionRestartTriggered();
    void onActionSavePatternTriggered();
    void onActionClearFieldTriggered();
    void onActionQuitTriggered();

private:
    void setupActions();

    Ui::MainWindow *ui;

    GameBoardModel* board;
    QTableView* view;
    CellDelegate* delegate;
};

#endif // MAINWINDOW_H
