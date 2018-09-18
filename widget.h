#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

#include <QListWidgetItem>

#include "paintscene.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QTimer *timer;//таймер для подготовки актуальных размеров

    paintScene *scene;//графическая сцена

private:
    /*переопределяем событие изменения размера окна для пересчета граф сцены*/
    void resizeEvent(QResizeEvent *event);

private slots:
    void slotTimer();
    void addItemWidget(const QString&);

    void on_checkBox_stateChanged(int arg1);
    void on_radioButton_2_toggled(bool checked);
    void on_radioButton_toggled(bool checked);
    void on_radioButton_3_toggled(bool checked);
    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_pushButton_clicked();
};

#endif // WIDGET_H
