

#include <QtCore/QVariant>
#include <QAbstractTableModel>
#include <KDChartChart>
#include <KDChartAbstractDiagram>
#include <QtGui>
#include "ChartPropertyDlg.h"
#include "ChartWrap.h"
#include "ColorTriangle.h"
#include "ChartTableModel.h"


struct ChartData
{
 ChartData() : val(0), color(Qt::gray) {};
 qreal val;
 QColor color;
};

Q_DECLARE_METATYPE(ChartData)

CChartPropertyDialog::CChartPropertyDialog(QGraphicsItem* item, QWidget* parent , Qt::WindowFlags f )
 :QDialog(parent, f), c_isPieDiagram(g_dataPtr(item)->Type() == Hmi::PieWidget)
{
 resize(500, 300);
 setWindowTitle("ChartProperty");
 QDialogButtonBox* buttonBox = new QDialogButtonBox(this);
 buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
 buttonBox->setGeometry(QRect(40, 260, 341, 32));
 buttonBox->setOrientation(Qt::Horizontal);
 buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);


 QObject::connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
 QObject::connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

 m_addRowButton = new QPushButton(QObject::tr("addRow"));
 m_addRowButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
 QObject::connect(m_addRowButton, SIGNAL(clicked(bool)), this, SLOT(OnTableProcess(bool)));
 m_delRowButton = new QPushButton(QObject::tr("removeRow"));
 m_delRowButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
 QObject::connect(m_delRowButton, SIGNAL(clicked(bool)), this, SLOT(OnTableProcess(bool)));
 m_addColButton = new QPushButton(QObject::tr("addColumn"));
 m_addColButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
 QObject::connect(m_addColButton, SIGNAL(clicked(bool)), this, SLOT(OnTableProcess(bool)));
 m_delColButton = new QPushButton(QObject::tr("removeColumn"));
 m_delColButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
 QObject::connect(m_delColButton, SIGNAL(clicked(bool)), this, SLOT(OnTableProcess(bool)));
 QHBoxLayout* buttonLayout = new QHBoxLayout;
 buttonLayout->addWidget(m_addRowButton);
 buttonLayout->addWidget(m_delRowButton);
 buttonLayout->addWidget(m_addColButton);
 buttonLayout->addWidget(m_delColButton);
 QSpacerItem* horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
 buttonLayout->addItem(horizontalSpacer);
 m_tableWidget = new QTableWidget;
 m_tableWidget->setMinimumSize(500, 200);
 QVBoxLayout* tableLayout = new QVBoxLayout;
 tableLayout->addWidget(m_tableWidget);
 tableLayout->addLayout(buttonLayout);

 m_colorTriangle = new QtColorTriangle;
 m_colorTriangle->setMinimumSize(200, 200);
 QHBoxLayout* rgbLayout = new QHBoxLayout;
 m_rgbLabel = new QLabel("RGB:");
 rgbLayout->addWidget(m_rgbLabel);
 for(int i=0; i<3; ++i)
 {
  m_rgbSpin[i] = new QSpinBox;
  m_rgbSpin[i]->setRange(0, 255);
  rgbLayout->addWidget(m_rgbSpin[i]);
  QObject::connect(m_rgbSpin[i], SIGNAL(editingFinished()), this, SLOT(OnColorChangedBySpin()));
 }
 QVBoxLayout* colorLayout = new QVBoxLayout;
 colorLayout->addWidget(m_colorTriangle);
 colorLayout->addLayout(rgbLayout);
 QHBoxLayout* tableAndColorLayout = new QHBoxLayout;
 tableAndColorLayout->addLayout(tableLayout);
 tableAndColorLayout->addLayout(colorLayout);
 QVBoxLayout* vLayout = new QVBoxLayout;
 vLayout->addLayout(tableAndColorLayout);
 vLayout->addWidget(buttonBox);
 setLayout(vLayout);

 m_diagram = ((CBaseChartData*)g_dataPtr(item))->GetDiagram();
 QAbstractItemModel* model = m_diagram->model();
 const int rowLimit = g_dataPtr(item)->Type() == Hmi::PieWidget ? 1 : model->rowCount();
 m_addRowButton->setDisabled(c_isPieDiagram);
 m_delRowButton->setDisabled(c_isPieDiagram);
 m_tableWidget->setRowCount(rowLimit);
 m_tableWidget->setIconSize(QSize(22, 22));
 m_tableWidget->setColumnCount(model->columnCount());
 for(int row=0; row<rowLimit; ++row)
 {
  for(int col=0; col<model->columnCount(); ++col)
  {
   QTableWidgetItem* tableWidgetItem = new QTableWidgetItem;
   tableWidgetItem->setTextAlignment(Qt::AlignCenter);
   ChartData data;
   data.val = model->data(model->index(row, col), Qt::EditRole).toFloat();
   data.color = m_diagram->brush(model->index(row, col)).color();
   tableWidgetItem->setText(QString::number(data.val));
   QPixmap pix(m_tableWidget->iconSize());
   pix.fill(data.color);
   tableWidgetItem->setIcon(QIcon(pix));
   m_tableWidget->setItem(row, col, tableWidgetItem);
   tableWidgetItem->setData(Qt::UserRole, qVariantFromValue(data));
  }
 }


 QObject::connect(m_tableWidget, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(OnItemClicked(QTableWidgetItem*)));
 QObject::connect(m_colorTriangle, SIGNAL(colorChanged(const QColor&)), this, SLOT(OnColorChanged(const QColor&)));
}

CChartPropertyDialog::~CChartPropertyDialog()
{

}

void CChartPropertyDialog::Apply()
{
 QAbstractItemModel* model = m_diagram->model();

 ((CChartTableModel*)model)->clear();
 model->insertRows(0, m_tableWidget->rowCount());
 model->insertColumns(0, m_tableWidget->columnCount());
 for(int row=0; row<m_tableWidget->rowCount(); ++row)
 {
  for(int col=0; col<m_tableWidget->columnCount(); ++col)
  {
   const QModelIndex index = model->index(row, col);
   const qreal val = m_tableWidget->item(row, col)->text().toFloat();
   ChartData data = m_tableWidget->item(row, col)->data(Qt::UserRole).value<ChartData>();

   model->setData(index, val, Qt::EditRole);
   if(c_isPieDiagram)
    m_diagram->setPen(index, QPen(QColor(data.color)));
   m_diagram->setBrush(index, QBrush(QColor(data.color)));
  }
 }

 m_diagram->update();

}

void CChartPropertyDialog::OnItemClicked( QTableWidgetItem* item )
{
 if(!item)
  return;

 QColor c = item->data(Qt::UserRole).value<ChartData>().color;
 m_colorTriangle->setColor(c);
 m_rgbSpin[0]->setValue(c.red());
 m_rgbSpin[1]->setValue(c.green());
 m_rgbSpin[2]->setValue(c.blue());
}

void CChartPropertyDialog::OnColorChanged( const QColor& c )
{
 m_rgbSpin[0]->setValue(c.red());
 m_rgbSpin[1]->setValue(c.green());
 m_rgbSpin[2]->setValue(c.blue());

 SetItemColorIcon(c);
}

void CChartPropertyDialog::OnColorChangedBySpin()
{
 QColor c(m_rgbSpin[0]->value(), m_rgbSpin[1]->value(), m_rgbSpin[2]->value());
 m_colorTriangle->setColor(c);
 SetItemColorIcon(c);
}

void CChartPropertyDialog::SetItemColorIcon( const QColor& c )
{
 QTableWidgetItem* item = m_tableWidget->currentItem();
 if(!item)
  return;

 QPixmap pix(m_tableWidget->iconSize());
 ChartData data = item->data(Qt::UserRole).value<ChartData>();
 data.color = c;
 pix.fill(c);
 item->setIcon(QIcon(pix));
 item->setData(Qt::UserRole, qVariantFromValue(data));
}

void CChartPropertyDialog::OnTableProcess(bool)
{
 QObject* signalSender = sender();
 int row = m_tableWidget->currentRow();
 if(row == -1)
  row = m_tableWidget->rowCount()-1;
 int col = m_tableWidget->currentColumn();
 if(col == -1)
  col = m_tableWidget->columnCount()-1;

 if(m_addRowButton == signalSender)
 {
  m_tableWidget->insertRow(row+1);
  for(int c=0; c<m_tableWidget->columnCount(); ++c)
  {
   QTableWidgetItem* item = new QTableWidgetItem;
   QTableWidgetItem* beforeItem = m_tableWidget->item(row, c);
   item->setText("0");
   item->setData(Qt::UserRole, beforeItem->data(Qt::UserRole));
   item->setIcon(beforeItem->icon());
   m_tableWidget->setItem(row+1, c, item);
  }
 }
 else if(m_delRowButton == signalSender)
 {
  m_tableWidget->removeRow(row);
 }
 else if(m_addColButton == signalSender)
 {
  m_tableWidget->insertColumn(col+1);
  for(int r=0; r<m_tableWidget->rowCount(); ++r)
  {
   QTableWidgetItem* item = new QTableWidgetItem;
   item->setText("0");
   item->setData(Qt::UserRole, qVariantFromValue(ChartData()));
   item->setIcon(QIcon(QPixmap(m_tableWidget->iconSize())));
   m_tableWidget->setItem(r, col+1, item);
  }
 }
 else if(m_delColButton == signalSender)
 {
  m_tableWidget->removeColumn(col);
 }
}
