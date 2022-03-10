#include <iostream>
#include <numeric>
#include <fstream>
#include "exercise_2.hpp"
#include "exercise_3.hpp"

int main()
{
exercise_2::StudentsGroup sg;
    std::ifstream in("student.bin", std::ios_base::binary);
    if (sg.ParseFromIstream(&in))
    {
        std::cout << sg.students(0).name().surname() << std::endl;
        std::cout << sg.students(0).avg_score() << std::endl;
    }
    else
    {
        std::cout << "Error!" << std::endl;
    }
    exercise_1_2();
    exercise_3();

    return 0;
}
