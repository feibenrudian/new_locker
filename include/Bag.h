//
// Created by Mingfei Deng on 2020/7/4.
//

#ifndef NEWLOCKER_BAG_H
#define NEWLOCKER_BAG_H

enum SIZE_TYPE_E { SIZE_TYPE_SMALL, SIZE_TYPE_MEDIUM, SIZE_TYPE_LARGE };

class Bag {
public:
  Bag(int id, SIZE_TYPE_E sizeType);
  Bag() = default;
  int id = 0; // id is 0, mean bag is not exist
  SIZE_TYPE_E size_type = SIZE_TYPE_SMALL;
};

#endif // NEWLOCKER_BAG_H
