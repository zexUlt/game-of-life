#pragma once

#include <QWidget>

namespace Ui {
class Cell;
}


class Cell : public QWidget
{
    Q_OBJECT

public:
    explicit Cell(QWidget *parent = nullptr, QPoint inCoord = {0, 0});
    ~Cell();

private slots:
    void on_CellBtn_toggled(bool checked);

private:
    Ui::Cell *ui;

    bool isLiving;
    const QPoint coord;
};

