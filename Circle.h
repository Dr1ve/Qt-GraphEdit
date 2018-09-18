#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsItem>
#include <QPainter>
#include "figure.h"

class Circle : public Figure
{
    Q_OBJECT
public:
    Circle(QPointF point, QObject *parent = nullptr);
    ~Circle();
    void onFocus() override;
    void offFocus() override;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPen pen;
};

#endif // CIRCLE_H
