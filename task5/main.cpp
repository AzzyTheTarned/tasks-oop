#include <algorithm>
#include <iostream>
#include <iterator>
#include <future>
#include <vector>
#include <numeric>

using namespace std;

static const int MT_MIN_SIZE = 10'000;

template <typename InputIt, typename T>
auto parallel_accumulate(InputIt first, InputIt last, T init) {
    const auto size = distance(first, last);
    const auto parts = (size < MT_MIN_SIZE)? 1 : thread::hardware_concurrency();

    vector<future<T>> futures;

    for (size_t i = 0; i != parts; ++i) {
        const auto part_size = (size * i + size) / parts - (size * i) / parts;
        futures.emplace_back(async(launch::async, [=] { return accumulate(first, next(first, part_size), T{}); }));
        advance(first, part_size);
    }
    return accumulate(begin(futures), end(futures), init, [] (const T prev, auto& future) { return prev + future.get(); });
}

int main() {
    using namespace std::literals;


    vector<int> v(1000000000, 0);
    iota(begin(v), end(v), 1);

    cout << "Sequential sum:" << endl;
    auto start = chrono::high_resolution_clock::now();
    auto sum = accumulate(begin(v), end(v), 0ull);
    auto end = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    cout << "Sum: " << sum << endl;

    cout << "Parallel sum:" << endl;
    start = chrono::high_resolution_clock::now();
    sum = parallel_accumulate(begin(v), std::end(v), 0ull);
    end = chrono::high_resolution_clock ::now();
    cout << "Time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
    cout << "Sum: " << sum << endl;
}