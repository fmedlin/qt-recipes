#include "fileutils.h"

#include <QFile>

FileUtils::FileUtils() {
}

FileUtils::~FileUtils() {
}

QByteArray FileUtils::sha256(QString filename) {
    return hash(filename, QCryptographicHash::Sha256);
}

QByteArray FileUtils::hash(QString filename, QCryptographicHash::Algorithm algorithm) {
    QByteArray result;

    QFile f(filename);
    if (f.open(QIODevice::ReadOnly)) {
        QCryptographicHash hash(algorithm);
        if (hash.addData(&f)) {
            result = hash.result();
        }
        f.close();
    }
    return result;
}
