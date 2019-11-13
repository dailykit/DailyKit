#include "itemviewmodel.h"

const QString ItemViewModel::ItemViewQuery = "SELECT  itemDetails.itemOrderId, itemDetails.orderId, itemDetails.itemName, itemDetails.itemServing"
                                             ", (SELECT Count(I1.ingredientId) FROM ingredients I1 WHERE I1.ingredientItemId = itemDetails.itemOrderId) as counttotal"
                                            ", (SELECT SUM(I2.isPackedComplete) FROM ingredients I2 WHERE I2.ingredientItemId = itemDetails.itemOrderId) as turnover "
                                             " FROM itemDetails WHERE itemDetails.orderId = ? ";
const QString ItemViewModel::TAG ="ItemViewModel.cpp : ";

ItemViewModel::ItemViewModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

ItemViewModel::~ItemViewModel()
{
    qDebug() <<TAG<<"deleted";
}


QVariant ItemViewModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_itemDetails.count())
    {
        return QVariant();

    }

    switch (role) {
    case ItemOrderId:
        return m_itemDetails[index.row()]->itemOrderId();
    case OrderId:
        return m_itemDetails[index.row()]->orderId();
    case ItemName:
        return m_itemDetails[index.row()]->recipeName();
    case IngredientCount:
        return m_itemDetails[index.row()]->ingredientCount();
    case PackedIngredientCount:
        return m_itemDetails[index.row()]->packedIngredients();
    case OrderNumber:
        return m_itemDetails[index.row()]->orderNumber();
    case IsCurrentItem:
        return m_itemDetails[index.row()]->itemOrderId() == m_currentItem;
    default:
        return QVariant();

    }


}

QHash<int, QByteArray> ItemViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(ItemOrderId, "itemOrderId");
    roles.insert(OrderId, "orderId");
    roles.insert(ItemName, "itemName");
    roles.insert(IngredientCount, "ingredientCount");
    roles.insert(PackedIngredientCount, "packedCount");
    roles.insert(OrderNumber, "orderNumber");



    return roles;
}

int ItemViewModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    qDebug() << "count" << m_itemDetails.count();
    return m_itemDetails.count();

}

void ItemViewModel::setQuery(int orderId)
{
    QSqlQuery query;
    query.prepare(ItemViewQuery);
    query.addBindValue(orderId);
    if(query.exec()) {
        qDebug()<<"sql statement exicuted fine items";
    }
    else{
        qDebug() <<"Errors accured with sql statement";
        qDebug() <<query.lastError();
    }

    m_itemDetails.clear();
    beginResetModel();
    while (query.next()){

        ItemDetailsPtr ptr(new ItemDetails());
        ptr->setItemOrderId(query.value(0).toString());
        ptr->setOrderId(query.value(1).toString());
        ptr->setRecipeName(query.value(2).toString());
        ptr->setIngredientCount(query.value(3).toInt());
        ptr->setPackedIngredients(query.value(4).toInt());
        ptr->setOrderNumber(orderId);

        m_itemDetails.append(ptr);

    }
    endResetModel();

}

void ItemViewModel::setCurrentItem(QString itemOrderId)
{
    m_currentItem = itemOrderId;

}

