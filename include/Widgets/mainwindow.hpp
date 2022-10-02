#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QTableView;
class GameBoard;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionPlay_triggered();

    void on_actionStop_triggered();

    void on_actionRestart_triggered();

    void on_actionSave_Pattern_triggered();

    void on_actionClear_field_triggered();

private:
    Ui::MainWindow *ui;

    GameBoard* board;
    QTableView* view;
};

#endif // MAINWINDOW_H
