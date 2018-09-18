#include "triangle.h"

Triangle::Triangle(QPointF point, QObject *parent) :
    Figure(point,parent),pen(Qt::green,2),focusScale(1)
{
}

Triangle::~Triangle()
{
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //макрос отключения предупреждения о неиспользуемых переменных
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPolygon polygon;//используем класс полигона, чтобы отрисовать треугольник
    //помещаем координаты точек в полигональную модель

    polygon << QPoint(static_cast<int>((startPoint().x() < endPoint().x()) ? (startPoint().x() + (abs(endPoint().x() - startPoint().x()) / 2)) :
                                                                             (startPoint().x() - (abs(endPoint().x() - startPoint().x()) / 2))),
                      static_cast<int>(startPoint().y()))
            << QPoint(static_cast<int>(endPoint().x()),static_cast<int>(endPoint().y()))
            << QPoint(static_cast<int>(startPoint().x()),static_cast<int>(endPoint().y()));

    //painter->setBrush(Qt::red);//устанавливаем кисть, которой будем отрисовывать объект
    painter->setPen(pen);
    painter->scale(focusScale,focusScale);
    painter->drawPolygon(polygon);//рисуем треугольник по полигональной модели
}

void Triangle::onFocus()
{
    focusScale = 1.3;
}

void Triangle::offFocus()
{
    focusScale = 1;
}
