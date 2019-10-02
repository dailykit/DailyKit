#include "weighingscalemodel.h"
#include <QDebug>
WeighingScaleModel::WeighingScaleModel(QObject *parent) :
    QObject(parent),
    m_ingredientCalculatedWeight(0),
    m_ingredientQuantity(0)
{
}

QString WeighingScaleModel::orderId() const
{
    return  m_orderId;
}

void WeighingScaleModel::setOrderId(const QString id)
{
    m_orderId = id;
    emit orderIdChanged();
}

QString WeighingScaleModel::itemName() const
{
    return m_itemName;
}

void WeighingScaleModel::setItemName(const QString item)
{
    m_itemName = item;
    emit itemNameChanged();

}

QString WeighingScaleModel::ingredientName() const
{
    return m_ingredientName;
}

void WeighingScaleModel::setIngredientName(QString ingredient)
{
    m_ingredientName = ingredient;
    emit ingredientNameChanged();

}

int WeighingScaleModel::calculatedQuantity() const
{
    return m_ingredientCalculatedWeight;
}

void WeighingScaleModel::setCalculatedQuantity(const int itemWeight)
{
    m_ingredientCalculatedWeight = itemWeight;
    emit calculatedQuantityChanged();
}

QString WeighingScaleModel::weight() const
{
    return m_ingredientWeight.toLower();
}

void WeighingScaleModel::setWeight(const QString grams)
{
    m_ingredientWeight = grams;
    emit weightChanged();
}

int WeighingScaleModel::ingredientQuantity() const
{
    return m_ingredientQuantity;
}

void WeighingScaleModel::calculateActualWeight(int quantity)
{
    setCalculatedQuantity(quantity);
}

void WeighingScaleModel::weighItem(QString ingredientId, QString itemName, QString ingredientName, int quantity, QString weight)
{
    qDebug() << "Weighing" << weight;
   // setOrderId(orderId);
    setIngredientName(ingredientName);
    setItemName(itemName);
    setWeight(weight);
    m_ingredientId = ingredientId;
    m_ingredientQuantity = quantity ;
}


