#include <iostream>
using namespace std;

void count(string sentence)
{
    int vowels = 0;
    int consonants = 0;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u')
            vowels++;
        else if (sentence[i] != ' ')
            consonants++;
    }
    cout << "vowels : " << vowels << endl;
    cout << "consonants : " << consonants;
}

int main()
{
    string sen;
    cout << "Enter a string to count vowels and consonants : ";
    getline(cin, sen);

    for (int i = 0; i < sen.length(); i++)
        sen[i] = tolower(sen[i]);
    count(sen);

    return 0;
}