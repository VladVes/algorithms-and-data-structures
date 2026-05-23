#include <iostream>
#include <vector>

using std::vector;

// void printVector(std::string s, vector<int> v) {
// std::cout << std::endl;
//  std::cout << "Printing vector - \"" << s << "\": " << std::endl;
//  for (int i = 0; i < v.size(); ++i) {
//     std::cout << "vector[" << i << "] == " << v[i] << std::endl;
//    }
// } 

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  const int size = weights.size();
  vector<int> sIndexes(size);
  vector<int> dIndexes;

  for (int i = 0; i < size; ++i) {
    sIndexes[i] = i;
  }

  while (sIndexes.size() > 0) {
  double itemValue = 0.0;
  int currentIndex = 0;
    for (int j = 0; j < sIndexes.size(); j++) {
      double currentItemValue = (double)values[sIndexes[j]] / (double)weights[sIndexes[j]];
      if (itemValue < currentItemValue) {
          itemValue = currentItemValue;
          currentIndex = j;
      }
    }
    dIndexes.push_back(sIndexes[currentIndex]);
    sIndexes.erase(sIndexes.begin() + currentIndex);
  }

  int capacityRest = capacity;
  for (int i = 0; i < size; ++i) {
      if (capacityRest >= weights[dIndexes[i]]) {
          capacityRest = capacityRest - weights[dIndexes[i]];
          value += (double)values[dIndexes[i]];
      } else {
          double itemValue = (double)values[dIndexes[i]] / (double)weights[dIndexes[i]];
          value += itemValue * (double)capacityRest;
          capacityRest = 0;
      }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  double optimal_value = get_optimal_value(capacity, weights, values);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
