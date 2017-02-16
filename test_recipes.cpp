#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "fileutils.h"
#include "predicates.h"

#include <QString>

TEST(FileUtils, CalculateSha256) {
    FileUtils utils;

    QByteArray hash(utils.sha256("../QtRecipes/hello.txt").toHex());

    ASSERT_EQ(QString(hash), QString("37980c33951de6b0e450c3701b219bfeee930544705f637cd1158b63827bb390"));
}

TEST(Predicates, SelectList) {
    QList<QString> numbers;
    numbers << "zero" << "one" << "two" << "three";

    QList<QString> filtered = predicates::select(numbers, [] (QString item) {
            return item.startsWith("t");
    });

    ASSERT_EQ(2, filtered.count());
    ASSERT_EQ(filtered[0], "two");
    ASSERT_EQ(filtered[1], "three");
}

TEST(Predicates, RejectList) {
    QList<QString> numbers;
    numbers << "zero" << "one" << "two" << "three";

    QList<QString> rejected = predicates::reject(numbers, [] (QString item) {
            return item.startsWith("t");
    });

    ASSERT_EQ(2, rejected.count());
    ASSERT_EQ(rejected[0], "zero");
    ASSERT_EQ(rejected[1], "one");
}

TEST(Predicates, MapList) {
    QList<QString> numbers;
    numbers << "zero" << "one" << "two" << "three";

    QList<int> sizes = predicates::map<QString,int>(numbers, [] (QString item) {
            return item.length();
    });

    ASSERT_EQ(4, sizes.count());
    ASSERT_EQ(sizes[0], 4);
    ASSERT_EQ(sizes[1], 3);
    ASSERT_EQ(sizes[2], 3);
    ASSERT_EQ(sizes[3], 5);
}
