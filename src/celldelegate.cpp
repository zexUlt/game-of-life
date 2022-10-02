#include "celldelegate.hpp"
#include "Widgets/gameboard.hpp"

#include <QLabel>

CellDelegate::CellDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}

QWidget *CellDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    auto editor = new QLabel(parent);
    auto model = static_cast<const GameBoardModel*>(index.model());

    model;

    editor->setStyleSheet("QLabel { background-color : " + ";}");
    return editor;
}
