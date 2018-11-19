#ifndef QSCRIPTCOMPLETIONPROVIDERINTERFACE_P_H
#define QSCRIPTCOMPLETIONPROVIDERINTERFACE_P_H 
#include <QtCore/qobjectdefs.h>

QT_BEGIN_NAMESPACE

class QScriptCompletionTaskInterface;

class Q_AUTOTEST_EXPORT QScriptCompletionProviderInterface
{
public:
    enum Option {
        ConsoleCommandCompletion = 1
    };

    virtual ~QScriptCompletionProviderInterface() {}

    virtual QScriptCompletionTaskInterface *createCompletionTask(
        const QString &contents, int cursorPosition,
        int frameIndex, int options) = 0;
};

QT_END_NAMESPACE

#endif
