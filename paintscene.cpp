#include "paintscene.h"

#include "Rectangle.h"
#include "Circle.h"
#include "triangle.h"

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent), focusFigure(nullptr)
{

}

paintScene::~paintScene()
{

}

int paintScene::typeFigure() const
{
    return m_typeFigure;
}

void paintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //если тип фигуры установлен 0 то значит идет перетаскивание

    switch (m_typeFigure) {
    case RectangleType:{
        Rectangle *item = new Rectangle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case CircleType:{
        Circle *item = new Circle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case TriangleType:{
        Triangle *item = new Triangle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    }
    if (m_typeFigure != MoveFigure)
        addItem(tempFigure);
}

void paintScene::focusItem(const int index)
{
    if (focusFigure)
        focusFigure->offFocus();
    QList<QGraphicsItem *> item = items();
    focusFigure = dynamic_cast<Figure*>(*(item.begin() + index));
    focusFigure->onFocus();
    update(QRectF(0,0,width(),height()));
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_typeFigure == MoveFigure)
    {
        if (focusFigure)
        focusFigure->setPos(event->scenePos().x() - ((focusFigure->startPoint().x() > focusFigure->endPoint().x()) ?
                                                   (focusFigure->endPoint().x()) + (abs(focusFigure->endPoint().x() - focusFigure->startPoint().x()) / 2) :
                                                   (focusFigure->startPoint().x()) + (abs(focusFigure->endPoint().x() - focusFigure->startPoint().x()) / 2) ),
                           event->scenePos().y() - ((focusFigure->startPoint().y() > focusFigure->endPoint().y()) ?
                                                   (focusFigure->endPoint().y())  + (abs(focusFigure->endPoint().y() - focusFigure->startPoint().y()) / 2) :
                                                   (focusFigure->startPoint().y()) + (abs(focusFigure->endPoint().y() - focusFigure->startPoint().y()) / 2)));
    }
    else
    {
        tempFigure->setEndPoint(event->scenePos());
    }
    update(QRectF(0,0,width(),height()));
}

void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    switch (m_typeFigure) {
        case RectangleType:
            emit addFigure("Прямоугольник");
        break;
        case CircleType:
            emit addFigure("Окружность");
        break;
        case TriangleType:
            emit addFigure("Треугольник");
        break;
    }

    Q_UNUSED(event);
}

void paintScene::deleteItem(const int index)
{
    QList<QGraphicsItem *> item = items();
    removeItem(*(item.begin() + index));
    update(QRectF(0,0,width(),height()));
}
