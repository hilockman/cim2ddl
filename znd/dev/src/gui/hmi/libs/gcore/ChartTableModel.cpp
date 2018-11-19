

#include "ChartTableModel.h"

#include <QtGlobal>
#include <QtDebug>
#include <QFile>
#include <QByteArray>
#include <QString>
#include <QStringList>

CChartTableModel::CChartTableModel(QObject * parent)
    : QAbstractTableModel(parent),
      m_dataHasHorizontalHeaders( true),
      m_dataHasVerticalHeaders( true),
      m_supplyHeaderData( true)
{
}

CChartTableModel::~CChartTableModel ()
{
}

int CChartTableModel::rowCount(const QModelIndex &) const
{
    return m_dataVecVec.size();
}

int CChartTableModel::columnCount(const QModelIndex &) const
{
    if(m_dataVecVec.isEmpty())
        return 0;
    else
        return m_dataVecVec[0].size();
}

QVariant CChartTableModel::data(const QModelIndex & index, int role) const
{


    if(index.row() == -1 || index.column() == -1)
    {
        /*qDebug() << "TableModel::data: row: "
                 << index.row() << ", column: " << index.column()
                 << ", rowCount: " << rowCount() << ", columnCount: "
                 << columnCount() << endl
                 << "TableModel::data: FIXME fix kdchart views to not query"
                    " model data for invalid indices!" << endl;*/
        return QVariant();
    }



    Q_ASSERT(index.row() >= 0 && index.row() < rowCount());
    Q_ASSERT(index.column() >= 0 && index.column() < columnCount());

    if(role == Qt::DisplayRole || role == Qt::EditRole)
        return m_dataVecVec[index.row()] [index.column()];
    else
        return QVariant();
}

QVariant CChartTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    QVariant result;

    switch(role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        if(m_supplyHeaderData)
        {
            if(orientation == Qt::Horizontal)
            {
                if(!m_horizontalHeaderData.isEmpty())
                    result = m_horizontalHeaderData[section];
            } else {

                if(!m_verticalHeaderData.isEmpty())
                    result = m_verticalHeaderData[section];
            }
        }
        break;
    case Qt::TextAlignmentRole:

        break;
    case Qt::DecorationRole:
    case Qt::ToolTipRole:
        break;
    default:

        break;
    }
    return result;
}


bool CChartTableModel::setData(const QModelIndex & index, const QVariant & value, int role )
{
    Q_ASSERT(index.row() >= 0 && index.row() < rowCount());
    Q_ASSERT(index.column() >= 0 && index.column() < columnCount());

    if(role == Qt::EditRole)
    {
        m_dataVecVec[index.row()] [index.column()] = value.toFloat();
        emit dataChanged( index, index);
        return true;
    } else {
        return false;
    }
}

void CChartTableModel::clear()
{
    beginResetModel();
    m_dataVecVec.resize(0);

    endResetModel();
}

bool CChartTableModel::loadFromCSV ( const QString& filename )
{
    QFile file ( filename );
    QStringList data;

    if ( file.exists() && file.open ( QIODevice::ReadOnly ) )
    {
        while ( !file.atEnd() )
        {
            QString line = QString::fromUtf8( file.readLine() );
            data.append ( line );
        }

        if ( data.size() > 0 )
        {
            setTitleText("");
            m_dataVecVec.resize ( data.size() - 1 );


            int previousColumnCount = 0;

            for ( int row = 0; row < data.size(); ++row )
            {
                QStringList parts = data.at( row ).split ( QString( ',' ) );

                Q_ASSERT ( previousColumnCount == parts.size() || previousColumnCount == 0 );

                QVector<qreal> values( m_dataHasVerticalHeaders ? parts.size() - 1 : parts.size() );

                for ( int column = 0; column < parts.size(); ++column )
                {
                    QString cell ( parts.at( column ).simplified() );

                    if ( cell.startsWith( '\"') )
                    {
                        cell.remove ( 0, 1 );
                    }
                    if ( cell.endsWith( '\"') )
                    {
                        cell.remove ( cell.length()-1, 1 );
                    }


                    if ( row == 0 && m_dataHasHorizontalHeaders )
                    {
                        if( column == 0 && m_dataHasVerticalHeaders )
                            setTitleText( cell );
                        else
                            m_horizontalHeaderData.append( cell );
                    }
                    else
                    {
                        if ( column == 0 && m_dataHasVerticalHeaders )
                        {
                            m_verticalHeaderData.append( cell );
                        }
                        else
                        {

                            bool convertedOk = false;
                            double value = cell.toDouble ( &convertedOk );

                            const int destColumn = m_dataHasVerticalHeaders ? column - 1 : column;
                            values[destColumn] = convertedOk? value : (cell.isEmpty() ? 0: QVariant( cell).toReal());

                        }
                    }
                }
                if ( row > 0 )
                {
                    const int destRow = m_dataHasHorizontalHeaders ? row - 1 : row;
                    m_dataVecVec[destRow] = values;
                }
            }
        }
        else
        {
            m_dataVecVec.resize ( 0 );
        }



        return true;
    }
    else
    {
       /* qDebug() << "TableModel::loadFromCSV: file" << filename
                 << "does not exist / or could not be opened" << endl;*/
        return false;
    }
}



void CChartTableModel::TestInit()
{
    m_dataVecVec.resize(1);
    for(int i=0; i<5;++i)
    {
        m_dataVecVec[0]<<i+1;
    }
}

bool CChartTableModel::removeRows( int row, int count, const QModelIndex &parent )
{
    beginRemoveRows(parent, row, count-1);
    m_dataVecVec.remove(row, count);
    endRemoveRows();
    return true;
}


bool CChartTableModel::insertRows( int row, int count, const QModelIndex &parent )
{
    beginInsertRows(parent, row, count-1);
    m_dataVecVec.insert(row, count, QVector<qreal>());
    endInsertRows();
    return true;
}

bool CChartTableModel::insertColumns( int column, int count, const QModelIndex &parent )
{
    beginInsertColumns(parent, column, count-1);
    for(int row=0; row<m_dataVecVec.size(); ++row)
    {
        m_dataVecVec[row].insert(column, count, 0.0);
    }
    endInsertColumns();
    return true;
}
