# include <iostream>
# include "timer.h"

int main() {
  std::vector<double> v;
  const unsigned runs = 100, N = 2e5;
  Timer t;
  t.start();
  for (unsigned j = 0; j < runs; ++j) {
    for (unsigned i = 0; i < N; ++i) {
      if (i % 79 == 0){
        v.push_back(i);
      }
    }
    t.lap();
  }
  std::cout << "Min:   " << t.min() << "\n";
  std::cout << "Mean:  " << t.mean() << "\n";
  std::cout << "Total: " << t.duration() << "\n";
  std::cout << "Mean*runs = " << t.mean()*runs << "\n";

  return 0;
}
