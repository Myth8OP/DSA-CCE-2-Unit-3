#include <iostream>
#include <vector>
#include <string>
using namespace std;

class IoTNetwork {
private:
    vector<string> devices;
    vector< vector<int> > adj;

    int findDevice(const string& name) const {
        for (int i = 0; i < (int)devices.size(); i++)
            if (devices[i] == name) return i;
        return -1;
    }

public:
    void addDevice(const string& name) {
        if (findDevice(name) == -1) {
            devices.push_back(name);
            adj.push_back(vector<int>());
        }
    }

    bool deviceExists(const string& name) const {
        return findDevice(name) != -1;
    }

    void addConnection(const string& a, const string& b) {
        int u = findDevice(a), v = findDevice(b);
        if (u == -1 || v == -1) return;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void displayNetwork() const {
        cout << "\nIoT Network (Device: Connected devices)\n";
        for (int i = 0; i < (int)devices.size(); i++) {
            cout << devices[i] << ": ";
            for (int j = 0; j < (int)adj[i].size(); j++) {
                cout << devices[adj[i][j]];
                if (j + 1 < (int)adj[i].size()) cout << ", ";
            }
            cout << endl;
        }
    }

    void DFS(const string& startName) const {
        int start = findDevice(startName);
        if (start == -1) {
            cout << "Error: Device " << startName << " is not in the network.\n";
            return;
        }

        vector<int> visited(devices.size(), 0), stack;
        stack.push_back(start);
        int count = 0;
        cout << "\nDFS traversal from " << startName << ": ";

        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            if (visited[u]) continue;
            visited[u] = 1;
            count++;
            cout << devices[u] << " ";
            for (int j = (int)adj[u].size() - 1; j >= 0; j--)
                if (!visited[adj[u][j]]) stack.push_back(adj[u][j]);
        }
        cout << "\nReachable devices: " << count << endl;
    }
};

int main() {
    IoTNetwork iot;
    int n, m;
    cout << "=== IoT Device Network using DFS ===\n";
    cout << "Enter number of IoT devices: ";
    if (!(cin >> n) || n <= 0) { cout << "Invalid number.\n"; return 1; }

    cout << "Enter device names (one word each):\n";
    for (int i = 0; i < n; i++) {
        string name;
        cout << "Device " << i + 1 << ": ";
        cin >> name;
        if (iot.deviceExists(name)) { cout << "Duplicate device name.\n"; return 1; }
        iot.addDevice(name);
    }

    cout << "Enter number of communication links: ";
    if (!(cin >> m) || m < 0) { cout << "Invalid number of links.\n"; return 1; }

    cout << "Enter each link as two device names:\n";
    for (int i = 0; i < m; i++) {
        string a, b;
        cout << "Link " << i + 1 << ": ";
        cin >> a >> b;
        if (!iot.deviceExists(a) || !iot.deviceExists(b)) {
            cout << "Both devices must be declared first.\n";
            return 1;
        }
        iot.addConnection(a, b);
    }

    iot.displayNetwork();
    string start;
    cout << "\nEnter starting device for DFS: ";
    cin >> start;
    iot.DFS(start);
    return 0;
}
