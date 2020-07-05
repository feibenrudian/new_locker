//
// Created by Mingfei Deng on 2020/7/5.
//

#include "../include/SuperLockerRobot.h"

#include <utility>
SuperLockerRobot::SuperLockerRobot(std::vector<Locker *> lockers)
    : lockers_(std::move(lockers)) {
  for (auto one_locker : lockers_) {
    if (SIZE_TYPE_LARGE != one_locker->GetSizeType()) {
      can_work_ = false;
    }
  }
}

SaveResult SuperLockerRobot::SaveBag(Bag bag) {
  SaveResult ret;
  int max_remain = 0;
  Locker *save_locker = nullptr;

  if (!can_work_) {
    ret.operate_result = OPERATE_RESULT_ROBOT_CAN_NOT_WORK;
    return ret;
  }

  for (auto one_locker : lockers_) {
    if (!one_locker->IsFull()) {
      auto remain = one_locker->GetRemain();
      if (remain > max_remain) {
        max_remain = remain;
        save_locker = one_locker;
      }
    }
  }

  if (nullptr != save_locker) {
    return save_locker->Save(bag);
  }

  ret.operate_result = OPERATE_RESULT_ILLEGAL_TICKET;

  return ret;
}
GetResult SuperLockerRobot::GetBag(Ticket ticket) {
  GetResult ret;

  if (ticket.size_type != SIZE_TYPE_LARGE) {
    ret.operate_result = OPERATE_RESULT_TICKET_TYPE_NOT_MATCH;
    return ret;
  }

  for (auto one_locker : lockers_) {
    auto get_from_one_ret = one_locker->GetBag(ticket);

    if (OPERATE_RESULT_SUCCESS == get_from_one_ret.operate_result) {
      return get_from_one_ret;
    }

    if (OPERATE_RESULT_ILLEGAL_TICKET == get_from_one_ret.operate_result) {
      continue;
    }
  }

  ret.operate_result = OPERATE_RESULT_ILLEGAL_TICKET;
  return ret;
}
