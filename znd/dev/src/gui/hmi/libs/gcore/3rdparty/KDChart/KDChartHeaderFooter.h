#ifndef KDCHARTHEADERFOOTER_H
#define KDCHARTHEADERFOOTER_H 

#include "KDChartTextArea.h"
#include "KDChartPosition.h"

namespace KDChart {

    class Chart;
    class TextAttributes;




class KDCHART_EXPORT HeaderFooter : public TextArea
{
    Q_OBJECT

    KDCHART_DECLARE_PRIVATE_DERIVED_PARENT( HeaderFooter, Chart* )

public:
    HeaderFooter( Chart* parent = 0 );
    virtual ~HeaderFooter();

    virtual HeaderFooter * clone() const;

    bool compare( const HeaderFooter& other ) const;

    enum HeaderFooterType{ Header,
                           Footer };

    void setType( HeaderFooterType type );
    HeaderFooterType type() const;

    void setPosition( Position position );
    Position position() const;

    void setParent( QObject* parent );

Q_SIGNALS:
    void destroyedHeaderFooter( HeaderFooter* );
    void positionChanged( HeaderFooter* );

};

}


#endif