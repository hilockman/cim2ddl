#ifndef KDTEXTDOCUMENT_H
#define KDTEXTDOCUMENT_H 
#include <QTextDocument>
#include <QSize>





class KDTextDocument : public QTextDocument
{
    Q_OBJECT

public:
    explicit KDTextDocument( QObject* parent = 0 );
    explicit KDTextDocument( const QString& text, QObject* parent = 0 );
    ~KDTextDocument();

    QSize sizeHint();
    QSize minimumSizeHint();

private:
    QSize sizeForWidth( int width );

private:
    bool mHintValid;
    QSize mSizeHint;
    QSize mMinimumSizeHint;
};


#endif
