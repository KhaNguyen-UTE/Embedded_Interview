#include "Do_uong.h"


ManageOrder::ManageOrder(){
    uint8_t status;
    cout <<"     Quan Li" <<endl
         <<" 1. Them do uong" <<endl
         <<" 2. Sua do uong" <<endl
         <<" 3. Xoa do uong" <<endl
         <<" 4. Danh sach do uong" <<endl
         <<" 5. Quay lai menu chinh" <<endl;
         INPUT_DATA ("Nhap lua chon cua ban: ", status);
}