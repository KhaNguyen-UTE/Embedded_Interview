/*
* File Name: Checkinput.cpp
* Author: Nguyen Tran Minh Kha
* Date: 15/06/2023
* Description: The program is used to setup for Class Check. The class will be use to check the input data is valid or not
*/

#include <Hotel.hpp>

/*
* Function: check_limit()
* Description: use for check input data, the data input need to between lower_limit and upper_limit
* Input:
*   text: int _ the input data
*   upper_limit: int _ the upper limit
*   lower_imit: int _ the lower limit
* Output:
*   false if the data is between the limit else return true
*/
bool Check::check_limit( int text, int upper_limit, int lower_limit){
    if (text >= lower_limit && text <= upper_limit) return false;
    else return true;
}

/*
* Function: check_input()
* Description: use for check input data, the data input need to in the right value
* Input:
*   *text: void _ the input data
*   tpye: TypeInput
* Output:
*   none
*/
void Check::check_input(void *text, TypeInput type){
    bool status = true;
    bool begin = true;
    while (status == true){
        if (begin == false) cout <<"-- Please enter the right value --" <<endl;
        if (begin == true) begin = false;
        switch (type)
        {
        case NAME:{
            bool status_name = true;
            INPUT_DATA_HAVE_SPACE("Enter new Name: ", *(string*)text);
            string name = *(string*)text;
            for (int i = 0; i < (int)name.length(); i++){                                                               
                if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' ')){}                                                                                                                                                                                      
                else{                                                                                                     
                    status_name = false;
                    break;
                }
            }
            if (status_name == true)    status = false;
        }break; 
        
        case ADDRESS:{
            bool status_address = true;
            INPUT_DATA_HAVE_SPACE("Enter new address: ", *(string*)text);
            string address = *(string*)text;
            for (int i = 0; i < (int)address.length(); i++){                                                               
                if (address[i] == ' '){ status_address = true;    break;}                                                                                                                                                                                      
                else{                                                                                                     
                    status_address = false;
                }
            }
            if (status_address == true)    status = false;
        }break;

        case PHONE_NUMBER:{
            bool status_phone = true;
            INPUT_DATA_HAVE_SPACE("Enter new phone number: ", *(string*)text);
            string phone_number = *(string*)text;
            for (int i = 0; i < (int)phone_number.length(); i++){                                                               
                if (phone_number[i] >= '0' && phone_number[i] <= '9' && phone_number[0] == '0' && (int)phone_number.length() == 10){}                                                                                                                                                                                      
                else{                                                                                                     
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
                     <<"    5. GRADENER"                  <<endl
                     <<"    6. MANAGER"                   <<endl;
                INPUT_DATA_NO_SPACE("Enter position: ", *(int*)text);
                if (cin.fail() == true){
                    cin.clear();
                    cin.ignore(100, '\n');
                    break;
                }
                status = check_limit(*(int*)text, 6, 1);
        }break;

        // Use for assume time
        case DAY:{
                INPUT_DATA_NO_SPACE("Enter day: ", *(int*)text);
                if (cin.fail() == true){
                    cin.clear();
                    cin.ignore(100, '\n');
                    break;
                }
                status = check_limit(*(int*)text, 31, 1);
        }break;

        case MONTH:{
                INPUT_DATA_NO_SPACE("Enter month: ", *(int*)text);
                if (cin.fail() == true){
                    cin.clear();
                    cin.ignore(100, '\n');
                    break;
                }
                status = check_limit(*(int*)text, 12, 1);
        }break;

        case YEAR:{
                INPUT_DATA_NO_SPACE("Enter year: ", *(int*)text);
                if (cin.fail() == true){
                    cin.clear();
                    cin.ignore(100, '\n');
                    break;
                }
                status = check_limit(*(int*)text, 2023, 2022);
        }break;

        case SECOND:{
                INPUT_DATA_NO_SPACE("Enter second: ", *(int*)text);
                if (cin.fail() == true){
                    cin.clear();
                    cin.ignore(100, '\n');
                    break;
                }
                status = check_limit(*(int*)text, 59, 0);
        }break;

        case MINUTE:{
                INPUT_DATA_NO_SPACE("Enter minute: ", *(int*)text);
                if (cin.fail() == true){
                    cin.clear();
                    cin.ignore(100, '\n');
                    break;
                }
                status = check_limit(*(int*)text, 59, 0);
        }break;

        case HOUR:{
                INPUT_DATA_NO_SPACE("Enter hour: ", *(int*)text);
                if (cin.fail() == true){
                    cin.clear();
                    cin.ignore(100, '\n');
                    break;
                }
                status = check_limit(*(int*)text, 23, 0);
        }break;
        }                                                                                                         
    }

}

