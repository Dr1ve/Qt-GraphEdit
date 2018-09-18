#include "Circle.h"

Circle::Circle(QPointF point, QObject *parent) :
    Figure(point,parent),pen(Qt::green,2)
{
}

Circle::~Circle()
{
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //макрос отключения предупреждения о неиспользуемых переменных
    Q_UNUSED(option);
    Q_UNUSED(widget);

    //painter->setBrush(Qt::red);//устанавливаем кисть, которой будем отрисовывать объект
    painter->setPen(pen);
    //круг
    painter->drawEllipse(static_cast<int>((startPoint().x() > endPoint().x()) ? endPoint().x() : startPoint().x()),
                         static_cast<int>((startPoint().y() > endPoint().y()) ? endPoint().y() : startPoint().y()),
                         static_cast<int>(abs(endPoint().x() - startPoint().x())),
                         static_cast<int>(abs(endPoint().y() - startPoint().y())));
}

void Circle::onFocus()
{
    pen = QPen(Qt::red,2);
}

void Circle::offFocus()
{
    pen = QPen(Qt::green,2);
}
