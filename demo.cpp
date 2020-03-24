#include "QVorbis.hpp"

#include <QDebug>
#include <QCoreApplication>

int main(int argc, char **argv)
{
	// Initialize Qt
	QCoreApplication app(argc, argv);

	// Check correct usage
	if (argc != 2)
	{
		qWarning() << "qvorbis_demo <file.ogg>";
		return 1;
	}

	// Play
	QVorbis vorbis;
	if (!vorbis.play(QString(argv[1])))
	{
		qWarning() << "file failed to load";
		return 1;
	}

	// Run main thing
	return QCoreApplication::exec();
}
