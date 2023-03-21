#include "realtimeplot.h"

RealTimePlot::RealTimePlot()
{
    counter = 0;
    painter = new QwtPlotDirectPainter(this);
    this->setAxisScale(QwtPlot::xBottom, 0, 1);
    this->setAxisScale(QwtPlot::yLeft, 0, 1);
    curve = new QwtPlotCurve("y(x)");
    curve->setStyle(QwtPlotCurve::NoCurve);
    curve->setData(new CurveData());
    curve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::red), QSize(1, 1)));
    curvev->attach(this);
    setAutoReplot(false);
    setData();
}

void RealTimePlot::setData()
{
    const int n = 1000;
    double h = 2.0 / n;
    for(int i = 0; i < n; i++)
    {
        x[i] = -1 + i * h;
        y[i] = qAbs(x[i]);
    }
}

RealTimePlot::~RealTimePlot()
{
    delete zoomer;
    delete painter;
    delete curve;
}

void RealTimePlot::timerHandle()
{
    QPointF newPoint = QPointF(this-x[this->counter], this->y[this->counter]);
    this->counter++;
    RealTimePlot::appendGraphPoint(newPoint);
}

void RealTimePlot::appendGraphPoint(QPointF point)
{
    CurveData *data = static_cast(curve->data());
    data->appendDataPoint(point);
    painter->drawSeries(curve, 0, data->size() - 1);
}

