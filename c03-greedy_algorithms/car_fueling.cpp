#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int coveredDistance = tank;
    int lastStop = stops.size() - 1;
    int previousStop = 0;
    int stopsNeeded = 0;
    for (int i = 0; i <= lastStop && coveredDistance < dist; ++i) {
	if (coveredDistance >= stops[i]) {
		previousStop = i;	
	} else {
		if (stops[i] - stops[previousStop] > tank) {
			return -1;
		}
		coveredDistance = stops[previousStop] + tank;
		--i;
		++stopsNeeded;
	}	
    }
    return stopsNeeded;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
