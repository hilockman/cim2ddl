#ifndef KDCHARTSIGNALCOMPRESSOR_H
#define KDCHARTSIGNALCOMPRESSOR_H 

#include <QObject>
#include <QTimer>

namespace KDChart {
    class SignalCompressor : public QObject
    {
        Q_OBJECT

    public:
        SignalCompressor( QObject* receiver, const char* signal,
                          QObject* parent = 0 );

    Q_SIGNALS:
        void finallyEmit();

    public Q_SLOTS:
        void emitSignal();

    private Q_SLOTS:
        void nowGoAlready();

    private:
        QTimer m_timer;
    };

}

#endif
