/**
 * Purpose : COMP90077 Adv Algs & DS (2022) - Assignment 2
 * @author Zhen Cai (1049487) <zhcai@student.unimelb.edu.au>
 */

#include "main.h"

Generator generator;

Treap treap;
DynamicArray arr;

long double timers[] = {0, 0};    // {treap, array}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    istringstream is(argv[2]);
    int L;
    double percent;

    switch (atoi(argv[1]))
    {
    case 1:
        is >> L;
        exp_1(L);
        break;
    case 2:
        is >> percent;
        exp_2(percent);
        break;
    case 3:
        is >> percent;
        exp_3(percent);
        break;
    case 4:
        is >> L;
        exp_4(L);
        break;
    }

    return 0;
}

void exp_1(int L)
{
    vector<Job> jobs;
    for (int i = 0; i < L; i++) {
        jobs.push_back(generator.gen_insertion());
    }

    for (Job j : jobs) run_treap(j);
    for (Job j : jobs) run_arr(j);

    cout << "Experiment 1 with L_ins = " << L << ":\t"
            << fixed << setprecision(3)
            << setw(8) << std::right << std::setfill(' ') << timers[0] << "\t"
            << setw(8) << std::right << std::setfill(' ') << timers[1] << endl;
}

void exp_2(double del_percent)
{
    random_device rd;
    mt19937 rng(rd());
    uniform_real_distribution<> dist(0, 100);

    vector<Job> jobs;
    for (int i = 0; i < pow(10,6); i++)
    {
        if (dist(rng) < del_percent) {
            jobs.push_back(generator.gen_deletion());
        } else {
            jobs.push_back(generator.gen_insertion());
        }
    }

    for (Job j : jobs) run_treap(j);
    for (Job j : jobs) run_arr(j);

    cout << "Experiment 2 with %_del = " << del_percent << ":\t\t"
            << fixed << setprecision(3)
            << setw(8) << std::right << std::setfill(' ') << timers[0] << "\t"
            << setw(8) << std::right << std::setfill(' ') << timers[1] << endl;
}

void exp_3(double sch_percent)
{
    random_device rd;
    mt19937 rng(rd());
    uniform_real_distribution<> dist(0, 100);

    vector<Job> jobs;
    for (int i = 0; i < pow(10,6); i++)
    {
        if (dist(rng) < sch_percent) {
            jobs.push_back(generator.gen_search());
        } else {
            jobs.push_back(generator.gen_insertion());
        }
    }

    for (Job j : jobs) run_treap(j);
    for (Job j : jobs) run_arr(j);

    cout << "Experiment 3 with %_sch = " << sch_percent << ":\t\t"
            << fixed << setprecision(3)
            << setw(8) << std::right << std::setfill(' ') << timers[0] << "\t"
            << setw(8) << std::right << std::setfill(' ') << timers[1] << endl;
}

void exp_4(int L)
{
    double r;
    random_device rd;
    mt19937 rng(rd());
    uniform_real_distribution<> dist(0, 100);

    vector<Job> jobs;
    for (int i = 0; i < L; i++)
    {
        r = dist(rng);
        if (r < 5) {
            jobs.push_back(generator.gen_deletion());
        } else if (r < 10) {
            jobs.push_back(generator.gen_search());
        } else {
            jobs.push_back(generator.gen_insertion());
        }
    }

    for (Job j : jobs) run_treap(j);
    for (Job j : jobs) run_arr(j);

    cout << "Experiment 4 with L = " << L << ":\t\t"
            << fixed << setprecision(3)
            << setw(8) << std::right << std::setfill(' ') << timers[0] << "\t"
            << setw(8) << std::right << std::setfill(' ') << timers[1] << endl;
}

void run_treap(Job j)
{
    chrono::_V2::system_clock::time_point start, stop;

    switch (j.op)
    {
        case INSERTION:
            start = high_resolution_clock::now();
            treap.insert(j._e);
            break;

        case DELETION:
            start = high_resolution_clock::now();
            treap.remove(j.key);
            break;

        case SEARCH:
            start = high_resolution_clock::now();
            treap.search(j.key);
            break;
    }
    stop = high_resolution_clock::now();
    duration<long double> elapsed = stop - start;
    timers[0] += elapsed.count();
}

void run_arr(Job j)
{
    chrono::_V2::system_clock::time_point start, stop;
    
    switch (j.op)
    {
        case INSERTION:
            start = high_resolution_clock::now();
            arr.insert(j._e);
            break;

        case DELETION:
            if (j.key == -1) return;
            start = high_resolution_clock::now();
            arr.remove(j.key);
            break;
            
        case SEARCH:
            start = high_resolution_clock::now();
            arr.search(j.key);
            break;
    }
    stop = high_resolution_clock::now();
    duration<long double> elapsed = stop - start;
    timers[1] += elapsed.count();
}
