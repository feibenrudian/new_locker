#include "../include/Locker.h"
#include "../include/PrimaryLockerRobot.h"
#include "../include/SuperLockerRobot.h"
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

TEST(
    locker,
    should_return_ticket_type_error_given_medduim_ticket_and_a_small_locker_saved_a_small_bag_when_get_bag_from_locker) {
  Locker locker(10, LOCKER_TYPE_SMALL);
  Bag bag(666, LOCKER_TYPE_SMALL);
  (void)locker.Save(bag);

  Ticket illegal_ticket;
  illegal_ticket.size_type = LOCKER_TYPE_MEDIUM;
  auto ret = locker.GetBag(illegal_ticket);

  EXPECT_EQ(OPERATE_RESULT_TICKET_TYPE_NOT_MATCH, ret.operate_result);
  EXPECT_EQ(0, ret.bag.id);
}

class primary_locker_robot_test : public testing::Test {
protected:
  void SetUp() override {
    locker1 = new Locker(1, LOCKER_TYPE_MEDIUM);
    locker2 = new Locker(10, LOCKER_TYPE_MEDIUM);
    primary_locker_robot = new PrimaryLockerRobot({locker1, locker2});
  }

  void TearDown() override {
    delete locker1;
    delete locker2;
    delete primary_locker_robot;
  }

  Locker *locker1{};
  Locker *locker2{};
  PrimaryLockerRobot *primary_locker_robot{};
};

TEST_F(
    primary_locker_robot_test,
    should_return_save_success_and_a_ticket_bag_save_in_first_locker_given_primary_locker_robot_manager_2_medium_not_full_locker_a_medium_bag_when_primary_locker_robot_manager_save_bag) {
  Bag bag(666, LOCKER_TYPE_MEDIUM);

  auto ret = primary_locker_robot->SaveBag(bag);

  EXPECT_EQ(OPERATE_RESULT_SUCCESS, ret.operate_result);
  EXPECT_NE(0, ret.ticket.id);
  bool exist = locker1->HasBag(bag.id, bag.size_type);
  EXPECT_EQ(true, exist);
}

TEST_F(
    primary_locker_robot_test,
    should_return_save_success_and_a_ticket_bag_save_in_second_locker_given_primary_locker_robot_manager_1_full_medium_locker_1_not_full_medium_locker_a_medium_bag_when_primary_locker_robot_manager_save_bag) {

  Bag bag1(666, LOCKER_TYPE_MEDIUM);
  Bag bag2(6666, LOCKER_TYPE_MEDIUM);
  (void)primary_locker_robot->SaveBag(bag1);

  auto ret = primary_locker_robot->SaveBag(bag2);

  EXPECT_EQ(OPERATE_RESULT_SUCCESS, ret.operate_result);
  EXPECT_NE(0, ret.ticket.id);
  bool exist = locker2->HasBag(bag2.id, bag2.size_type);
  EXPECT_EQ(true, exist);
}

TEST_F(
    primary_locker_robot_test,
    should_get_success_and_correct_bag_given_primary_locker_robot_manager_saved_a_bag_have_a_right_ticket_when_get_bag_from_locker_robot_manager) {
  Bag bag1(666, LOCKER_TYPE_MEDIUM);

  auto save_ret = primary_locker_robot->SaveBag(bag1);
  auto ret = primary_locker_robot->GetBag(save_ret.ticket);

  EXPECT_EQ(OPERATE_RESULT_SUCCESS, ret.operate_result);
  EXPECT_EQ(666, ret.bag.id);
}

TEST_F(
    primary_locker_robot_test,
    should_get_illegal_ticket_error_given_primary_locker_robot_manager_saved_a_bag_have_a_illegal_ticket_when_get_bag_from_locker_robot_manager) {
  Bag bag1(666, LOCKER_TYPE_MEDIUM);

  auto save_ret = primary_locker_robot->SaveBag(bag1);

  Ticket illegal_ticket;
  illegal_ticket.size_type = LOCKER_TYPE_MEDIUM;
  auto ret = primary_locker_robot->GetBag(illegal_ticket);

  EXPECT_EQ(OPERATE_RESULT_ILLEGAL_TICKET, ret.operate_result);
  EXPECT_EQ(0, ret.bag.id);
}

TEST_F(
    primary_locker_robot_test,
    SHOULD_get_type_not_match_error_GIVEN_primary_locker_robot_manager_saved_a_bag_have_a_small_type_ticket_WHEN_get_bag_from_locker_robot_manager) {
  Bag bag1(666, LOCKER_TYPE_MEDIUM);

  auto save_ret = primary_locker_robot->SaveBag(bag1);

  Ticket illegal_ticket;
  illegal_ticket.size_type = LOCKER_TYPE_SMALL;
  auto ret = primary_locker_robot->GetBag(illegal_ticket);

  EXPECT_EQ(OPERATE_RESULT_TICKET_TYPE_NOT_MATCH, ret.operate_result);
  EXPECT_EQ(0, ret.bag.id);
}

TEST(
    primary_locker_robot,
    SHOULD_robot_can_not_work_error_GIVEN_primary_locker_robot_manager_manager_a_small_size_lock_and_a_bag_WHEN_save_bag) {
  Bag bag1(666, LOCKER_TYPE_MEDIUM);

  auto locker1 = new Locker(1, LOCKER_TYPE_SMALL);
  auto primary_locker_robot = new PrimaryLockerRobot({locker1});

  auto ret = primary_locker_robot->SaveBag(bag1);

  EXPECT_EQ(OPERATE_RESULT_ROBOT_CAN_NOT_WORK, ret.operate_result);
  EXPECT_EQ(0, ret.ticket.id);
}

TEST(
    super_locker_robot_test,
    SHOULD_save_success_return_a_ticket_GIVEN_super_locker_robot_manager_manager_2_large_size_lock_and_a_large_bag_WHEN_save_bag) {
  Bag bag1(666, LOCKER_TYPE_LARGE);

  auto locker1 = new Locker(3, LOCKER_TYPE_LARGE);
  auto locker2 = new Locker(3, LOCKER_TYPE_LARGE);
  auto super_locker_robot = new SuperLockerRobot({locker1, locker2});

  auto ret = super_locker_robot->SaveBag(bag1);

  EXPECT_EQ(OPERATE_RESULT_SUCCESS, ret.operate_result);
  EXPECT_NE(0, ret.ticket.id);

  delete locker1;
  delete locker2;
  delete super_locker_robot;
}

TEST(
    super_locker_robot_test,
    SHOULD_save_success_return_a_ticket_and_bag_save_in_second_locker_GIVEN_super_locker_robot_manager_manager_2_large_size_lock_first_remain_2_second_remain_2_and_a_large_bag_WHEN_save_bag) {
  Bag bag1(666, LOCKER_TYPE_LARGE);
  Bag bag2(6666, LOCKER_TYPE_LARGE);

  auto locker1 = new Locker(3, LOCKER_TYPE_LARGE);
  auto locker2 = new Locker(3, LOCKER_TYPE_LARGE);
  auto super_locker_robot = new SuperLockerRobot({locker1, locker2});

  (void)super_locker_robot->SaveBag(bag1);
  auto ret = super_locker_robot->SaveBag(bag2);

  EXPECT_EQ(OPERATE_RESULT_SUCCESS, ret.operate_result);
  EXPECT_NE(0, ret.ticket.id);
  auto exist = locker2->HasBag(bag2.id, bag2.size_type);
  EXPECT_EQ(true, exist);

  delete locker1;
  delete locker2;
  delete super_locker_robot;
}
