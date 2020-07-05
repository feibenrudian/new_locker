//
// Created by Mingfei Deng on 2020/7/5.
//

#ifndef NEWLOCKER_SUPERLOCKERROBOT_H
#define NEWLOCKER_SUPERLOCKERROBOT_H
#include "Locker.h"
#include <vector>

class SuperLockerRobot {
public:
  SuperLockerRobot(std::vector<Locker *> lockers);
  SaveResult SaveBag(Bag bag);
  GetResult GetBag(Ticket ticket);

private:
  std::vector<Locker *> lockers;
};

#endif // NEWLOCKER_SUPERLOCKERROBOT_H
