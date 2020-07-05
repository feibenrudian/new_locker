//
// Created by Mingfei Deng on 2020/7/5.
//

#include "../include/PrimaryLockerRobot.h"

#include <utility>
PrimaryLockerRobot::PrimaryLockerRobot(std::vector<Locker *> lockers)
    : lockers(std::move(lockers)) {}
SaveResult PrimaryLockerRobot::SaveBag(Bag bag) {
  SaveResult ret;

  for (auto one_locker : lockers) {
    if (!one_locker->IsFull()) {
      return one_locker->Save(bag);
    }
  }

  ret.operate_result = OPERATE_RESULT_LOCKER_FULL;
  return ret;
}

GetResult PrimaryLockerRobot::GetBag(Ticket ticket) {
  GetResult ret;

  for (auto one_locker : lockers) {
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
