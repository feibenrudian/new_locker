//
// Created by Mingfei Deng on 2020/7/4.
//

#ifndef NEWLOCKER_LOCKER_H
#define NEWLOCKER_LOCKER_H
#include "Bag.h"

enum OPERATE_RESULT_E { OPERATE_RESULT_SUCCESS };

struct Ticket {
  unsigned int id = 0;
  Ticket() = default;
  explicit Ticket(unsigned int id) : id(id) {}
};

struct SaveResult {
  OPERATE_RESULT_E operate_result = OPERATE_RESULT_SUCCESS;
  Ticket ticket;
  SaveResult() = default;
};

class Locker {
public:
  Locker(int amount, SIZE_TYPE_E sizeType);
  SaveResult Save(Bag bag);

private:
  int amount;
  int remain;
  SIZE_TYPE_E size_type_;
};

#endif // NEWLOCKER_LOCKER_H
