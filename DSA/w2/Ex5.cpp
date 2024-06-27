#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Student
{
    std::string      name;
    float            score1;
    float            score2;
    std::vector<int> opts;

    bool operator<(const Student &r)
    {
        if ((score1 + score2) == (r.score1 + r.score2))
        {
            if (score1 == r.score1)
            {
                return score2 < r.score2;
            }
            return score1 < r.score1;
        }
        return (score1 + score2) < (r.score1 + r.score2);
    }

    bool operator==(const Student &r)
    {
        return (score1 == r.score1) && (score2 == r.score2);
    }

    float avg()
    {
        return (score1 + score2) / 2;
    }
};

void insertion(std::vector<Student> &a)
{
    Student v;
    for (int i = 1; i < a.size(); i++)
    {
        v = a[i];
        int j;
        for (j = i; j > 0 && v < a[j - 1]; j--)
            a[j] = a[j - 1];
        a[j] = v;
    }
}

int main()
{
    std::fstream file("exam.txt", std::ios::in);
    if (!file.is_open())
    {
        std::cerr << "cant open file.\n";
    }

    int m;
    file >> m;
    std::vector<int> slots(m);
    int              temp;
    for (int i = 0; i < m; i++)
    {
        file >> temp;
        file >> slots[i];
    }

    file.ignore();
    std::vector<std::vector<Student>> students(m + 1);
    std::string                       name;
    while (std::getline(file, name, ','))
    {
        Student stud = {name};
        file >> stud.score1;
        file.ignore();
        file >> stud.score2;
        file.ignore();
        for (int i = 0; i < m; i++)
        {
            int option;
            file >> option;
            stud.opts.push_back(option);
            file.ignore();
        }
        students[0].push_back(stud);
    }

    insertion(students[0]);

    for (int i = students[0].size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            int option = students[0][i].opts[j];
            if (slots[option - 1] == 0 && students[option].back() == students[0][i])
            {
                slots[option - 1]++;
            }
            if (slots[option - 1] > 0)
            {
                students[option].push_back(students[0][i]);
                students[0].pop_back();
                slots[option - 1]--;
                break;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        std::cout << "Successful candidates for option " << i << '\n';
        int j = 0;
        for (auto &stud : students[i])
        {
            j++;
            std::cout << j << ". " << stud.name << " " << stud.avg() << '\n';
        }
    }
    std::cout << "Unsuccessful candidates\n";
    int j = 0;
    for (auto &stud : students[0])
    {
        j++;
        std::cout << j << ". " << stud.name << " " << stud.avg() << '\n';
    }

    return 0;
}