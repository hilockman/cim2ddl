#include <QtScript>
#include "GraphItem.h"
#include "CQScriptWrap.h"
#include "GFunc.h"
#include "IPluginQScript.h"
#include "IconMng.h"
#include "GraphView.h"
#include "GraphSvgRW.h"

QVariant QSInput::getText(const QString &label, const QString &text, const QString &title,
                          QWidget *parent)
{
    bool ok;
    QString lab = label;
    if (lab.isEmpty())
        lab = tr("Text:");
    QString res = QInputDialog::getText(parent ? parent : qApp->activeWindow(), title,
                                        lab, QLineEdit::Normal, text, &ok);

    return (ok ? QVariant(res) : QVariant());
}

QVariant QSInput::getNumber(const QString &label, double value,
                            int decimals, double minValue, double maxValue,
                            const QString &title, QWidget *parent)
{
    QString lab = label;
    if (lab.isEmpty())
        lab = tr("Number:");
    bool ok;
    if (decimals > 0) {
        double d = QInputDialog::getDouble(parent ? parent : qApp->activeWindow(), title, lab,
                                           value, minValue, maxValue, decimals, &ok);
        return (ok ? QVariant(d) : QVariant());
    }
    int i = QInputDialog::getInt(parent ? parent : qApp->activeWindow(), title, lab, int(value),
                                 int(minValue), int(maxValue), 1, &ok);
    return (ok ? QVariant(i) : QVariant());
}


QVariant QSInput::getItem(const QString &label,
                          const QStringList &itemList,
                          const QString &currentItem,
                          bool editable,
                          const QString &title,
                          QWidget *parent)
{
    QString lab = label;
    if (lab.isEmpty())
        lab = tr("Item:");
    int idx = 0;
    if (!currentItem.isEmpty())
        idx = itemList.indexOf(currentItem);
    bool ok;
    QString res = QInputDialog::getItem(parent ? parent : qApp->activeWindow(), title,
                                        lab, itemList, qMax(idx,0), editable, &ok);
    return (ok ? QVariant(res) : QVariant());
}





QVariant QSFileDialog::getOpenFileName(const QString &dir, const QString &filter, const QString &title,
                                       QWidget *parent)
{
	QString str = QFileDialog::getOpenFileName(parent ? parent : qApp->activeWindow(), title, dir, filter, 0);
    return str.isNull() ? QVariant() : QVariant(str);
}

QVariant QSFileDialog::getSaveFileName(const QString &filter, const QString &title,
                                       QWidget *parent)
{
    QString str = QFileDialog::getSaveFileName(parent ? parent : qApp->activeWindow(), title, QString::null, filter,
                                               0);
    return str.isNull() ? QVariant() : QVariant(str);
}

QVariant QSFileDialog::getExistingDirectory(const QString &dir, const QString &title,
                                            QWidget *parent)
{
    QString str = QFileDialog::getExistingDirectory(parent ? parent : qApp->activeWindow(), title, dir, 0);
    return str.isNull() ? QVariant() : QVariant(str);
}

QStringList QSFileDialog::getOpenFileNames(const QString &dir,
                                           const QString &filter,
                                           const QString &title,
                                           QWidget *parent)
{
	return QFileDialog::getOpenFileNames(parent ? parent : qApp->activeWindow(), title, dir, filter, 0);
}



int QSMessageBox::getQMesButton(ButtonType btnType)
{
    int btn = QMessageBox::NoButton;
    switch (btnType)
    {
    case Ok:
        btn = QMessageBox::Ok;
        break;
    case Cancel:
        btn = QMessageBox::Cancel;
        break;
    case Yes:
        btn = QMessageBox::Yes;
        break;
    case No:
        btn = QMessageBox::No;
        break;
    case Abort:
        btn = QMessageBox::Abort;
        break;
    case Retry:
        btn = QMessageBox::Retry;
        break;
    case Ignore:
        btn = QMessageBox::Ignore;
        break;
    default:
        break;
    }
    return btn;
}

int QSMessageBox::getButtonType(int QMesStandardButton)
{
    int btn = NoButton;
    switch (QMesStandardButton)
    {
    case QMessageBox::Ok:
        btn = Ok;
        break;
    case QMessageBox::Cancel:
        btn = Cancel;
        break;
    case QMessageBox::Yes:
        btn = Yes;
        break;
    case QMessageBox::No:
        btn = No;
        break;
    case QMessageBox::Abort:
        btn = Abort;
        break;
    case QMessageBox::Retry:
        btn = Retry;
        break;
    case QMessageBox::Ignore:
        btn = Ignore;
        break;
    default:
        break;
    }
    return btn;
}

int QSMessageBox::information(const QString &text,
                              ButtonType button0,
                              ButtonType button1,
                              ButtonType button2,
                              const QString &title,
                              QWidget *parent)
{
	int standButton = QMessageBox::information(parent,
                                              title, text, getQMesButton(button0), getQMesButton(button1), getQMesButton(button2) );
    return getButtonType(standButton);
}
int QSMessageBox::warning(const QString &text,
                          ButtonType button0,
                          ButtonType button1,
                          ButtonType button2,
                          const QString &title,
                          QWidget *parent)
{
    int standButton = QMessageBox::warning(parent, title, text, getQMesButton(button0), getQMesButton(button1), getQMesButton(button2));
    return getButtonType(standButton);
}

int QSMessageBox::critical(const QString &text,
                           ButtonType button0,
                           ButtonType button1,
                           ButtonType button2,
                           const QString &title,
                           QWidget *parent)
{
    int standButton = QMessageBox::critical(parent, title, text, getQMesButton(button0), getQMesButton(button1), getQMesButton(button2));
    return getButtonType(standButton);
}




QString QSWidget::whatsThis() const
{
    return widget->whatsThis();
}

void QSWidget::setWhatsThis(const QString &text) const
{
    widget->setWhatsThis(text);
}

QString QSWidget::toolTip() const
{
    return widget->toolTip();
}

void QSWidget::setToolTip(const QString &text) const
{
    widget->setToolTip(text);
}

#define QS_WIDGET(Class) \
    inline Q##Class *d() const { return (Q##Class*)widget; }




void QSLabeled::setLabel(const QString &txt)
{
    labelWidget->setText(txt);
    if(txt.isEmpty())
        labelWidget->hide();
}

QSLabeled::QSLabeled(const QString& label, QWidget *w)
    : QSWidget(w), labelWidget(new QLabel(label,0))
{
    labelWidget->setBuddy(w);
}
QStringList QSComboBox::itemList() const
{
    QStringList l;
    for (int i = 0; i < d()->count(); ++i)
        l << d()->itemText(i);
    return l;
}



QSGroupBox::QSGroupBox()
    : QSWidget(new QGroupBox), invisibleButtonGroup(0)
{
    hbox = new QHBoxLayout(d());
    grid = new QGridLayout();

    hbox->addLayout(grid);
    grid->setAlignment(Qt::AlignTop);
}

void QSGroupBox::add(QSWidget *widget)
{
    QWidget *w = widget->widget;

    int row = grid->rowCount();
    if (qobject_cast<QSLabeled *>(widget)) {
        QLabel *label = ((QSLabeled*)widget)->labelWidget;
        grid->addWidget(label, row, 0);
        grid->addWidget(w, row, 1);
        label->setVisible(!label->text().isEmpty());
    } else {
        grid->addWidget(w, row, 0, 1, 2);
    }

    if (w && qobject_cast<QRadioButton *>(w)) {
        if (!invisibleButtonGroup)
            invisibleButtonGroup = new QButtonGroup(d());
        invisibleButtonGroup->addButton(qobject_cast<QRadioButton *>(w));
    }

}

void QSGroupBox::addSpace(int space)
{
    QSpacerItem *spacer = new QSpacerItem(0, qMax(space,0), QSizePolicy::Fixed, QSizePolicy::Fixed);
    grid->addItem(spacer, grid->rowCount(), 1);
    invisibleButtonGroup = 0;
}

void QSGroupBox::newColumn() {
    if (grid->rowCount()) {
        hbox->addSpacing(17);
        grid = new QGridLayout;
        grid->setAlignment(Qt::AlignTop);
        hbox->addLayout(grid);
    }
}



class QSDialogPrivate : public QDialog
{
public:
    QSDialogPrivate(QWidget *parent=0);
    int width;
    QSize sizeHint() const { return QDialog::sizeHint().expandedTo(QSize(width, 0)); }
    QWidget *lastWidget;

    QHBoxLayout *hbox;
    QGridLayout *grid;

    QButtonGroup *invisibleButtonGroup;
    QTabWidget *tabWidget;
    QGroupBox *groupBox;

    QHBoxLayout *buttonRow;
    void fixTabOrder();

    QPushButton *okButton, *cancelButton;
    QWidget *parent;

    void addSpace(int space);
    void add(QSWidget *widget);
};


QSDialogPrivate::QSDialogPrivate(QWidget *parent)
    : QDialog(parent),
      width(0), lastWidget(0),
      invisibleButtonGroup(0), tabWidget(0), groupBox(0)
{
    this->parent = this;

    QVBoxLayout *vbox = new QVBoxLayout(this);
    setLayout(vbox);

    hbox = new QHBoxLayout;
    vbox->addLayout(hbox);

    grid = new QGridLayout;
    hbox->addLayout(grid);
    grid->setAlignment(Qt::AlignTop);

    okButton = new QPushButton(QMessageBox::tr("OK"), this);
    okButton->setDefault(true);
    QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    cancelButton = new QPushButton(QMessageBox::tr("Cancel"), this);
    QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    buttonRow = new QHBoxLayout;
    vbox->addLayout(buttonRow);
    buttonRow->addStretch(10);
    buttonRow->addWidget(okButton);
    buttonRow->addWidget(cancelButton);
}

void QSDialogPrivate::fixTabOrder()
{
    if (lastWidget) {
        if (lastWidget) {
            QWidget::setTabOrder(lastWidget, okButton);
            QWidget::setTabOrder(okButton, cancelButton);
        }
        layout()->activate();
        lastWidget = 0;
    }
}

void QSDialogPrivate::addSpace(int space)
{
    QSpacerItem *spacer = new QSpacerItem(0, qMax(space,0), QSizePolicy::Fixed, QSizePolicy::Fixed);
    grid->addItem(spacer, grid->rowCount(), 1);
    invisibleButtonGroup = 0;
}

void QSDialogPrivate::add(QSWidget *widget)
{
    QWidget *w = widget->widget;

    int row = grid->rowCount();
    if (qobject_cast<QSLabeled *>(widget)) {
        QLabel *label = ((QSLabeled*)widget)->labelWidget;
        label->setVisible(!label->text().isEmpty());
        grid->addWidget(label, row, 0);
        grid->addWidget(w, row, 1);
    } else {
        grid->addWidget(w, row, 0, 1, 2);
    }

    if (w && qobject_cast<QRadioButton *>(w)) {
        if (!invisibleButtonGroup)
            invisibleButtonGroup = new QButtonGroup(this);
        invisibleButtonGroup->addButton(qobject_cast<QRadioButton *>(w));
    }

    lastWidget = w;
}

QSDialog::QSDialog(const QString &title, QWidget *parent)
{
    d = new QSDialogPrivate(parent);
    widget = d;
    if (!title.isEmpty())
        setTitle(title);
}

QSDialog::~QSDialog()
{
    delete d;
}

void QSDialog::setTitle(const QString &title) { d->setWindowTitle(title); }
QString QSDialog::title() const { return d->windowTitle(); }
void QSDialog::setWidth(int width){ d->width = width; }
int QSDialog::width() const { return d->width; }
void QSDialog::setOkButtonText(const QString &text) { d->okButton->setText(text); }
QString QSDialog::okButtonText() const { return d->okButton->text(); }
void QSDialog::setCancelButtonText(const QString &text) { d->cancelButton->setText(text); }
QString QSDialog::cancelButtonText() const { return d->cancelButton->text(); }

void QSDialog::newTab(const QString &label)
{
    if (!d->tabWidget) {
        d->tabWidget = new QTabWidget(d);
        int row = d->grid->rowCount();
        d->grid->addWidget(d->tabWidget, row, 0, 1, 2);
    }
    QWidget *w = new QWidget;
    d->tabWidget->addTab(w, label);
    d->parent = w;
    d->hbox = new QHBoxLayout(w);
    d->grid = new QGridLayout(0);
    d->hbox->addLayout(d->grid);
    d->grid->setAlignment(Qt::AlignTop);
}

void QSDialog::newColumn()
{
    if (d->grid->rowCount()) {
        d->hbox->addSpacing(17);
        d->grid = new QGridLayout(0);
        d->hbox->addLayout(d->grid);
        d->grid->setAlignment(Qt::AlignTop);
    }
}

void QSDialog::addSpace(int space)
{
    d->addSpace(space);
}

void QSDialog::add(QSWidget *widget)
{
    d->add(widget);
}

bool QSDialog::exec()
{
    d->fixTabOrder();
    int res = d->exec();
    return (res == QDialog::Accepted);
}

QSButtonGroup::QSButtonGroup(QObject * parent )
    :QButtonGroup( parent )
{
    connect(this, SIGNAL(buttonToggled(int, bool)), this, SIGNAL(ButtonToggled(int, bool)));
	connect(this, SIGNAL(buttonClicked(int)), this, SIGNAL(ButtonClicked(int)));
	connect(this, SIGNAL(buttonPressed(int)), this, SIGNAL(ButtonPressed(int)));
	connect(this, SIGNAL(buttonReleased(int)), this, SIGNAL(ButtonReleased(int)));
}
QSButtonGroup::~QSButtonGroup()
{
}
void QSButtonGroup::addQSButton(QAbstractButton *widget)
{
    addButton( widget );
}

void QSButtonGroup::addQSButton(QAbstractButton *widget, int id)
{
    addButton( widget, id );
}

int QSButtonGroup::CheckedID ()
{
    return checkedId();
}
int QSButtonGroup::BtnID( QAbstractButton * button )
{
    return id( button );
}
QObject* QSButtonGroup::Btn(int id)
{
	return (QObject*)button(id);
}
void QSButtonGroup::RemoveButton ( QAbstractButton * button )
{
    removeButton( button );
}


void QSButtonGroup::SetBtnID ( QAbstractButton * button, int id )
{
    setId ( button, id );
}

////

File::File(QObject* parent ): QObject( parent )
{

}
File::~File()
{

}

QVariant File::Read( const QString& type)
{

    return "";
}

int  File::Write(const QString& type,const QVariant& val)
{

	if (type == "bool"){ m_Stream << val.toBool(); return 1; }
	else if (type == "char")
	{ 
		QChar qc = val.toChar();/////QChar是两个字节/////////
		m_Stream << qc.cell();
		return 1;
	}
	else if (type == "short"){	m_Stream << (short)(val.toInt()); return 2;	}
	else if (type == "int") { m_Stream << val.toInt(); return 4;}
	else if (type == "float") {	m_Stream << val.toFloat(); return 4;}
	else if (type == "string"){ 
		QByteArray by = val.toString().toUtf8();//////存储string的utf8码//////
		uchar* puchar = (uchar*)by.data();///////必须用uchar//////////
		for (int i = 0; i < by.size(); i++)
		{
			m_Stream << puchar[i];
		}
		return by.size();
	}

    return 0;

}

QStringList File::Utf8codecArray(QString str)
{
	QStringList ret;
	QByteArray by = str.toUtf8();//////存储string的utf8码//////
	uchar* puchar = (uchar*)by.data();///////必须用uchar//////////
	for (int i = 0; i < by.size(); i++)
	{
		ret.append(QString("0x%1").arg(QString::number(puchar[i], 16)));
	}
	return ret;
}

bool File::Open(QString fileName,const QString& mode)
{
    QString pathfileName=fileName;
    if (false==QDir::isAbsolutePath(fileName))
    {
        pathfileName=UnqFunc()->GetSysHome()+QDir::separator()+fileName;
    }

    m_File.setFileName(pathfileName);
    if (m_File.open(QFile::ReadWrite ))
    {
        m_Stream.setDevice(&m_File);
        return true;
    }
    return false;

}

void File::Close()
{
    m_File.close();

}

void File::Clear()
{
	m_File.resize(0);
}

void File::SetByteOrder(int bo)//0:QDataStream::BigEndian; 1:QDataStream::LittleEndian, default is BigEndian
{
	m_Stream.setByteOrder(QDataStream::ByteOrder(bo));
}

QSManager * QSManagerInstance()
{
    static QSManager _instance;
    return &_instance;
}



QScriptValue QSManager::Create(QString context, QScriptEngine *engine)
{
    QString src = context ;
    if (src=="MessageBox")
    {
        return engine->newQObject(new QSMessageBox(), QScriptEngine::ScriptOwnership);
    }
    else if(src=="Dialog")
    {
        return engine->newQObject(new QSDialog(), QScriptEngine::ScriptOwnership);
    }
    else if (src=="ComboBox")
    {
        return engine->newQObject(new QSComboBox(), QScriptEngine::ScriptOwnership);
    }
    else if (src=="InputDlg")
    {
        return engine->newQObject(new QSInput(), QScriptEngine::ScriptOwnership);
    }
    else if (src=="FileDlg")
    {
        return engine->newQObject(new QSFileDialog(), QScriptEngine::ScriptOwnership);
    }
    else if (src=="File")
    {
        return engine->newQObject(new File(), QScriptEngine::ScriptOwnership);
    }
    else if (src=="Timer")
    {
		return engine->newQObject(new QSTimer(), QScriptEngine::QtOwnership);
    }
    else if (src=="TimerSingleShot")
    {
        return engine->newQObject(new QSTimer(), QScriptEngine::ScriptOwnership);
    }
    else if (src=="xmlReader")
    {
        return engine->newQObject(new CGraphSvgReader(), QScriptEngine::ScriptOwnership);
    }
    else if (src=="xmlWriter")
    {
        return engine->newQObject(new CGraphSvgWriter(), QScriptEngine::ScriptOwnership);
    }
    return QScriptValue();

}

bool QSManager::Create(QString context )
{
    Create( context, m_Engine);
    return true;
}

QScriptValue QSManager::create(QScriptContext *context, QScriptEngine *engine)
{
    QString src = context->argument(0).toString();
    return Create(src, engine);
}

bool QSManager::LoadDLL(QString dllName,QString ObjName)
{
    QObject* customObj=NULL;
    QString path=UnqFunc()->GetDir(CGFunc::PATH_TYPE_DLL);

    QDir pluginsDir = QDir(path);
    QString fileName;
    try
    {
#ifdef WIN32
        fileName=dllName;
#else
        if ( dllName.contains(QRegExp("^lib")))
            fileName=dllName;
        else
        {
            dllName.replace(".dll",".so");
            fileName+="lib";
            fileName+=dllName;
        }
#endif
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin)
        {
            PluginQScriptInterface *m_pPlugInInterface = qobject_cast<PluginQScriptInterface *>(plugin);
            if (m_pPlugInInterface)
            {
                std::vector<void*> ptr_vect;
                bool ret=m_pPlugInInterface->Create(&customObj,ptr_vect);



            }
        }
        else
        {

        }

        if (customObj)
        {

            QScriptValue objectValue = m_Engine->newQObject(customObj);
            m_Engine->globalObject().setProperty(ObjName, objectValue);
            return true;
        }
        else
        {

        }

    }
    catch (...)
    {

    }
    return false;

}

bool QSManager::Include(QString filePathName)
{
    QFile scriptFile(filePathName);

    if(!scriptFile.open(QIODevice::ReadOnly))
    {
        QString err=scriptFile.errorString();
        QMessageBox::warning(NULL, "Tips" , "Can not load script file "+filePathName+" err:"+err);
        return false;
    }

    QTextStream stream(&scriptFile);
    QString s=stream.readAll();
    scriptFile.close();

    QScriptContext *context = m_Engine->currentContext();
    QScriptContext *parent=context->parentContext();
    if(parent!=0)
    {
        context->setActivationObject(context->parentContext()->activationObject());
        context->setThisObject(context->parentContext()->thisObject());
    }

    QScriptValue result = m_Engine->evaluate(s);
    return true;
}



QScriptValue toQScriptValue( QScriptEngine* eng,const QVariant& qvar)
{
    switch(qvar.type())
    {
    case QVariant::Bool:
    case QVariant::Char:
    case QVariant::Int:
    case QVariant::UInt:
        return QScriptValue(eng,qvar.toInt());
    case QVariant::Double:
        return QScriptValue(eng,qvar.toDouble());
    case QVariant::String:
        return QScriptValue(eng,qvar.toString());
    default:
        return QScriptValue(eng,qvar.toString());
    }
}

Q_DECLARE_METATYPE(QSButtonGroup*)

QScriptValue myQSButtonGroupConstructor(QScriptContext *context,
                                        QScriptEngine *engine)
{
    QObject *parent = context->argument(0).toQObject();
    QSButtonGroup *bg = new QSButtonGroup(parent);
    return engine->newQObject(bg, QScriptEngine::ScriptOwnership);
}

//
QScriptValue toScriptValueQPoint(QScriptEngine *engine, const QPoint &s)
{
  QScriptValue obj = engine->newObject();
  obj.setProperty("x", s.x());
  obj.setProperty("y", s.y());
  return obj;
}

void fromScriptValueQPoint(const QScriptValue &obj, QPoint &s)
{
  s.setX(  obj.property("x").toInt32());
  s.setY(obj.property("y").toInt32());
}

QScriptValue toScriptValueQPointF(QScriptEngine *engine, const QPointF &s)
{
  QScriptValue obj = engine->newObject();
  obj.setProperty("x", s.x());
  obj.setProperty("y", s.y());
  return obj;
}

void fromScriptValueQPointF(const QScriptValue &obj, QPointF &s)
{
  s.setX(  obj.property("x").toInteger());
  s.setY(obj.property("y").toInteger());
}

QScriptValue toScriptValueQRect(QScriptEngine *engine, const QRect &s)
{
  QScriptValue obj = engine->newObject();
  obj.setProperty("x", s.x());
  obj.setProperty("y", s.y());
  obj.setProperty("width", s.width());
  obj.setProperty("height", s.height());
  return obj;
}

void fromScriptValueQRect(const QScriptValue &obj, QRect &s)
{
  s.setX(obj.property("x").toInt32());
  s.setY(obj.property("y").toInt32());
  s.setWidth( obj.property("width").toInt32());
  s.setHeight(obj.property("height").toInt32());
}

QScriptValue toScriptValueQRectF(QScriptEngine *engine, const QRectF &s)
{
  QScriptValue obj = engine->newObject();
  obj.setProperty("x", s.x());
  obj.setProperty("y", s.y());
  obj.setProperty("width", s.width());
  obj.setProperty("height", s.height());
  return obj;
}

void fromScriptValueQRectF(const QScriptValue &obj, QRectF &s)
{
  s.setX(obj.property("x").toInteger());
  s.setY(obj.property("y").toInteger());
  s.setWidth( obj.property("width").toInteger());
  s.setHeight(obj.property("height").toInteger());
}

QScriptValue toScriptValueQSize(QScriptEngine *engine, const QSize &s)
{
  QScriptValue obj = engine->newObject();
  obj.setProperty("width", s.width());
  obj.setProperty("height", s.height());
  return obj;
}

void fromScriptValueQSize(const QScriptValue &obj, QSize &s)
{
  s.setWidth( obj.property("width").toInt32());
  s.setHeight(obj.property("height").toInt32());
}

QScriptValue toScriptValueQColor(QScriptEngine *engine, const QColor &s)
{
  QScriptValue obj(engine,s.name());
  //obj.setProperty("width", s.width());
  //obj.setProperty("height", s.height());
  return obj;
}

void fromScriptValueQColor(const QScriptValue &obj, QColor &s)
{
    s=QColor(obj.toString());
}


QScriptValue Include(QScriptContext *context,QScriptEngine *engine)
{
    QString fileName = context->argument(0).toString();
    QFile file( fileName );
    if(!file.exists())
    {
        QString file_path_name;
        UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_SCRIPT,fileName,file_path_name);
        file.setFileName(file_path_name);
    }
    if ( !file.open( QIODevice::ReadOnly ) )
    {
        QString err=file.errorString();
        QMessageBox::warning(NULL, "Tips" , "Can not load script file "+fileName+" err:"+err);
        return QString();
    }
    QTextStream str( &file );
    QString code=str.readAll();
    //set ScriptContext
    QScriptContext *context1 = engine->currentContext();
    QScriptContext *parent = context1->parentContext();
    if (parent != 0)
    {
        context1->setActivationObject(context1->parentContext()->activationObject());
        context1->setThisObject(context1->parentContext()->thisObject());
    }

	QString  errfileName = fileName;
    int startlineNumber=1;
    int line_number = 0;
    try
    {
        QScriptValue a= engine->evaluate(code,errfileName,startlineNumber);
        if ( engine->hasUncaughtException() )
        {
            line_number = engine->uncaughtExceptionLineNumber();
            QString error=engine->uncaughtException().toString();
            QStringList btrace=engine->uncaughtExceptionBacktrace();
			QString msg = QString::fromLatin1("-------Evaluate exception:%0 ,file:%1,line:%2;trace:%3").arg(error).arg(fileName).arg(line_number).arg(btrace.join(","));
            gWarn(msg.toLocal8Bit().data());
        }
        return QScriptValue();

    }
    catch(...)
    {
        return QScriptValue();
    }

}

///
CScriptEngine::CScriptEngine(QObject *parent)
    : QScriptEngine(parent)
{
    QScriptValue objectValue = newQObject(UnqFunc());
    globalObject().setProperty("Func", objectValue);

    QScriptValue ctor = newFunction(myQSButtonGroupConstructor);
    globalObject().setProperty("QSButtonGroup", ctor);

    QScriptValue constructor = newFunction(&QSManager::create);
    globalObject().setProperty("create",constructor);

    QScriptValue func1 = newFunction(Include);
    globalObject().setProperty("include", func1);

/*
    QSManagerInstance()->SetQSEngine(this);
    QScriptValue objectValue1 = newQObject(QSManagerInstance());
    globalObject().setProperty("Qsm", objectValue1);
*/

    QScriptValue iconMng = newQObject(UnqIconMng());
    globalObject().setProperty("IconMng", iconMng);


    AddObject(qApp,"qApp");
    qScriptRegisterMetaType(this, toScriptValueQPoint, fromScriptValueQPoint);
    qScriptRegisterMetaType(this, toScriptValueQPointF, fromScriptValueQPointF);
    qScriptRegisterMetaType(this, toScriptValueQRect, fromScriptValueQRect);
    qScriptRegisterMetaType(this, toScriptValueQRectF, fromScriptValueQRectF);
    qScriptRegisterMetaType(this, toScriptValueQSize, fromScriptValueQSize);
    qScriptRegisterMetaType(this, toScriptValueQColor, fromScriptValueQColor);


}

CScriptEngine::~CScriptEngine()
{
    abortEvaluation();
}
int CScriptEngine::AddObject(QObject* object,QString alias_name)
{

    if (object==NULL)
    {
        return -1;
    }

    if (alias_name.isEmpty())
    {
        alias_name=object->objectName();
    }
    QScriptValue objectValue = newQObject(object);
    globalObject().setProperty(alias_name, objectValue);
    return 0;
}

QVariant CScriptEngine::Call( const QString & fun_name, const QVariantList & args , CBaseData* self,QObject * context)
{
    SetQsaSelf(self);
    QVariant ret;
    QScriptValue fun;
    if (fun_name.left(8)=="function")
    {
        QString tmp_str="("+fun_name+")";
        fun = evaluate(tmp_str);
    }
    else
        fun=globalObject().property(fun_name);

    if (fun.isFunction())
    {
        QScriptValueList arguments;
        for (int i=0;i<args.size();i++)
        {
            arguments<<toQScriptValue(this,args[i]);
        }
        ret=fun.call(globalObject(),arguments).toVariant();
    }
    else
        ret=Evaluate(fun_name);

    return ret;
}

QVariant CScriptEngine::Evaluate( const QString & code, CBaseData* self,const QString & errfileName, int startlineNumber)
{
    SetQsaSelf(self);
    int line_number = 0;
    try
    {
        QScriptValue a= evaluate(code,errfileName,startlineNumber);
        if ( hasUncaughtException() )
        {
            line_number = uncaughtExceptionLineNumber();
            QString error=uncaughtException().toString();
            QStringList btrace=uncaughtExceptionBacktrace(); 
			QString msg = QString::fromLatin1("-------Evaluate exception:%0 ,file:%1,line:%2;trace:%3").arg(error).arg(errfileName).arg(line_number).arg(btrace.join(","));
            gWarn(msg.toLocal8Bit().data());

        }
        return a.toVariant();

    }
    catch(...)
    {
        return -1;
    }
}

int CScriptEngine::Clear()
{

    return 0;
}

QVariant CScriptEngine::LoadFile( QString fileName )
{
    QFile file( fileName );
    if(!file.exists())
    {
        QString file_path_name;
        UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_SCRIPT,fileName,file_path_name);
        file.setFileName(file_path_name);
    }
    if ( !file.open( QIODevice::ReadOnly ) )
    {
        QString err=file.errorString();
        QMessageBox::warning(NULL, "Tips" , "Can not load script file "+fileName+" err:"+err);
        return QString();
    }
    QTextStream str( &file );
    QString code=str.readAll();
    //set ScriptContext
    QScriptContext *context = currentContext();
    QScriptContext *parent = context->parentContext();
    if (parent != 0)
    {
        context->setActivationObject(context->parentContext()->activationObject());
        context->setThisObject(context->parentContext()->thisObject());
    }

    return Evaluate(code,0,fileName);
}

void CScriptEngine::SetQsaSelf(CBaseData* item)
{
    if (item)
    {
        globalObject().setProperty("self",newQObject(item));
    }

}

void CScriptEngine::EnableDebug(bool enable)
{
    if(enable==false && agent())
    {
        setAgent(0);
    }
    if(enable && !agent())
    {
        setAgent(new CScriptDebugger(this));
    }

}
////////////////


void CScriptDebugger::errorMessage(const QString &text)
{

}
void CScriptDebugger::exceptionCatch(qint64 scriptId,const QScriptValue &exception)
{
    exceptionThrow(scriptId ,  exception, true);
}

void CScriptDebugger::exceptionThrow(qint64  scriptId , const QScriptValue &exception, bool hasHandler)
{
    if (!hasHandler) {
        QScriptContext *ctx = engine()->currentContext();
        QScriptContextInfo info( ctx);
        int lineNumber = info.lineNumber();
        QString fileName = info.fileName();
		QString functionName = info.functionName()+"()";
		CGraphView* view = (CGraphView*)(engine()->globalObject().property("Me").toQObject());
		if (view != NULL)
            fileName = view->CurrentFile()+"@"+fileName;
		QString msg = QString::fromLatin1("uncaught exception: [ %1 ] at %2::%3 :line %4").arg(exception.toString()).arg(fileName).arg(functionName).arg(lineNumber);
        gError(msg.toLocal8Bit().data());
    }
}

#ifdef QML
////////////////////
/// \brief CQmlEngine::CQmlEngine
/// \param parent

CQmlEngine::CQmlEngine(QObject *parent)
    : QQmlEngine(parent),m_RootObj(0)
{
    rootContext()->setContextProperty("GTimer", new QTimer());
    rootContext()->setContextProperty("Func", UnqFunc());
}

CQmlEngine::~CQmlEngine()
{

}

QJSValue CQmlEngine::toQScriptValue( const QVariant& qvar)
{
    switch(qvar.type())
    {
    case QVariant::Bool:
    case QVariant::Char:
    case QVariant::Int:
    case QVariant::UInt:
        return QJSValue( qvar.toInt());
    case QVariant::Double:
        return QJSValue( qvar.toDouble());
    case QVariant::String:
        return QJSValue( qvar.toString());
    default:
        return QJSValue( qvar.toString());
    }
}
int CQmlEngine::AddObject(QObject* object,QString alias_name)
{

    if (object==NULL)
    {
        return -1;
    }
    if (alias_name.isEmpty())
    {
        alias_name=object->objectName();
    }
    rootContext()->setContextProperty(alias_name,object);
    return 0;

}

QVariant CQmlEngine::Call( const QString & fun_name, const QVariantList & args , CBaseData* self,QObject * context)
{
    QObject *object = m_RootObj;

    QVariant returnedValue;
    QMetaObject::invokeMethod(object, fun_name.toLocal8Bit().data(), Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, args));
    //qDebug() << "QML function returned:" << fun_name<<returnedValue.toString();
    return returnedValue;


    SetQsaSelf(self);
    QVariant ret;
    QJSValue fun;
    if (fun_name.left(9)=="function(")
    {
        QString tmp_str="("+fun_name+")";
        fun = evaluate(tmp_str);
    }
    else
        fun=globalObject().property(fun_name);

    if (fun.isCallable() )
    {
        QJSValueList arguments;
        for (int i=0;i<args.size();i++)
        {
            arguments<<toQScriptValue( args[i]);
        }
        ret=fun.call( arguments).toVariant();
    }
    else
        ret=Evaluate(fun_name);

    return ret;
}

QVariant CQmlEngine::Evaluate( const QString & code, CBaseData* self,const QString & errfileName, int startlineNumber)
{
    //qDebug() << "------CQmlEngine::Evaluate-------" << code;
    SetQsaSelf(self);
    int line_number = 0;
    try
    {
        QJSValue result= evaluate(code,errfileName,startlineNumber);
        if (result.isError())
        {
            qDebug() << "uncaught exception:" << result.toString();
        }
        return result.toVariant();

    }
    catch(...)
    {
        return -1;
    }
}

int CQmlEngine::Clear()
{


    return 0;
}

QVariant CQmlEngine::LoadFile(const QString &fileName )
{
    QString file_path_name=fileName;
    QFile file( file_path_name );
    if(!file.exists())
    {
        UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_SCRIPT,fileName,file_path_name);
        file.setFileName(file_path_name);
    }
    if ( !file.open( QIODevice::ReadOnly ) )
    {
        QMessageBox::warning(NULL, "Tips" , "Can not find script file£º"+fileName);
        return QString();
    }
    QQmlComponent * component=new QQmlComponent(this, QUrl::fromLocalFile(file_path_name));
    m_RootObj=component->create();
    return 0;
}

void CQmlEngine::SetQsaSelf(CBaseData* item)
{
    if (item)
    {
        globalObject().setProperty("self",newQObject(item));
    }

}
#endif
