#include <iostream>
#include <vector>

using std::vector;

void printVector(std::string s, vector<int> v) {
  std::cout << std::endl;
  std::cout << "Printing vector - \"" << s << "\": " << std::endl;
  for (int i = 0; i < v.size(); ++i) {
      std::cout << "vector[" << i << "] == " << v[i] << std::endl;
    }
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  std::cout << "function start" << std::endl;
  const int size = weights.size();
  std::cout << "sorted indexex size: " << size << std::endl;
  vector<int> sIndexes(size);
  vector<int> dIndexes;
  
  for (int i = 0; i < size; ++i) {
    sIndexes[i] = i;
  }

  printVector("source indexes", sIndexes);
  
  while (sIndexes.size() > 0) {
  // int s = size;
  // while (s != 0) {
  double itemValue = 0.0;
  int currentIndex = 0;

    for (int j = 0; j < sIndexes.size(); j++) {
      double currentItemValue = values[sIndexes[j]] / weights[sIndexes[j]];
      std::cout << "values[sIndexes[j]] / weights[sIndexes[j]]: " << values[sIndexes[j]] / weights[sIndexes[j]] << std::endl;
      std::cout << "iter: " << j << std::endl;
      std::cout << "value: " << values[sIndexes[j]] << " weights: " << weights[sIndexes[j]] << " val per item: " << currentItemValue << std::endl;
      if (itemValue < currentItemValue) {
          itemValue = currentItemValue;
          currentIndex = j;
          std::cout << "BEST VALUE: " << itemValue << std::endl;
          std::cout << "INDEX of best val: " << sIndexes[currentIndex] << std::endl;
      }
    }
    dIndexes.push_back(sIndexes[currentIndex]);
    std::cout << "INDEX PUSHED: " << sIndexes[currentIndex] << " with: ";
    std::cout << "VAL: " << values[sIndexes[currentIndex]] << " WEIGHT: " << weights[sIndexes[currentIndex]] << std::endl;
    sIndexes.erase(sIndexes.begin() + currentIndex);
  }
  printVector("dest indexes", dIndexes);

  for (int i = 0; i < size; ++i) {
    std::cout << "VAL: " << values[dIndexes[i]] << " WEIGHT: " << weights[dIndexes[i]] << std::endl;
  }

  int capacityRest = capacity;
  while (capacityRest > 0) {
    for (int i = 0; i < size; ++i) {
        if (capacityRest >= weights[dIndexes[i]]) {
            capacityRest = capacityRest - weights[dIndexes[i]];
            value = value + values[dIndexes[i]];
        } else {
            double itemValue = values[dIndexes[i]] / weights[dIndexes[i]];
            value += itemValue * capacityRest;
            capacityRest = 0;
        }
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
  // double result = test();
  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;

}
