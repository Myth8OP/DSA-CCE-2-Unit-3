# IoT Device Network using DFS

**Dev-C++ compatibility:** C++98-compatible code; no `unordered_map` or other C++11-only syntax.

## Run
Extract the ZIP, open `main.cpp` in Dev-C++, then choose **Execute > Compile & Run**.

## Sample input
```text
6
Sensor1
Sensor2
SmartLight
Gateway
Camera
Controller
5
Sensor1 Sensor2
Sensor2 Gateway
Gateway SmartLight
Gateway Camera
Camera Controller
Sensor1
```

The program displays the DFS traversal and number of reachable devices. Links are treated as two-way.

## Complexity
Time: `O(V + E)`. Auxiliary space: `O(V)`.
