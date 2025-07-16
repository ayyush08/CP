/** CRAAZYY QUESTION */
// D. Shichikuji and Power Grid
// time limit per test2 seconds
// memory limit per test256 megabytes
// Shichikuji is the new resident deity of the South Black Snail Temple. Her first job is as follows:

// There are n
//  new cities located in Prefecture X. Cities are numbered from 1
//  to n
// . City i
//  is located xi
//  km North of the shrine and yi
//  km East of the shrine. It is possible that (xi,yi)=(xj,yj)
//  even when i≠j
// .

// Shichikuji must provide electricity to each city either by building a power station in that city, or by making a connection between that city and another one that already has electricity. So the City has electricity if it has a power station in it or it is connected to a City which has electricity by a direct connection or via a chain of connections.

// Building a power station in City i
//  will cost ci
//  yen;
// Making a connection between City i
//  and City j
//  will cost ki+kj
//  yen per km of wire used for the connection. However, wires can only go the cardinal directions (North, South, East, West). Wires can cross each other. Each wire must have both of its endpoints in some cities. If City i
//  and City j
//  are connected by a wire, the wire will go through any shortest path from City i
//  to City j
// . Thus, the length of the wire if City i
//  and City j
//  are connected is |xi−xj|+|yi−yj|
//  km.
// Shichikuji wants to do this job spending as little money as possible, since according to her, there isn't really anything else in the world other than money. However, she died when she was only in fifth grade so she is not smart enough for this. And thus, the new resident deity asks for your help.

// And so, you have to provide Shichikuji with the following information: minimum amount of yen needed to provide electricity to all cities, the cities in which power stations will be built, and the connections to be made.

// If there are multiple ways to choose the cities and the connections to obtain the construction of minimum price, then print any of them.

// Input
// First line of input contains a single integer n
//  (1≤n≤2000
// ) — the number of cities.

// Then, n
//  lines follow. The i
// -th line contains two space-separated integers xi
//  (1≤xi≤106
// ) and yi
//  (1≤yi≤106
// ) — the coordinates of the i
// -th city.

// The next line contains n
//  space-separated integers c1,c2,…,cn
//  (1≤ci≤109
// ) — the cost of building a power station in the i
// -th city.

// The last line contains n
//  space-separated integers k1,k2,…,kn
//  (1≤ki≤109
// ).

// Output
// In the first line print a single integer, denoting the minimum amount of yen needed.

// Then, print an integer v
//  — the number of power stations to be built.

// Next, print v
//  space-separated integers, denoting the indices of cities in which a power station will be built. Each number should be from 1
//  to n
//  and all numbers should be pairwise distinct. You can print the numbers in arbitrary order.

// After that, print an integer e
//  — the number of connections to be made.

// Finally, print e
//  pairs of integers a
//  and b
//  (1≤a,b≤n
// , a≠b
// ), denoting that a connection between City a
//  and City b
//  will be made. Each unordered pair of cities should be included at most once (for each (a,b)
//  there should be no more (a,b)
//  or (b,a)
//  pairs). You can print the pairs in arbitrary order.

// If there are multiple ways to choose the cities and the connections to obtain the construction of minimum price, then print any of them.

// Examples
// InputCopy
// 3
// 2 3
// 1 1
// 3 2
// 3 2 3
// 3 2 3
// OutputCopy
// 8
// 3
// 1 2 3
// 0
// InputCopy
// 3
// 2 1
// 1 2
// 3 3
// 23 2 23
// 3 2 3
// OutputCopy
// 27
// 1
// 2
// 2
// 1 2
// 2 3

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P pair<int, int>
struct DSU
{
    vector<int> parent;
    vector<int> rank;
    void init(int n)
    {
        parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }
    int find(int v)
    {
        if (parent[v] == v)
            return v;
        return parent[v] = find(parent[v]);
    }
    void merge(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};

int manhattan_distance(int x1, int x2, int y1, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> cities(n);
    vector<int> power_station_cities;
    vector<P> connected_cities;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cities[i] = {x, y};
    }
    vector<int> per_city_cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> per_city_cost[i];
    }
    vector<int> k_values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k_values[i];
    }

    vector<pair<int, P>> edges;

    for (int i = 0; i < n; i++)
    {

        edges.push_back({per_city_cost[i], {0, i + 1}}); // Connecting to the power grid
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int cost = (k_values[i] + k_values[j]) * manhattan_distance(cities[i][0], cities[j][0], cities[i][1], cities[j][1]);
            edges.push_back({cost, {i + 1, j + 1}}); // Connecting cities
        }
    }

    sort(edges.begin(), edges.end());
    DSU dsu;

    dsu.init(n + 1); // n cities + 1 for the power grid
    int total_cost = 0;

    for (auto &edge : edges)
    {
        int cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (dsu.find(u) != dsu.find(v))
        {
            dsu.merge(u, v);
            total_cost += cost;
            if (u == 0 || v == 0)
            {
                // This means connecting to virtual power grid => build station
                power_station_cities.push_back((u == 0 ? v : u));
            }
            else
            {
                // This is a wire between two cities
                connected_cities.push_back({u, v});
            }
        }
    }

    cout << total_cost << "\n";

    cout << power_station_cities.size() << "\n";
    for (int city : power_station_cities)
        cout << city << " ";
    cout << "\n";

    cout << connected_cities.size() << "\n";
    for (auto &p : connected_cities)
        cout << p.first << " " << p.second << "\n";

    return 0;
}