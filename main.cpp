#include<vector>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<algorithm>
using namespace std;


struct Emp {
    int eid;
    string ename;
    int age;
    string salary;
};

bool compare(const Emp *a, const Emp *b)
{
   return a->eid < b->eid;
}

Emp* create_emp_blcok(int eid, string ename, int age, string salary){
    Emp* temp = new Emp;
    temp->eid = eid;
    temp->ename = ename;
    temp->age = age;
    temp->salary = salary;
    return temp;
};


void fileopen(string filename, vector<Emp*>& emp){
    fstream fin;
    vector<string> row;
    string line, word, temp;
    Emp* ep = new Emp;

    fin.open(filename,ios::in);
    while (fin){
        getline(fin, temp);
        row.clear();
        stringstream d(temp);

        while (getline(d,word,',')) {
            row.push_back(word);
        }
        ep = create_emp_blcok(atoi(row[0].c_str()), row[1], atoi(row[2].c_str()), row[3]);
        emp.push_back(ep);
    }
    fin.close();
}

int main(){

    string filename = "Emp.csv";
    vector<Emp *> emp;
    int memory_size = 22;
    fileopen(filename, emp);
    emp.pop_back();

    sort(emp.begin(), emp.end(), compare);

    ofstream outfile;
    outfile.open("EmpSorted.csv", ios::out);
    for(int i = 0; i<emp.size(); i++){
        outfile << emp[i]->eid << ',' << emp[i]->ename << ',' << emp[i]->age << ',' << emp[i]->salary << endl;
    }
    outfile.close();
    return 0;
}
