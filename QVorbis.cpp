#include "QVorbis.hpp"

#include "stb_vorbis.h"

QVorbis::QVorbis(QObject *parent) : parent(parent)
{
}

QVorbis::~QVorbis()
{
	// Close and deallocate file
	if (file != nullptr)
	{
		file->close();
		delete file;
	}

	// Stop and deallocate audio
	if (audio != nullptr)
	{
		audio->stop();
		delete audio;
	}

	// Deallocate buffer
	if (buffer != nullptr)
		delete buffer;
}

bool QVorbis::play(QString fileName)
{
	// Decode vorbis data to memory
	short *decoded;
	int channels, sampleRate, len;
	len = stb_vorbis_decode_filename(fileName.toStdString().c_str(), &channels, &sampleRate, &decoded);

	// If no data was decoded, something went wrong
	if (len <= 0)
		return false;

	// Write raw PCM data to buffer
	buffer = new QBuffer(parent);
	buffer->open(QBuffer::ReadWrite);
	buffer->write((const char*) decoded, 2 * len * channels);
	buffer->seek(0);

	// Create PCM format info
	QAudioFormat format;
	format.setSampleRate(sampleRate);
	format.setChannelCount(channels);
	format.setSampleSize(16);
	format.setCodec("audio/pcm");
	format.setByteOrder(QAudioFormat::LittleEndian);
	format.setSampleType(QAudioFormat::SignedInt);

	// Play audio
	audio = new QAudioOutput(format, parent);
	audio->start(buffer);

	// Everything hopefully went fine
	return true;
}