#include "Widgets/gameboard.hpp"

#include <QFile>
#include <QTextStream>
#include <QRect>
#include <QDebug>

GameBoardModel::GameBoardModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    clear();
}

QHash<int, QByteArray> GameBoardModel::roleNames() const
{
    return {{CellRole, "value"}};
}

int GameBoardModel::rowCount(const QModelIndex& parent) const
{
    if(parent.isValid()){
        return 0;
    }

    return GameBoardModel::height;
}

int GameBoardModel::columnCount(const QModelIndex& parent) const
{
    if(parent.isValid()){
        return 0;
    }

    return GameBoardModel::width;
}

QVariant GameBoardModel::data(const QModelIndex& index, int role) const
{
    if(!index.isValid() || role != GameBoardModel::Roles::CellRole){
        return QVariant();
    }

    return QVariant(this->playground[GameBoardModel::cellIndex({index.column(), index.row()})]);
}

bool GameBoardModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if(role != GameBoardModel::Roles::CellRole || data(index, role) == value){
        return false;
    }

    this->playground[GameBoardModel::cellIndex({index.column(), index.row()})] = value.toBool();
    emit dataChanged(index, index, {role});

    return true;
}

Qt::ItemFlags GameBoardModel::flags(const QModelIndex& index) const
{
    if(!index.isValid()){
        return Qt::NoItemFlags;
    }

    return Qt::ItemIsEditable;
}

void GameBoardModel::nextStep(){
    PlaygroundType newPlayground;

    for(std::size_t i = 0u; i < size; ++i){
        bool currentState = this->playground[i];

        int cellNeighborsCount = GameBoardModel::cellNeighborsCount(cellCoordsFromIndex(static_cast<int>(i)));

        newPlayground[i] = currentState
                ? cellNeighborsCount == 2 || cellNeighborsCount == 3
                : cellNeighborsCount == 3;
    }

    this->playground = std::move(newPlayground);

    emit dataChanged(index(0, 0), index(GameBoardModel::height - 1, GameBoardModel::width - 1), {GameBoardModel::Roles::CellRole});
}

bool GameBoardModel::loadFile(const QString& fileName)
{
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);
    loadPattern(in.readAll());

    return true;
}

void GameBoardModel::loadPattern(const QString& plainText)
{
    clear();

    QStringList rows = plainText.split("\n");
    QSize patternSize(0, rows.count());
    for(auto row : rows){
        if(row.size() > patternSize.width()){
            patternSize.setWidth(row.size());
        }
    }

    QPoint patternLocation{(GameBoardModel::width - patternSize.width()) / 2,
                           (GameBoardModel::height - patternSize.height()) / 2};

    for(int y = 0; y < patternSize.height(); ++y){
        const QString line = rows[y];

        for(int x = 0; x < line.length(); ++x){
            QPoint cellPosition{x + patternLocation.x(), y + patternLocation.y()};
            this->playground[GameBoardModel::cellIndex(cellPosition)] = line[x] == 'O';
        }
    }

    emit dataChanged(index(0, 0), index(GameBoardModel::height - 1, GameBoardModel::width - 1), {CellRole});
}

void GameBoardModel::clear()
{
    this->playground.fill(false);
    emit dataChanged(index(0, 0), index(GameBoardModel::height - 1, GameBoardModel::width - 1), {CellRole});
}

int GameBoardModel::cellNeighborsCount(const QPoint& cellCoords) const
{
    int count{0};

    for(int x = -1; x <= 1; ++x){
        for(int y = -1; y <= 1; ++y){
            if(x == 0 && y == 0){
                continue;
            }

            const QPoint neighborPos{((cellCoords.x() + x) % GameBoardModel::height) % GameBoardModel::height,
                                     ((cellCoords.y() + y) % GameBoardModel::width) % GameBoardModel::width};

            if(this->playground[GameBoardModel::cellIndex(neighborPos)]){
                ++count;
            }

            if(count > 3){
                return count;
            }
        }
    }

    return count;
}

QPoint GameBoardModel::cellCoordsFromIndex(int cellIndex)
{
    return {cellIndex % GameBoardModel::width, cellIndex / GameBoardModel::width};
}

std::size_t GameBoardModel::cellIndex(const QPoint& coordinates)
{
    return std::size_t(coordinates.y() * GameBoardModel::width + coordinates.x());
}
