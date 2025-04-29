#include <bits/stdc++.h>
using namespace std;

string toLower(string str)
{
    for (auto &c : str)
        c = tolower(c);
    return str;
}

string getResponse(string userInput)
{
    userInput = toLower(userInput);

    if (userInput.find("hello") != string::npos || userInput.find("hi") != string::npos)
    {
        return "Hello! How can I help you today?";
    }
    else if (userInput.find("order") != string::npos)
    {
        return "You can check your order status in the 'My Orders' section.";
    }
    else if (userInput.find("refund") != string::npos)
    {
        return "Refunds are processed within 5-7 business days.";
    }
    else if (userInput.find("price") != string::npos)
    {
        return "Can you please specify which product you are asking about?";
    }
    else if (userInput.find("thank") != string::npos)
    {
        return "You're welcome! Have a great day!";
    }
    else
    {
        return "I'm sorry, I didn't understand that. Could you please rephrase?";
    }
}

int main()
{
    cout << "Welcome to Customer Support Chatbot!" << endl;
    cout << "Type 'exit' to end the chat." << endl;

    while (true)
    {
        cout << "You: ";
        string userInput;
        getline(cin, userInput);

        if (toLower(userInput) == "exit")
        {
            cout << "Chatbot: Thank you for contacting us. Goodbye!" << endl;
            break;
        }

        string reply = getResponse(userInput);
        cout << "Chatbot: " << reply << endl;
    }

    return 0;
}
