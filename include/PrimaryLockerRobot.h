//
// Created by Mingfei Deng on 2020/7/5.
//

#ifndef NEWLOCKER_PRIMARYLOCKERROBOT_H
#define NEWLOCKER_PRIMARYLOCKERROBOT_H
#include "Locker.h"
#include "vector"

class PrimaryLockerRobot {
public:
  PrimaryLockerRobot(std::vector<Locker *> lockers);
  SaveResult SaveBag(Bag bag);
  GetResult GetBag(Ticket ticket);

private:
  std::vector<Locker *> lockers;
};

#endif // NEWLOCKER_PRIMARYLOCKERROBOT_H
