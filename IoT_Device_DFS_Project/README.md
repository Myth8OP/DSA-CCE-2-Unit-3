# IoT Device Network Using DFS

## Problem Statement
Implement DFS on an IoT device network to explore the devices reachable from a selected device.

## Overview
This menu-driven C++ program represents IoT devices as vertices and communication links as edges in an undirected graph. It uses an adjacency matrix to store the network and recursive Depth First Search (DFS) to explore all devices reachable from a selected starting device.

## Features
1. Add IoT devices.
2. Connect two devices.
3. Display all devices.
4. Display the adjacency matrix.
5. Display the connections of a selected device.
6. Run DFS from any selected device.
7. Count reachable and unreachable devices.

## DSA Concepts
- Graph and vertices/edges
- Adjacency matrix
- Depth First Search (DFS)
- Recursion
- Visited array

## Run in Dev-C++
1. Extract the ZIP file.
2. Open `iot_device_dfs.cpp` in Dev-C++.
3. Select **Execute -> Compile & Run**.
4. Add devices, then connect them using their IDs.
5. Select option 6 and choose the starting device ID.

## Sample Network
Devices:
- ID 0: Smart Gateway
- ID 1: Temperature Sensor
- ID 2: Smart Light
- ID 3: Security Camera
- ID 4: Water Sensor

Connections:
- 0 -- 1
- 0 -- 2
- 1 -- 3
- 2 -- 4

Starting from Smart Gateway (ID 0), one possible DFS order is:
`Smart Gateway -> Temperature Sensor -> Security Camera -> Smart Light -> Water Sensor`

Reachable devices: 5
Unreachable devices: 0

The exact traversal order depends on device IDs and the order in which neighbours are checked.

## Complexity
With an adjacency matrix, DFS takes O(V^2) time. Space complexity is O(V^2) for the matrix and O(V) for the visited array and recursion stack.

## Note
This is an educational graph simulation. It does not discover real devices or scan an actual IoT network.
