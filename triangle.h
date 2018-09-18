#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include "figure.h"

class Triangle : public Figure
{
    Q_OBJECT
public:
    explicit Triangle(QPointF point, QObject *parent = nullptr);
    ~Triangle();
    void onFocus() override;
    void offFocus() override;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPen pen;
    //переменная для увеличения размера при выделении
    qreal focusScale;
};

#endif // TRIANGLE_H
