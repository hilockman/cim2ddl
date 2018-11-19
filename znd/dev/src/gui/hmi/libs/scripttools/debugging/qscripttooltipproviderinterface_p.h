#ifndef QSCRIPTTOOLTIPPROVIDERINTERFACE_P_H
#define QSCRIPTTOOLTIPPROVIDERINTERFACE_P_H 
#include <QtCore/qobjectdefs.h>

QT_BEGIN_NAMESPACE

class QPoint;
class QStringList;

class Q_AUTOTEST_EXPORT QScriptToolTipProviderInterface
{
public:
    virtual ~QScriptToolTipProviderInterface() {}

    virtual void showToolTip(const QPoint &pos, int frameIndex,
                             int lineNumber, const QStringList &path) = 0;
};

QT_END_NAMESPACE

#endif
