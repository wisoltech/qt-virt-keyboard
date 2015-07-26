#ifndef KEY_EMITTER_H
#define KEY_EMITTER_H

#include <QObject>

class KeyEmitter : public QObject
{
	Q_OBJECT

public:
	KeyEmitter();
	~KeyEmitter();

public slots:
	void emitKey(Qt::Key key);
};

#endif // KEY_EMITTER_H
