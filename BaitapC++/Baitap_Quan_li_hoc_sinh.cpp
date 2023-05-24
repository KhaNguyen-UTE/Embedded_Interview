#include <iostream>
#include <stdio.h>
#include <string>
#include <stdint.h>
#include <vector>

using namespace std; 

typedef enum{
    NAM,
    NU
}TypeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}TypeHocLuc;

class HocSinh{
    private:
        uint8_t ID;
        string NAME;
        int TUOI;
        float DIEM_TOAN;
        float DIEM_LY;
        float DIEM_HOA;
        TypeGioiTinh GIOI_TINH;
    public:
        HocSinh(string name, TypeGioiTinh gioitinh, int tuoi, float diemtoan, float diemly, float diemhoa);
        
        void setTen(string ten);
        string getTen();
        void setGioiTinh(TypeGioiTinh gioitinh);
        TypeGioiTinh getGioiTinh();
        void setTuoi(int tuoi);
        int getTuoi();

        void setDiemToan(float diemtoan);
        float getDiemToan();
        void setDiemLy(float diemly);
        float getDiemLy();
        void setDiemHoa(float diemhoa);
        float getDiemHoa();

        uint8_t getId();
        float DiemTrungBinh();
        TypeHocLuc HocLuc();
};

HocSinh::HocSinh(string name, TypeGioiTinh gioitinh, int tuoi, float diemtoan, float diemly, float diemhoa){
    static uint8_t id = 100;
    HocSinh::ID = id;
    HocSinh::NAME = name;
    HocSinh::TUOI = tuoi;
    HocSinh::DIEM_TOAN = diemtoan;
    HocSinh::DIEM_LY = diemly;
    HocSinh::DIEM_HOA = diemhoa;
    HocSinh::GIOI_TINH = gioitinh;
    id++;
}

void HocSinh::setTen(string ten){
    this->NAME = ten;
}

string HocSinh::getTen(){
    return HocSinh::NAME;
}

void HocSinh::setGioiTinh(TypeGioiTinh gioitinh){
    this->GIOI_TINH = gioitinh;
}

TypeGioiTinh HocSinh::getGioiTinh(){
    return HocSinh::GIOI_TINH;
}

void HocSinh::setTuoi(int tuoi){
    this->TUOI = tuoi;
}

int HocSinh::getTuoi(){
    return HocSinh::TUOI;
}

float HocSinh::DiemTrungBinh(){
    return (HocSinh::DIEM_TOAN + HocSinh::DIEM_LY + HocSinh::DIEM_HOA) / 3 ;
}

void HocSinh::setDiemToan(float diemtoan){
    this->DIEM_TOAN = diemtoan;
}

float HocSinh::getDiemToan(){
    return this->DIEM_TOAN;
}

void HocSinh::setDiemLy(float diemly){
    this->DIEM_LY = diemly;
}

float HocSinh::getDiemLy(){
    return this->DIEM_LY;
}

void HocSinh::setDiemHoa(float diemhoa){
    this->DIEM_HOA = diemhoa;
}

float HocSinh::getDiemHoa(){
    return this->DIEM_HOA;
}

TypeHocLuc HocSinh::HocLuc(){
    if (HocSinh::DiemTrungBinh() >=8) return GIOI;
    else if (HocSinh::DiemTrungBinh() >= 6.5) return KHA;
    else if (HocSinh::DiemTrungBinh() >= 5) return TRUNG_BINH;
    else return YEU;
}

uint8_t HocSinh::getId(){
    return HocSinh::ID;
}
class Menu{
    private:
        vector <HocSinh> Database;
    public:
        Menu();
        void addHocSinh();
        void updateInfo();
        void deleteHocSinh();
        void findHocSinh();
        void sapxepGPA();
        void sapxepTen();
        void hienthiHocSinh();
};

Menu::Menu(){
    int status_menu = 0;
    do
    {   
        begin:{
            cout << "1. Them sinh vien" << endl;
            cout << "2. Cap nhat thong tin" << endl;
            cout << "3. Xoa thong tin sinh vien" << endl;
            cout << "4. Tim kiem sinh vien" << endl;
            cout << "5. Sap xep sinh vien theo diem GPA"<< endl;
            cout << "6. Sap xep sinh vien theo ten"<< endl;
            cout << "7. Hien thi hoc sinh" <<endl;
            cout << "8. Ket thuc chuong trinh" << endl <<endl;
            cout << "Nhap lua chon cua ban: ";
            cin >> status_menu; 
        }
        if (status_menu == 8) break;
        if (status_menu <=0 || status_menu > 7){
            status_menu = 0;
            cout << "-- Vui long nhap lua chon co trong Menu --" <<endl;
            goto begin;
        }
    
    switch (status_menu){
            case 1: {
                        char status;
                        do{
                            Menu::addHocSinh();
                            cout <<endl <<"Ban da them sinh vien thanh cong" <<endl ;;
                            cout <<"Hay nhap lua chon tiep theo" <<endl;
                            cout <<"    - Nhan 1 de tiep tuc them sinh vien" <<endl ;
                            cout <<"    - Phim bat ki de quay lai menu" <<endl <<"Lua chon cua ban: ";
                            cin >> status;
                        }
                        while (status == '1');
                    }break;
            case 2: {
                        char status;
                        do{
                            Menu::updateInfo();
                            cout <<"Hay nhap lua chon tiep theo" <<endl;
                            cout <<"    - Nhan 1 de tiep tuc cap nhat thong tin sinh vien" <<endl ;
                            cout <<"    - Phim bat ki de quay lai menu" <<endl <<"Lua chon cua ban: ";
                            cin >> status;
                        }
                        while (status == '1');
                    }break;
            case 3: {
                        char status;
                        do{
                            Menu::deleteHocSinh();
                            cout <<"Hay nhap lua chon tiep theo" <<endl;
                            cout <<"    - Nhan 1 de tiep tuc xoa thong tin sinh vien" <<endl ;
                            cout <<"    - Phim bat ki de quay lai menu" <<endl <<"Lua chon cua ban: ";
                            cin >> status;
                        }
                        while (status == '1');
                    }break;
            case 4:{
                        char status;
                        do{
                            Menu::findHocSinh();
                            cout <<"Hay nhap lua chon tiep theo" <<endl;
                            cout <<"    - Nhan 1 de tiep tuc tim thong tin sinh vien" <<endl ;
                            cout <<"    - Phim bat ki de quay lai menu" <<endl <<"Lua chon cua ban: ";
                            cin >> status;
                        }
                        while (status == '1');
                    }break;
            case 5: {
                        char status;
                        Menu::sapxepGPA(); 
                        cout<<"--Da sap xep xong--" <<endl <<"Ban co muon in thong tin ra khong?" <<endl <<"    1. Co" <<endl <<"    Phim bat ki: Khong" <<endl <<"Nhap lua chon: ";
                        cin >> status;
                        if (status == '1') Menu::hienthiHocSinh();
                    }break;
            case 6: {
                        char status;
                        Menu::sapxepTen();
                        cout<<"--Da sap xep xong--" <<endl <<"Ban co muon in thong tin ra khong?" <<endl <<"    1. Co" <<endl <<"    Phim bat ki: Khong" <<endl <<"Nhap lua chon: ";
                        cin >> status;
                        if (status == '1') Menu::hienthiHocSinh();
                    }break;
            case 7: Menu::hienthiHocSinh(); break;
    }
    }
    while (status_menu != 8 );
    
}

void Menu::addHocSinh(){
    string ten;
    string s_GioiTinh;
    TypeGioiTinh gioiTinh;
    TypeHocLuc hocLuc;
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;
    cout << "Nhap thong tin sinh vien" <<endl;
    cout << "   Ten: ";    cin.ignore(100, '\n');    getline(cin,ten);
    cout << "   Tuoi: ";    cin >> tuoi;    cin.ignore(100, '\n');
    cout << "   Gioi tinh: "; cin >> s_GioiTinh; cin.ignore(100, '\n');
    
    while (s_GioiTinh != "nam" && s_GioiTinh != "nu"){
        cout << "--Vui long nhap dung gioi tinh--" <<endl << "  Gioi tinh: ";
        cin >> s_GioiTinh; cin.ignore(100, '\n');
    }
    
    if (s_GioiTinh == "nam") gioiTinh = NAM;
    else if(s_GioiTinh == "nu") gioiTinh = NU;

    cout << "   Diem Toan: "; cin >> diemToan; 
    while (diemToan < 0 || diemToan > 10)
    {
        cout <<"--Vui long nhap dung diem--"<<endl <<"  Diem Toan: "; 
        cin >> diemToan;
    }

    cout << "   Diem Ly: "; cin >> diemLy;
    while (diemLy < 0 || diemLy > 10){
        cout <<"--Vui long nhap dung diem--"<<endl <<"  Diem Ly: "; 
        cin >> diemLy;
    }
    
    cout << "   Diem Hoa:"; cin >> diemHoa;
    while (diemHoa < 0 || diemHoa > 10){
        cout <<"--Vui long nhap dung diem--"<<endl <<"  Diem Hoa: "; 
        cin >> diemHoa;
    }

    HocSinh sv(ten, gioiTinh, tuoi, diemToan, diemLy, diemHoa);
    Database.push_back(sv);
    

}

void Menu::updateInfo(){
    uint8_t id_update;
    cout << "Nhap Id cua sinh vien muon update:";
    scanf ("%d", &id_update);
    bool status = false;
    uint8_t vector_index = 0;
    for(HocSinh sv : Database)
    {
        if (sv.getId() == id_update){
            string ten;
            string s_GioiTinh;
            int tuoi;
            float diemToan;
            float diemLy;
            float diemHoa;
            TypeGioiTinh gioiTinh;

            cout << "Nhap thong tin sinh vien can cap nhat" <<endl;
            cout << "    Ten: ";    cin.ignore(100, '\n');    getline(cin,ten);
            cout << "    Tuoi: ";     cin >> tuoi; cin.ignore(100, '\n');

            cout << "    Gioi tinh: "; cin >> s_GioiTinh;
            while (s_GioiTinh != "nam" && s_GioiTinh != "nu"){
                cout << "--Vui long nhap dung gioi tinh--" <<endl << "    Gioi tinh: ";
                cin >> s_GioiTinh;
            }
    
            if (s_GioiTinh == "nam") gioiTinh = NAM;
            else if(s_GioiTinh == "nu") gioiTinh = NU;

            cout << "    Diem Toan: "; cin >> diemToan;
            while (diemToan < 0 || diemToan > 10){
                cout <<"--Vui long nhap dung diem--"<<endl <<"    Diem Toan: "; 
                cin >> diemToan;
            }

            cout << "    Diem Ly: "; cin >> diemLy;
            while (diemLy < 0 || diemLy > 10){
                cout <<"--Vui long nhap dung diem--"<<endl <<"    Diem Ly: "; 
                cin >> diemLy;
            }
    
            cout << "    Diem Hoa:"; cin >> diemHoa;
            while (diemHoa < 0 || diemHoa > 10){
                cout <<"--Vui long nhap dung diem--"<<endl <<"    Diem Hoa: "; 
                cin >> diemHoa;
            }
            sv.setTen(ten);
            sv.setDiemHoa(diemHoa);
            sv.setDiemToan(diemToan);
            sv.setDiemLy(diemLy);
            sv.setGioiTinh(gioiTinh);
            sv.setTuoi(tuoi);
            sv.DiemTrungBinh();
            sv.HocLuc();
            Database[vector_index] = sv;
            cout <<"--Ban da cap nhat thong tin sinh vien thanh cong--" <<endl;
            status = true;
        }
        vector_index ++;
    }
    if(status == false) cout <<"--Khong co thong tin sinh vien trong Data--" <<endl;
    cin.ignore(100,'\n');
}

void Menu::hienthiHocSinh(){
    cout << "+--------+-------------------------+--------+-----------+--------+--------+---------+--------+-----------+" <<endl;
    cout << "|   ID   |           Ten           |  Tuoi  | Gioi Tinh | D.Toan |  D.Ly  |  D.Hoa  |  D.TB  |  Hoc Luc  |" <<endl;
    cout << "----------------------------------------------------------------------------------------------------------" <<endl;
    for (HocSinh sv : Database){
        string s_GioiTinh;
        string s_HocLuc;
        string name = sv.getTen();
        if(sv.getGioiTinh() == NAM) s_GioiTinh = "Nam";
        else s_GioiTinh = "Nu";

        if(sv.HocLuc() == GIOI) s_HocLuc = "Gioi";
        else if(sv.HocLuc() == KHA) s_HocLuc ="Kha";
        else if(sv.HocLuc() == TRUNG_BINH) s_HocLuc = "Tr.Binh";
        else s_HocLuc = "Yeu"; 
        printf("|  %-6d|  %-23s|  %-6d|  %-9s| %-7.2f| %-7.2f|  %-7.2f|  %-6.2f|  %-9s|\n",sv.getId(), sv.getTen().c_str(), sv.getTuoi(), s_GioiTinh.c_str()
        , sv.getDiemToan(), sv.getDiemLy(), sv.getDiemHoa(), sv.DiemTrungBinh(), s_HocLuc.c_str());
        
    }
    cout << "+--------------------------------------------------------------------------------------------------------+" <<endl;
}

void Menu::deleteHocSinh(){
    uint8_t id_delete;
    bool status = false;
    cout << "Nhap Id cua sinh vien muon delete:";
    scanf ("%d", &id_delete);
    vector <HocSinh>::iterator vector_index= Database.begin();
    for(HocSinh sv : Database)
    {
    
        if (sv.getId() == id_delete){
            Database.erase(vector_index);
            cout <<"--Da xoa thanh cong sinh vien--" <<endl ;
            status = true;
        } 
        vector_index++;
    }
    if ( status == false) cout <<"--Khong co sinh vien nao duoc xoa--" <<endl;

}

void Menu::findHocSinh(){
    uint8_t id_find;
    bool status = false;
    cout << "Nhap Id cua sinh vien muon tim:";
    scanf ("%d", &id_find);
    for(HocSinh sv : Database)
    {
        if (sv.getId() == id_find){
            cout << "+--------+-------------------------+--------+-----------+--------+--------+---------+--------+-----------+" <<endl;
            cout << "|   ID   |           Ten           |  Tuoi  | Gioi Tinh | D.Toan |  D.Ly  |  D.Hoa  |  D.TB  |  Hoc Luc  |" <<endl;
            cout << "----------------------------------------------------------------------------------------------------------" <<endl;
            string s_GioiTinh;
            string s_HocLuc;
            string name = sv.getTen();
            if(sv.getGioiTinh() == NAM) s_GioiTinh = "Nam";
            else s_GioiTinh = "Nu";

            if(sv.HocLuc() == GIOI) s_HocLuc = "Gioi";
            else if(sv.HocLuc() == KHA) s_HocLuc ="Kha";
            else if(sv.HocLuc() == TRUNG_BINH) s_HocLuc = "Tr.Binh";
            else s_HocLuc = "Yeu"; 
            printf("|  %-6d|  %-23s|  %-6d|  %-9s| %-7.2f| %-7.2f|  %-7.2f|  %-6.2f|  %-9s|\n",sv.getId(), sv.getTen().c_str(), sv.getTuoi(), s_GioiTinh.c_str()
            , sv.getDiemToan(), sv.getDiemLy(), sv.getDiemHoa(), sv.DiemTrungBinh(), s_HocLuc.c_str());
            cout << "+--------------------------------------------------------------------------------------------------------+" <<endl;
            status = true;
            break;
        } 
    }
    if ( status == false) cout <<"--Khong co sinh vien trong Data--" <<endl;
}

void Menu::sapxepGPA(){
    uint8_t length = Database.size();
    for(int i = 0; i < length; i++){
        for (int j = i+1 ; j < length; j++){
            if (Database[i].DiemTrungBinh() > Database[j].DiemTrungBinh()){
                    Database.push_back(Database[i]);
                    Database[i] = Database[j];
                    Database[j] = Database[length];
                    Database.pop_back();
                    
            }
        }
    }
}

void Menu::sapxepTen(){
    uint8_t length = Database.size();
    for(int i = 0; i < length; i++){
        for (int j = i+1 ; j < length; j++){
            if (Database[i].getTen() > Database[j].getTen()){
                    Database.push_back(Database[i]);
                    Database[i] = Database[j];
                    Database[j] = Database[length];
                    Database.pop_back();
            }
        }
    }
}

int main(){
    Menu *menu1;
    Menu();
}