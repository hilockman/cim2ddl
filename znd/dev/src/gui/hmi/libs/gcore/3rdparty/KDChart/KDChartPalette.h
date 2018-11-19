#ifndef __KDCHART_PALETTE_H__
#define __KDCHART_PALETTE_H__ 

#include <QObject>
#include <QBrush>
#include "KDChartGlobal.h"

namespace KDChart {
class KDCHART_EXPORT Palette: public QObject
{
    Q_OBJECT
public:
    explicit Palette( QObject *parent = 0 );
    Palette( const Palette& );
    Palette &operator= ( const Palette & );

    ~Palette();



    static const Palette& defaultPalette();
    static const Palette& subduedPalette();
    static const Palette& rainbowPalette();



    bool isValid() const;


    int size() const;




    void addBrush( const QBrush & brush, int position = -1 );





    QBrush getBrush( int position ) const;


    void removeBrush( int position );

Q_SIGNALS:


    void changed();

private:
    KDCHART_DECLARE_PRIVATE_BASE_VALUE( Palette )
};

}

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::Palette )

#endif
