#include "qscriptxmlparser_p.h"

#include <QtCore/qstringlist.h>
#include <QtCore/qxmlstream.h>
#include <QtCore/qdebug.h>

QT_BEGIN_NAMESPACE

static void tokenUntil(QXmlStreamReader &reader, QXmlStreamReader::TokenType target,
                       QList<int> &lineNumbers)
{
    int level = 0;
    while (!reader.atEnd()) {
        QXmlStreamReader::TokenType t = reader.readNext();
        if ((t == target) && (level == 0))
            return;
        if (t == QXmlStreamReader::StartElement) {
            ++level;
            QString line = reader.attributes().value(QLatin1String("line")).toString();
            if (!line.isEmpty())
                lineNumbers.append(line.toInt());
        } else if (t == QXmlStreamReader::EndElement) {
            --level;
        }
    }

}

QScriptXmlParser::Result QScriptXmlParser::parse(const QString &xml)
{
    QMap<QString, int> functionsInfo;
    QList<int> lineNumbers;
    QXmlStreamReader reader(xml);
    reader.readNext();
    reader.readNext();
    reader.readNext();
    while (reader.readNext() == QXmlStreamReader::StartElement) {

        int line = reader.attributes().value(QLatin1String("line")).toString().toInt();
        lineNumbers.append(line);
        if (reader.name() == QLatin1String("function-declaration")) {

            reader.readNext();
            reader.readNext();
            QString name = reader.text().toString();
            reader.readNext();
            reader.readNext();
            QStringList formalParameters;
            while (reader.readNext() == QXmlStreamReader::StartElement) {
                reader.readNext();
                formalParameters.append(reader.text().toString());
                reader.readNext();
            }
            reader.readNext();
            tokenUntil(reader, QXmlStreamReader::EndElement, lineNumbers);

            QString signature;
            signature.append(name);
            signature.append(QLatin1Char('('));
            for (int i = 0; i < formalParameters.size(); ++i) {
                if (i > 0)
                    signature.append(QLatin1String(", "));
                signature.append(formalParameters.at(i));
            }
            signature.append(QLatin1Char(')'));
            functionsInfo.insert(signature, line);
        } else if (reader.name() == QLatin1String("expression-statement")) {
            reader.readNext();
            if ((reader.name() == QLatin1String("binary-expression"))
                && reader.attributes().value(QLatin1String("op")) == QLatin1String("=")) {


                QString first, second, third;
                reader.readNext();
                if (reader.name() == QLatin1String("field-member-expression")) {
                    reader.readNext();
                    if (reader.name() == QLatin1String("field-member-expression")) {
                        reader.readNext();
                        if (reader.name() == QLatin1String("identifier")) {
                            reader.readNext();
                            first = reader.text().toString();
                        }
                        tokenUntil(reader, QXmlStreamReader::EndElement, lineNumbers);
                        reader.readNext();
                        if (reader.name() == QLatin1String("identifier")) {
                            reader.readNext();
                            second = reader.text().toString();
                        }
                        tokenUntil(reader, QXmlStreamReader::EndElement, lineNumbers);
                    } else if (reader.name() == QLatin1String("identifier")) {
                        reader.readNext();
                        first = reader.text().toString();
                    }
                    tokenUntil(reader, QXmlStreamReader::EndElement, lineNumbers);
                    reader.readNext();
                    if (reader.name() == QLatin1String("identifier")) {
                        reader.readNext();
                        if (second.isEmpty())
                            second = reader.text().toString();
                        else
                            third = reader.text().toString();
                    }
                    tokenUntil(reader, QXmlStreamReader::EndElement, lineNumbers);
                }
                tokenUntil(reader, QXmlStreamReader::EndElement, lineNumbers);
                reader.readNext();
                if (reader.name() == QLatin1String("function-expression")) {
                    if (!first.isEmpty()) {
                        QString signature = first;
                        if (!second.isEmpty()) {
                            signature.append(QLatin1Char('.'));
                            signature.append(second);
                            if (!third.isEmpty()) {
                                signature.append(QLatin1Char('.'));
                                signature.append(third);
                            }
                        }
                        signature.append(QLatin1String("()"));
                        functionsInfo.insert(signature, line);
                    }
                }
                tokenUntil(reader, QXmlStreamReader::EndElement, lineNumbers);
            }
            tokenUntil(reader, QXmlStreamReader::EndElement, lineNumbers);
        }
        tokenUntil(reader, QXmlStreamReader::EndElement, lineNumbers);
    }
    reader.readNext();
    reader.readNext();
    reader.readNext();
    Q_ASSERT(reader.atEnd());
    return Result(functionsInfo, lineNumbers.toSet());
}

QT_END_NAMESPACE
