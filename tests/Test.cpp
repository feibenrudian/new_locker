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

TEST(
    locker,
    should_get_success_and_correct_bag_given_rigint_ticket_and_a_small_locker_saved_a_small_bag_when_get_bag_from_locker) {
  Locker locker(10, LOCKER_TYPE_SMALL);
  Bag bag(666, LOCKER_TYPE_SMALL);
  auto save_ret = locker.Save(bag);

  auto ret = locker.GetBag(save_ret.ticket);

  EXPECT_EQ(OPERATE_RESULT_SUCCESS, ret.operate_result);
  EXPECT_EQ(666, ret.bag.id);
  EXPECT_EQ(LOCKER_TYPE_SMALL, ret.bag.size_type);
}

TEST(
    locker,
    should_return_full_error_given_full_locker_a_small_bag_then_locker_save_bag) {
  Locker locker(2, LOCKER_TYPE_SMALL);
  Bag bag(666, LOCKER_TYPE_SMALL);

  for (int i = 0; i < 2; ++i) {
    Bag in_locker_bag(i, LOCKER_TYPE_SMALL);
    (void)locker.Save(in_locker_bag);
  }

  auto ret = locker.Save(bag);

  EXPECT_EQ(OPERATE_RESULT_LOCKER_FULL, ret.operate_result);
  EXPECT_EQ(0, ret.ticket.id);
}

TEST(
    locker,
    should_return_illegal_ticket_error_given_illegal_ticket_and_a_small_locker_saved_a_small_bag_when_get_bag_from_locker) {
  Locker locker(10, LOCKER_TYPE_SMALL);
  Bag bag(666, LOCKER_TYPE_SMALL);
  (void)locker.Save(bag);

  Ticket illegal_ticket;
  auto ret = locker.GetBag(illegal_ticket);

  EXPECT_EQ(OPERATE_RESULT_ILLEGAL_TICKET, ret.operate_result);
  EXPECT_EQ(0, ret.bag.id);
}
