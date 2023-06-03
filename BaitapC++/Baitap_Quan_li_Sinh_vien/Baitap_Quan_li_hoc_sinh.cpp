/*
 * File Name: Baitap_Quan_li_hoc_sinh.cpp
 * Author: Nguyen Tran Minh Kha
 * Date: 27/05/2023
 * Description: The program has the function of managing students from a function menu
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

typedef enum{
    NAM,
    NU
} TypeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
} TypeHocLuc;

typedef enum{
    TEN,
    TUOI,
    GIOI_TINH,
    DIEM
} TypeInput;

#define INPUT_DATA(text, var)     \
    cout << text;                 \
    cin >> var;                   \

/*
 * Function: Class HocSinh
 * Description: The class represents the properties and methods of the student
 * Input:
 *    None
 * Output:
 *    None
 */
class HocSinh{
    private:
        int ID;
        string NAME;
        int TUOI;
        float DIEM_TOAN;
        float DIEM_LY;
        float DIEM_HOA;
        TypeGioiTinh GIOI_TINH;

    public:
        HocSinh(string name, TypeGioiTinh gioitinh, int tuoi, float diemtoan, float diemly, float diemhoa);
        HocSinh() = default;

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

        int getId();
        float DiemTrungBinh();
        TypeHocLuc HocLuc();
};

/*
 * Function: Constructor HocSinh
 * Description: import parameters to the object of the class HocSinh( name , gioiTinh, tuoi, diemtoan, diemly, diem hoa)
 * Input:
 *    name: string
 *    gioiTinh: TypeGioiTinh
 *    tuoi: int
 *    diemtoan: float
 *    diemly: float
 *    diemhoa: float
 * Output:
 *    None
 */
HocSinh::HocSinh(string name, TypeGioiTinh gioitinh, int tuoi, float diemtoan, float diemly, float diemhoa){
    static int id = 100;
    HocSinh::ID = id;
    HocSinh::NAME = name;
    HocSinh::TUOI = tuoi;
    HocSinh::DIEM_TOAN = diemtoan;
    HocSinh::DIEM_LY = diemly;
    HocSinh::DIEM_HOA = diemhoa;
    HocSinh::GIOI_TINH = gioitinh;
    id++;
}

/*
 * Function: HocSinh::setTen()
 * Description: set name for object
 * Input:
 *    ten: string
 * Output:
 *    none
 */
void HocSinh::setTen(string ten){
    this->NAME = ten;
}

/*
 * Function: HocSinh::getTen()
 * Description: use to get name
 * Input:
 *    none
 * Output:
 *    return name in type of string
 */
string HocSinh::getTen(){
    return HocSinh::NAME;
}

/*
 * Function: HocSinh::setGioiTinh()
 * Description: set sex for object
 * Input:
 *    gioitinh: TypeGioiTinh
 * Output:
 *    none
 */
void HocSinh::setGioiTinh(TypeGioiTinh gioitinh){
    this->GIOI_TINH = gioitinh;
}

/*
 * Function: HocSinh::getGioiTinh()
 * Description: use to get sex
 * Input:
 *    none
 * Output:
 *    return sex in type of TypeGioiTinh
 */
TypeGioiTinh HocSinh::getGioiTinh(){
    return HocSinh::GIOI_TINH;
}

/*
 * Function: HocSinh::setTuoi()
 * Description: set age for object
 * Input:
 *    tuoi: int
 * Output:
 *    none
 */
void HocSinh::setTuoi(int tuoi){
    this->TUOI = tuoi;
}

/*
 * Function: HocSinh::getTuoi()
 * Description: use to get age
 * Input:
 *    none
 * Output:
 *    return age in type of int
 */
int HocSinh::getTuoi(){
    return HocSinh::TUOI;
}

/*
 * Function: HocSinh::DiemTrungBinh()
 * Description: use to get average scores of 3 subjects
 * Input:
 *    none
 * Output:
 *    return average scores in type of float
 */
float HocSinh::DiemTrungBinh(){
    return (HocSinh::DIEM_TOAN + HocSinh::DIEM_LY + HocSinh::DIEM_HOA) / 3;
}

/*
 * Function: HocSinh::setDiemToan()
 * Description: set math scores for object
 * Input:
 *    diemtoan: float
 * Output:
 *    none
 */
void HocSinh::setDiemToan(float diemtoan){
    this->DIEM_TOAN = diemtoan;
}

/*
 * Function: HocSinh::getDiemToan()
 * Description: use to get math scores
 * Input:
 *    none
 * Output:
 *    return math scores in type of float
 */
float HocSinh::getDiemToan(){
    return this->DIEM_TOAN;
}

/*
 * Function: HocSinh::setDiemLy()
 * Description: set physics scores for object
 * Input:
 *    diemly: float
 * Output:
 *    none
 */
void HocSinh::setDiemLy(float diemly){
    this->DIEM_LY = diemly;
}

/*
 * Function: HocSinh::getDiemLy()
 * Description: use to get physic scores
 * Input:
 *    none
 * Output:
 *    return physic scores in type of float
 */
float HocSinh::getDiemLy(){
    return this->DIEM_LY;
}

/*
 * Function: HocSinh::setDiemHoa()
 * Description: set chemistry scores for object
 * Input:
 *    diemhoa: float
 * Output:
 *    none
 */
void HocSinh::setDiemHoa(float diemhoa){
    this->DIEM_HOA = diemhoa;
}

/*
 * Function: HocSinh::getDiemHoa()
 * Description: use to get chemistry scores
 * Input:
 *    none
 * Output:
 *    return chemistry scores in type of float
 */
float HocSinh::getDiemHoa(){
    return this->DIEM_HOA;
}

/*
 * Function: HocSinh::HocLuc()
 * Description: use to get academic ability of students
 * Input:
 *    none
 * Output:
 *    return academic ability in type of TypeHocLuc
 */
TypeHocLuc HocSinh::HocLuc()
{
    if (HocSinh::DiemTrungBinh() >= 8)
        return GIOI;
    else if (HocSinh::DiemTrungBinh() >= 6.5)
        return KHA;
    else if (HocSinh::DiemTrungBinh() >= 5)
        return TRUNG_BINH;
    else
        return YEU;
}

/*
 * Function: HocSinh::getId()
 * Description: use to get Id of students
 * Input:
 *    none
 * Output:
 *    return Id in type of int
 */
int HocSinh::getId(){
    return HocSinh::ID;
}

/*
 * Function: Class Menu
 * Description: The class represents the properties and methods of the menu
 * Input:
 *    None
 * Output:
 *    None
 */
class Menu{
    private:
        vector<HocSinh> Database;
        void hienthiMotHocSinh(HocSinh sv);
        void checkInput(void *value, TypeInput doiTuong);
        void swapData(int index_1, int index_2, TypeInput doiTuong);

    public:
        Menu();
        void addHocSinh();
        void updateInfo();
        void deleteHocSinh();
        void findHocSinh();
        void sapxepGPA();
        void sapxepTen();
        void hienthiAllHocSinh();
};

/*
 * Function: RUN_SELECTION()
 * Description: The macro used to print the user's selection screen and get the next data
 * Input:
 *    text: text is printed on the screen
 *    var: variable used to receive user's data
 *    run: one of the included functions
 * Output:
 *    None
 */
#define RUN_SELECTION(text, var, run)                        \
run;                                                         \
cout << "Hay nhap lua chon tiep theo" <<endl;                \
cout << "    - Nhan 1 de " <<text <<endl;                    \
cout << "    - Nhan phim bat ki de quay lai menu" <<endl;    \
cout << "Lua chon cua ban: ";                                \
cin  >> var;                                                 \
 
 /*
 * Function: Menu::checkInput()
 * Description: The method has the function of entering student information including name, age, gender and grades then check the input condition
 * Input:
 *    *value: void
 *    doiTuong: TypeInput
 * Output:
 *    get input data
 */
void Menu::checkInput(void *value, TypeInput doiTuong){
    bool status = true;        //If input data is wrong, so status = true, then loop the function again for re-enter
    while (status == true){
        switch (doiTuong)
        {
        case TEN:{
            bool status_ten = true;
            cout << "   Ten: ";
            getline(cin, *(string *)value);
            string name = *(string *)value;
            for (int i = 0; i < name.length(); i++){
                // If the name contains numbers or special characters, required to re-enter
                if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' ')){}
                else{
                    cout << "--Vui long nhap dung ten--" << endl;
                    status_ten = false;
                    break;
                }
            }
            if (status_ten == true)    status = false;
        }break;

        case TUOI:{
            INPUT_DATA("   Tuoi: ", *(int *)value);
            // If the age is smaller than 0 or the input data is not in type int, required to re-enter
            if (*(int *)value < 0 || cin.fail()){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "--Vui long nhap dung tuoi--" << endl;
                break;
            }
            status = false;
        }break;

        case DIEM:{
            INPUT_DATA(" = ", *(float *)value);
            // If the age is smaller than 0 or bigger than 10 or the input data is not in type float, required to re-enter
            if (*(float *)value < 0 || *(float *)value > 10 || cin.fail() == true){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "--Vui long nhap dung diem--" << endl
                     << "   Diem";
                break;
            }
            status = false;
        }break;

        case GIOI_TINH:{
            string s_GioiTinh;
            INPUT_DATA("   Gioi tinh: ", s_GioiTinh);
            // If the age is different with "nam" or "nu", required to re-enter
            if (s_GioiTinh != "nam" && s_GioiTinh != "nu"){
                cout << "--Vui long nhap dung gioi tinh--" << endl;
                break;
            }
            if (s_GioiTinh == "nam")    *(TypeGioiTinh *)value = NAM;
            else if (s_GioiTinh == "nu")    *(TypeGioiTinh *)value = NU;
            status = false;
        }break;
        }
    }
}

/*
 * Function: Constructor Menu
 * Description: import parameters to the object of the class Menu with 8 functions
 * Input:
 *    none
 * Output:
 *    none
 */
Menu::Menu()
{   
    int menu_selection = 0;
    while(true)
    {
        cout << "1. Them sinh vien" << endl;
        cout << "2. Cap nhat thong tin" << endl;
        cout << "3. Xoa thong tin sinh vien" << endl;
        cout << "4. Tim kiem sinh vien" << endl;
        cout << "5. Sap xep sinh vien theo diem GPA" << endl;
        cout << "6. Sap xep sinh vien theo ten" << endl;
        cout << "7. Hien thi hoc sinh" << endl;
        cout << "8. Ket thuc chuong trinh" << endl << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> menu_selection;

        /* Check condition of user option*/
        if (menu_selection == 8)    break;
        if (menu_selection <= 0 || menu_selection > 7 || cin.fail() == true){        // If input type is wrong, then require enter data again
            cin.clear();
            cin.ignore(100, '\n');
            cout <<endl << "-- Vui long nhap lua chon co trong Menu --" << endl;
        }

        char status;   // Condition for loop function
        do{
            switch (menu_selection)
            {
            case 1: RUN_SELECTION("tiep tuc them sinh vien", status,Menu::addHocSinh());
                    break;
            case 2: RUN_SELECTION("tiep tuc cap nhat sinh vien", status, Menu::updateInfo());
                    break;
            case 3: RUN_SELECTION("tiep tuc xoa sinh vien", status, Menu::deleteHocSinh());
                    break;
            case 4: RUN_SELECTION("tiep tuc tim sinh vien", status, Menu::findHocSinh());
                    break;
            case 5: Menu::sapxepGPA();
                    Menu::hienthiAllHocSinh();
                    break;
            case 6: Menu::sapxepTen();
                    Menu::hienthiAllHocSinh();
                    break;
            case 7: Menu::hienthiAllHocSinh();
                    break;
            }
        }
        while(status == '1');
    }
}

/*
 * Function: Menu::addHocSinh()
 * Description: The method has the function of entering student information including name, age, gender and grades
 * Input:
 *    none
 * Output:
 *    add info into Database
 */
void Menu::addHocSinh()
{
    string ten;
    string s_GioiTinh;

    TypeGioiTinh gioiTinh;
    TypeHocLuc hocLuc;

    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;

    cout << "Nhap thong tin sinh vien" << endl;
    cin.ignore(100, '\n');    // Bỏ ký tự xuống dòng khỏi bộ nhớ của thư viện iostream, tránh bị bỏ qua hàm nhập dữ liệu
    checkInput(&ten, TEN);
    checkInput(&tuoi, TUOI);
    checkInput(&gioiTinh, GIOI_TINH);

    cout << "   Diem Toan";
    checkInput(&diemToan, DIEM);
    cout << "   Diem Ly";
    checkInput(&diemLy, DIEM);
    cout << "   Diem Hoa";
    checkInput(&diemHoa, DIEM);

    HocSinh sv(ten, gioiTinh, tuoi, diemToan, diemLy, diemHoa);
    Database.push_back(sv);
    cout <<"Ban da them sinh vien thanh cong" <<endl;
}

/*
 * Function: Menu::updateInfo()
 * Description: The method has the ability to update student information through ID
 * Input:
 *    none
 * Output:
 *    add up date info into Database
 */
void Menu::updateInfo()
{
    int id_update;
    int update_selection;
    int vector_index = 0;
    bool status = false;
    INPUT_DATA("Nhap ID cua sinh vien: ", id_update);
    for (HocSinh sv : Database)
    {
        if (sv.getId() == id_update)
        {
            string ten;
            string s_GioiTinh;
            int tuoi;
            float diemToan;
            float diemLy;
            float diemHoa;
            TypeGioiTinh gioiTinh;

            cout << "Ban muon cap nhat gi" << endl
                 << "    1. Ten" << endl
                 << "    2. Tuoi" << endl
                 << "    3. Gioi Tinh" << endl
                 << "    4. Diem Toan" << endl
                 << "    5. Diem Ly" << endl
                 << "    6. Diem Hoa" << endl
                 << "Nhap lua chon: ";
            cin >> update_selection;
            switch (update_selection)
            {
            case 1:
                cin.ignore(100, '\n');
                checkInput(&ten, TEN);
                sv.setTen(ten);
                break;
            case 2:
                checkInput(&tuoi, TUOI);
                sv.setTuoi(tuoi);
                break;
            case 3:
                checkInput(&s_GioiTinh, GIOI_TINH);
                sv.setGioiTinh(gioiTinh);
                break;
            case 4:
                cout << "   Diem Toan";
                checkInput(&diemToan, DIEM);
                sv.setDiemToan(diemToan);
                break;
            case 5:
                cout << "   Diem Ly";
                checkInput(&diemLy, DIEM);
                sv.setDiemLy(diemLy);
                break;
            case 6:
                cout << "   Diem Hoa";
                checkInput(&diemHoa, DIEM);
                sv.setDiemHoa(diemHoa);
                break;
            }
            sv.DiemTrungBinh();
            sv.HocLuc();
            Database[vector_index] = sv;
            cout << "--Ban da cap nhat thong tin sinh vien thanh cong--" << endl;
            status = true;
            break;
        }
        vector_index++;
    }
    if (status == false)
    cout << "--Khong co thong tin sinh vien trong Data--" << endl;
}

/*
 * Function: Menu::hienthiMotHocSinh()
 * Description: The method has the function of displaying one student information on the screen in the form of a table
 * Input:
 *    sv: HocSinh
 * Output:
 *    show the data
 */
void Menu::hienthiMotHocSinh(HocSinh sv)
{
    string s_GioiTinh;
    string s_HocLuc;
    string name = sv.getTen();
    if (sv.getGioiTinh() == NAM)
        s_GioiTinh = "Nam";
    else
        s_GioiTinh = "Nu";

    if (sv.HocLuc() == GIOI)
        s_HocLuc = "Gioi";
    else if (sv.HocLuc() == KHA)
        s_HocLuc = "Kha";
    else if (sv.HocLuc() == TRUNG_BINH)
        s_HocLuc = "Tr.Binh";
    else
        s_HocLuc = "Yeu";
    printf("|  %-6d|  %-23s|  %-6d|  %-9s| %-7.2f| %-7.2f|  %-7.2f|  %-6.2f|  %-9s|\n", sv.getId(),
           sv.getTen().c_str(), sv.getTuoi(), s_GioiTinh.c_str(), sv.getDiemToan(), sv.getDiemLy(),
           sv.getDiemHoa(), sv.DiemTrungBinh(), s_HocLuc.c_str());
}

/*
 * Function: Menu::hienthiAllHocSinh()
 * Description: The method has the function of displaying student information on the screen in the form of a table
 * Input:
 *    none
 * Output:
 *    show the data
 */
void Menu::hienthiAllHocSinh()
{
    cout << "+--------+-------------------------+--------+-----------+--------+--------+---------+--------+-----------+" << endl;
    cout << "|   ID   |           Ten           |  Tuoi  | Gioi Tinh | D.Toan |  D.Ly  |  D.Hoa  |  D.TB  |  Hoc Luc  |" << endl;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;
    for (HocSinh sv : Database)
    {
        hienthiMotHocSinh(sv);
    }

    cout << "+--------------------------------------------------------------------------------------------------------+" << endl;
}

/*
 * Function: Menu::deleteHocSinh()
 * Description: The method has the function to remove 1 student from the data
 * Input:
 *    none
 * Output:
 *    remove from the data
 */
void Menu::deleteHocSinh()
{
    int id_delete;
    bool status = false;
    INPUT_DATA("Nhap ID cua sinh vien: ", id_delete);
    vector<HocSinh>::iterator vector_index = Database.begin();
    for (HocSinh sv : Database){
        if (sv.getId() == id_delete){
            Database.erase(vector_index);
            cout << "--Da xoa thanh cong sinh vien--" << endl;
            status = true;
        }
        vector_index++;
    }
    if (status == false)
        cout << "--Khong co sinh vien nao duoc xoa--" << endl;
}

/*
 * Function: Menu::findHocSinh()
 * Description: The method has the function of searching students in the data by ID
 * Input:
 *    none
 * Output:
 *    display information of the student being searched
 */
void Menu::findHocSinh()
{
    int id_find;
    bool status = false;
    INPUT_DATA("Nhap ID cua sinh vien: ", id_find);
    for (HocSinh sv : Database){
        if (sv.getId() == id_find){
            cout << "+--------+-------------------------+--------+-----------+--------+--------+---------+--------+-----------+" << endl;
            cout << "|   ID   |           Ten           |  Tuoi  | Gioi Tinh | D.Toan |  D.Ly  |  D.Hoa  |  D.TB  |  Hoc Luc  |" << endl;
            cout << "----------------------------------------------------------------------------------------------------------" << endl;
            hienthiMotHocSinh(sv);
            cout << "+--------------------------------------------------------------------------------------------------------+" << endl;
            status = true;
            break;
        }
    }
    if (status == false)
        cout << "--Khong co sinh vien trong Data--" << endl;
}

/*
 * Function: Menu::swapData()
 * Description: The method has the function of swaping student's data
 * Input:
 *    index_1: int, student's position in Database
 *    index_2: int, student's position in Database
 *    doiTuong: TypeInput
 * Output:
 *    swap information of the student in Database base on index of data
 */
void Menu::swapData(int index_1, int index_2, TypeInput doiTuong)
{
    HocSinh sv;
    bool status = false;
    switch (doiTuong){
    case DIEM:
        if (Database[index_1].DiemTrungBinh() > Database[index_2].DiemTrungBinh())
            status = true;
        break;

    case TEN:
        if (Database[index_1].getTen() > Database[index_2].getTen())
            status = true;
        break;
    }
    if (status == true){
        sv = Database[index_1];
        Database[index_1] = Database[index_2];
        Database[index_2] = sv;
    }
}

/*
 * Function: Menu::sapxepGPA()
 * Description: The method has the function of sorting students in ascending order by GPA
 * Input:
 *    none
 * Output:
 *    show the result
 */
void Menu::sapxepGPA(){
    for (int i = 0; i < Database.size(); i++){
        for (int j = i + 1; j < Database.size(); j++){
            swapData(i, j, DIEM);
        }
    }
}

/*
 * Function: Menu::sapxepTen()
 * Description: The method has the function of sorting students in ascending order by Name
 * Input:
 *    none
 * Output:
 *    show the result
 */
void Menu::sapxepTen(){
    for (int i = 0; i < Database.size(); i++){
        for (int j = i + 1; j < Database.size(); j++){
            swapData(i, j, TEN);
        }
    }
}

int main()
{
    Menu();
}