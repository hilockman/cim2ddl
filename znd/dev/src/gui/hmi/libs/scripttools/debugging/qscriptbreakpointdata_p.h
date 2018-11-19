#ifndef QSCRIPTBREAKPOINTDATA_P_H
#define QSCRIPTBREAKPOINTDATA_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qmap.h>

QT_BEGIN_NAMESPACE

class QDataStream;
class QVariant;

class QScriptBreakpointDataPrivate;
class Q_AUTOTEST_EXPORT QScriptBreakpointData
{
public:
    friend Q_AUTOTEST_EXPORT QDataStream &operator<<(QDataStream &, const QScriptBreakpointData &);
    friend Q_AUTOTEST_EXPORT QDataStream &operator>>(QDataStream &, QScriptBreakpointData &);

    QScriptBreakpointData();
    QScriptBreakpointData(qint64 scriptId, int lineNumber);
    QScriptBreakpointData(const QString &fileName, int lineNumber);
    QScriptBreakpointData(const QScriptBreakpointData &other);
    ~QScriptBreakpointData();
    QScriptBreakpointData &operator=(const QScriptBreakpointData &other);

    bool isValid() const;


    qint64 scriptId() const;
    void setScriptId(qint64 id);

    QString fileName() const;
    void setFileName(const QString &fileName);

    int lineNumber() const;
    void setLineNumber(int lineNumber);


    bool isEnabled() const;
    void setEnabled(bool enabled);

    bool isSingleShot() const;
    void setSingleShot(bool singleShot);

    int ignoreCount() const;
    void setIgnoreCount(int count);

    QString condition() const;
    void setCondition(const QString &condition);

    QVariant data() const;
    void setData(const QVariant &data);

    bool hit();


    int hitCount() const;


    bool operator==(const QScriptBreakpointData &other) const;
    bool operator!=(const QScriptBreakpointData &other) const;

private:
    QScopedPointer<QScriptBreakpointDataPrivate> d_ptr;

    Q_DECLARE_PRIVATE(QScriptBreakpointData)
};

typedef QMap<int, QScriptBreakpointData> QScriptBreakpointMap;

Q_AUTOTEST_EXPORT QDataStream &operator<<(QDataStream &, const QScriptBreakpointData &);
Q_AUTOTEST_EXPORT QDataStream &operator>>(QDataStream &, QScriptBreakpointData &);

QT_END_NAMESPACE

#endif
