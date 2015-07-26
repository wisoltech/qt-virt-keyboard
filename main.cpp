#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "key_emitter.h"

int main(int argc, char* argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;
	KeyEmitter keyEmitter;
	QQmlContext* ctx = engine.rootContext();
	ctx->setContextProperty("keyEmitter", &keyEmitter);
	engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
	return app.exec();
}
