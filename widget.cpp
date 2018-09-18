#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new paintScene();
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0,0,500,500);
    ui->graphicsView->setScene(scene);

    timer = new QTimer();//инициализируем таймер
    connect(timer, &QTimer::timeout, this, &Widget::slotTimer);
    timer->start(100);

    connect(scene, &paintScene::addFigure, this, &Widget::addItemWidget);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);//устанавливаю сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//отключаю скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//отключаю скроллбар по горизонтали
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
}

Widget::~Widget()
{
    delete scene;
    delete ui;   
}

void Widget::slotTimer()
{
    //переопределяем размеры граф сцены в зависимости от размеров окна
    timer->stop();
    scene->setSceneRect(0, 0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void Widget::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}

void Widget::on_checkBox_stateChanged(int arg1)
{
    Q_UNUSED(arg1)
    //Если стоит галочка то рисуем иначе перетаскиваем элементы
    if (ui->checkBox->isChecked())
    {
        if (ui->radioButton_2->isChecked())
            scene->setTypeFigure(paintScene::RectangleType);
        if (ui->radioButton->isChecked())
            scene->setTypeFigure(paintScene::CircleType);
        if (ui->radioButton_3->isChecked())
            scene->setTypeFigure(paintScene::TriangleType);
    }
    else
    {
        scene->setTypeFigure(paintScene::MoveFigure);//устанавливаем не существующий тип фигуры, значит не рисуем

    }

}

void Widget::addItemWidget(const QString &s)
{
    ui->listWidget->addItem(s);
}

void Widget::on_radioButton_2_toggled(bool checked)
{
    if (ui->checkBox->isChecked())
        if (checked)
        {
            //если элемент установился
            scene->setTypeFigure(paintScene::RectangleType);
        }
}

void Widget::on_radioButton_toggled(bool checked)
{
    if (ui->checkBox->isChecked())
        if (checked)
        {
            //если элемент установился
            scene->setTypeFigure(paintScene::CircleType);
        }
}

void Widget::on_radioButton_3_toggled(bool checked)
{
    if (ui->checkBox->isChecked())
        if (checked)
        {
            //если элемент установился
            scene->setTypeFigure(paintScene::TriangleType);
        }
}

void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    Q_UNUSED(current);
    Q_UNUSED(previous);
    int index = ui->listWidget->currentRow();
    if (index >= 0)
        scene->focusItem(ui->listWidget->currentRow());
}

void Widget::on_pushButton_clicked()
{
    int item = ui->listWidget->currentRow();
    QListWidgetItem *it = ui->listWidget->currentItem();
    delete it;
    scene->deleteItem(item);
}
