#include "Widgets/cell.hpp"
#include "ui_cell.h"

Cell::Cell(QWidget *parent, QPoint inCoord) :
    QWidget(parent),
    ui(new Ui::Cell),
    coord{inCoord}
{
    ui->setupUi(this);
}

Cell::~Cell()
{
    delete ui;
}

void Cell::on_CellBtn_toggled(bool checked)
{
    this->isLiving = checked;
}

