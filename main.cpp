#include "Queue.h"
#include <iostream>

int main() {
    Queue q1;
    q1 << 10 << 20 << 30;
    std::cout << "q1 = " << q1 << "\n";

    Queue q2;
    q2 << 40 << 50;
    std::cout << "q2 = " << q2 << "\n";

    Queue q3 = q1 + q2;
    std::cout << "q1 + q2 = " << q3 << "\n";

    int x;
    q3 >> x;
    std::cout << "Достали: " << x << "\n";
    std::cout << "После >> : " << q3 << "\n";

    std::cout << "q1 == q2 ? " << (q1 == q2) << "\n";
    std::cout << "q1 < q2  ? " << (q1 < q2) << "\n";

    return 0;
}