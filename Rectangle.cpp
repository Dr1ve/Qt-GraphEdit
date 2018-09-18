#include "Rectangle.h"

Rectangle::Rectangle(QPointF point, QObject *parent) :
    Figure(point,parent),pen(Qt::green,2)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //макрос отключения предупреждения о неиспользуемых переменных
    Q_UNUSED(option);
    Q_UNUSED(widget);

    //painter->setBrush(Qt::red);//устанавливаем кисть, которой будем отрисовывать объект
    painter->setPen(pen);
    //квардарт
    painter->drawRect(static_cast<int>((startPoint().x() > endPoint().x()) ? endPoint().x() : startPoint().x()),
                      static_cast<int>((startPoint().y() > endPoint().y()) ? endPoint().y() : startPoint().y()),
                      static_cast<int>(abs(endPoint().x() - startPoint().x())),
                      static_cast<int>(abs(endPoint().y() - startPoint().y())));
}

void Rectangle::onFocus()
{
    pen = QPen(Qt::green,5);
}

void Rectangle::offFocus()
{
    pen = QPen(Qt::green,2);
}
