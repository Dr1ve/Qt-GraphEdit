#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "figure.h"

class paintScene : public QGraphicsScene
{
    Q_OBJECT
    //свойство используемой фигуры
    Q_PROPERTY(int typeFigure
               READ typeFigure WRITE setTypeFigure
               NOTIFY typeFigureChanged)
public:
    explicit paintScene(QObject *parent = nullptr);
    ~paintScene();

    int typeFigure() const;
    void setTypeFigure(const int type);

    //перечисление типов фигур
    enum FigureTypes
    {
        RectangleType,
        CircleType,
        TriangleType,
        MoveFigure
    };

signals:
    void addFigure(const QString&);
    void typeFigureChanged();//сигнал об изменении типа фигуры

public slots:
    void focusItem(const int);
    void deleteItem(const int);

private:
    //для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    Figure *tempFigure;
    Figure *focusFigure;
    int m_typeFigure = 0;//текущий тип фигуры
};

#endif // PAINTSCENE_H
