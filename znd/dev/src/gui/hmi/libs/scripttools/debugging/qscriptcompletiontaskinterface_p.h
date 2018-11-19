#ifndef QSCRIPTCOMPLETIONTASKINTERFACE_P_H
#define QSCRIPTCOMPLETIONTASKINTERFACE_P_H 
#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE

class QString;

class QScriptCompletionTaskInterfacePrivate;
class Q_AUTOTEST_EXPORT QScriptCompletionTaskInterface
    : public QObject
{
    Q_OBJECT
public:
    enum CompletionType {
        NoCompletion,
        CommandNameCompletion,
        CommandArgumentCompletion,
        ScriptIdentifierCompletion
    };

    ~QScriptCompletionTaskInterface();

    virtual void start() = 0;

    CompletionType completionType() const;

    int resultCount() const;
    QString resultAt(int index) const;

    int position() const;
    int length() const;

    QString appendix() const;

protected:
    void addResult(const QString &result);

Q_SIGNALS:
    void finished();

protected:
    QScriptCompletionTaskInterface(
        QScriptCompletionTaskInterfacePrivate &dd, QObject *parent);

private:
    Q_DECLARE_PRIVATE(QScriptCompletionTaskInterface)
    Q_DISABLE_COPY(QScriptCompletionTaskInterface)
};

QT_END_NAMESPACE

#endif
