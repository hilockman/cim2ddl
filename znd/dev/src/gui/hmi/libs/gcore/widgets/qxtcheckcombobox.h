/****************************************************************************
 **
 ** Copyright (C) Qxt Foundation. Some rights reserved.
 **
 ****************************************************************************/
#ifndef QXTCHECKCOMBOBOX_H
#define QXTCHECKCOMBOBOX_H

#include <QComboBox>
#include <QStandardItemModel>


#define QXT_DECLARE_PRIVATE(PUB) friend class PUB##Private; QxtPrivateInterface<PUB, PUB##Private> qxt_d;
#define QXT_DECLARE_PUBLIC(PUB) friend class PUB;
#define QXT_INIT_PRIVATE(PUB) qxt_d.setPublic(this);
#define QXT_D(PUB) PUB##Private& d = qxt_d()
#define QXT_P(PUB) PUB& p = qxt_p()

template <typename PUB>
class QxtPrivate
{
public:
    virtual ~QxtPrivate()
    {}
    inline void QXT_setPublic(PUB* pub)
    {
        qxt_p_ptr = pub;
    }

protected:
    inline PUB& qxt_p()
    {
        return *qxt_p_ptr;
    }
    inline const PUB& qxt_p() const
    {
        return *qxt_p_ptr;
    }

private:
    PUB* qxt_p_ptr;
};


template <typename PUB, typename PVT>
class QxtPrivateInterface
{
    friend class QxtPrivate<PUB>;
public:
    QxtPrivateInterface()
    {
        pvt = new PVT;
    }
    ~QxtPrivateInterface()
    {
        delete pvt;
    }

    inline void setPublic(PUB* pub)
    {
        pvt->QXT_setPublic(pub);
    }
    inline PVT& operator()()
    {
        return *static_cast<PVT*>(pvt);
    }
    inline const PVT& operator()() const
    {
        return *static_cast<PVT*>(pvt);
    }
private:
    QxtPrivateInterface(const QxtPrivateInterface&) { }
    QxtPrivateInterface& operator=(const QxtPrivateInterface&) { }
    QxtPrivate<PUB>* pvt;
};

class QxtCheckComboBox;
class QxtCheckComboBoxPrivate : public QObject, public QxtPrivate<QxtCheckComboBox>
{
	Q_OBJECT

public:
	QXT_DECLARE_PUBLIC(QxtCheckComboBox)
		QxtCheckComboBoxPrivate();
	bool eventFilter(QObject* receiver, QEvent* event);
	QString separator;
	QString defaultText;
	bool containerMousePress;

	public Q_SLOTS:
	void updateCheckedItems();
	void toggleCheckState(int index);
};

class QxtCheckComboBox : public QComboBox
{
    Q_OBJECT
    QXT_DECLARE_PRIVATE(QxtCheckComboBox)
    Q_PROPERTY(QString separator READ separator WRITE setSeparator)
    Q_PROPERTY(QString defaultText READ defaultText WRITE setDefaultText)
    Q_PROPERTY(QStringList checkedItems READ checkedItems WRITE setCheckedItems)
    Q_PROPERTY(QStringList checkIndexs READ checkIndexs WRITE setCheckIndexs)
    Q_PROPERTY(QStringList itemList READ ItemList WRITE SetItemList)

public:
    explicit QxtCheckComboBox(QWidget* parent = 0);
    virtual ~QxtCheckComboBox();

    virtual void hidePopup();

    QString defaultText() const;
    void setDefaultText(const QString& text);

    Qt::CheckState itemCheckState(int index) const;
    void setItemCheckState(int index, Qt::CheckState state);

    QString separator() const;
    void setSeparator(const QString& separator);

    QStringList checkedItems() const;

    QStringList checkIndexs() const;
    void setCheckIndexs(const QStringList& idxs);

public Q_SLOTS:
    void setCheckedItems(const QStringList& items);

	QStringList ItemList() const
	{
		QStringList l;
		for (int i = 0; i < count(); ++i)
			l << itemText(i);
		return l;
	}
	void SetItemList(const QStringList &l)
	{
		clear();
		insertItems(0, l);
	}

Q_SIGNALS:
    void checkedItemsChanged(const QStringList& items);
};

class QxtCheckComboModel : public QStandardItemModel
{
    Q_OBJECT

public:
    explicit QxtCheckComboModel(QObject* parent = 0);

    virtual Qt::ItemFlags flags(const QModelIndex& index) const;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);

Q_SIGNALS:
    void checkStateChanged();
};

#endif // QXTCHECKCOMBOBOX_H

