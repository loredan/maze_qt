#ifndef MAZE_H
#define MAZE_H

#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QPainter>

class Maze : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(Display display MEMBER display NOTIFY displayChanged)
    Q_PROPERTY(int size MEMBER size NOTIFY sizeChanged)

public:
    Maze(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    void invalidate();
    Q_INVOKABLE void resetMaze();

    enum class Display { Full, Terse };
    enum class Path { Path, Wall, Border };

    struct Cell
    {
        Path right = Path::Wall;
        Path bottom = Path::Wall;
        QColor color = QColor(0,0,0);
        QColor rightColor = QColor(0,0,0);
        QColor bottomColor = QColor(0,0,0);
    };
signals:
    void displayChanged();
    void sizeChanged();
public slots:
private:
    Cell **paths;
    Display display = Display::Full;
    int size;
};

#endif // MAZE_H
