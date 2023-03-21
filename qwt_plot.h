/******************************************************************************
  * Qwt Widget Library
  * Copyright (C) 1997   Josef Wilgen
  * Copyright (C) 2002   Uwe Rathmann
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the Qwt License, Version 1.0
  *****************************************************************************/

 #ifndef QWT_PLOT_H
 #define QWT_PLOT_H

 #include "qwt_global.h"
 #include "qwt_axis_id.h"
 #include "qwt_plot_dict.h"

 #include <qframe.h>

 class QwtPlotLayout;
 class QwtAbstractLegend;
 class QwtScaleWidget;
 class QwtScaleEngine;
 class QwtScaleDiv;
 class QwtScaleMap;
 class QwtScaleDraw;
 class QwtTextLabel;
 class QwtInterval;
 class QwtText;
 template< typename T > class QList;

 // 6.1 compatibility definitions
 #define QWT_AXIS_COMPAT 1

 class QWT_EXPORT QwtPlot : public QFrame, public QwtPlotDict
 {
     Q_OBJECT

     Q_PROPERTY( QBrush canvasBackground
         READ canvasBackground WRITE setCanvasBackground )

     Q_PROPERTY( bool autoReplot READ autoReplot WRITE setAutoReplot )

   public:
     enum LegendPosition
     {
         LeftLegend,

         RightLegend,

         BottomLegend,

         TopLegend
     };

     explicit QwtPlot( QWidget* = NULL );
     explicit QwtPlot( const QwtText& title, QWidget* = NULL );

     virtual ~QwtPlot();

     void setAutoReplot( bool = true );
     bool autoReplot() const;

     // Layout

     void setPlotLayout( QwtPlotLayout* );

     QwtPlotLayout* plotLayout();
     const QwtPlotLayout* plotLayout() const;

     // Title

     void setTitle( const QString& );
     void setTitle( const QwtText& );
     QwtText title() const;

     QwtTextLabel* titleLabel();
     const QwtTextLabel* titleLabel() const;

     // Footer

     void setFooter( const QString& );
     void setFooter( const QwtText& );
     QwtText footer() const;

     QwtTextLabel* footerLabel();
     const QwtTextLabel* footerLabel() const;

     // Canvas

     void setCanvas( QWidget* );

     QWidget* canvas();
     const QWidget* canvas() const;

     void setCanvasBackground( const QBrush& );
     QBrush canvasBackground() const;

     virtual QwtScaleMap canvasMap( QwtAxisId ) const;

     double invTransform( QwtAxisId, double pos ) const;
     double transform( QwtAxisId, double value ) const;

     // Axes

     bool isAxisValid( QwtAxisId ) const;

     void setAxisVisible( QwtAxisId, bool on = true );
     bool isAxisVisible( QwtAxisId ) const;

     // Axes data

     QwtScaleEngine* axisScaleEngine( QwtAxisId );
     const QwtScaleEngine* axisScaleEngine( QwtAxisId ) const;
     void setAxisScaleEngine( QwtAxisId, QwtScaleEngine* );

     void setAxisAutoScale( QwtAxisId, bool on = true );
     bool axisAutoScale( QwtAxisId ) const;

     void setAxisFont( QwtAxisId, const QFont& );
     QFont axisFont( QwtAxisId ) const;

     void setAxisScale( QwtAxisId, double min, double max, double stepSize = 0 );
     void setAxisScaleDiv( QwtAxisId, const QwtScaleDiv& );
     void setAxisScaleDraw( QwtAxisId, QwtScaleDraw* );

     double axisStepSize( QwtAxisId ) const;
     QwtInterval axisInterval( QwtAxisId ) const;
     const QwtScaleDiv& axisScaleDiv( QwtAxisId ) const;

     const QwtScaleDraw* axisScaleDraw( QwtAxisId ) const;
     QwtScaleDraw* axisScaleDraw( QwtAxisId );

     const QwtScaleWidget* axisWidget( QwtAxisId ) const;
     QwtScaleWidget* axisWidget( QwtAxisId );

     void setAxisLabelAlignment( QwtAxisId, Qt::Alignment );
     void setAxisLabelRotation( QwtAxisId, double rotation );

     void setAxisTitle( QwtAxisId, const QString& );
     void setAxisTitle( QwtAxisId, const QwtText& );
     QwtText axisTitle( QwtAxisId ) const;

     void setAxisMaxMinor( QwtAxisId, int maxMinor );
     int axisMaxMinor( QwtAxisId ) const;

     void setAxisMaxMajor( QwtAxisId, int maxMajor );
     int axisMaxMajor( QwtAxisId ) const;

     // Legend

     void insertLegend( QwtAbstractLegend*,
         LegendPosition = QwtPlot::RightLegend, double ratio = -1.0 );

     QwtAbstractLegend* legend();
     const QwtAbstractLegend* legend() const;

     void updateLegend();
     void updateLegend( const QwtPlotItem* );

     // Misc

     virtual QSize sizeHint() const QWT_OVERRIDE;
     virtual QSize minimumSizeHint() const QWT_OVERRIDE;

     virtual void updateLayout();
     virtual void drawCanvas( QPainter* );

     void updateAxes();
     void updateCanvasMargins();

     virtual void getCanvasMarginsHint(
         const QwtScaleMap maps[], const QRectF& canvasRect,
         double& left, double& top, double& right, double& bottom) const;

     virtual bool event( QEvent* ) QWT_OVERRIDE;
     virtual bool eventFilter( QObject*, QEvent* ) QWT_OVERRIDE;

     virtual void drawItems( QPainter*, const QRectF&,
         const QwtScaleMap maps[ QwtAxis::AxisPositions ] ) const;

     virtual QVariant itemToInfo( QwtPlotItem* ) const;
     virtual QwtPlotItem* infoToItem( const QVariant& ) const;

 #if QWT_AXIS_COMPAT
     enum Axis
     {
         yLeft   = QwtAxis::YLeft,
         yRight  = QwtAxis::YRight,
         xBottom = QwtAxis::XBottom,
         xTop    = QwtAxis::XTop,

         axisCnt = QwtAxis::AxisPositions
     };

     void enableAxis( int axisId, bool on = true )
     {
         setAxisVisible( axisId, on );
     }

     bool axisEnabled( int axisId ) const
     {
         return isAxisVisible( axisId );
     }
 #endif

   Q_SIGNALS:
     void itemAttached( QwtPlotItem* plotItem, bool on );

     void legendDataChanged( const QVariant& itemInfo,
         const QList< QwtLegendData >& data );

   public Q_SLOTS:
     virtual void replot();
     void autoRefresh();

   protected:

     virtual void resizeEvent( QResizeEvent* ) QWT_OVERRIDE;

   private Q_SLOTS:
     void updateLegendItems( const QVariant& itemInfo,
         const QList< QwtLegendData >& legendData );

   private:
     friend class QwtPlotItem;
     void attachItem( QwtPlotItem*, bool );

     void initAxesData();
     void deleteAxesData();
     void updateScaleDiv();

     void initPlot( const QwtText& title );

     class ScaleData;
     ScaleData* m_scaleData;

     class PrivateData;
     PrivateData* m_data;
 };

 #endif
