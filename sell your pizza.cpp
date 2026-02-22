#include <bits/stdc++.h>
using namespace std;

int main() {

    cout << "Chao mung den voi game Sell your pizza.\n";

    // ===== DAY 1 =====
    cout << "\n== DAY 1 ==\n";
    cout << "Ban muon dat ten quan la gi? : ";

    string name;
    getline(cin, name);

    long long money = 10000000000LL;
    int phobien = 0;

    cout << "\nBan dang co 10 ti dong va ban dang tim mat bang.\n";
    cout << "1. Mua mat bang o dai lo (400 trieu)\n";
    cout << "2. Mua mat bang o duong nho (160 trieu)\n";

    int choice1;
    cin >> choice1;

    switch(choice1){
        case 1:
            money -= 400000000;
            phobien += 5;
            break;
        case 2:
            money -= 160000000;
            phobien += 2;
            break;
        default:
            cout << "Lua chon khong hop le!\n";
    }

    cout << "So du hien tai: " << money << "\n";

    // ===== DAY 2 =====
    cout << "\n== DAY 2 ==\n";
    cout << "Chon bien quang cao:\n";
    cout << "1. 15 trieu\n";
    cout << "2. 6 trieu\n";
    cout << "3. 2.5 trieu\n";
    cout << "4. 1 trieu\n";

    int choice2;
    cin >> choice2;

    switch(choice2){
        case 1: money -= 15000000; phobien += 10; break;
        case 2: money -= 6000000; phobien += 7; break;
        case 3: money -= 2500000; phobien += 5; break;
        case 4: money -= 1000000; phobien += 3; break;
        default: cout << "Lua chon khong hop le!\n";
    }

    cout << "So du hien tai: " << money << "\n";

    // ===== DAY 3 =====
    cout << "\n== DAY 3 ==\n";
    cout << "Chon nhan vien:\n";
    cout << "1. Thoi vu (160k/ngay)\n";
    cout << "2. Chinh thuc (170k/ngay)\n";

    int choice3;
    cin >> choice3;

    int luongthang = 0;

    if(choice3 == 1){
        luongthang = 160000 * 30;
    }
    else if(choice3 == 2){
        cout << "Ban muon thue 1 hay 2 NV? ";
        int soNV;
        cin >> soNV;
        luongthang = 170000 * 30 * soNV;
    }
    else{
        cout << "Lua chon khong hop le!\n";
    }

    cout << "Luong thang phai tra: " << luongthang << "\n";

    // Clear buffer trý?c khi getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // ===== CHON PIZZA =====
    cout << "\nBan se chon pizza gi de ban?\n";
    cout << "1. Pizza pho mai (35000)\n";
    cout << "2. Pizza pepperoni (50000)\n";
    cout << "3. Pizza dua (45000)\n";
    cout << "4. Pizza nhieu loai thit (60000)\n";
    cout << "5. Pizza hai san (65000)\n";
    cout << "VD nhap: 1,3,5\n";

    vector<string> tatcapizza = {
        "Pizza pho mai",
        "Pizza pepperoni",
        "Pizza dua",
        "Pizza nhieu loai thit",
        "Pizza hai san"
    };

    vector<string> seban;

    string input;
    getline(cin, input);

    stringstream ss(input);
    string temp;

    while(getline(ss, temp, ',')){
        if(temp.empty()) continue;

        try{
            int index = stoi(temp);

            if(index >= 1 && index <= tatcapizza.size()){
                seban.push_back(tatcapizza[index - 1]);
            }
            else{
                cout << "So khong hop le!\n";
            }
        }
        catch(...){
            cout << "Nhap sai dinh dang!\n";
        }
    }

    // ===== IN MENU =====
    cout << "\n=== MENU cua quan " << name << " ===\n";
    for(const string& mon : seban){
        cout << "- " << mon << "\n";
    }

    return 0;
}

