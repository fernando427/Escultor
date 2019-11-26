#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

/**
 * @brief The Plotter class
 * Classe que haverá os protótipos padrões
 * sobre o plotter.
 */

class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // PLOTTER_H
