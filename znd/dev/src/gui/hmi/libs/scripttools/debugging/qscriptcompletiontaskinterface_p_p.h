#ifndef QSCRIPTCOMPLETIONTASKINTERFACE_P_P_H
#define QSCRIPTCOMPLETIONTASKINTERFACE_P_P_H 
#include <private/qobject_p.h>

#include <QtCore/qstring.h>
#include <QtCore/qstringlist.h>

QT_BEGIN_NAMESPACE

class QScriptCompletionTaskInterface;
class QScriptCompletionTaskInterfacePrivate
    : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QScriptCompletionTaskInterface)
public:
    QScriptCompletionTaskInterfacePrivate();
    virtual ~QScriptCompletionTaskInterfacePrivate();

    int type;
    QStringList results;
    int position;
    int length;
    QString appendix;
};

QT_END_NAMESPACE

#endif
