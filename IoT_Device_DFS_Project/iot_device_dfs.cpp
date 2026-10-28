#include <iostream>
#include <string>
using namespace std;

#define MAX 50

class IoTNetwork
{
    string device[MAX];
    int graph[MAX][MAX];
    int visited[MAX];
    int total;

public:
    IoTNetwork()
    {
        total = 0;
        for (int i = 0; i < MAX; i++)
        {
            visited[i] = 0;
            for (int j = 0; j < MAX; j++)
                graph[i][j] = 0;
        }
    }

    void addDevice()
    {
        if (total >= MAX)
        {
            cout << "Device limit reached!\n";
            return;
        }

        cin.ignore(1000, '\n');
        cout << "Enter device name: ";
        getline(cin, device[total]);

        if (device[total].empty())
        {
            cout << "Device name cannot be empty!\n";
            return;
        }

        cout << "Device added with ID: " << total << endl;
        total++;
    }

    void displayDevices()
    {
        if (total == 0)
        {
            cout << "No devices added yet!\n";
            return;
        }

        cout << "\n--- IoT Devices ---\n";
        for (int i = 0; i < total; i++)
            cout << i << " : " << device[i] << endl;
    }

    void connectDevices()
    {
        if (total < 2)
        {
            cout << "Add at least two devices first!\n";
            return;
        }

        int a, b;
        displayDevices();

        cout << "Enter first device ID: ";
        cin >> a;
        cout << "Enter second device ID: ";
        cin >> b;

        if (a < 0 || a >= total || b < 0 || b >= total || a == b)
        {
            cout << "Invalid device IDs!\n";
            return;
        }

        if (graph[a][b] == 1)
        {
            cout << "These devices are already connected!\n";
            return;
        }

        graph[a][b] = 1;
        graph[b][a] = 1;

        cout << "Devices connected successfully!\n";
    }

    void displayConnections()
    {
        if (total == 0)
        {
            cout << "No devices available!\n";
            return;
        }

        int id;
        displayDevices();
        cout << "Enter device ID to view connections: ";
        cin >> id;

        if (id < 0 || id >= total)
        {
            cout << "Invalid device ID!\n";
            return;
        }

        cout << "Devices connected to " << device[id] << ":\n";
        int found = 0;

        for (int i = 0; i < total; i++)
        {
            if (graph[id][i] == 1)
            {
                cout << "- " << device[i] << endl;
                found = 1;
            }
        }

        if (!found)
            cout << "No connected devices.\n";
    }

    void displayMatrix()
    {
        if (total == 0)
        {
            cout << "No devices available!\n";
            return;
        }

        cout << "\nAdjacency Matrix:\n   ";
        for (int i = 0; i < total; i++)
            cout << i << " ";
        cout << endl;

        for (int i = 0; i < total; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < total; j++)
                cout << graph[i][j] << " ";
            cout << endl;
        }

        cout << "1 = connected, 0 = not connected\n";
    }

    void DFS(int v)
    {
        visited[v] = 1;
        cout << device[v] << " -> ";

        for (int i = 0; i < total; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
                DFS(i);
        }
    }

    void exploreDFS()
    {
        if (total == 0)
        {
            cout << "Add devices first!\n";
            return;
        }

        int start;
        displayDevices();
        cout << "Enter starting device ID: ";
        cin >> start;

        if (start < 0 || start >= total)
        {
            cout << "Invalid device ID!\n";
            return;
        }

        for (int i = 0; i < total; i++)
            visited[i] = 0;

        cout << "\nDFS Traversal:\n";
        DFS(start);
        cout << "END\n";

        int count = 0;
        for (int i = 0; i < total; i++)
            if (visited[i] == 1)
                count++;

        cout << "Reachable devices (including start): " << count << endl;
        cout << "Unreachable devices: " << total - count << endl;
    }
};

int main()
{
    IoTNetwork network;
    int choice;

    do
    {
        cout << "\n===== IoT DEVICE NETWORK =====\n";
        cout << "1. Add Device\n";
        cout << "2. Connect Devices\n";
        cout << "3. Display Devices\n";
        cout << "4. Display Adjacency Matrix\n";
        cout << "5. Display Device Connections\n";
        cout << "6. Explore Devices Using DFS\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: network.addDevice(); break;
            case 2: network.connectDevices(); break;
            case 3: network.displayDevices(); break;
            case 4: network.displayMatrix(); break;
            case 5: network.displayConnections(); break;
            case 6: network.exploreDFS(); break;
            case 7: cout << "Program terminated.\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
