

#ifndef CHARTPROPERTYDLG_H
#define CHARTPROPERTYDLG_H 

#include <QDialog>

class QTableWidget;
class QTableWidgetItem;
class QtColorTriangle;
class QGraphicsItem;
class QLabel;
class QSpinBox;
namespace KDChart { class AbstractDiagram; };
class CChartPropertyDialog : public QDialog
{
    Q_OBJECT

public:
    CChartPropertyDialog(QGraphicsItem* item, QWidget* parent=0, Qt::WindowFlags f=0);
    ~CChartPropertyDialog();

    void Apply();
private slots:
    void OnItemClicked(QTableWidgetItem* item);
    void OnColorChanged(const QColor& c);
    void OnColorChangedBySpin();
    void OnTableProcess(bool);

private:
    void SetItemColorIcon(const QColor& c);

    QTableWidget* m_tableWidget;
    QtColorTriangle* m_colorTriangle;
    KDChart::AbstractDiagram* m_diagram;
    QPushButton* m_addRowButton;
    QPushButton* m_delRowButton;
    QPushButton* m_addColButton;
    QPushButton* m_delColButton;

    QLabel* m_rgbLabel;
    QSpinBox* m_rgbSpin[3];

    const bool c_isPieDiagram;
};


#endif
