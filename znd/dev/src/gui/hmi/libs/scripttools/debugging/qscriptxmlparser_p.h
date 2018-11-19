#ifndef QSCRIPTXMLPARSER_P_H
#define QSCRIPTXMLPARSER_P_H 
#include <QtCore/qobjectdefs.h>

#include <QtCore/qmap.h>
#include <QtCore/qset.h>
#include <QtCore/qstring.h>

QT_BEGIN_NAMESPACE

class Q_AUTOTEST_EXPORT QScriptXmlParser
{
public:
    struct Result
    {
        Result(const QMap<QString, int> &fi, const QSet<int> &eln)
            : functionsInfo(fi), executableLineNumbers(eln) {}

        QMap<QString, int> functionsInfo;
        QSet<int> executableLineNumbers;
    };

    static Result parse(const QString &xml);
};

QT_END_NAMESPACE

#endif
