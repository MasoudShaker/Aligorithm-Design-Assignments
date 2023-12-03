#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define Pair pair<int, int>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int max_n = 100000;

int main()
{

    fastio

        int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int first_num;
        cin >> first_num;

        int second_num;
        cin >> second_num;

        char l_or_r;
        cin >> l_or_r;
    }

    // baraye halle in soal bayad yek bar dfs e chap va yek bar dfs e rast anjam bedim
    // ya'ni az rishe shoroo konim
    // hey berim be farzande chap ta beresim be ra'si ke farzande chap nadare
    // ba'd bargardim bala berim farzande rastesh va dobare berim chap ta jayi ke beshe
    // baraye rast ham moshabehe hamin karo anjam bedim
    // baraye inke befahmim che ra's hayi ro bayad khoroji bedim,
    // baraye har rastayi ke kastim ye flagi mizarim
    // va tooye peymayeshemoon baraye har ra'si ke mibinim age flagesh false bood,true mikonim va be majmoo'e javab ezafe mkonim
    // injoori baraye ra's haye ham rasta, olaviat ba ra'si hast ke dar sathe bala tari gharar dare
}