#ifndef QSCRIPTDEBUGGERSCRIPTSMODEL_P_H
#define QSCRIPTDEBUGGERSCRIPTSMODEL_P_H 
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qpair.h>

#include "qscriptscriptdata_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerScriptsModelPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerScriptsModel
    : public QAbstractItemModel
{
    Q_OBJECT
public:
    QScriptDebuggerScriptsModel(QObject *parent = 0);
    ~QScriptDebuggerScriptsModel();

    void removeScript(qint64 id);
    void addScript(qint64 id, const QScriptScriptData &data);
    void addExtraScriptInfo(
        qint64 id, const QMap<QString, int> &functionsInfo,
        const QSet<int> &executableLineNumbers);
    void commit();

    QScriptScriptData scriptData(qint64 id) const;
    QScriptScriptMap scripts() const;
    qint64 resolveScript(const QString &fileName) const;
    QSet<int> executableLineNumbers(qint64 scriptId) const;

    QModelIndex indexFromScriptId(qint64 id) const;
    qint64 scriptIdFromIndex(const QModelIndex &index) const;
    QPair<QString, int> scriptFunctionInfoFromIndex(const QModelIndex &index) const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

private:
    Q_DECLARE_PRIVATE(QScriptDebuggerScriptsModel)
    Q_DISABLE_COPY(QScriptDebuggerScriptsModel)
};

QT_END_NAMESPACE

#endif
