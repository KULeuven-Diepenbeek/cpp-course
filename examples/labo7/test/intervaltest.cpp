
#include "gtest/gtest.h"
#include "interval.h"

class IntervalSuite : public ::testing::Test {
protected:
    Interval *interval;
protected:
    virtual void TearDown() {
        delete interval;
    }

    virtual void SetUp() {
        interval = new Interval(5, 10);
    }
};

TEST_F(IntervalSuite, TelOpNeemtKleinsteBegin) { 
    Interval tweeTotTwaalf = Interval(2, 12);
    Interval vijfTotTien = *interval;

    Interval nieuw = tweeTotTwaalf + vijfTotTien;
    ASSERT_EQ(2, nieuw.getBegin());
}

TEST_F(IntervalSuite, TelOpNeemtGrootsteEinde) { 
    Interval tweeTotTwaalf = Interval(2, 12);
    Interval vijfTotTien = *interval;

    Interval nieuw = tweeTotTwaalf + vijfTotTien;
    ASSERT_EQ(12, nieuw.getEinde());
}

TEST_F(IntervalSuite, BeginZitInInterval) {
    ASSERT_TRUE(interval->inclusief(5));
}
TEST_F(IntervalSuite, EindeZitInInterval) {
    ASSERT_TRUE(interval->inclusief(10));
}
TEST_F(IntervalSuite, GetalTussenBeginEnEindeZitInInterval) {
    ASSERT_TRUE(interval->inclusief(7));
}
TEST_F(IntervalSuite, GetalGroterDanEindeZitNietInInterval) {
    ASSERT_FALSE(interval->inclusief(70));
}
TEST_F(IntervalSuite, GetalKleinerDanBeginZitNietInInterval) {
    ASSERT_FALSE(interval->inclusief(2));
}
