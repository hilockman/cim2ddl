

#include <QtGui>
#include "CDyTableItemDelegate.h"
#include "Colorbutton.h"

int g_width=48;
static QPixmap BrushPixmap(int shape)
{
    QPainter p;
    QPixmap pix(g_width,16);
    pix.fill("White");
    p.begin(&pix);
    if (shape<15)
        p.setBrush(Qt::BrushStyle(shape));
    if (shape==Qt::LinearGradientPattern)
    {
        QLinearGradient gradient(0,0,100,100);
        gradient.setColorAt(0.0,Qt::white);
        gradient.setColorAt(0.2,Qt::red);
        gradient.setColorAt(0.8,Qt::black);

        p.setBrush(gradient);

    }
    if(shape==Qt::RadialGradientPattern)
    {
        QRadialGradient rgradient(30,7,20,50,12);
        p.setBrush(rgradient);

    }
    if(shape==Qt::ConicalGradientPattern)
    {
        QConicalGradient cgradient(31,7,45);
        p.setBrush(cgradient);

    }
    p.drawRect(0,0,g_width-2,14);
    p.end();

    return pix;
}


static void addBrush(QComboBox *combo, int shape)
{
    combo->addItem(BrushPixmap(shape), QString(), shape);
}


QWidget *GCNoEditorDelegate::createEditor(QWidget *parent,
                                          const QStyleOptionViewItem &option,
                                          const QModelIndex &index) const
{
    int exist = m_ReadOnlyCols.indexOf( index.column() );
    if ( exist != -1 )
    {
        return NULL;
    }
    else
    {
        return QItemDelegate::createEditor(parent,option,index);
    }
}

void GCNoEditorDelegate::insertColumn( int col )
{
    m_ReadOnlyCols.push_back( col );
}

void CDyTableDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    int disp_type = index.data( Qt::UserRole).toInt();
    switch (disp_type ) {
    case QVariant::Brush:
    {
        int bs = index.data( Qt::UserRole+1).toInt();
        painter->save();
        QRect rect = option.rect.adjusted( 10, 6, 4,4);
        rect.setSize( QSize(g_width, 16) );
        painter->drawPixmap( rect, BrushPixmap( bs ));
        painter->restore();
        return;
    }
        break;
    default:
        QItemDelegate::paint(painter, option, index);
        break;
    }
}



QWidget *CDyTableDelegate::createEditor(QWidget *parent,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const

{
    int disp_type = index.data( Qt::UserRole ).toInt();
    switch (disp_type ) {
    case QVariant::Brush:
    {
        QComboBox *combo = new QComboBox(parent);
        combo->view()->setTextElideMode(Qt::ElideNone);
        combo->setFrame(0);
        combo->setIconSize(QSize(g_width,16));

        addBrush(combo, Qt::NoBrush);
        addBrush(combo, Qt::SolidPattern);
        addBrush(combo, Qt::Dense1Pattern);
        addBrush(combo, Qt::Dense2Pattern);
        addBrush(combo, Qt::Dense3Pattern);
        addBrush(combo, Qt::Dense4Pattern);
        addBrush(combo, Qt::Dense5Pattern);
        addBrush(combo, Qt::Dense6Pattern);
        addBrush(combo, Qt::Dense7Pattern);
        addBrush(combo, Qt::HorPattern);
        addBrush(combo, Qt::VerPattern);
        addBrush(combo, Qt::CrossPattern);
        addBrush(combo, Qt::BDiagPattern);
        addBrush(combo, Qt::FDiagPattern);
        addBrush(combo, Qt::DiagCrossPattern);
        addBrush(combo, Qt::LinearGradientPattern);
        addBrush(combo, Qt::RadialGradientPattern);
        addBrush(combo, Qt::ConicalGradientPattern);
        addBrush(combo, Qt::TexturePattern);
        return combo;

    }
        break;
    default:
        return QItemDelegate::createEditor(parent, option, index);
        break;
    }
}

void CDyTableDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
{
    int disp_type = index.data( Qt::UserRole).toInt();
    switch (disp_type ) {
    case QVariant::Brush:
    {
        QComboBox *pComboBox = qobject_cast<QComboBox *>(editor);
        int bs = index.data( Qt::UserRole+1).toInt();
        pComboBox->setCurrentIndex( pComboBox->findData( bs, Qt::UserRole ));
    }
        break;
    default:
        QItemDelegate::setEditorData(editor, index);
        break;
    }
}

void CDyTableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    int disp_type = index.data( Qt::UserRole).toInt();
    switch (disp_type ) {
    case QVariant::Brush:
    {
        QComboBox *pComboBox = qobject_cast<QComboBox *>(editor);

        int bs = pComboBox->itemData( pComboBox->currentIndex() ).toInt();
        model->setData( index, bs, Qt::UserRole+1);
    }
        break;
    default:
        QItemDelegate::setModelData(editor, model, index);
        break;
    }
}
