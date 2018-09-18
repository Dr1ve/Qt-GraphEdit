#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include "figure.h"

class Rectangle : public Figure
{
    Q_OBJECT
public:
    explicit Rectangle(QPointF point, QObject *parent = nullptr);
    ~Rectangle();
    void onFocus() override;
    void offFocus() override;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPen pen;

};

#endif // RECTANGLE_H
