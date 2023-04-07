#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string wagon;
    int n, m, k;
    vector<string> pyciong;
    vector<string> maly_pyciong;
    vector<vector<int>> pary;
    cin >> n >> m >> k;
    
    string odp(n, '0');

    for (int i = 0; i < n; i++) {
        cin >> wagon;
        pyciong.push_back(wagon);
    }

    for (int i = 0; i < m; i++) {
        cin >> wagon;
        maly_pyciong.push_back(wagon);
    }

    int przod = 0;
    for (int i = 0; i < n; i++) {
        if (przod > maly_pyciong.size()) break;
        if (pyciong[i] == maly_pyciong[przod]) {
            pary.push_back(vector<int>());
            pary[przod].push_back(i);
            przod++;
        }
    }

    int tyl = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (przod < 0) break;

        if (pyciong[i] == maly_pyciong[tyl]) {
            pary[tyl].push_back(i);
            tyl--;
        }
    }
        
    for(int i = 0; i < m; i++) {
        for(int j = pary[i][0]; j <= pary[i][1]; j++) {
            if(pyciong[j] == maly_pyciong[i]) {
                odp[j] = '1';
            }
        }
    }

    for(int i = 0; i < odp.size(); i++) {
        cout << odp[i] << " ";
    }

    return 0;
}