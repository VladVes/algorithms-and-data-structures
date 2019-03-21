#include <iostream>

const int N = 3;
const int NOMINALS[N] = { 1, 5, 10 };

int get_change(int m) {
  int coinsCounter = 0;
  if (m == 0) {
      return coinsCounter;
  }
  int rest = m;
  int currentNominal = N - 1;
  while (rest != 0) {
    const int currentRest = rest - NOMINALS[currentNominal]; 
    if (currentRest >= 0) { 
        rest = currentRest; 
        ++coinsCounter;
    } else { 
        --currentNominal; 
    }
  }
  return coinsCounter;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
