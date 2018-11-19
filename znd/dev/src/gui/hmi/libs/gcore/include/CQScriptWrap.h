

#ifndef CQSCRIPTWRAP_H
#define CQSCRIPTWRAP_H 

#include "Global.h"
#include <QtScript>

#ifdef QML
#include <QtQml>
#endif

class CBaseData;

class QSTimer : public QTimer
{
    Q_OBJECT
    Q_PROPERTY(int timerId READ timerId  )
public:
    QSTimer(QObject * parent = 0) : QTimer(parent) {}
    ~QSTimer(){};

};

class QSInput : public QObject
{
    Q_OBJECT
    Q_OVERRIDE(QCString name SCRIPTABLE false)
public:
    QSInput() : QObject(0)
    {
        setObjectName(QLatin1String("Input"));
    }

public slots:
    QVariant getText(const QString &label = QString::null,
                     const QString &text = QString::null,
                     const QString &title = QString::null,
                     QWidget *parent = 0);
    QVariant getNumber(const QString &label = QString::null,
                       double value = 0,
                       int decimals = 0,
                       double minValue = -2147483647,
                       double maxValue = 2147483647,
                       const QString &title = QString::null,
                       QWidget *parent = 0);
    QVariant getItem(const QString &label,
                     const QStringList &itemList,
                     const QString &currentItem = QString::null,
                     bool editable = false,
                     const QString &title = QString::null,
                     QWidget *parent = 0);
    QVariant getItem(const QStringList &itemList,
                     const QString &currentItem = QString::null,
                     bool editable = false,
                     QWidget *parent = 0) {
        return getItem(QString::null, itemList, currentItem, editable, QString::null, parent);
    }
};

class QSFileDialog : public QObject
{
    Q_OBJECT
    Q_OVERRIDE(QCString name SCRIPTABLE false)

public:
    QSFileDialog() : QObject(0)
    {
        setObjectName(QLatin1String("FileDialog"));
    }

public slots:
QVariant getOpenFileName(const QString &dir = QString::null,
                             const QString &filter = QString::null,
                             const QString &title = QString::null,
                             QWidget *parent = 0);
    QVariant getSaveFileName(const QString &filter = QString::null,
                             const QString &title = QString::null,
                             QWidget *parent = 0);
    QVariant getExistingDirectory(const QString &dir = QString::null,
                                  const QString &title = QString::null,
                                  QWidget *parent = 0);
    QStringList getOpenFileNames(const QString &dir = QString::null,
                                 const QString &filter = QString::null,
                                 const QString &title = QString::null,
                                 QWidget *parent = 0);
private:
    QString cap;
};
class QSMessageBox : public QObject
{
    Q_OBJECT
    Q_OVERRIDE(QCString name SCRIPTABLE false)
    Q_ENUMS(ButtonType)
public:
    enum ButtonType { NoButton , Ok, Cancel, Yes , No, Abort,
                      Retry, Ignore };

    QSMessageBox() : QObject(0)
    {
        setObjectName(QLatin1String("MessageBox"));
    }

public slots:
    int information(const QString &text,
                    ButtonType button0 = Yes, ButtonType button1 = No, ButtonType button2 = NoButton,
                    const QString &title = "Tips",
                    QWidget *parent = 0);

    int warning(const QString &text,
                ButtonType button0 = Retry,
                ButtonType button1 = Abort,
                ButtonType button2 = NoButton,
                const QString &title = "Tips",
                QWidget *parent = 0);

    int critical(const QString &text,
                 ButtonType button0 = Retry,
                 ButtonType button1 = NoButton,
                 ButtonType button2 = NoButton,
                 const QString &title = "Tips",
                 QWidget *parent = 0);

private:
    int getQMesButton(ButtonType btnType);
    int getButtonType(int QMesStandardButton);
    QString cap;
};

class QSWidget : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString whatsThis READ whatsThis WRITE setWhatsThis)
    Q_PROPERTY(QString toolTip READ toolTip WRITE setToolTip)
    Q_OVERRIDE(QCString name SCRIPTABLE false)
public:
    QSWidget(QWidget *w = 0) : widget(w) {}
    QWidget *widget;
    QString whatsThis() const;
    void setWhatsThis(const QString &text) const;
    QString toolTip() const;
    void setToolTip(const QString &text) const;
};

#define QS_WIDGET(Class) \
    inline Q##Class *d() const { return (Q##Class*)widget; }

class QSLabel : public QSWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    inline QLabel *d() const { return (QLabel *) widget; }
public:
    QSLabel() : QSWidget(new QLabel(0)) {}
    QString text() const
    { return d()->text(); }
    void setText(const QString &txt)
    { d()->setText(txt); }
};

class QSLabeled : public QSWidget
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label WRITE setLabel)
public:
    QSLabeled(const QString& label, QWidget *w);
    inline QString label() const { return labelWidget->text(); }
    void setLabel(const QString &txt);
    QLabel *labelWidget;
};


class QSLineEdit : public QSLabeled
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    QS_WIDGET(LineEdit)
    public:
        QSLineEdit() : QSLabeled(QSInput::tr("Text:"), new QLineEdit(0)) {}
    QString text() const
    { return d()->text(); }
    void setText(const QString &txt)
    { d()->setText(txt); }
};

class QSNumberEdit : public QSLabeled
{
    Q_OBJECT
    Q_PROPERTY(double value READ value WRITE setValue)
    Q_PROPERTY(double decimals READ decimals WRITE setDecimals)
    Q_PROPERTY(double minimum READ minimum WRITE setMinimum)
    Q_PROPERTY(double maximum READ maximum WRITE setMaximum)
    QS_WIDGET(LineEdit)
    public:
        QSNumberEdit() : QSLabeled(QSInput::tr("Value:"), new QLineEdit(0)), validator(new QDoubleValidator(widget))
    {
        d()->setValidator(validator);
        validator->setDecimals(0);
    }
    double value() const
    { return d()->text().toDouble(); }
    void setValue(double val)
    { d()->setText(QString::number(val)); }
    double decimals() const
    { return validator->decimals(); }
    void setDecimals(double decimals)
    { validator->setDecimals(int(decimals)); }
    double minimum() const
    { return validator->bottom(); }
    void setMinimum(double minimum)
    { validator->setBottom(minimum); }
    double maximum() const
    { return validator->top(); }
    void setMaximum(double maximum)
    { validator->setBottom(maximum); }
private:
    QDoubleValidator *validator;
};

class QSDateEditEnums : public QObject
{
    Q_OBJECT
    Q_ENUMS(Order)
    Q_OVERRIDE(QCString name SCRIPTABLE false)
public:
    enum Order { DMY, MDY, YMD, YDM };
};

class QSDateEdit : public QSLabeled
{
    Q_OBJECT
    Q_ENUMS(Order)
    Q_PROPERTY(int order READ order WRITE setOrder)
    Q_PROPERTY(QDate date READ date WRITE setDate)
    Q_PROPERTY(QDate minimum READ minimum WRITE setMinimum)
    Q_PROPERTY(QDate maximum READ maximum WRITE setMaximum)
    QS_WIDGET(DateEdit)
    public:
        enum Order { DMY, MDY, YMD, YDM };
    QSDateEdit() : QSLabeled(tr("Date:"), new QDateEdit(0))
    { }

    int order() const
    {
        QString format = d()->displayFormat();
        if (format == "dd.MM.yyyy") return DMY;
        else if (format == "MM.dd.yyyy") return MDY;
        else if (format == "yyyy.MM.dd") return YMD;
        else if (format == "yyyy.dd.MM") return YDM;
        return -1;;
    }

    void setOrder(int order)
    {
        if (order == DMY) d()->setDisplayFormat("dd.MM.yyyy");
        else if (order == MDY) d()->setDisplayFormat("MM.dd.yyyy");
        else if (order == YMD) d()->setDisplayFormat("yyyy.MM.dd");
        else if (order == YDM) d()->setDisplayFormat("yyyy.dd.MM");
    }

    QDate date() const { return d()->date(); }
    void setDate(QDate date) { d()->setDate(date); }
    QDate minimum() const { return d()->minimumDate(); }
    void setMinimum(const QDate &minimum) { d()->setMinimumDate(minimum); }
    QDate maximum() const { return d()->maximumDate(); }
    void setMaximum(const QDate &maximum) { d()->setMaximumDate(maximum); }
};

class QSTimeEdit : public QSLabeled
{
    Q_OBJECT
    Q_PROPERTY(bool showSeconds READ seconds WRITE setSeconds)
    Q_PROPERTY(bool showAMPM READ ampm WRITE setAmpm)
    Q_PROPERTY(QTime time READ time WRITE setTime)
    Q_PROPERTY(QTime minimum READ minimum WRITE setMinimum)
    Q_PROPERTY(QTime maximum READ maximum WRITE setMaximum)
    QS_WIDGET(TimeEdit)
    public:
        QSTimeEdit() : QSLabeled(tr("Time:"), new QTimeEdit(0))
    { }

    void updateDisplayFormat(bool ampm, bool secs)
    {
        QString baseFormat = "HH::mm";
        if (ampm)
            baseFormat = "AP" + baseFormat;
        if (secs)
            baseFormat += ":ss";
        d()->setDisplayFormat(baseFormat);
    }

    bool seconds() const { return d()->displayFormat().contains("ss"); }
    void setSeconds(bool b) { updateDisplayFormat(ampm(), b); }

    bool ampm() const { return d()->displayFormat().toLower().contains("ap"); }
    void setAmpm(bool b) { updateDisplayFormat(b, seconds()); }

    QTime time() const { return d()->time(); }
    void setTime(QTime time) { d()->setTime(time); }

    QTime minimum() const { return d()->minimumTime(); }
    void setMinimum(const QTime &minimum) { d()->setMinimumTime(minimum); }

    QTime maximum() const { return d()->maximumTime(); }
    void setMaximum(const QTime &maximum) { d()->setMaximumTime(maximum); }
};

class QSTextEdit : public QSWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    QS_WIDGET(TextEdit)
    public:
        QSTextEdit() : QSWidget(new QTextEdit(0))
    { }
    QString text() const
    { return d()->toPlainText(); }
    void setText(const QString &txt)
    { d()->setPlainText(txt); }
};

class QSSpinBox : public QSLabeled
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue)
    Q_PROPERTY(int minimum READ minimum WRITE setMinimum)
    Q_PROPERTY(int maximum READ maximum WRITE setMaximum)
    QS_WIDGET(SpinBox)
    public:
        QSSpinBox() : QSLabeled(QSInput::tr("Value:"), new QSpinBox(0)) {}
    int value() const
    { return d()->value(); }
    void setValue(int val)
    { d()->setValue(val); }
    int minimum() const
    { return d()->value(); }
    void setMinimum(int minimum)
    { d()->setMinimum(minimum); }
    int maximum() const
    { return d()->value(); }
    void setMaximum(int maximum)
    { d()->setMaximum(maximum); }
};

class QSCheckBox : public QSWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(bool checked READ isChecked WRITE setChecked)
    QS_WIDGET(CheckBox)
    public:
        QSCheckBox() : QSWidget(new QCheckBox(0)) {}
    QString text() const
    { return d()->text(); }
    void setText(const QString &txt)
    { d()->setText(txt); }

    bool isChecked() const
    { return d()->isChecked(); }
    void setChecked(bool b)
    { d()->setChecked(b); }
};

class QSRadioButton : public QSWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(bool checked READ isChecked WRITE setChecked)
    QS_WIDGET(RadioButton)
    public:
        QSRadioButton() : QSWidget(new QRadioButton(0)) {}
    QString text() const
    { return d()->text(); }
    void setText(const QString &txt)
    { d()->setText(txt); }

    bool isChecked() const
    { return d()->isChecked(); }
    void setChecked(bool b)
    { d()->setChecked(b); }
};

class QSComboBox : public QSLabeled
{
    Q_OBJECT
    Q_PROPERTY(QStringList itemList READ itemList WRITE setItemList)
    Q_PROPERTY(QString currentItem READ currentItem WRITE setCurrentItem)
    Q_PROPERTY(bool editable READ isEditable WRITE setEditable)
    QS_WIDGET(ComboBox)
    public:
        QSComboBox() : QSLabeled(QSInput::tr("Item:"), new QComboBox(0))
    {
        setEditable(false);
    }
    QString currentItem() const
    { return d()->currentText(); }
    void setCurrentItem(const QString &txt)
    {
        int idx = d()->findText(txt);
        if (idx >= 0)
            d()->setCurrentIndex(idx);
    }
    bool isEditable() const
    { return d()->isEditable(); }
    void setEditable(bool b)
    { d()->setEditable(b); }
    QStringList itemList() const;
    void setItemList(const QStringList &l)
    {
        d()->clear();
        d()->insertItems(0, l);
    }
};

class QSGroupBox : public QSWidget
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle)
    QS_WIDGET(GroupBox)
    public:
        QSGroupBox();
    QString title() const
    { return d()->title(); }
    void setTitle(const QString &title)
    { d()->setTitle(title); }
public slots:
    void add(QSWidget *widget);
    void newColumn();
    void addSpace(int space);
private:
    QButtonGroup *invisibleButtonGroup;
    QHBoxLayout *hbox;
    QGridLayout *grid;
};

class QSDialogPrivate;
class QSDialog : public QSWidget
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(int width READ width WRITE setWidth)
    Q_PROPERTY(QString okButtonText READ okButtonText WRITE setOkButtonText)
    Q_PROPERTY(QString cancelButtonText READ cancelButtonText WRITE setCancelButtonText)
    QSDialogPrivate *d;
public:
    QSDialog(const QString &caption = QString::null, QWidget *parent=0);
    ~QSDialog();

    void setTitle(const QString &title);
    QString title() const;

    void setWidth(int width);
    int width() const;

    void setOkButtonText(const QString &text);
    QString okButtonText() const;

    void setCancelButtonText(const QString &text);
    QString cancelButtonText() const;

public slots:
    void newTab(const QString &label);
    void newColumn();
    void addSpace(int space);
    void add(QSWidget *widget);
    bool exec();

};
class QSButtonGroup : public QButtonGroup
{
    Q_OBJECT
public:
    QSButtonGroup( QObject * parent = 0);
    ~QSButtonGroup();
	
signals:
    void ButtonToggled(int id, bool checked);
	void ButtonClicked(int id);
	void ButtonPressed(int id);
	void ButtonReleased(int id);

public slots:
    void addQSButton(QAbstractButton *widget);
    void addQSButton(QAbstractButton *widget, int id);
    int CheckedID ();
    int BtnID( QAbstractButton * button );
	QObject* Btn(int id);
    void RemoveButton ( QAbstractButton * button );
    void SetBtnID ( QAbstractButton * button, int id );
};

class File : public QObject
{
    Q_OBJECT
public:
    File( QObject* parent=0);
    ~File();
public slots:
    QVariant Read( const QString& type);
	//////Write 返回写入的字节数///////
    int  Write(const QString& type,const QVariant& val);
    bool Open(QString fileName,const QString& mode="rw");
	void SetByteOrder(int bo);//0:QDataStream::BigEndian; 1:QDataStream::LittleEndian, default is BigEndian，master need LittleEndian
    void Close();
	void Clear();
	QStringList Utf8codecArray(QString str);//////获取文字的utf8码数组，用于计算字节数、和/////////

private:
    QFile m_File;
    QDataStream m_Stream;
};


class QSManager :public QObject
{
    Q_OBJECT
public:
    QSManager(QObject * parent = 0 ):QObject(parent){};
    virtual ~QSManager(){};
    void SetQSEngine(QScriptEngine *engine){m_Engine=engine;};

    static QScriptValue create(QScriptContext *context, QScriptEngine *engine);
public slots:
    bool LoadDLL(QString dllName,QString ObjName);
    bool Create(QString context );
    bool Include(QString filePathName);
private:
    static QScriptValue Create(QString context, QScriptEngine *engine);
private:
    QScriptEngine *m_Engine;
};

QSManager * QSManagerInstance();
////
/// \brief The CScriptDebugger class
///
class CScriptDebugger:public QScriptEngineAgent
{
public:
    CScriptDebugger( QScriptEngine *engine):QScriptEngineAgent(engine){};
    ~CScriptDebugger(){};
    void exceptionThrow(qint64 scriptId,const QScriptValue &exception,bool hasHandler);
    void exceptionCatch(qint64 scriptId,const QScriptValue &exception);
    void errorMessage(const QString &text);
};

///
/// \brief The CScriptEngine class
///
class DLL_CLASS CScriptEngine :public QScriptEngine
{

public:
    CScriptEngine(QObject * parent = 0 );
    virtual ~CScriptEngine();
public:
    void EnableDebug(bool enable);
    int AddObject(QObject* object,QString alias_name=QString());
    QVariant Call( const QString & function, const QVariantList & args =QVariantList(),CBaseData* self=0,QObject * context = 0 );
    QVariant Evaluate(const QString & code,CBaseData* self=0, const QString & errfileName=QString(), int startlineNumber=1);
    QVariant LoadFile(QString fileName);
    int Clear();
    void SetQsaSelf(CBaseData* item);

};

#ifdef QML
class DLL_CLASS CQmlEngine :public QQmlEngine
{
public:
    CQmlEngine(QObject * parent = 0 );
    virtual ~CQmlEngine();
public:
    int AddObject(QObject* object,QString alias_name=QString());
    QVariant Call( const QString & function, const QVariantList & args =QVariantList(),CBaseData* self=0,QObject * context = 0 );
    QVariant Evaluate(const QString & code,CBaseData* self=0, const QString & errfileName=QString(), int startlineNumber=1);
    QVariant LoadFile(const QString& fileName);
    int Clear();
    void SetQsaSelf(CBaseData* item);
private:
    QJSValue toQScriptValue( const QVariant& qvar);
    QObject* m_RootObj;

};
#endif

#endif
