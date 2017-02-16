#ifndef PREDICATES_H
#define PREDICATES_H

#include <functional>
#include <QList>

namespace predicates {

template <typename T, typename Func>
static QList<T> select(QList<T> items, Func predicate) {
    QList<T> result;
    QListIterator<T> iter(items);
    while (iter.hasNext()) {
        T t = iter.next();
        if (predicate(t)) {
            result.append(t);
        }
    }
    return result;
}

template <typename T, typename Func>
static QList<T> reject(QList<T> items, Func predicate) {
    QList<T> result;
    QListIterator<T> iter(items);
    while (iter.hasNext()) {
        T t = iter.next();
        if (!predicate(t)) {
            result.append(t);
        }
    }
    return result;
}

template <typename T, typename U>
static QList<U> map(QList<T> items, std::function<U(T)> predicate) {
    QList<U> result;
    QListIterator<T> iter(items);
    while (iter.hasNext()) {
        result.append(predicate(iter.next()));
    }
    return result;
}

}

#endif // PREDICATES_H
