# C++ STL Complete Tutorial for Competitive Programming

## 1. Vector
```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    v.push_back(4);
    v.pop_back();
    for (int i : v) cout << i << " ";
    return 0;
}
```

## 2. Pair
```cpp
#include <iostream>
#include <utility>
using namespace std;

int main() {
    pair<int, string> p = {1, "hello"};
    cout << p.first << " " << p.second << endl;
    return 0;
}
```

## 3. Set
```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(3); s.insert(1); s.insert(2);
    for (int i : s) cout << i << " ";
    return 0;
}
```

## 4. Multiset
```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms = {1, 2, 2, 3};
    ms.erase(ms.find(2)); // only one occurrence removed
    for (int i : ms) cout << i << " ";
    return 0;
}
```

## 5. Map
```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> mp;
    mp["a"] = 1;
    mp["b"] = 2;
    for (auto p : mp) cout << p.first << " -> " << p.second << endl;
    return 0;
}
```

## 6. Unordered Map
```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> ump;
    ump[1] = "one";
    ump[2] = "two";
    for (auto p : ump) cout << p.first << ": " << p.second << endl;
    return 0;
}
```

## 7. Stack
```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(1); s.push(2);
    cout << s.top() << endl; // 2
    s.pop();
    return 0;
}
```

## 8. Queue
```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1); q.push(2);
    cout << q.front() << endl; // 1
    q.pop();
    return 0;
}
```

## 9. Priority Queue
```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(1); pq.push(3); pq.push(2);
    cout << pq.top() << endl; // 3
    return 0;
}
```

## 10. Deque
```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    for (int x : dq) cout << x << " "; // 2 1
    return 0;
}
```

## 11. Bitset
```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<8> b(string("10110011"));
    cout << b.count() << endl; // number of 1's
    return 0;
}
```

## 12. Algorithm (Sort, Reverse, Max, Min)
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {3, 1, 2};
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << *max_element(v.begin(), v.end()) << endl;
    return 0;
}
```
