#include<iostream> // used for input output..
#include<fstream>  // used for open files....
#include<sstream>  // Provide templetes and types btw string buffer and string objects
#include<string>

using namespace std;
int main(){
    int a, i=0;
    string text, old, password1,password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout<<"                Security System       "<<endl<<endl;
    cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"|                 1. Register                |"<<endl;
    cout<<"|                 2. Login                   |"<<endl;
    cout<<"|                 3. Change Password         |"<<endl;
    cout<<"|                 4. End Program             |"<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;

do
{
    cout<<endl<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>a;
    switch(a)
    {
    case 1:{
        cout<<" ____________________________________________"<<endl;
        cout<<"|-------------------Register-----------------|"<<endl;
        cout<<" ____________________________________________"<<endl;
        cout<<"Please Enter username:-   ";
        cin>>name;
        cout<<"Enter your password:-   ";
        cin>>password0;
        cout<<"Please Enter your age:-   ";
        cin>>age;

        // ofstream class is use for open file and writing purpose
        // ifstream class is use for open and reading purpose
        ofstream of1;
        of1.open("file.txt");
        if(of1.is_open()){
            of1<<name<<"\n";
            of1<<password0;
            cout<<"Registration Successful"<<endl;
        }
        break;
    }
    case 2:{
        cout<<"__________________________________________________"<<endl;
        cout<<"|------------------Login--------------------------"<<endl;
        cout<<"|________________________________________________|"<<endl;
        
        ifstream of2;
        of2.open("file.txt");
        cout<<"Please Enter the username: "<<endl;
        cin>>user;
        cout<<"Please Enter Password: "<<endl;
        cin>>pass;

        if(of2.is_open()){
            while(!of2.eof()){
                while(getline(of2,text)){
                    istringstream iss(text);
                    iss>>word;
                    creds[i]=word;
                    i++;
                }
                if(user==creds[0] && pass==creds[1])
                {
                    cout<<"------------Log in Successful------------";
                    cout<<endl<<endl;

                    cout<<"Details: "<<endl;

                    cout<<"Username: "+name<<endl;
                    cout<<"Password: "+pass<<endl;
                    cout<<"Age: "+age<<endl;
                }
                else
                {
                    cout<<endl<<endl;
                    cout<<"Incorrect Credentials"<<endl;
                    cout<<"|----- 1. Press 2 to Login-----|"<<endl;
                    cout<<"|----- 2. Press 3 to Change Password-----|"<<endl;
                    break;
                }
            }
        }
        break;
    }
    case 3:
    {
        i=0;
        cout<<"---------------------Change Password----------------------"<<endl<<endl;
        ifstream of0;
        of0.open("file.txt");
        cout<<"Enter the old password:-  "<<endl;
        cin>>old;
        if(of0.is_open()){
            while(of0.eof()){
                while(getline(of0, text)){
                    istringstream iss(text);
                    iss>>word1;
                    cp[i]=word1;
                    i++;
                }
                if(old==cp[1]){
                    of0.close();

                    ofstream of1;
                    if(of1.is_open()){
                        cout<<"Enter your new password:-  "<<endl;
                        cin>>password1;
                        cout<<"Enter your password again:-  "<<endl;
                        cin>>password2;

                        if(password1==password2){
                            of1<<cp[0]<<"\n";
                            of1<<password1;
                            cout<<"Password Change Successful"<<endl;
                        }
                        else{
                            of1<<cp[0]<<"\n";
                            of1<<old;
                            cout<<"Password do not match"<<endl;
                        }
                    }
                }
                else{
                    cout<<"Please enter a valid password"<<endl;
                    break;
                }
            }
        }
        break;
    }
    case 4:{
        cout<<"_________________Thank you___________________"<<endl;
        break;
    }
    default:
        cout<<"Enter a valid choice"<<endl;
    }
    }
    while(a!=4);
        return 0;
    
}