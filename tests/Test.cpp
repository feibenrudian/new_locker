#include "../include/Locker.h"
#include <gtest/gtest.h>

using namespace std;

TEST(
    locker,
    should_save_success_and_return_a_ticket_given_a_small_size10_locker_and_a_small_bag_when_save_bag_to_locker) {
  Locker locker(10, LOCKER_TYPE_SMALL);
  Bag bag(666, LOCKER_TYPE_SMALL);

  auto ret = locker.Save(bag);

  EXPECT_EQ(OPERATE_RESULT_SUCCESS, ret.operate_result);
  EXPECT_NE(0, ret.ticket.id);
}
