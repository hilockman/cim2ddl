#ifndef CARTESIANCOORDINATETRANSFORMATION_H
#define CARTESIANCOORDINATETRANSFORMATION_H 

#include <QList>
#include <QRectF>
#include <QPointF>

#include "KDChartZoomParameters.h"

#include <cmath>
#include <limits>

namespace KDChart {







    struct CoordinateTransformation {

        CoordinateTransformation()
            : axesCalcModeY( CartesianCoordinatePlane::Linear ),
              axesCalcModeX( CartesianCoordinatePlane::Linear ),
              isPositiveX( true ),
              isPositiveY( true )
        {}

        CartesianCoordinatePlane::AxesCalcMode axesCalcModeY;
        CartesianCoordinatePlane::AxesCalcMode axesCalcModeX;

        ZoomParameters zoom;

        QTransform transform;
        QTransform backTransform;

        bool isPositiveX;
        bool isPositiveY;

        qreal logTransform( qreal value, bool isPositiveRange ) const
        {
            if ( isPositiveRange ) {
                return log10( value );
            } else {
                return -log10( -value );
            }
        }

        qreal logTransformBack( qreal value, bool wasPositive ) const
        {
            if ( wasPositive ) {
                return pow( 10.0, value );
            } else {
                return -pow( 10.0, -value );
            }
        }

        void updateTransform( const QRectF& constDataRect, const QRectF& screenRect )
        {
            QRectF dataRect = constDataRect;
            if ( axesCalcModeX == CartesianCoordinatePlane::Logarithmic ) {

                isPositiveX = dataRect.left() >= 0.0;
                dataRect.setLeft( logTransform( dataRect.left(), isPositiveX ) );
                dataRect.setRight( logTransform( dataRect.right(), isPositiveX ) );
            }
            if ( axesCalcModeY == CartesianCoordinatePlane::Logarithmic ) {
                isPositiveY = dataRect.top() >= 0.0;
                dataRect.setTop( logTransform( dataRect.top(), isPositiveY ) );
                dataRect.setBottom( logTransform( dataRect.bottom(), isPositiveY ) );
            }

            transform.reset();

            transform.translate( screenRect.left(), screenRect.bottom() );
            transform.scale( screenRect.width(), screenRect.height() );




            transform.translate( 0.5, -0.5 );
            transform.scale( zoom.xFactor, zoom.yFactor );
            transform.translate( -zoom.xCenter, 1.0 - zoom.yCenter );

            transform.scale( 1.0 / dataRect.width(), 1.0 / dataRect.height() );
            transform.translate( -dataRect.left(), -dataRect.bottom() );


            backTransform = transform.inverted();
        }


        inline QPointF translate( const QPointF& dataPoint ) const
        {
            QPointF data = dataPoint;
            if ( axesCalcModeX == CartesianCoordinatePlane::Logarithmic ) {
                data.setX( logTransform( data.x(), isPositiveX ) );
            }
            if ( axesCalcModeY == CartesianCoordinatePlane::Logarithmic ) {
                data.setY( logTransform( data.y(), isPositiveY ) );
            }

            return transform.map( data );
        }


        inline const QPointF translateBack( const QPointF& screenPoint ) const
        {
            QPointF ret = backTransform.map( screenPoint );
            if ( axesCalcModeX == CartesianCoordinatePlane::Logarithmic ) {
                ret.setX( logTransformBack( ret.x(), isPositiveX ) );
            }
            if ( axesCalcModeY == CartesianCoordinatePlane::Logarithmic ) {
                ret.setY( logTransformBack( ret.y(), isPositiveY ) );
            }
            return ret;
        }
    };

    typedef QList<CoordinateTransformation> CoordinateTransformationList;

}

#endif
