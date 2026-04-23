#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int jumlah_kota = 4;
    vector<vector<pair<int, int>>> peta(jumlah_kota);
    
    peta[0].push_back({1, 5});
    peta[0].push_back({2, 2});
    peta[1].push_back({3, 4});
    peta[2].push_back({3, 10});
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> jarak(jumlah_kota, INT_MAX);
    jarak[0] = 0;
    pq.push({0, 0});
    
    cout << "Mulai mencari jalur terpendek." << endl;
    
    while (!pq.empty()) {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        char nama_kota = 'A' + u;
        if (dist > jarak[u]) continue;
        
        cout << "Memproses Kota " << nama_kota << " (Jarak: " << dist << ")" << endl;
        
        if (u == 3) {
            cout << "\n> Jarak terpendek ke Kota D adalah: " << dist << " km" << endl;
            break;
        }
        
        for (auto &edge : peta[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (jarak[u] + weight < jarak[v]) {
                jarak[v] = jarak[u] + weight;
                pq.push({jarak[v], v});
            }
        }
    }
    
    return 0;
}