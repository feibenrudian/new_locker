//
// Created by Mingfei Deng on 2020/7/5.
//

#include "../include/SuperLockerRobot.h"

#include <utility>
SuperLockerRobot::SuperLockerRobot(std::vector<Locker *> lockers)
    : lockers(std::move(lockers)) {}

SaveResult SuperLockerRobot::SaveBag(Bag bag) {
  SaveResult ret;
  int max_remain = 0;
  Locker *save_locker = nullptr;

  for (auto one_locker : lockers) {
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

  if (ticket.size_type != LOCKER_TYPE_LARGE) {
    ret.operate_result = OPERATE_RESULT_TICKET_TYPE_NOT_MATCH;
    return ret;
  }

  for (auto one_locker : lockers) {
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
