#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, H, male_H = 0, do_a_flip = 0;
    string nawiasy;
    cin >> n >> H;
    cin >> nawiasy;

    if(nawiasy != "0") {
        for(int i = 0; i < n; i++) {
            if(nawiasy[i] == '(') {
                male_H++;
            } else {
                male_H--;
            }

            if(male_H > H) {
                male_H -= 2;
                do_a_flip++;
            }

            if(male_H < 0) {
                male_H = 1;
                do_a_flip++;
            }
        }

        cout << do_a_flip;

    } else cout << "0";


    return 0;
}