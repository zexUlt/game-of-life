#pragma once

#include <array>
#include <QAbstractTableModel>
#include <QPoint>

class GameBoardModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum Roles{
        CellRole
    };

    QHash<int, QByteArray> roleNames() const override;

    explicit GameBoardModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    void nextStep();
    bool loadFile(const QString& fileName);
    void loadPattern(const QString& plainText);
    void clear();

private:
    static constexpr int width = 32;
    static constexpr int height = 32;
    static constexpr int size = width * height;

    using PlaygroundType = std::array<bool, size>;
    PlaygroundType playground;

    int cellNeighborsCount(const QPoint& cellCoords) const;
    static QPoint cellCoordsFromIndex(int cellIndex);
    static std::size_t cellIndex(const QPoint& coordinates);
};

