#include <cstdio>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class deckOfCards
{
public:
    vector<string> decks(int n);
    string getcard(vector<string> &d);
};

string deckOfCards::getcard(vector<string> &d)
{
    auto it = d.begin();
    int no_of_card = stoi(*it);
    d.erase(d.begin());
    srand((unsigned)time(nullptr)); //seed the random
    rand();
    int card_num = rand() % no_of_card;
    string myCard = d[card_num];
    d.erase(d.begin() + card_num);
    no_of_card -= 1;
    string s = to_string(no_of_card);
    d.insert(d.begin(), s);

    return myCard;
}

vector<string> deckOfCards::decks(int n)
{
    char faceValue[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    char cardType[4] = {'s', 'h', 'd', 'c'};
    string s;
    vector<string> myDeck;

    string no_of_cards = to_string(n * 52);
    myDeck.push_back(no_of_cards); //store the number of cards we have

    while (n > 0)
    {
        for (int i = 0; i < 13; i++)
        {

            for (int j = 0; j < 4; j++)
            {
                char fValue = faceValue[i];
                s = fValue;
                char cType = cardType[j];
                s += cType;
                myDeck.push_back(s);
            }
        }
        n -= 1;
    }
    return myDeck;
}

int main()
{
    deckOfCards D1;
    static vector<string> getDeck = D1.decks(2);
    string needCard = D1.getcard(getDeck);
    cout << needCard << endl;
    for (auto it = getDeck.begin(); it < getDeck.end(); ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}
