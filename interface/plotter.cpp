#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{

}

/**
 * @brief Plotter::paintEvent
 * @param event
 * Folha de desenho do plotter.
 */

void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::CrossPattern);

    pen.setColor(QColor(0,0,0));
    pen.setWidth(5);

    painter.setBrush(brush);
    painter.setPen(pen);

    painter.drawRect(0,0,width(),height());
}
