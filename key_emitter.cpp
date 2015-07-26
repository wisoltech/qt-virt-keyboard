#include <QCoreApplication>
#include <QGuiApplication>
#include <QKeyEvent>
#include <QQuickItem>
#include "key_emitter.h"

KeyEmitter::KeyEmitter()
{
}

KeyEmitter::~KeyEmitter()
{
}

void KeyEmitter::emitKey(Qt::Key key)
{
	QQuickItem* receiver = qobject_cast<QQuickItem*>(QGuiApplication::focusObject());
	if(!receiver) {
		return;
	}
	QKeyEvent* pressEvent = new QKeyEvent(QEvent::KeyPress, key, Qt::NoModifier, QKeySequence(key).toString());
	QKeyEvent* releaseEvent = new QKeyEvent(QEvent::KeyRelease, key, Qt::NoModifier);
	QCoreApplication::sendEvent(receiver, pressEvent);
	QCoreApplication::sendEvent(receiver, releaseEvent);
}
