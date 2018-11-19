#ifndef QSCRIPTSCRIPTDATA_P_H
#define QSCRIPTSCRIPTDATA_P_H 
#include <QtCore/qobjectdefs.h>
#include <QtCore/private/qscopedpointer_p.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qmap.h>

QT_BEGIN_NAMESPACE

class QDataStream;
class QString;
class QStringList;

class QScriptScriptDataPrivate;
class Q_AUTOTEST_EXPORT QScriptScriptData
{
public:
    friend Q_AUTOTEST_EXPORT QDataStream &operator<<(QDataStream &, const QScriptScriptData &);
    friend Q_AUTOTEST_EXPORT QDataStream &operator>>(QDataStream &, QScriptScriptData &);

    QScriptScriptData();
    QScriptScriptData(const QString &contents, const QString &fileName,
                      int baseLineNumber, const QDateTime &timeStamp = QDateTime());
    QScriptScriptData(const QScriptScriptData &other);
    ~QScriptScriptData();

    QString contents() const;
    QStringList lines(int startLineNumber, int count) const;
    QString fileName() const;
    int baseLineNumber() const;
    QDateTime timeStamp() const;

    bool isValid() const;

    QScriptScriptData &operator=(const QScriptScriptData &other);

    bool operator==(const QScriptScriptData &other) const;
    bool operator!=(const QScriptScriptData &other) const;

private:
    QScopedSharedPointer<QScriptScriptDataPrivate> d_ptr;

    Q_DECLARE_PRIVATE(QScriptScriptData)
};

typedef QMap<qint64, QScriptScriptData> QScriptScriptMap;

Q_AUTOTEST_EXPORT QDataStream &operator<<(QDataStream &, const QScriptScriptData &);
Q_AUTOTEST_EXPORT QDataStream &operator>>(QDataStream &, QScriptScriptData &);

QT_END_NAMESPACE

#endif
