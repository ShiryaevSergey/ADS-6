// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
  T Arr[10];
  int h, t;

 public:
  TPQueue(): h(0), t(0) {}
  int Dimension() {
    return t - h;
  }
  void push(T value) {
    if (Dimension() >= size) {
      throw std::string("Full!");
    } else {
      int counter = t - 1;
      while (counter >= h && value.prior > Arr[counter % size].prior) {
        Arr[(counter + 1) % size] = Arr[counter % size];
        counter--;
      }
      Arr[(counter + 1) % size] = value;
      t++;
    }
  }
  T pop() {
    if (h == t) {
      throw std::string("Empty!");
    } else {
      return Arr[(h++) % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
