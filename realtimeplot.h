#ifndef REALTIMEPLOT_H
#define REALTIMEPLOT_H

#include "mainwindow.h"

class RealTimePlot : public QwtPlot
{
    Q_OBJECT

public:

    RealTimePlot();

    ~RealTimePlot();

public slots:

    void    timerHandle();

private:

    QwtPlotCurve            *curve;
    QwtPlotDirectPainter    *painter;

    void    setData();
    void    appendGraphPoint(QPointF point);
    int     counter;
    double  x[1000];
    double  y[1000];
};

#endif // REALTIMEPLOT_H
