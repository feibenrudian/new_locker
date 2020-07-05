//
// Created by Mingfei Deng on 2020/7/5.
//

#include "../include/SuperLockerRobot.h"

#include <utility>
SuperLockerRobot::SuperLockerRobot(std::vector<Locker *> lockers)
    : lockers(std::move(lockers)) {}

SaveResult SuperLockerRobot::SaveBag(Bag bag) {
  SaveResult ret;

  for (auto one_locker : lockers) {
    if (!one_locker->IsFull()) {
      return one_locker->Save(bag);
    }
  }

  ret.operate_result = OPERATE_RESULT_ILLEGAL_TICKET;

  return ret;
}
