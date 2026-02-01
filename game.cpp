 #include <bits/stdc++.h>
using namespace std;
// ===== BIEN =====
bool hasPhoto = false;
bool talkedOldLady = false;
bool gaveManager = false;

bool gotDiary = false;
bool gotCamera = false;
bool tookMirrorPhoto = false;

int mental = 0;
int trust = 0;

// ===== HAM CHUONG 1 =====
void chapter1() {
    cout << "\n== CHUONG 1: BUC ANH ==\n";
    cout << "Ban la Minh, mot hoc sinh/nha bao tre dang song trong mot khu chung cu cu.\n";
    cout << "Trong luc don nha, ban thay mot tam anh.\n";
    cout << "Trong do co 6 nguoi va nguoi bao ve da chet trong tuan truoc.\n";

    cout << "\nBan se:\n";
    cout << "1. Giu buc anh cho rieng minh.\n";
    cout << "2. Dua anh cho ban quan ly chung cu.\n";
    cout << "3. Hoi ba lao tang 3.\n";

    int choice1;
    cin >> choice1;

    switch(choice1) {
        case 1:
            hasPhoto = true;
            mental += 2;
            cout << "Ban phat hien mat sau anh co ghi ngay thang va mot ky hieu la.\n";
            cout << "Ban bat dau bi mat ngu va mo thay nhung nguoi trong anh.\n";
            break;

        case 2:
            gaveManager = true;
            trust += 1;   // ?? s?a truts -> trust
            cout << "Ban quan ly to ra kho chiu va ne tranh.\n";
            cout << "Ho noi se giu giup, nhung buc anh bien mat.\n";
            break;

        case 3:
            talkedOldLady = true;
            gotDiary = true;
            mental += 2;
            cout << "Ba lao nhan ra buc anh ngay lap tuc.\n";
            cout << "Ba noi: Dang le tat ca bon ho da bien mat tu lau.\n";
            cout<<"(Ban da nhan 1 cuon nhat ky trong rat ky la...)";
			cout<<"(Ban da mo cuon nhat ky do ra.)"; 
            cout << "Ban nhan duoc ten mot nguoi trong anh.\n";
            break;

        default:
            cout << "Lua chon khong hop le! Moi chon lai.\n";
            chapter1();
            break;
    }  
} 

// ===== HAM CHUONG 2 =====
void chapter2() {
    cout << "\n== CHUONG 2: NHUNG CAI CHET ==\n";
    cout << "Mot nguoi trong buc anh vua qua doi (tai nan?).\n";

    cout << "\nBan se:\n";
    cout << "1. Dot nhap phong nan nhan tim manh moi\n";
    cout << "2. Goi cong an va ke ve buc anh\n";
    cout << "3. Pho lo, tranh xa moi chuyen\n";

    int choice2;
    cin >> choice2;   // ?? s?a choice -> choice2

    if(choice2 == 1) {
        cout << "Ban le lut vao phong nan nhan...\n";

        if(gotDiary) {
            gotCamera = true;
            mental += 1;
            trust += 1;
            cout << "Nhat ky trung khop voi hien truong!\n";
            cout << "Ban tim thay doan camera bi xoa!\n";
        } 
        else {
            mental += 2;
            cout << "Manh moi roi rac, khong day du...\n";
            cout << "Ban bat dau nghi ngo chinh minh.\n";
        }
    }
    else if(choice2 == 2) {
        cout << "Ban goi cong an...\n";

        if(hasPhoto) {
            trust += 2;
            cout << "Ban dua buc anh lam bang chung.\n";
            cout << "Cong an bat dau chu y vu viec.\n";
        } 
        else {
            trust -= 1;
            cout << "Khong co buc anh, loi ke kem thuyet phuc.\n";
        }
    }
    else if(choice2 == 3) {
        mental += 1;
        trust -= 2;
        cout << "Ban quyet dinh tranh xa moi chuyen...\n";
    }
    else {
        cout << "Lua chon khong hop le! Moi chon lai.\n";
        chapter2();
    }
}

// ===== HAM CHUONG 3 =====
void chapter3() {
    cout << "\n=== CHUONG 3: GUONG ===\n";
    cout<<"Ban thay 1 bong nguoi trong guong ma..."<<endl;
    cout<<"no ko ton tai?"<<endl; 
    cout << "1. Chup anh guong\n";
    cout << "2. Dap guong\n";
    cout << "3. Gia vo khong thay gi\n";
    cout << "Chon: ";

    int choice3;
    cin >> choice3;

    if(choice3 == 1) {
        tookMirrorPhoto = true;
        mental += 2;
        cout << "Ban chup anh. Trong anh co mot bong nguoi la...\n";
    }
    else if(choice3 == 2) {
        mental += 3;
        cout << "Guong vo. Cam giac bat an tang len...\n";
    }
    else if(choice3 == 3) {
        cout << "Ban tu choi doi mat su that.\n";
        trust -= 1;
    }
    else{
    	cout<<"Lua chon ko hop le!"<<endl; 
	} 
}

// ===== KET CUC =====
void ending() {
    cout << "\n=== KET CUC ===\n";

    if(gotDiary && gotCamera && trust >= 2) {
        cout << "ENDING A: Su that duoc phoi bay.\n";
    }
    else if(mental >= 5 && trust <= 0) {
        cout << "ENDING C: Ban bi am anh boi chinh minh.\n";
    }
    else if(tookMirrorPhoto && hasPhoto) {
        cout << "ENDING D: Bi an sieu nhien.\n";
    }
    else if(gaveManager) {
        cout << "ENDING B: Mot nguoi vo toi bi do toi.\n";
    }
    else {
        cout << "ENDING E: Ban roi khoi chung cu, su that bi chon vui.\n";
    }
}

// ===== MAIN =====
int main() {
    cout << "Muon choi tro choi khong?\n";
    cout << "Choi ghi Y; Khong choi ghi N\n";

    string Luachon;
    cin >> Luachon;

    if(Luachon == "Y") {
        cout << "OK! Bat dau game...\n";
        chapter1();
        chapter2();
        chapter3();
        ending();
    }
    else if(Luachon == "N") {
        cout << "Bye!\n";
        return 0;
    }
    else {
        cout << "Lua chon khong hop le!\n";
    }

    return 0;
}
