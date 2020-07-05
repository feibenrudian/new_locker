//
// Created by Mingfei Deng on 2020/7/4.
//

#ifndef NEWLOCKER_LOCKER_H
#define NEWLOCKER_LOCKER_H
#include "Bag.h"
#include <map>

enum OPERATE_RESULT_E {
  OPERATE_RESULT_SUCCESS,
  OPERATE_RESULT_LOCKER_FULL,
};

struct Ticket {
  unsigned int id = 0; // id is 0 mean ticket is illegal
  Ticket() = default;
  explicit Ticket(unsigned int id) : id(id) {}
};

struct GetResult {
  OPERATE_RESULT_E operate_result = OPERATE_RESULT_SUCCESS;
  Bag bag;
  GetResult() = default;
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
  GetResult GetBag(Ticket ticket);

private:
  int amount;
  int remain;
  SIZE_TYPE_E size_type;
  std::map<unsigned int, Bag> save_bags;
};

#endif // NEWLOCKER_LOCKER_H
