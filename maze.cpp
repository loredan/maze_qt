#include "maze.h"

Maze::Maze(QQuickItem *parent) : QQuickPaintedItem(parent)
{
}

void Maze::paint(QPainter *painter)
{
    qreal cellSizeH;
    qreal cellSizeV;
    switch (display) {
    case Display::Terse:
        cellSizeH = this->width() / size;
        cellSizeV = this->height() / size;
        break;
    case Display::Full:
    default:
        cellSizeH = this->width() / (size * 2 + 1);
        cellSizeV = this->height() / (size * 2 + 1);
    }
    if(paths != 0) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                switch (display) {
                case Display::Terse:
                    painter->fillRect(QRectF(cellSizeH * i, cellSizeV * j, cellSizeH, cellSizeV), paths[i][j].color);
                    break;
                case Display::Full:
                default:
                    painter->fillRect(QRectF(cellSizeH * (i * 2 + 1), cellSizeV * (j * 2 + 1), cellSizeH, cellSizeV), paths[i][j].color);
                    if (paths[i][j].right == Path::Path) {
                        painter->fillRect(QRectF(cellSizeH * (i * 2 + 2), cellSizeV * (j * 2 + 1), cellSizeH, cellSizeV), paths[i][j].rightColor);
                    }
                    if (paths[i][j].bottom == Path::Path) {
                        painter->fillRect(QRectF(cellSizeH * (i * 2 + 1), cellSizeV * (j * 2 + 2), cellSizeH, cellSizeV), paths[i][j].bottomColor);
                    }
                }
            }
        }
    }
}

void Maze::resetMaze()
{
    paths = new Cell*[size];
    for (int i = 0; i < size; i++) {
        paths[i] = new Cell[size];
        paths[i][size - 1].bottom = Path::Border;
        if (i == size - 1) {
            for (int j = 0; j < size; j++) {
                paths[i][j].right = Path::Border;
            }
        }
    }
    invalidate();
}

void Maze::invalidate()
{
    update();
}
