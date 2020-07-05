//
// Created by Mingfei Deng on 2020/7/5.
//

#ifndef NEWLOCKER_LOCKERROBOTMANAGER_H
#define NEWLOCKER_LOCKERROBOTMANAGER_H
#include "PrimaryLockerRobot.h"
#include "SuperLockerRobot.h"
#include <vector>

class LockerRobotManager {
public:
  LockerRobotManager(std::vector<Locker *> lockers,
                     std::vector<PrimaryLockerRobot *> primaryLockerRobots,
                     std::vector<SuperLockerRobot *> superLockerRobots);

  SaveResult SaveBag(Bag bag);
  GetResult GetBag(Ticket ticket);

private:
  std::vector<Locker *> lockers_;
  std::vector<PrimaryLockerRobot *> primary_locker_robots_;
  std::vector<SuperLockerRobot *> super_locker_robots_;
  bool can_work_ = true;
};

#endif // NEWLOCKER_LOCKERROBOTMANAGER_H
