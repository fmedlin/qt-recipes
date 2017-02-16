#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QByteArray>
#include <QCryptographicHash>
#include <QString>

class FileUtils {
public:
    FileUtils();
    virtual ~FileUtils();

    virtual QByteArray sha256(QString filename);

protected:
    virtual QByteArray hash(QString filename, QCryptographicHash::Algorithm algorithm);
};

#endif // FILEUTILS_H
