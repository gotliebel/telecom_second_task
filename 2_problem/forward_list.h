#pragma once

template<class T>
class ForwardList {
 private:

  struct Node {
    Node() = default;
    explicit Node(T val) : value(val) {}
    Node(const Node &v) {
      value = v.value;
      delete next;
      next = new Node();
      next = v.next;
    }

    T value;
    Node *next = nullptr;
  };

  Node *head_ = nullptr;
  size_t size_ = 0;

 public:
  class Iterator {
   private:
    Node *ptr;
   public:
    Iterator() : ptr(nullptr) {}
    explicit Iterator(Node *ptr1) : ptr(ptr1) {}
    Iterator &operator++() {
      ptr = ptr->next;
      return *this;
    }
    Iterator operator++(int) {
      Iterator tmp(this->ptr);
      ptr = ptr->next;
      return tmp;
    }
    Iterator operator+(int n) {
      Iterator tmp(this->ptr);
      for (int i = 0; i < n; ++i) {
        ptr = ptr->next;
      }
      return tmp;
    }
    T &operator*() {
      return ptr->value;
    }

    friend bool operator==(const Iterator &x, const Iterator &y) {
      return x.ptr == y.ptr;
    }
    friend bool operator!=(const Iterator &x, const Iterator &y) {
      return !(x == y);
    }
    Node *ptr_go() {
      return this->ptr;
    }
  };

  Iterator begin() {
    return Iterator(head_);
  }
  Iterator end() {
    return Iterator(nullptr);
  }

  ForwardList() = default;
  explicit ForwardList(size_t size_) {
    if (size_ <= 0) {
      throw "Negative size";
    }
    head_ = new Node();
    this->size_ = size_;
    Node *tmp = head_;
    for (int i = 1; i < size_; i++) {
      tmp->next = new Node();
      tmp = tmp->next;
    }
  }
  ForwardList(const ForwardList<T> &v) {
    this->size_ = v.size_;
    delete head_;
    Node *c = v.head_;
    head_ = new Node(c->value);
    Node *tmp = head_;
    c = c->next;
    while (c) {
      tmp->next = new Node(c->value);
      c = c->next;
      tmp = tmp->next;
    }
  }
  ForwardList(ForwardList &&v) noexcept {
    Node *tmp = v.head_;
    this->head_ = tmp;
    this->size_ = v.size_;
    v.head_ = nullptr;
  }

  ~ForwardList() {
    clear();
  }

  void clear() {
    Node *tmp = head_;
    while (tmp) {
      Node *tmp1 = tmp->next;
      delete[] tmp;
      tmp = tmp1;
    }
  }

  const ForwardList &operator=(const ForwardList &v) {
    if (this == &v) {
      return *this;
    }
    ForwardList tmp(v);
    this->clear();
    this->head_ = tmp.head_;
    this->size_ = tmp.size_;
    return *this;
  }
  const ForwardList &operator=(ForwardList &&v) noexcept {
    if (this == &v) {
      return *this;
    }
    this->clear();
    this->size_ = v.size_;
    Node *tmp = v.head_;
    this->head_ = tmp;
    v.head_ = nullptr;
  }

  Iterator find(const T &val) {
    Node *tmp = head_;
    while (tmp) {
      if (tmp->value == val) {
        return Iterator(tmp);
      }
      tmp = tmp->next;
    }
    return Iterator(nullptr);
  }

  void pop_front() {
    if (this->empty()) {
      throw "Empty list";
    }
    Node *tmp = head_->next;
    delete head_;
    head_ = tmp;
    size_--;
  }

  void push_front(const T &val) {
    Node *tmp1 = new Node(val);
    Node *tmp2 = head_;
    head_ = tmp1;
    head_->next = tmp2;
    size_++;
  }

  bool empty() {
    return (size_ == 0);
  }

  size_t size() {
    return size_;
  }

  T operator[](const size_t &index) const {
    if (index >= size_) {
      throw "Out of range";
    }
    Node *tmp = head_;
    for (int i = 0; i < index; i++) {
      tmp = tmp->next;
    }
    return tmp->value;
  }
  T &operator[](const size_t &index) {
    if (index >= size_) {
      throw "Out of range";
    }
    Node *tmp = head_;
    for (int i = 0; i < index; i++) {
      tmp = tmp->next;
    }
    return tmp->value;
  }

  Iterator insert_after(Iterator it, T val) {
    Node *tmp = new Node(val);
    tmp->next = (it.ptr_go())->next;
    (it.ptr_go())->next = tmp;
    size_++;
    return Iterator(tmp);
  }
  Iterator erase_after(Iterator it) {
    Node *tmp1 = it.ptr_go();
    Node *tmp2 = tmp1->next;
    tmp1->next = tmp2->next;
    delete[] tmp2;
    size_--;
    return Iterator(tmp1->next);
  }
};