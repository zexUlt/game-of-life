#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionPlay_triggered();

private:
    Ui::MainWindow *ui;

    bool** gameField;
    size_t fieldSize;
};

#endif // MAINWINDOW_H
