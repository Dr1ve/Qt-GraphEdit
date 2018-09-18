#include "figure.h"
#include <QPainter>

Figure::Figure(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    //Устанавливаем стартовую координату для отрисовки фигуры
    setStartPoint(mapFromScene(point));
    setEndPoint(mapFromScene(point));
    /*подключаю сигнал изменения координат к слоту запуска обновления содержимого объекта*/
    connect(this,&Figure::pointChanged,this,&Figure::updateRomb);
}

Figure::~Figure()
{

}

QRectF Figure::boundingRect() const
{
    //возвращаю область в которой лежит фигура
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                  (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                  abs(endPoint().x() - startPoint().x()) + 10,
                  abs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::updateRomb()
{
    //вызываем обновление области
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                 (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                 abs(endPoint().x() - startPoint().x()) + 10,
                 abs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void Figure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
}

QPointF Figure::startPoint() const
{
    return m_startPoint;
}

QPointF Figure::endPoint() const
{
    return m_endPoint;
}
