

#include "IconDlg.h"
#include "IconMng.h"
#include "ItemBox.h"
#include <QMessageBox>
#include <QPainter>
#include <QGraphicsItem>
#include <QXmlStreamReader>
#include <GFunc.h>
#include "DesignerWnd.h"
#include "Mdi.h"
static int n = 0;
IconSetDlg::IconSetDlg(QPixmap& icon, QStringList& symbolInfo, QWidget* parent)
    :QDialog(parent),m_symbolInfo(symbolInfo),m_icon(icon)
{
    ui.setupUi(this);
    QString name = QString("Symbol%1").arg(n++);
    while (!UnqIconMng()->IsVaildIconName(ICONPREFIX+name))
    {
        name = QString("Symbol%1").arg(n++);
    }
    const QRegExp re = QRegExp(QLatin1String("[_a-zA-Z][_a-zA-Z0-9]*"));
    ui.lineEdit->setValidator(new QRegExpValidator(re, ui.lineEdit));
    ui.lineEdit->setText(name);
    ui.radioBtn_auto->setChecked(true);
}
bool IconSetDlg::Init()
{
    if (LoadTypeInfo())
    {
        ui.comboBox->addItems(m_iconTypeList);
        ui.comboBox->setCurrentIndex(0);
        return true;
    }
    else
    {
        return false;
    }
}
bool IconSetDlg::LoadTypeInfo()
{
    QMap<QString, QVariant> typeProperty;
    QMap<int, QStringList> iconType = UnqIconMng()->GetIconType();
    foreach(int type, iconType.keys())
    {
        QStringList typeinfo = iconType.value(type);
        if (typeinfo.length() > 0)
        {
            m_iconTypeList.append(typeinfo[0] + QString("-%1").arg(type));
        }
    }

    return true;
}
void IconSetDlg::on_buttonBox_clicked(QAbstractButton* button)
{
    if (button == (QAbstractButton*)ui.buttonBox->button(QDialogButtonBox::Cancel))
    {
        reject();
        return;
    }
    if (button == (QAbstractButton*)ui.buttonBox->button(QDialogButtonBox::Ok))
    {
        QString name=ui.lineEdit->text();
        QString desc=ui.textEdit->toPlainText();
        if(desc.isEmpty()) desc=name;
        if (name.isEmpty() || desc.isEmpty())
        {
            QMessageBox::warning(this,"", tr("Please enter icon name!"));
            return;
        }

        if (CDesignerWnd::CheckName(ICONPREFIX + name, true, true, desc) < 0)
			return;

        if (CDesignerWnd::CheckName(desc, true, true) < 0)
            return;

        if (!(ui.radioBtn_auto->isChecked() || ui.radioBtn_sel->isChecked()))
        {
            QMessageBox::warning(this,"", tr("Please select icon generation method!"));
            return;
        }
        QString iconType=ui.comboBox->currentText().section("-",1,1);
        m_symbolInfo << name << iconType << desc << m_iconPicFile;
        accept();
        return;
    }
}
void IconSetDlg::on_radioBtn_sel_clicked(bool checked)
{
	QString path = UnqFunc()->GetDir(CGFunc::PATH_TYPE_ITEMICON);
	m_iconPicFile = QFileDialog::getOpenFileName(this, QObject::tr("Open File"), path, QObject::tr("Images (*.png *.jpg *.bmp)"));
    if(!m_iconPicFile.isEmpty())
        bool beOk = m_icon.load(m_iconPicFile);
}
void IconSetDlg::on_radioBtn_auto_clicked(bool checked)
{
    m_icon.detach();
    m_icon = QPixmap();
}
