//
// Created by Mingfei Deng on 2020/7/5.
//

#include "../include/LockerRobotManager.h"

#include <utility>
LockerRobotManager::LockerRobotManager(
    std::vector<Locker *> lockers,
    std::vector<PrimaryLockerRobot *> primaryLockerRobots,
    std::vector<SuperLockerRobot *> superLockerRobots)
    : lockers_(std::move(lockers)),
      primary_locker_robots_(std::move(primaryLockerRobots)),
      super_locker_robots_(std::move(superLockerRobots)) {}

SaveResult LockerRobotManager::SaveBag(Bag bag) {
  SaveResult ret;

  if (SIZE_TYPE_SMALL == bag.size_type) {
    for (auto one_locker : lockers_) {
      if (!one_locker->IsFull()) {
        return one_locker->Save(bag);
      }
    }
  }

  if (SIZE_TYPE_MEDIUM == bag.size_type) {
    return primary_locker_robots_[0]->SaveBag(bag);
  }

  if (SIZE_TYPE_LARGE == bag.size_type) {
    return super_locker_robots_[0]->SaveBag(bag);
  }

  ret.operate_result = OPERATE_RESULT_ILLEGAL_TICKET;

  return ret;
}
GetResult LockerRobotManager::GetBag(Ticket ticket) {
  GetResult ret;

  if (SIZE_TYPE_SMALL == ticket.size_type) {
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

  if (SIZE_TYPE_MEDIUM == ticket.size_type) {
    return primary_locker_robots_[0]->GetBag(ticket);
  }

  if (SIZE_TYPE_LARGE == ticket.size_type) {
    return super_locker_robots_[0]->GetBag(ticket);
  }

  return ret;
}
