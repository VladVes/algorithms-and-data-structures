#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  std::cout << "function start" << std::endl;
  const int size = weights.size();
  std::cout << "sorted indexex size: " << size << std::endl;
  vector<int> sortedIndexes;
  for (int i = 0; i < size; i++) {
     double itemValue = 0.0;
     int currentIndex = i;
     std::cout << "outer sort cycle i: " << i << " current index: " << currentIndex << std::endl;
     for (int j = 0; j < size; j++) {
        int currentItemValue = values[j] / weights[j];
        if (itemValue < currentItemValue) { 
            itemValue = currentItemValue;
            currentIndex = j;
        }
	std::cout << "inner sort cycle j: " << j << " item value: " << itemValue << " currentItemValue: " << currentItemValue << std::endl;
     }
     std::cout << "sorted indexes push " << currentIndex << std::endl;
     sortedIndexes.push_back(currentIndex);
  }
  std::cout << "result:  " << sortedIndexes.size() << std::endl;
  for (int x = 0; x < sortedIndexes.size(); x++) {
     std::cout << "sorted index: " << sortedIndexes[x] << std::endl;
     std::cout << "value: " << values[sortedIndexes[x]] << std::endl;
     std::cout << "weights:  " << weights[sortedIndexes[x]] << std::endl;
  }
  
  int capacityRest = capacity;
  while (capacityRest > 0) {
    for (int i = 0; i < size; ++i) {  
        if (capacityRest >= weights[sortedIndexes[i]]) {
            capacityRest = capacityRest - weights[sortedIndexes[i]];
            value = value + values[sortedIndexes[i]];
        } else {
            double itemValue = values[sortedIndexes[i]] / weights[sortedIndexes[i]];
            value = value + itemValue * capacityRest;
        } 
     }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  std::cout << n;
  std::cout << "ready for calculation!" << n << " " << capacity << std::endl;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cout << i << "I" << std::endl;
    std::cin >> values[i] >> weights[i];
    std::cout << "value: " << values[i] << " weight: " << weights[5] << std::endl;
  }
  std::cout << "data received" << std::endl;
  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
