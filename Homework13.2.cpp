// Homework13.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

void sum(int threadnum, int elemsum, std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int> vecres) {

    for (int i = (0 + elemsum * threadnum); i < (elemsum * (threadnum + 1)); i++) {
        vecres[i] = vec1[i] + vec2[i];
    }
}

void vecsum(std::vector<int>& vec1, std::vector<int>& vec2, const int threadsnum, const int vecsize) {
    std::vector<int> vecres(vecsize);

    auto start = std::chrono::high_resolution_clock::now();
  
    std::vector<std::thread> T;
    for (int i = 0; i < threadsnum; i++) {
        T.push_back(std::thread(sum, i, (vecsize/threadsnum), ref(vec1), ref(vec2), ref(vecres)));
    }
    for (auto& thd : T) {
        thd.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time = end - start;
    std::cout << time.count() << " ms\t";

}

int main()
{
    int threads = 1;

    unsigned int n = std::thread::hardware_concurrency();
    std::cout << "We have " << n << " cores!\n\n";

    std::cout << "\t\t1000\t\t10000\t\t100000\t\t1000000\n";

    //1 поток
    std::cout << "1 core:\t\t";

    for (int i = 1000; i <= 1000000; i *= 10) {
        
        std::vector<int> vec1(i, 2);
        std::vector<int> vec2(i, 5);
        vecsum(vec1, vec2, 1, i);
    }
    std::cout << std::endl;

    //2 потока
    std::cout << "2 core:\t\t";

    for (int i = 1000; i <= 1000000; i *= 10) {

        std::vector<int> vec1(i, 2);
        std::vector<int> vec2(i, 5);
        vecsum(vec1, vec2, 2, i);
    }
    std::cout << std::endl;

    //4 потока
    std::cout << "4 core:\t\t";

    for (int i = 1000; i <= 1000000; i *= 10) {

        std::vector<int> vec1(i, 2);
        std::vector<int> vec2(i, 5);
        vecsum(vec1, vec2, 4, i);
    }
    std::cout << std::endl;

    //8 потоков
    std::cout << "8 core:\t\t";

    for (int i = 1000; i <= 1000000; i *= 10) {

        std::vector<int> vec1(i, 2);
        std::vector<int> vec2(i, 5);
        vecsum(vec1, vec2, 8, i);
    }
    std::cout << std::endl;

    //16 потоков
    std::cout << "16 core:\t";

    for (int i = 1000; i <= 1000000; i *= 10) {

        std::vector<int> vec1(i, 2);
        std::vector<int> vec2(i, 5);
        vecsum(vec1, vec2, 16, i);
    }
    std::cout << std::endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
