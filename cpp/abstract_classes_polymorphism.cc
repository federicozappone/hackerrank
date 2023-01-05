#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Cache
{
 protected:
  virtual void set(int, int) = 0;  // set function
  virtual int get(int) = 0;        // get function
};

class LRUCache : public Cache
{
  int cp;
  map<int, list<pair<int, int>>::iterator> mp;
  list<pair<int, int>> lru;

 public:
  LRUCache(int capacity) : cp(capacity) {}

  void set(int key, int val)
  {
    if (mp.find(key) != mp.end())
    {
      mp[key]->first = key;
      mp[key]->second = val;
    }
    else
    {
      lru.push_front({key, val});
      mp[key] = lru.begin();
      if (lru.size() > cp)
      {
        mp.erase(lru.back().first);
        lru.pop_back();
      }
    }
  }

  int get(int key)
  {
    if (mp.find(key) != mp.end())
    {
      lru.push_front(*mp[key]);
      lru.erase(mp[key]);
      mp[key] = lru.begin();
      return mp[key]->second;
    }
    else
      return -1;
  }
};

int main()
{
  int n, capacity, i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  for (i = 0; i < n; i++)
  {
    string command;
    cin >> command;
    if (command == "get")
    {
      int key;
      cin >> key;
      cout << l.get(key) << endl;
    }
    else if (command == "set")
    {
      int key, value;
      cin >> key >> value;
      l.set(key, value);
    }
  }
  return 0;
}
