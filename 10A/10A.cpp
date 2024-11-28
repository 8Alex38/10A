#include <iostream>
#include <string>
#include <vector>

// Перерахування для спеціальностей
enum Speciality {
    COMPUTER_SCIENCE,
    MATHEMATICS,
    PHYSICS,
    ENGINEERING,
    BIOLOGY,
    CHEMISTRY
};

// Структура для студента
struct Student {
    std::string surname;
    int course;
    Speciality speciality;
    int physicsGrade;
    int mathematicsGrade;
    int informaticsGrade;
};

// Функція для створення масиву студентів
std::vector<Student> createStudentArray() {
    int numberOfStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numberOfStudents;

    std::vector<Student> students(numberOfStudents);  // Створюємо вектор студентів

    // Цикл для введення інформації для кожного студента
    for (int i = 0; i < numberOfStudents; ++i) {
        std::cout << "Enter surname for student " << (i + 1) << ": ";
        std::cin >> students[i].surname;

        std::cout << "Enter course for student " << (i + 1) << ": ";
        std::cin >> students[i].course;

        int specialityInput;
        std::cout << "Enter speciality for student " << (i + 1) << " (0: Computer Science, 1: Mathematics, 2: Physics, 3: Engineering, 4: Biology, 5: Chemistry): ";
        std::cin >> specialityInput;
        students[i].speciality = static_cast<Speciality>(specialityInput);

        std::cout << "Enter grade in Physics for student " << (i + 1) << ": ";
        std::cin >> students[i].physicsGrade;

        std::cout << "Enter grade in Mathematics for student " << (i + 1) << ": ";
        std::cin >> students[i].mathematicsGrade;

        std::cout << "Enter grade in Informatics for student " << (i + 1) << ": ";
        std::cin >> students[i].informaticsGrade;
    }

    return students;  // Повертаємо вектор студентів
}

void displayStudentArray(const std::vector<Student>& students) {
    std::cout << "\n| No | Surname         | Course | Speciality        | Physics | Mathematics | Informatics |\n";
    std::cout << "--------------------------------------------------------------------------------------\n";

    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "| " << (i + 1) << "  | "
            << students[i].surname << "       | "
            << students[i].course << "      | "
            << students[i].speciality << "          | "
            << students[i].physicsGrade << "      | "
            << students[i].mathematicsGrade << "        | "
            << students[i].informaticsGrade << "        |\n";
    }
    std::cout << "--------------------------------------------------------------------------------------\n";
}

// Функція для підрахунку кількості відмінних оцінок (5) з кожної дисципліни
void countExcellentGrades(const std::vector<Student>& students, int& physicsCount, int& mathematicsCount, int& informaticsCount) {
    physicsCount = 0;
    mathematicsCount = 0;
    informaticsCount = 0;

    // Перевіряємо кожного студента
    for (const auto& student : students) {
        if (student.physicsGrade == 5) {
            ++physicsCount;
        }
        if (student.mathematicsGrade == 5) {
            ++mathematicsCount;
        }
        if (student.informaticsGrade == 5) {
            ++informaticsCount;
        }
    }
}

int main() {
    // Створюємо масив студентів за допомогою функції createStudentArray
    std::vector<Student> students = createStudentArray();

    // Виводимо список студентів
    displayStudentArray(students);

    // Лічильники відмінних оцінок
    int physicsExcellentCount, mathematicsExcellentCount, informaticsExcellentCount;
    // Підраховуємо кількість відмінних оцінок
    countExcellentGrades(students, physicsExcellentCount, mathematicsExcellentCount, informaticsExcellentCount);

    // Виводимо кількість відмінних оцінок
    std::cout << "\nNumber of 'excellent' grades (5):\n";
    std::cout << "Physics: " << physicsExcellentCount << "\n";
    std::cout << "Mathematics: " << mathematicsExcellentCount << "\n";
    std::cout << "Informatics: " << informaticsExcellentCount << "\n";

    return 0;
}
