#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int r1, r2, B;
        cin >> r1 >> r2 >> B;

        double balls_played = 300 - B;
        double current_run_rate = (r2 * 6.0) / balls_played;
        double runs_needed = (r1 + 1) - r2;
        double required_run_rate = (runs_needed * 6.0) / B;
        cout << fixed << setprecision(2) << current_run_rate << " " << required_run_rate << endl;
    }

    return 0;
}