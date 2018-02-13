#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <maze.h>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    qDebug() << "WTF";
    QGuiApplication app(argc, argv);

    qmlRegisterType<Maze>("ru.loredan13.maze", 1, 0, "Maze");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
