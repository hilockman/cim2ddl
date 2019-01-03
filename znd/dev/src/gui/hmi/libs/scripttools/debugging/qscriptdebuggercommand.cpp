#include "qscriptdebuggercommand_p.h"
#include "qscriptbreakpointdata_p.h"
#include "qscriptdebuggervalue_p.h"

#include <QtCore/qhash.h>
#include <QtCore/qdatastream.h>
#include <QtCore/qstringlist.h>

Q_DECLARE_METATYPE(QScriptBreakpointData)
Q_DECLARE_METATYPE(QScriptDebuggerValue)

QT_BEGIN_NAMESPACE
class QScriptDebuggerCommandPrivate
{
public:
    QScriptDebuggerCommandPrivate();
    ~QScriptDebuggerCommandPrivate();

    QScriptDebuggerCommand::Type type;
    QHash<QScriptDebuggerCommand::Attribute, QVariant> attributes;
};

QScriptDebuggerCommandPrivate::QScriptDebuggerCommandPrivate()
    : type(QScriptDebuggerCommand::None)
{
}

QScriptDebuggerCommandPrivate::~QScriptDebuggerCommandPrivate()
{
}




QScriptDebuggerCommand::QScriptDebuggerCommand()
    : d_ptr(new QScriptDebuggerCommandPrivate)
{
    d_ptr->type = None;
}





QScriptDebuggerCommand::QScriptDebuggerCommand(Type type)
    : d_ptr(new QScriptDebuggerCommandPrivate)
{
    d_ptr->type = type;
}





QScriptDebuggerCommand::QScriptDebuggerCommand(const QScriptDebuggerCommand &other)
    : d_ptr(new QScriptDebuggerCommandPrivate)
{
    *d_ptr = *other.d_ptr;
}




QScriptDebuggerCommand::~QScriptDebuggerCommand()
{
}




QScriptDebuggerCommand &QScriptDebuggerCommand::operator=(const QScriptDebuggerCommand &other)
{
    *d_ptr = *other.d_ptr;
    return *this;
}




QScriptDebuggerCommand::Type QScriptDebuggerCommand::type() const
{
    Q_D(const QScriptDebuggerCommand);
    return d->type;
}





QVariant QScriptDebuggerCommand::attribute(Attribute attribute,
                                           const QVariant &defaultValue) const
{
    Q_D(const QScriptDebuggerCommand);
    return d->attributes.value(attribute, defaultValue);
}




void QScriptDebuggerCommand::setAttribute(Attribute attribute,
                                          const QVariant &value)
{
    Q_D(QScriptDebuggerCommand);
    if (!value.isValid())
        d->attributes.remove(attribute);
    else
        d->attributes[attribute] = value;
}

QHash<QScriptDebuggerCommand::Attribute, QVariant> QScriptDebuggerCommand::attributes() const
{
    Q_D(const QScriptDebuggerCommand);
    return d->attributes;
}







QString QScriptDebuggerCommand::fileName() const
{
    Q_D(const QScriptDebuggerCommand);
    return d->attributes.value(FileName).toString();
}

void QScriptDebuggerCommand::setFileName(const QString &fileName)
{
    Q_D(QScriptDebuggerCommand);
    d->attributes[FileName] = fileName;
}







int QScriptDebuggerCommand::lineNumber() const
{
    Q_D(const QScriptDebuggerCommand);
    return d->attributes.value(LineNumber, -1).toInt();
}

void QScriptDebuggerCommand::setLineNumber(int lineNumber)
{
    Q_D(QScriptDebuggerCommand);
    d->attributes[LineNumber] = lineNumber;
}







qint64 QScriptDebuggerCommand::scriptId() const
{
    Q_D(const QScriptDebuggerCommand);
    return d->attributes.value(ScriptID, -1).toLongLong();
}

void QScriptDebuggerCommand::setScriptId(qint64 id)
{
    Q_D(QScriptDebuggerCommand);
    d->attributes[ScriptID] = id;
}

QString QScriptDebuggerCommand::program() const
{
    Q_D(const QScriptDebuggerCommand);
    return d->attributes.value(Program).toString();
}

void QScriptDebuggerCommand::setProgram(const QString &program)
{
    Q_D(QScriptDebuggerCommand);
    d->attributes[Program] = program;
}

int QScriptDebuggerCommand::breakpointId() const
{
    Q_D(const QScriptDebuggerCommand);
    return d->attributes.value(BreakpointID, -1).toInt();
}

void QScriptDebuggerCommand::setBreakpointId(int id)
{
    Q_D(QScriptDebuggerCommand);
    d->attributes[BreakpointID] = id;
}

QScriptBreakpointData QScriptDebuggerCommand::breakpointData() const
{
    Q_D(const QScriptDebuggerCommand);
    return qvariant_cast<QScriptBreakpointData>(d->attributes.value(BreakpointData));
}

void QScriptDebuggerCommand::setBreakpointData(const QScriptBreakpointData &data)
{
    Q_D(QScriptDebuggerCommand);
    d->attributes[BreakpointData] = QVariant::fromValue(data);
}

QScriptDebuggerValue QScriptDebuggerCommand::scriptValue() const
{
    Q_D(const QScriptDebuggerCommand);
    return qvariant_cast<QScriptDebuggerValue>(d->attributes.value(ScriptValue));
}

void QScriptDebuggerCommand::setScriptValue(const QScriptDebuggerValue &value)
{
    Q_D(QScriptDebuggerCommand);
    d->attributes[ScriptValue] = QVariant::fromValue(value);
}

int QScriptDebuggerCommand::contextIndex() const
{
    Q_D(const QScriptDebuggerCommand);
    return d->attributes.value(ContextIndex, -1).toInt();
}

void QScriptDebuggerCommand::setContextIndex(int index)
{
    Q_D(QScriptDebuggerCommand);
    d->attributes[ContextIndex] = index;
}

int QScriptDebuggerCommand::iteratorId() const
{
    Q_D(const QScriptDebuggerCommand);
    return d->attributes.value(IteratorID, -1).toInt();
}

void QScriptDebuggerCommand::setIteratorId(int id)
{
    Q_D(QScriptDebuggerCommand);
    d->attributes[IteratorID] = id;
}

QString QScriptDebuggerCommand::name() const
{
    Q_D(const QScriptDebuggerCommand);
    return d->attributes.value(Name).toString();
}

void QScriptDebuggerCommand::setName(const QString &name)
{
    Q_D(QScriptDebuggerCommand);
    d->attributes[Name] = name;
}

QScriptDebuggerValue QScriptDebuggerCommand::subordinateScriptValue() const
{
    Q_D(const QScriptDebuggerCommand);
    return qvariant_cast<QScriptDebuggerValue>(d->attributes.value(SubordinateScriptValue));
}

void QScriptDebuggerCommand::setSubordinateScriptValue(const QScriptDebuggerValue &value)
{
    Q_D(QScriptDebuggerCommand);
    d->attributes[SubordinateScriptValue] = QVariant::fromValue(value);
}

int QScriptDebuggerCommand::snapshotId() const
{
    Q_D(const QScriptDebuggerCommand);
    return d->attributes.value(SnapshotID, -1).toInt();
}

void QScriptDebuggerCommand::setSnapshotId(int id)
{
    Q_D(QScriptDebuggerCommand);
    d->attributes[SnapshotID] = id;
}





bool QScriptDebuggerCommand::operator==(const QScriptDebuggerCommand &other) const
{
    Q_D(const QScriptDebuggerCommand);
    const QScriptDebuggerCommandPrivate *od = other.d_func();
    if (d == od)
        return true;
    if (!d || !od)
        return false;
    return ((d->type == od->type)
            && (d->attributes == od->attributes));
}





bool QScriptDebuggerCommand::operator!=(const QScriptDebuggerCommand &other) const
{
    return !(*this == other);
}

QScriptDebuggerCommand QScriptDebuggerCommand::interruptCommand()
{
    QScriptDebuggerCommand cmd(Interrupt);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::continueCommand()
{
    QScriptDebuggerCommand cmd(Continue);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::stepIntoCommand(int count)
{
    QScriptDebuggerCommand cmd(StepInto);
    cmd.setAttribute(StepCount, count);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::stepOverCommand(int count)
{
    QScriptDebuggerCommand cmd(StepOver);
    cmd.setAttribute(StepCount, count);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::stepOutCommand()
{
    QScriptDebuggerCommand cmd(StepOut);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::runToLocationCommand(const QString &fileName, int lineNumber)
{
    QScriptDebuggerCommand cmd(RunToLocation);
    cmd.setFileName(fileName);
    cmd.setLineNumber(lineNumber);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::runToLocationCommand(qint64 scriptId, int lineNumber)
{
    QScriptDebuggerCommand cmd(RunToLocationByID);
    cmd.setScriptId(scriptId);
    cmd.setLineNumber(lineNumber);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::forceReturnCommand(int contextIndex, const QScriptDebuggerValue &value)
{
    QScriptDebuggerCommand cmd(ForceReturn);
    cmd.setContextIndex(contextIndex);
    cmd.setScriptValue(value);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::resumeCommand()
{
    QScriptDebuggerCommand cmd(Resume);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::setBreakpointCommand(const QString &fileName, int lineNumber)
{
    QScriptDebuggerCommand cmd(SetBreakpoint);
    cmd.setBreakpointData(QScriptBreakpointData(fileName, lineNumber));
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::setBreakpointCommand(const QScriptBreakpointData &data)
{
    QScriptDebuggerCommand cmd(SetBreakpoint);
    cmd.setBreakpointData(data);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::deleteBreakpointCommand(int id)
{
    QScriptDebuggerCommand cmd(DeleteBreakpoint);
    cmd.setBreakpointId(id);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::deleteAllBreakpointsCommand()
{
    QScriptDebuggerCommand cmd(DeleteAllBreakpoints);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getBreakpointsCommand()
{
    QScriptDebuggerCommand cmd(GetBreakpoints);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getBreakpointDataCommand(int id)
{
    QScriptDebuggerCommand cmd(GetBreakpointData);
    cmd.setBreakpointId(id);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::setBreakpointDataCommand(int id, const QScriptBreakpointData &data)
{
    QScriptDebuggerCommand cmd(SetBreakpointData);
    cmd.setBreakpointId(id);
    cmd.setBreakpointData(data);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getScriptsCommand()
{
    QScriptDebuggerCommand cmd(GetScripts);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getScriptDataCommand(qint64 id)
{
    QScriptDebuggerCommand cmd(GetScriptData);
    cmd.setScriptId(id);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::scriptsCheckpointCommand()
{
    QScriptDebuggerCommand cmd(ScriptsCheckpoint);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getScriptsDeltaCommand()
{
    QScriptDebuggerCommand cmd(GetScriptsDelta);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::resolveScriptCommand(const QString &fileName)
{
    QScriptDebuggerCommand cmd(ResolveScript);
    cmd.setFileName(fileName);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getBacktraceCommand()
{
    QScriptDebuggerCommand cmd(GetBacktrace);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getContextCountCommand()
{
    QScriptDebuggerCommand cmd(GetContextCount);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getContextStateCommand(int contextIndex)
{
    QScriptDebuggerCommand cmd(GetContextState);
    cmd.setContextIndex(contextIndex);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getContextInfoCommand(int contextIndex)
{
    QScriptDebuggerCommand cmd(GetContextInfo);
    cmd.setContextIndex(contextIndex);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getContextIdCommand(int contextIndex)
{
    QScriptDebuggerCommand cmd(GetContextID);
    cmd.setContextIndex(contextIndex);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getThisObjectCommand(int contextIndex)
{
    QScriptDebuggerCommand cmd(GetThisObject);
    cmd.setContextIndex(contextIndex);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getActivationObjectCommand(int contextIndex)
{
    QScriptDebuggerCommand cmd(GetActivationObject);
    cmd.setContextIndex(contextIndex);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getScopeChainCommand(int contextIndex)
{
    QScriptDebuggerCommand cmd(GetScopeChain);
    cmd.setContextIndex(contextIndex);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::contextsCheckpoint()
{
    QScriptDebuggerCommand cmd(ContextsCheckpoint);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getPropertyExpressionValue(
    int contextIndex, int lineNumber, const QStringList &path)
{
    QScriptDebuggerCommand cmd(GetPropertyExpressionValue);
    cmd.setContextIndex(contextIndex);
    cmd.setLineNumber(lineNumber);
    cmd.setAttribute(UserAttribute, path);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getCompletions(
    int contextIndex, const QStringList &path)
{
    QScriptDebuggerCommand cmd(GetCompletions);
    cmd.setContextIndex(contextIndex);
    cmd.setAttribute(UserAttribute, path);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::newScriptObjectSnapshotCommand()
{
    QScriptDebuggerCommand cmd(NewScriptObjectSnapshot);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::scriptObjectSnapshotCaptureCommand(int id, const QScriptDebuggerValue &object)
{
    Q_ASSERT(object.type() == QScriptDebuggerValue::ObjectValue);
    QScriptDebuggerCommand cmd(ScriptObjectSnapshotCapture);
    cmd.setSnapshotId(id);
    cmd.setScriptValue(object);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::deleteScriptObjectSnapshotCommand(int id)
{
    QScriptDebuggerCommand cmd(DeleteScriptObjectSnapshot);
    cmd.setSnapshotId(id);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::newScriptValueIteratorCommand(const QScriptDebuggerValue &object)
{
    QScriptDebuggerCommand cmd(NewScriptValueIterator);
    Q_ASSERT(object.type() == QScriptDebuggerValue::ObjectValue);
    cmd.setScriptValue(object);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::getPropertiesByIteratorCommand(int id, int count)
{
    Q_UNUSED(count);
    QScriptDebuggerCommand cmd(GetPropertiesByIterator);
    cmd.setIteratorId(id);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::deleteScriptValueIteratorCommand(int id)
{
    QScriptDebuggerCommand cmd(DeleteScriptValueIterator);
    cmd.setIteratorId(id);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::evaluateCommand(
    int contextIndex, const QString &program, const QString &fileName, int lineNumber)
{
    QScriptDebuggerCommand cmd(Evaluate);
    cmd.setContextIndex(contextIndex);
    cmd.setProgram(program);
    cmd.setFileName(fileName);
    cmd.setLineNumber(lineNumber);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::scriptValueToStringCommand(const QScriptDebuggerValue &value)
{
    QScriptDebuggerCommand cmd(ScriptValueToString);
    cmd.setScriptValue(value);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::setScriptValuePropertyCommand(
    const QScriptDebuggerValue &object, const QString &name,
    const QScriptDebuggerValue &value)
{
    QScriptDebuggerCommand cmd(SetScriptValueProperty);
    cmd.setScriptValue(object);
    cmd.setName(name);
    cmd.setSubordinateScriptValue(value);
    return cmd;
}

QScriptDebuggerCommand QScriptDebuggerCommand::clearExceptionsCommand()
{
    QScriptDebuggerCommand cmd(ClearExceptions);
    return cmd;
}







QDataStream &operator<<(QDataStream &out, const QScriptDebuggerCommand &command)
{
    const QScriptDebuggerCommandPrivate *d = command.d_ptr.data();
    out << (quint32)d->type;
    out << (qint32)d->attributes.size();
    QHash<QScriptDebuggerCommand::Attribute, QVariant>::const_iterator it;
    for (it = d->attributes.constBegin(); it != d->attributes.constEnd(); ++it) {
        out << (quint32)it.key();
        out << it.value();
    }
    return out;
}
QDataStream &operator>>(QDataStream &in, QScriptDebuggerCommand &command)
{
    QScriptDebuggerCommandPrivate *d = command.d_ptr.data();

    quint32 type;
    in >> type;
    d->type = QScriptDebuggerCommand::Type(type);

    qint32 attribCount;
    in >> attribCount;
    QHash<QScriptDebuggerCommand::Attribute, QVariant> attribs;
    for (qint32 i = 0; i < attribCount; ++i) {
        quint32 key;
        in >> key;
        QVariant value;
        in >> value;
        attribs[QScriptDebuggerCommand::Attribute(key)] = value;
    }
    d->attributes = attribs;

    return in;
}

QT_END_NAMESPACE