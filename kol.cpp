#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> wonsz;
    vector<string> order = {"1 1"};
    unordered_map<string, int> coord;
    unordered_map<string, int> colors;
    coord["1 1"] = 0;
    wonsz.push_back(0);

    int x_pos = 1, y_pos = 1;

    int i = 0, to_back = 0, order_i = 0;
    int m, p, n, color;
    string oper, x, y;
    cin >> m >> p >> n;


    for (int j = 0; j < p; j++) {
        cin >> x >> y >> color;

        colors[x+" "+y] = color;
    }

    for (int j = 0; j < n; j++) {
        cin >> oper;
        if (oper == "Z") { 
            cin >> x >> y;
            if (coord.find(x + " " + y) == coord.end() || coord[x + " " + y] < 0) cout << "-1\n";
            else cout << wonsz[coord[x + " " + y] - to_back] << "\n";

        } else {
            if (oper == "G") y_pos--;
            else if (oper == "D") y_pos++;
            else if (oper == "P") x_pos++;
            else if (oper == "L") x_pos--;

            string pos = to_string(y_pos) + " " + to_string(x_pos);

            if (colors.find(pos) == colors.end()) {
                coord[order[order_i]] = -1;
                order_i++;
                order.push_back(pos);
                i++;
                to_back++;
                coord[pos] = i;

            } else {
                i++;
                wonsz.push_back(colors[pos]);
                order.push_back(pos);
                coord[pos] = i; 
                colors.erase(pos);      
            }


        }
    }

    return 0;
}