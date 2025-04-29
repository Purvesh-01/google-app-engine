#include <iostream>
#include <string>
using namespace std;

string toLower(string s)
{
    for (auto &c : s)
        c = tolower(c);
    return s;
}

bool ask(string question)
{
    string answer;
    cout << question << " (yes/no): ";
    cin >> answer;
    return toLower(answer) == "yes";
}

int main()
{
    cout << "Welcome to the Medical Expert System\n";
    cout << "Please answer the following questions with yes or no.\n\n";

    bool fever = ask("Do you have a fever?");
    bool cough = ask("Do you have a cough?");
    bool sore_throat = ask("Do you have a sore throat?");
    bool headache = ask("Do you have a headache?");
    bool fatigue = ask("Do you feel fatigue?");
    bool rash = ask("Do you have a skin rash?");

    cout << "\nDiagnosis Result:\n";

    if (fever && cough && fatigue)
    {
        cout << "You might have the flu. It is recommended to rest and stay hydrated.\n";
    }
    else if (fever && rash)
    {
        cout << "You might have dengue or measles. Please visit a hospital immediately.\n";
    }
    else if (sore_throat && cough)
    {
        cout << "You may have a common cold. Drink warm fluids and get rest.\n";
    }
    else if (headache && !fever)
    {
        cout << "It could be a migraine. Avoid bright lights and try to rest.\n";
    }
    else
    {
        cout << "Symptoms are unclear. Please consult a doctor for a proper diagnosis.\n";
    }

    return 0;
}
