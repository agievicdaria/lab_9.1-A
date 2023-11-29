#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum Specialty
{
    COMPUTER_SCIENCE,
    INFORMATICS,
    MATH_ECON,
    PHYS_INF,
    HANDICRAFT
};

struct Student
{
    string lastName;
    int course;
    Specialty specialty;
    double physicsGrade;
    double mathGrade;
    double computerScienceGrade;
};

string specialtyStr[] = {"computer science", "informatics", "math and economics", "physics and informatics", "handicraft"};

void Create(Student *students, int numberOfStudents)
{
    for (int i = 0; i < numberOfStudents; ++i)
    {
        cout << "Студента #" << i + 1 << ":\n";
        cin.ignore();
        cout << "Прізвище: ";
        getline(cin, students[i].lastName);
        cout << "Курс: ";
        cin >> students[i].course;
        cout << "Спеціальність (0 - комп'ютерні науки, 1 - інформатика, 2 - математика та економіка, 3 - фізика та інформатика, 4 - трудове навчання): ";
        int specialty;
        cin >> specialty;
        students[i].specialty = static_cast<Specialty>(specialty);
        cout << "Оцінка з фізики: ";
        cin >> students[i].physicsGrade;
        cout << "Оцінка з математики: ";
        cin >> students[i].mathGrade;
        cout << "Оцінка з інформатики: ";
        cin >> students[i].computerScienceGrade;
        cout << endl;
    }
}

void PrintTable(const Student *students, const int numberOfStudents)
{
    cout << "========================================================================================"
         << endl;
    cout << "| №  | Прізвище | Курс | Спеціальність            | Фізика | Математика | Інформатика |"
         << endl;
    cout << "----------------------------------------------------------------------------------------"
         << endl;

    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " "
             << "| " << setw(9) << left << students[i].lastName
             << "| " << setw(5) << right << students[i].course
             << "| " << setw(25) << left << specialtyStr[static_cast<int>(students[i].specialty)]
             << "| " << setw(7) << right << students[i].physicsGrade
             << "| " << setw(11) << right << students[i].mathGrade
             << "| " << setw(11) << right << students[i].computerScienceGrade << " |" << endl;
    }
    cout << "========================================================================================"
         << endl;
    cout << endl;
}

string printExcellentStudents(const Student *students, int numberOfStudents)
{
    string excellentStudents;

    for (int i = 0; i < numberOfStudents; ++i)
    {
        if (students[i].physicsGrade == 5.0 &&
            students[i].mathGrade == 5.0 &&
            students[i].computerScienceGrade == 5.0)
        {
            excellentStudents += students[i].lastName + "\n";
        }
    }

    return excellentStudents;
}

double calculatePercentageOfStudents(const Student *students, int numberOfStudents)
{
    int countHighGrades = 0;
    for (int i = 0; i < numberOfStudents; ++i)
    {
        double averageGrade = (students[i].physicsGrade + students[i].mathGrade + students[i].computerScienceGrade) / 3.0;
        if (averageGrade > 4.5)
        {
            ++countHighGrades;
        }
    }

    return static_cast<double>(countHighGrades) / static_cast<double>(numberOfStudents) * 100.0;
}

int main()
{
    int numberOfStudents;
    cout << "Введіть кількість студентів: ";
    cin >> numberOfStudents;

    Student *students = new Student[numberOfStudents];

    Create(students, numberOfStudents);
    PrintTable(students, numberOfStudents);
    
    string excellentStudents = printExcellentStudents(students, numberOfStudents);
    cout << "Студенти, які вчаться на 'відмінно':\n" << excellentStudents;

    double percentageOfStudents = calculatePercentageOfStudents(students, numberOfStudents);
    cout << "Процент студентів із середнім балом більше за 4,5: " << fixed << setprecision(2) << percentageOfStudents << "%" << endl;

    delete[] students;
    return 0;
}