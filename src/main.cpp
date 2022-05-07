// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

void Train::addCage(bool Light) {
  if (first && last) {
    Cage* cage = new Cage;
    cage->light = Light;
    last->next = cage;
    cage->next = first;
    cage->prev = last;
    first->prev = cage;
    last = cage;
  } else {
    Cage* cage = new Cage;
    cage->light = Light;
    cage->next = nullptr;
    cage->prev = nullptr;
    first = last = cage;
  }
}

int Train::getLength() {
  int count = 0;
  first->light = true;
  Cage* temp = first->next;
  Cage* temp1 = first;
  count += 1;
  countOp += 1;
  while (true) {
    if (temp->light == false) {
      temp = temp->next;
      count += 1;
      countOp += 1;
    } else {
      temp->light = false;
      for (int i = count; i > 0; --i) {
        temp = temp->prev;
        countOp += 1;
      }
      if (temp->light == false) {
        return count;
      } else {
        temp = first->next;
        count = 1;
        countOp += 1;
      }
    }
  }
}

int Train::getOpCount() {
  return countOp;
}

int main() {
  Train train;
  int count = 60; // кол-во вагонов

  while (count--)
    train.addCage(false);

  std::cout << train.getLength() << std::endl;
  std::cout << train.getOpCount() << std::endl;
  return 0;
}
