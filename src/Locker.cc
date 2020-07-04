//
// Created by Mingfei Deng on 2020/7/4.
//

#include "../include/Locker.h"
#include <random>

Locker::Locker(int amount, SIZE_TYPE_E sizeType)
    : amount(amount), remain(amount), size_type_(sizeType) {}
SaveResult Locker::Save(Bag bag) {
  SaveResult result;
  result.operate_result = OPERATE_RESULT_SUCCESS;
  std::default_random_engine e;
  result.ticket = Ticket(e());

  return result;
}
