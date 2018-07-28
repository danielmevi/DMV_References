/*
 *
 */

#include <memory>

shared_ptr<widget> make_widget(int id) {
  static map<int, weak_ptr<widget>> cache;
  static mutex mut_cache;
  lock_guard<mutex> hold(mut_cache);
  auto sp = cache[id].lock();
  if (!sp) cache[id] = sp = load_widget(id);
  return sp;
}

