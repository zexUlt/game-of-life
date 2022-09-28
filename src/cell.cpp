#include "Widgets/cell.hpp"
#include "ui_cell.h"

Cell::Cell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cell)
{
    ui->setupUi(this);
}

Cell::~Cell()
{
    delete ui;
}

void Cell::on_CellBtn_toggled(bool checked)
{

}

