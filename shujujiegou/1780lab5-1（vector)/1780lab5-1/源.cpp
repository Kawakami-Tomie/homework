#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <random>
using namespace std;
struct Card {
    string suit;   // 花色
    string value;  // 牌值
};

vector<Card> generateDeck() {
    vector<Card> deck;

    string suits[] = { "桃", "心", "梅", "方" };
    string values[] = {  "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K","A", "2" };

    for (const auto& suit : suits) {
        for (const auto& value : values) {
            deck.push_back({ suit, value });
        }
    }

    deck.push_back({ "", "JOKER" });
    deck.push_back({ "", "Joker" });

    // 乱序生成扑克牌列表
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);

    return deck;
}

void displayDeck(const vector<Card>& deck) {
    for (const auto& card : deck) {
        cout << card.suit << card.value << " ";
    }
    cout << endl;
}

void displayPlayerHand(const vector<Card>& player) {
    for (const auto& card : player) {
        cout << card.suit << card.value << " ";
    }
    cout << endl;
}

//自定义比较大小方式
bool compareCards(const Card& card1, const Card& card2) {
    //if (card1.suit == card2.suit)//花色相同看值
    //{
    //    return card1.value < card2.value;
    //}
    //return card1.suit < card2.suit;

    if (card1.value == card2.value)//值相同看花色
    {
        return card1.suit < card2.suit;
    }
    return card1.value < card2.value;
}

void distributeCards(const vector<Card>& deck, vector<Card>& player1, vector<Card>& player2, vector<Card>& player3) {
    int numCards = deck.size();
    for (int i = 0; i < numCards; i++) {
        if (i % 3 == 0) {
            player1.push_back(deck[i]);
        }
        else if (i % 3 == 1) {
            player2.push_back(deck[i]);
        }
        else {
            player3.push_back(deck[i]);
        }
    }
    cout << "排序之前玩家手牌顺序如下：" << endl;
    cout << "玩家1手中的牌：";
    displayPlayerHand(player1);
    cout << "玩家2手中的牌：";
    displayPlayerHand(player2);
    cout << "玩家3手中的牌：";
    displayPlayerHand(player3);
    //对玩家手牌进行排序
    sort(player1.begin(), player1.end(), compareCards);
    sort(player2.begin(), player2.end(), compareCards);
    sort(player3.begin(), player3.end(), compareCards);
    cout << "排序之后玩家手牌顺序如下：" << endl;
    cout << "玩家1手中的牌：";
    displayPlayerHand(player1);
    cout << "玩家2手中的牌：";
    displayPlayerHand(player2);
    cout << "玩家3手中的牌：";
    displayPlayerHand(player3);
}




void playCard(vector<Card>& player, vector<Card>& pile) {
    vector<Card> cardstoPlay;
    int index,count=0;
 flag_again:  cout << "请输入要出的牌的位置（从0开始），可以连续输入,以99结束：";
    while (cin >> index && index != 99)
    {
        if (index < 0 || index >= player.size()) {
            cout << "输入不合法！请重新输入"; goto flag_again;
            return;
        }
        cardstoPlay.push_back(player[index-count]);
        player.erase(player.begin() + index-count); count++;
        cout << "请输入要出的牌的位置（从0开始），可以连续输入,以99结束：";
    }
    for (const auto& card : cardstoPlay) {
      pile.push_back(card);
    }
    cout << "玩家手牌：";
    displayPlayerHand(player);
    cout << "牌堆：";
    displayDeck(pile);
}

int main() {
    vector<Card> deck = generateDeck();

    cout << "当前扑克牌存放顺序：";
    displayDeck(deck);

    vector<Card> player1, player2, player3;
    distributeCards(deck, player1, player2, player3);
  

    vector<Card> pile;

    cout << "#########################游戏开始#######################" << std::endl;
    cout << "开始出牌：" << endl;

    int currentPlayer = 1;
    while (true) {
        cout << "当前轮到玩家" << currentPlayer << "出牌" << std::endl;
        cout << "玩家" << currentPlayer << "手中的牌：";
        if (currentPlayer == 1) {
            displayPlayerHand(player1);
        }
        else if (currentPlayer == 2) {
            displayPlayerHand(player2);
        }
        else {
            displayPlayerHand(player3);
        }

        playCard(currentPlayer == 1 ? player1 : (currentPlayer == 2 ? player2 : player3), pile);

        currentPlayer = (currentPlayer % 3) + 1;

        // 检查是否有玩家已经出完所有的牌
        if (player1.empty()) {
            cout << "玩家1已出完所有的牌！游戏结束。";
            break;
        }
        else if (player2.empty()) {
            cout << "玩家2已出完所有的牌！游戏结束。";
            break;
        }
        else if (player3.empty()) {
            cout << "玩家3已出完所有的牌！游戏结束。";
            break;
        }
    }

    return 0;
}

