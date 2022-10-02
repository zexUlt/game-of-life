#include "celldelegate.hpp"
#include "Widgets/gameboard.hpp"

#include <QCheckBox>
#include <QEvent>
#include <QDebug>

const QString CellDelegate::livingCellStyleSheet{"QCheckBox { background-color : black ;}"};
const QString CellDelegate::deadCellStyleSheet{"QCheckBox { background-color : white ;}"};

CellDelegate::CellDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}

QWidget *CellDelegate::createEditor(QWidget *parent,
                                    const QStyleOptionViewItem &/*option*/,
                                    const QModelIndex &index) const
{
    auto editor = new QCheckBox(parent);

    bool isAlive = index.model()->data(index, GameBoardModel::Roles::CellRole).toBool();

    editor->setAutoFillBackground(true);
    if(isAlive){
        editor->setStyleSheet(CellDelegate::livingCellStyleSheet);
    }else{
        editor->setStyleSheet(CellDelegate::deadCellStyleSheet);
    }
    return editor;
}

void CellDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    bool isAlive = index.model()->data(index, GameBoardModel::Roles::CellRole).toBool();

    if(isAlive){
        editor->setStyleSheet(CellDelegate::livingCellStyleSheet);
    }else{
        editor->setStyleSheet(CellDelegate::deadCellStyleSheet);
    }
}

void CellDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    bool value = static_cast<QCheckBox*>(editor)->isChecked();
    model->setData(index, value, GameBoardModel::Roles::CellRole);
}

void CellDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                                        const QModelIndex& /*index*/) const
{
    editor->setGeometry(option.rect);
}

bool CellDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                               const QStyleOptionViewItem & /*option*/,
                               const QModelIndex &index)
{
    if(event->type() == QEvent::MouseButtonPress){
        qDebug() << "Clicked index at " << index.row() << " " << index.column() << '\n';
        return true;
    }

    return false;
}
