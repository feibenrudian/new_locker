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
