/* PURSPOSE: Obtain the current date and time of system
 * PROJECT_NAME: Profiling
 * IMPLEMENTATION: QML application, using Qt formatTime,formatDateTime
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
