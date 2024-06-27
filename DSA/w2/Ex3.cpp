
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
struct employee
{
    std::string id;
    std::string name;

    int birthYear;

    bool operator>(employee const &other)
    {
        if (birthYear == other.birthYear)
            return std::lexicographical_compare(name.begin(), name.end(), other.name.begin(), other.name.end());
        return birthYear > other.birthYear;
    }

    bool operator<(employee const &other)
    {
        if (birthYear == other.birthYear)
            return !std::lexicographical_compare(name.begin(), name.end(), other.name.begin(), other.name.end());
        return birthYear < other.birthYear;
    }

    bool operator>=(employee const &other)
    {
        if (birthYear == other.birthYear)
            return std::lexicographical_compare(name.begin(), name.end(), other.name.begin(), other.name.end());
        return birthYear >= other.birthYear;
    }
};

void merge(std::vector<employee> &a, std::vector<employee> &aux, int l, int m, int r)
{
    int i, j, k;
    i = l;
    j = m + 1;
    k = l;
    while (i <= m && j <= r)
        if (aux[i] >= aux[j])
            a[k++] = aux[i++];
        else
            a[k++] = aux[j++];
    while (j <= r)
        a[k++] = aux[j++];
    while (i <= m)
        a[k++] = aux[i++];
}

void mergesort(std::vector<employee> &a, std::vector<employee> &aux, int l, int r)
{
    std::vector<employee> *real = &a;
    std::vector<employee> *fake = &aux;
    for (int sz = 1; sz <= r - l; sz = sz + sz)
    {
        for (int i = l; i <= r - sz; i += sz + sz)
        {
            merge(*fake, *real, i, i + sz - 1, std::min(i + sz + sz - 1, r));
        }
        std::swap(real, fake);
    }
    if (fake == &a)
    {
        for (int k = l; k <= r; k++)
            a[k] = aux[k];
    }
}

int partition(std::vector<employee> &a, int l, int r)
{
    int mid = (l + r) / 2;
    if (a[l] < a[mid])
        std::swap(a[l], a[mid]);
    if (a[l] < a[r])
        std::swap(a[l], a[r]);
    if (a[mid] < a[r])
        std::swap(a[mid], a[r]);
    employee v = a[mid];
    std::swap(a[mid], a[r - 1]);

    int i = l - 1, j = r - 1;
    while (true)
    {
        while (a[++i] > v)
            ;
        while (v > a[--j])
            if (j == l)
                break;
        if (i >= j)
            break;
        std::swap(a[i], a[j]);
    }
    std::swap(a[i], a[r - 1]);
    return i;
}

void quicksort(std::vector<employee> &a, int l, int r)
{
    if (r <= l)
        return;
    int i = partition(a, l, r);
    quicksort(a, l, i - 1);
    quicksort(a, i + 1, r);
}

int main()
{
    std::fstream ifile("employee.txt", std::ios::in);
    std::fstream ofile("sortedemponage.txt", std::ios::out);

    std::vector<employee> employees;
    std::string           id;
    std::string           name;
    int                   birthYear;
    std::getline(ifile, id);
    while (std::getline(ifile, id, ','))
    {
        std::getline(ifile, name, ',');
        ifile >> birthYear;
        ifile.ignore();
        employee temp = {id, name, birthYear};
        employees.push_back(temp);
    }

    // mergesort here
    // std::vector<employee> aux(employees.size());
    // mergesort(employees, aux, 0, employees.size() - 1);

    quicksort(employees, 0, employees.size() - 1);

    for (auto &i : employees)
    {
        ofile << i.id << ',' << i.name << ',' << i.birthYear << '\n';
    }
}