#include <Hotel.hpp>



bool Check::check_limit( int text, int upper_limit, int lower_limit){
    if (text >= lower_limit && text <= upper_limit) return false;
    else return true;
}

void Check::check_input(void *text, TypeInput type){
    bool status = true;
    while (status == true){
        switch (type)
        {
        case NAME:{
            bool status_name = true;
            INPUT_DATA_HAVE_SPACE("Enter Name: ", *(string*)text);
            string name = *(string*)text;
            for (int i = 0; i < (int)name.length(); i++){                                                               
                if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' ')){}                                                                                                                                                                                      
                else{                                                                                                     
                    cout << "--Please enter the right name--" << endl;
                    status_name = false;
                    break;
                }
            }
            if (status_name == true)    status = false;
        }break; 
        
        case ADDRESS:{
            bool status_address = true;
            INPUT_DATA_HAVE_SPACE("Enter address: ", *(string*)text);
            string address = *(string*)text;
            for (int i = 0; i < (int)address.length(); i++){                                                               
                if (address[i] == ' '){ status_address = true;    break;}                                                                                                                                                                                      
                else{                                                                                                     
                    status_address = false;
                }
            }
            if (status_address == true)    status = false;
            else cout << "--Please enter the detail address--" << endl;
        }break;

        case PHONE_NUMBER:{
            bool status_phone = true;
            INPUT_DATA_HAVE_SPACE("Enter phone number: ", *(string*)text);
            string phone_number = *(string*)text;
            for (int i = 0; i < (int)phone_number.length(); i++){                                                               
                if (phone_number[i] >= '0' && phone_number[i] <= '9' && phone_number[0] == '0' && (int)phone_number.length() == 10){}                                                                                                                                                                                      
                else{                                                                                                     
                    cout << "--Please enter the right phone number--" << endl;
                    status_phone = false;
                    break;
                }
            }
            if (status_phone == true)    status = false;
        }break;

        case POSITION:{
                cout <<"Please chose Position in Table: " <<endl
                     <<"    1. JANITOR"                   <<endl
                     <<"    2. RECEPTIONIST"              <<endl
                     <<"    3. LAUNDRY_STAFF"             <<endl
                     <<"    4. LAUGGAGE_STAFF"            <<endl
                     <<"    5. GRADENER"                  <<endl;
                INPUT_DATA_NO_SPACE("Enter position: ", *(int*)text);
                if (check_limit(*(int*)text, 5 , 1) == true){
                    cout <<"--Please enter the rigth value--" <<endl;
                }
                status = check_limit(*(int*)text, 5, 1);
        }break;

        case DAY:{
                INPUT_DATA_NO_SPACE("Enter day: ", *(int*)text);
                status = check_limit(*(int*)text, 1, 31);
        }break;

        case MONTH:{
                INPUT_DATA_NO_SPACE("Enter month: ", *(int*)text);
                status = check_limit(*(int*)text, 1, 12);
        }break;

        case YEAR:{
                INPUT_DATA_NO_SPACE("Enter year: ", *(int*)text);
                status = check_limit(*(int*)text, 2022, 2023);
        }break;

        case SECOND:{
                INPUT_DATA_NO_SPACE("Enter second: ", *(int*)text);
                status = check_limit(*(int*)text, 0, 59);
        }break;

        case MINUTE:{
                INPUT_DATA_NO_SPACE("Enter minute: ", *(int*)text);
                status = check_limit(*(int*)text, 0, 59);
        }break;

        case HOUR:{
                INPUT_DATA_NO_SPACE("Enter hour: ", *(int*)text);
                status = check_limit(*(int*)text, 1, 12);
        }break;
        }                                                                                                         
    }

}

