#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

int MaxPairwiseProductFast(const vector<int>& numbers) {
    int n = numbers.size();
    
    int max_index1 = -1;
    for (int i = 0; i < n; ++i)
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
    	   max_index1 = i;		
    
    int max_index2 = -1;
    for (int j = 0; j < n; ++j)
    	if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
	       max_index2 = j;

    cout << max_index1 << " " << max_index2 << "\n";

    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}


int main() {
    while (true) {
        int n = rand() % 100 + 2;
        cout << n << "\n";
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(rand() % 100000);
        }    
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << "\n";
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);
        if (res1 != res2) {
            cout << "Wrong answer: " << res1 << " " << res2 << "\n";
            break;
        }
        else {
            cout << "OK\n";
        }
    } 
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << "simple:" << MaxPairwiseProduct(numbers) << "\n";
    cout << "fast:" << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
