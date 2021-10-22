#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

void tests(int &counter_of_succesfully_done, int &counter_of_all_done, int &wrong_asnwered)
{
    ifstream in("dic.in");

    srand(time(NULL));

    string answer;

    vector<string> dictionary;
    while (in >> answer)
    {
        dictionary.push_back(answer);
    }

    while (true)
    {
        int idx = rand() % dictionary.size();

        cout << dictionary[idx] << endl;

        cin >> answer;

        counter_of_all_done++;

        if (answer == dictionary[idx])
            counter_of_succesfully_done++;
        else
            wrong_asnwered++;
    }
}

int main()
{
    int total_quantity_of_questions = 0, answered_questions = 0, wrong_answers = 0;

    auto variables = [&answered_questions, &total_quantity_of_questions, &wrong_answers]()
    {
        tests(answered_questions, total_quantity_of_questions, wrong_answers);
    };

    thread thread_for_tests(variables);
    thread_for_tests.detach();

    for (int i = 1; i <= 60; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    cout << "\nyou've answered: " << answered_questions << " questions of " << total_quantity_of_questions << endl;

    if (total_quantity_of_questions != 0)
        cout << "percentage of correct answers: " << (double)(answered_questions * 100 / total_quantity_of_questions) << " %" << endl;
    else
        cout << "percentage of correct answers: 0%" << endl;

    if (answered_questions != 0)
        cout << "accuracy: " << (double)(100 - wrong_answers * 100 / answered_questions) << "%\n\n";
    else
        cout << "accuracy: 0%\n\n";

    cout << "your result: " << answered_questions << " WPM\n";

    return 0;
}