#pragma once

#include <QWidget>

namespace Ui {
class Cell;
}

class LivingCell;

class Cell : public QWidget
{
    Q_OBJECT

public:
    explicit Cell(QWidget *parent = nullptr);
    ~Cell();

private slots:
    void on_CellBtn_toggled(bool checked);

private:
    Ui::Cell *ui;

    LivingCell* cell;
};

