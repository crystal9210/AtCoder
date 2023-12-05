#include <iostream>
#include <functional>
#include <vector>

void printInt(int number) {
    std::cout << "Number: " << number << std::endl;
}

int main() {
    std::vector<std::function<void(int)>> tasks;

    tasks.push_back(printInt); // 関数ポインタ
    tasks.push_back([](int number) { std::cout << "Lambda: " << number << std::endl; }); // ラムダ式
    tasks.push_back([](int number) { std::cout << "Another Lambda: " << number * 2 << std::endl; }); // 別のラムダ式

    for (auto& task : tasks) {
        task(5); // 同一インターフェースで異なるタイプの関数を実行
    }

    return 0;
}
