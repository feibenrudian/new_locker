//
// Created by Mingfei Deng on 2020/7/4.
//

#include "../include/Locker.h"
#include <random>

Locker::Locker(int amount, SIZE_TYPE_E sizeType)
    : amount(amount), remain(amount), size_type(sizeType) {}
SaveResult Locker::Save(Bag bag) {
  SaveResult result;

  if (remain >= amount) {
    result.operate_result = OPERATE_RESULT_LOCKER_FULL;
    return result;
  }

  result.operate_result = OPERATE_RESULT_SUCCESS;
  std::default_random_engine e;
  result.ticket = Ticket(e());

  save_bags[result.ticket.id] = bag;
  --remain;

  return result;
}
GetResult Locker::GetBag(Ticket ticket) {
  GetResult ret;

  if (save_bags.end() == save_bags.find(ticket.id)) {
    ret.operate_result = OPERATE_RESULT_ILLEGAL_TICKET;
    return ret;
  }

  ret.bag = save_bags[ticket.id];
  ret.operate_result = OPERATE_RESULT_SUCCESS;
  return ret;
}
