//
// Created by Mingfei Deng on 2020/7/5.
//

#include "../include/PrimaryLockerRobot.h"

#include <utility>
PrimaryLockerRobot::PrimaryLockerRobot(std::vector<Locker *> lockers)
    : lockers_(std::move(lockers)) {
  for (auto one_locker : lockers_) {
    if (one_locker->GetSizeType() != SIZE_TYPE_MEDIUM) {
      can_work_ = false;
    }
  }
}
SaveResult PrimaryLockerRobot::SaveBag(Bag bag) {
  SaveResult ret;

  if (!can_work_) {
    ret.operate_result = OPERATE_RESULT_ROBOT_CAN_NOT_WORK;
    return ret;
  }

  for (auto one_locker : lockers_) {
    if (!one_locker->IsFull()) {
      return one_locker->Save(bag);
    }
  }

  ret.operate_result = OPERATE_RESULT_LOCKER_FULL;
  return ret;
}

GetResult PrimaryLockerRobot::GetBag(Ticket ticket) {
  GetResult ret;

  if (ticket.size_type != SIZE_TYPE_MEDIUM) {
    ret.operate_result = OPERATE_RESULT_TICKET_TYPE_NOT_MATCH;
    return ret;
  }

  for (auto one_locker : lockers_) {
    auto get_ret = one_locker->GetBag(ticket);
    if (OPERATE_RESULT_ILLEGAL_TICKET == get_ret.operate_result) {
      continue;
    } else {
      if (OPERATE_RESULT_SUCCESS == get_ret.operate_result) {
        return get_ret;
      }
    }
  }

  ret.operate_result = OPERATE_RESULT_ILLEGAL_TICKET;

  return ret;
}
