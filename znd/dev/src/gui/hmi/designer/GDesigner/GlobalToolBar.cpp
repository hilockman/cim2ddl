

#include "GFunc.h"
#include "GlobalToolBar.h"
#include "ItemCreator.h"
#include "DesignerWnd.h"
#include "DesignerScene.h"

GlobalToolBarCreator::GlobalToolBarCreator(QMainWindow* win) : QObject(win)
{
    m_window = win;
    QString iconbuf;

    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ACTIONICON, "bold.png", iconbuf);
    boldAction = new QAction(QPixmap( iconbuf ),tr("Bold"), win);
    boldAction->setCheckable(true);
    boldAction->setShortcut(tr("Ctrl+B"));
    connect(boldAction, SIGNAL(triggered()), this, SLOT(handleFontChange()));

    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ACTIONICON, "italic.png", iconbuf);
    italicAction = new QAction(QPixmap( iconbuf ),tr("Italic"), win);
    italicAction->setCheckable(true);
    italicAction->setShortcut(tr("Ctrl+I"));
    connect(italicAction, SIGNAL(triggered()), this, SLOT(handleFontChange()));

    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ACTIONICON, "underline.png", iconbuf);
    underlineAction = new QAction(QPixmap( iconbuf ),tr("underline"), win);
    underlineAction->setCheckable(true);
    underlineAction->setShortcut(tr("Ctrl+U"));
    connect(underlineAction, SIGNAL(triggered()),this, SLOT(handleFontChange()));

    fontCombo = new QFontComboBox();
	fontCombo->setCurrentFont(QFont("Arial"));
    connect(fontCombo, SIGNAL(currentFontChanged(QFont)),this, SLOT(currentFontChanged(QFont)));

    fontSizeCombo = new QComboBox;
    fontSizeCombo->setEditable(true);
    for (int i = 8; i < 30; i = i + 2)
        fontSizeCombo->addItem(QString().setNum(i));
	fontSizeCombo->setCurrentText("12");
    QIntValidator* validator = new QIntValidator(2, 64, this);
    fontSizeCombo->setValidator(validator);
    connect(fontSizeCombo, SIGNAL(currentIndexChanged(QString)),this, SLOT(fontSizeChanged(QString)));

    QToolBar* textToolBar = win->addToolBar(tr("Font"));
    textToolBar->setObjectName("fontbar");
    textToolBar->addWidget(fontCombo);
    textToolBar->addWidget(fontSizeCombo);
    textToolBar->addAction(boldAction);
    textToolBar->addAction(italicAction);
    textToolBar->addAction(underlineAction);


    /*fontColorToolButton = new QToolButton;
    fontColorToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    fontColorToolButton->setMenu(createColorMenu(SLOT(textColorChanged()), Qt::black));

    textAction = fontColorToolButton->menu()->defaultAction();
    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ACTIONICON, "textpointer.png", iconbuf);
    fontColorToolButton->setIcon(createColorToolButtonIcon( iconbuf, Qt::black));
    fontColorToolButton->setAutoFillBackground(true);
    connect(fontColorToolButton, SIGNAL(clicked()), this, SLOT(textButtonTriggered()));*/


    fillColorToolButton = new QToolButton;
    fillColorToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    fillColorToolButton->setMenu(createColorMenu(SLOT(itemColorChanged()), Qt::white,"fcolor"));
    fillAction = fillColorToolButton->menu()->defaultAction();
    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ACTIONICON, "floodfill.png", iconbuf);
    fillColorToolButton->setIcon(createColorToolButtonIcon( iconbuf, Qt::white));
    connect(fillColorToolButton, SIGNAL(clicked()), this, SLOT(fillButtonTriggered()));


    lineColorToolButton = new QToolButton;
    lineColorToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    lineColorToolButton->setMenu(createColorMenu(SLOT(lineColorChanged()), Qt::black,"lcolor"));
    lineAction = lineColorToolButton->menu()->defaultAction();
    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ACTIONICON, "linecolor.png", iconbuf);
    lineColorToolButton->setIcon(createColorToolButtonIcon( iconbuf, Qt::black));
    connect(lineColorToolButton, SIGNAL(clicked()), this, SLOT(lineButtonTriggered()));

    QToolBar* colorToolBar = win->addToolBar(tr("Color"));
    colorToolBar->setObjectName("colorbar");
    //colorToolBar->addWidget(fontColorToolButton);
    colorToolBar->addWidget(fillColorToolButton);
    colorToolBar->addWidget(lineColorToolButton);


    QToolBar* patchToolBar = win->addToolBar(tr("Patch"));
    patchToolBar->setObjectName("patchbar");
    patchCreateItemCheck = new QCheckBox;
	UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ACTIONICON, "patch.png", iconbuf);
	patchCreateItemCheck->setIcon(QIcon(iconbuf));
	patchCreateItemCheck->setToolTip(tr("PatchCreate"));
    createNum = new QSpinBox;
	createNum->setToolTip(tr("CreateNum"));
    createNum->setMinimum(1);
    patchToolBar->addWidget(patchCreateItemCheck);
    patchToolBar->addWidget(createNum);
    createNum->setEnabled(false);
    connect(patchCreateItemCheck, SIGNAL(stateChanged(int)), this, SLOT(patchCheckChanged(int)));
    connect(createNum, SIGNAL(valueChanged(int)), this, SLOT(patchCheckChanged(int)));
}

void GlobalToolBarCreator::setDrawSettings(QVariantMap& settings)
{
    QColor linecolor=QColor(settings["linecolor"].toString());
    QColor fillcolor=QColor(settings["fillcolor"].toString());
    QString iconbuf;

    if(linecolor.isValid())
    {
        UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ACTIONICON, "linecolor.png", iconbuf);
        lineColorToolButton->setIcon(createColorToolButtonIcon(iconbuf,  linecolor ));
        ItemCreator::SetDefaultLineColor(linecolor);
        ItemCreator::SetDefaultTextColor(linecolor);
    }
    if(fillcolor.isValid())
    {
        UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ACTIONICON, "floodfill.png", iconbuf);
        fillColorToolButton->setIcon(createColorToolButtonIcon(iconbuf, QColor(fillcolor)));
        ItemCreator::SetDefaultFillColor(fillcolor);
    }
}

void GlobalToolBarCreator::patchCheckChanged(int state)
{
    if (sender()->inherits("QCheckBox"))
    {
        if (state == Qt::Checked)
        {
            createNum->setEnabled(true);
            int patchCreateNum = createNum->value();
            ((CDesignerWnd*)m_window)->OnPatchCreateChanged(true, patchCreateNum);
        }
        else
        {
            createNum->setEnabled(false);
            ((CDesignerWnd*)m_window)->OnPatchCreateChanged(false, 0);
        }
    }
    else
    {
        int patchCreateNum = createNum->value();
        ((CDesignerWnd*)m_window)->OnPatchCreateChanged(true, patchCreateNum);
    }
}

void GlobalToolBarCreator::currentFontChanged(const QFont& )
{
    handleFontChange();
}


void GlobalToolBarCreator::fontSizeChanged(const QString& )
{
    handleFontChange();
}


//void GlobalToolBarCreator::textColorChanged()
//{
//    textAction = qobject_cast<QAction* >(sender());
//
//    QString iconbuf;
//    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ACTIONICON, "textpointer.png", iconbuf);
//    fontColorToolButton->setIcon(createColorToolButtonIcon(iconbuf, textAction->data().value<QColor>()));
//    textButtonTriggered();
//
//
//}


void GlobalToolBarCreator::itemColorChanged()
{
    fillAction = qobject_cast<QAction* >(sender());
    QString iconbuf;
    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ACTIONICON, "floodfill.png", iconbuf);

    fillColorToolButton->setIcon(createColorToolButtonIcon(iconbuf, fillAction->data().value<QColor>()));
    fillButtonTriggered();
}



void GlobalToolBarCreator::lineColorChanged()
{
    lineAction = qobject_cast<QAction* >(sender());
    QString iconbuf;
    UnqFunc()->GetFilePathName(CGFunc::PATH_TYPE_ACTIONICON, "linecolor.png", iconbuf);

    lineColorToolButton->setIcon(createColorToolButtonIcon(iconbuf, lineAction->data().value<QColor>()));
    lineButtonTriggered();
}



//void GlobalToolBarCreator::textButtonTriggered()
//{
//    ItemCreator::SetDefaultTextColor(textAction->data().value<QColor>());
//    ((CDesignerWnd*)m_window)->ActiveScene()->onGlobalSetChanged(QObject::tr("lineColor"), textAction->data());
//}


void GlobalToolBarCreator::fillButtonTriggered()
{
    ItemCreator::SetDefaultFillColor(fillAction->data().value<QColor>());
    if(((CDesignerWnd*)m_window)->ActiveScene())
        ((CDesignerWnd*)m_window)->ActiveScene()->onGlobalSetChanged(QObject::tr("fillColor"), fillAction->data());
}



void GlobalToolBarCreator::lineButtonTriggered()
{
    ItemCreator::SetDefaultLineColor(lineAction->data().value<QColor>());
	ItemCreator::SetDefaultTextColor(lineAction->data().value<QColor>());
    if(((CDesignerWnd*)m_window)->ActiveScene())
        ((CDesignerWnd*)m_window)->ActiveScene()->onGlobalSetChanged(QObject::tr("lineColor"), lineAction->data());
}



void GlobalToolBarCreator::handleFontChange()
{
    QFont font = fontCombo->currentFont();
    font.setPointSize(fontSizeCombo->currentText().toInt());
    font.setWeight(boldAction->isChecked() ? QFont::Bold : QFont::Normal);
    font.setItalic(italicAction->isChecked());
    font.setUnderline(underlineAction->isChecked());

    ItemCreator::SetDefaultFont(font);
    if(((CDesignerWnd*)m_window)->ActiveScene())
        ((CDesignerWnd*)m_window)->ActiveScene()->onGlobalSetChanged(QObject::tr("font"), font);
}

static QList<QColor> g_GetColorList()
{
    QList<QColor> colors;
    QColor  none;
    colors<<Qt::black<<Qt::white<<Qt::red<<Qt::blue<<Qt::yellow<<Qt::gray <<Qt::cyan<<Qt::magenta<<none;
    return colors;
}

static QStringList g_GetNameList()
{
    QStringList names;
    names <<"black"<<"white"<<"red"<<"blue"<<"yellow"<<"gray"<<"cyan"<<"magenta"<<"none";
    return names;
}

void GlobalToolBarCreator::getColor()
{
    QAction* action = qobject_cast<QAction* >(sender());
    QColor color=QColorDialog::getColor(action->data().value<QColor>(),m_window);
    action->setData(color);
    action->setIcon(createColorIcon(color));
    if(action->objectName()=="fcolor")
    {
        m_customfcolor->setData(color);
        m_customfcolor->trigger();
    }
    else
    {
        m_customlcolor->setData(color);
        m_customlcolor->trigger();
    }

}

QMenu* GlobalToolBarCreator::createColorMenu(const char* slot, QColor defaultColor,QString flag)
{
    static QList<QColor> colors = g_GetColorList();
    static QStringList names = g_GetNameList();

    QMenu* colorMenu = new QMenu();
    for (int i = 0; i < colors.count(); ++i)
    {
        QAction* action = new QAction(names.at(i), parent());
        action->setData(colors.at(i));
        action->setIcon(createColorIcon(colors.at(i)));
        connect(action, SIGNAL(triggered()), this, slot);
        colorMenu->addAction(action);
        if (colors.at(i) == defaultColor)
        {
            colorMenu->setDefaultAction(action);
        }
    }
    QAction* caction = new QAction(tr("custom"), parent());
    caction->setObjectName(flag);
    connect(caction, SIGNAL(triggered()), this, SLOT(getColor()));
    colorMenu->addAction(caction);

    if(flag=="fcolor")
    {
        m_customfcolor = new QAction(flag, parent());
        connect(m_customfcolor, SIGNAL(triggered()), this, slot);
    }
    else
    {
        m_customlcolor = new QAction(flag, parent());
        connect(m_customlcolor, SIGNAL(triggered()), this, slot);
    }

    return colorMenu;
}



QIcon GlobalToolBarCreator::createColorToolButtonIcon(const QString& imageFile, QColor color)
{
    QPixmap pixmap(50, 80);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    QPixmap image(imageFile);
    QRect target(0, 0, 50, 60);
    QRect source(0, 0, 42, 42);
    painter.fillRect(QRect(0, 60, 50, 80), color);
    painter.drawPixmap(target, image, source);

    return QIcon(pixmap);
}



QIcon GlobalToolBarCreator::createColorIcon(QColor color)
{
    QPixmap pixmap(20, 20);
    QPainter painter(&pixmap);
    painter.setPen(Qt::NoPen);
    painter.fillRect(QRect(0, 0, 20, 20), color);

    return QIcon(pixmap);
}
