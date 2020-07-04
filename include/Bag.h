//
// Created by Mingfei Deng on 2020/7/4.
//

#ifndef NEWLOCKER_BAG_H
#define NEWLOCKER_BAG_H

enum SIZE_TYPE_E { LOCKER_TYPE_SMALL, LOCKER_TYPE_MEDIUM, LOCKER_TYPE_LARGE };

class Bag {
public:
  Bag(int id, SIZE_TYPE_E sizeType);

private:
  int id;
  SIZE_TYPE_E size_type_;
};

#endif // NEWLOCKER_BAG_H
