#pragma once

#include <QString>
#include <QFile>
#include <QAudioOutput>
#include <QBuffer>
#include <QAudioDeviceInfo>
#include <QAudioOutput>

class QVorbis
{
public:
	QVorbis(QObject *parent = nullptr);
	~QVorbis();
	bool play(QString fileName);
private:
	QObject *parent = nullptr;
	QFile *file = nullptr;
	QAudioOutput *audio = nullptr;
	QBuffer *buffer = nullptr;
};
