template <typename T>
class Queue {
private:
    RStack<T> reversed; //reversed
    RStack<T> ordered; //ordered

    void transfer(RStack<T>& source, RStack<T>& destination) {
        while (!source.empty()){
            destination.push(source.top());
            source.pop();
        }
    }

public:
    bool empty() const;
    void push(T const& x);
    void pop();
    T head() const;
};

template <typename T>
bool Queue<T>::empty() const {
    return reversed.empty() && ordered.empty();
}

template <typename T>
void Queue<T>::push(T const& x) {
    this->transfer(ordered, reversed);
    this->reversed.push(x);
}

template <typename T>
void Queue<T>::pop() {
    this->transfer(reversed, ordered);
    this->ordered.pop();
}

template <typename T>
T Queue<T>::head() const {
    this->transfer(reversed, ordered);
    return this->ordered.top();
}
