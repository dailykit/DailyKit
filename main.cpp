#include <QGuiApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "DailyKitCore/External/WebServices/retrievewebappdata.h"
#include "DailyKitCore/DatabaseModels/dbmanager.h"
#include "DailyKitCore/ViewModels/orderviewmodel.h"
#include "DailyKitCore/ViewModels/ingredientviewmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    DBManager::connectToDatabase();

    OrderViewModel *m_model = new OrderViewModel();
//    RetrieveWebAppData *webData = new RetrieveWebAppData();
//    webData->getOrderList();

    IngredientViewModel* m_ingredient = new IngredientViewModel();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("orderModel", m_model);
    engine.rootContext()->setContextProperty("ingredientModel", m_ingredient);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));




    return app.exec();
}



