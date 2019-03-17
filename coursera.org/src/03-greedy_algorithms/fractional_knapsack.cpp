#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  const int size = weights.size();
  vector<int> sortedIndexes(size);
  for (int i = 0; i < size; ++i) {
     double itemValue = 0.0;
     int currentIndex = i;
     for (int j = i; j < size - i; ++j) {
        int currentItemValue = values[j] / weights[j];
        if (itemValue < currentItemValue) { 
            itemValue = currentItemVlaue; 
            currentIndex = j;
        }
     }
     sortedIndexes.push_back(currentIndex);     
  }
  int capacityRest = capacity;   
  for (int  = 0; 

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
