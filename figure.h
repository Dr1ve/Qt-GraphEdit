#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
    //Свойство стартовой точки, относительно которой отрисовывается фигура
    Q_PROPERTY(QPointF startPoint
               READ startPoint WRITE setStartPoint
               NOTIFY pointChanged)
    //Свойство конечной точки, до куда отрисовываем фигуру
    Q_PROPERTY(QPointF endPoint
               READ endPoint WRITE setEndPoint
               NOTIFY pointChanged)
public:
    explicit Figure(QPointF point, QObject *parent = nullptr);
    ~Figure();

    QPointF startPoint() const;//стартовая точка
    QPointF endPoint() const;//конечная точка

    void setStartPoint(const QPointF point);//установка стартовой точки
    void setEndPoint(const QPointF point);//установка конечной точки
    virtual void onFocus() = 0;
    virtual void offFocus() = 0;
signals:
    void pointChanged();//сигнал об изменении точки

private:
    QPointF m_startPoint;//стартовая точка
    QPointF m_endPoint;//конечная точка

    QRectF boundingRect() const; //область, в которой содержится фигура

public slots:
    void updateRomb();//слот обновления области, в которой содержится фигура
};

#endif // FIGURE_H
