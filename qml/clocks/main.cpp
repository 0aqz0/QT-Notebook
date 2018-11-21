#include "../../shared/shared.h"
#include <QGuiApplication>
#include <QtQuick/QQuickView>
#include <QQmlContext>
#include "datasource.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);

    QQuickView viewer;

#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif
    viewer.engine()->addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
                                      QString::fromLatin1("qml")));
    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);

    viewer.setTitle(QStringLiteral("QML with data from c++ thread"));

    DataSource dataSource;
    dataSource.activate_thread();
    viewer.rootContext()->setContextProperty("dataSource", &dataSource);

    viewer.setSource(QUrl::fromLocalFile("C://Users//0AQZ0//myProject//clocks//clocks.qml"));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.setColor(QColor("#404040"));
    viewer.show();

    return app.exec();
}
