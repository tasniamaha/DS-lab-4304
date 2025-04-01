#include <bits/stdc++.h>
using namespace std;

void searchdatabase(const string filename,int id){
    fstream new_file;
    new_file.open(filename,ios::in);
    if(!new_file){
        cout<<"Error while opening file"<<endl;
        return ;
    }
    string line;
    while(getline(new_file,line)){
        stringstream ss(line);
        string serial,incantation,spell_name,effect,light;
        getline(ss,serial,',');
        getline(ss,incantation,',');
        getline(ss,spell_name,',');
        getline(ss,effect,',');
        getline(ss,light,',');
        int ser=stoi(serial);
        if(ser==id){
            cout<<"Serial ID :"<<ser<<endl;
            cout<<"Incantation :"<<incantation<<endl;
            cout<<"Spell name :"<<spell_name<<endl;
            cout<<"Effect :"<<effect<<endl;
            cout<<"Light :"<<light<<endl;
            return ;
        }
    }
    cout<<"Not found!"<<endl;
    new_file.close();
}
void insertrow(const string filename){
    fstream new_file;
    new_file.open(filename,ios::in);
    
    if(!new_file){
        cout<<"Error in opening"<<endl;
        return ;
    }
    int id;
    string incantation,spell,effect,light;
    string lastline,line;
    while(getline(new_file,line)){
        lastline=line;
    }
    new_file.close();
    string last_id;
    int last;
    if(!lastline.empty()){
        stringstream ss(lastline);
        
        getline(ss,last_id,',');
        last=stoi(last_id);
    }
    ofstream add_file(filename,ios::app);
    cin.ignore();
    cout<<"Enter Incantation :";
    getline(cin,incantation);
    cout<<"Enter Spell name :";
    getline(cin,spell);
    cout<<"Enter Effect :";
    getline(cin,effect);
    cout<<"Enter Light :";
    getline(cin,light);
    if(!add_file){
        cout<<"Error in adding"<<endl;
        return ;
    }
    add_file<<last+1<<','<<incantation<<','<<spell<<','<<effect<<','<<light<<endl;
    cout<<"Successfully added"<<endl;
    add_file.close();
}
void deleterows(const string filename,int id){
    fstream new_file,updated_file;
    new_file.open(filename);
    updated_file.open("temp.txt",ios::out);
    if(!new_file || !updated_file){
        cout<<"File cannot be opened"<<endl;
        return ;
    }
    string line;
    while(getline(new_file,line)){
        stringstream ss(line);
        string serial;
        getline(ss,serial,',');
        int s=stoi(serial);
        if(s!=id){
            updated_file<<line<<endl;
        }
    }
    new_file.close();
    updated_file.close();
    remove(filename.c_str());
    rename("temp.txt",filename.c_str());
}
void updateentry(const string filename,const string col,int id){
    fstream new_file,updated_file;
    new_file.open(filename);
    updated_file.open("temp.txt",ios::out);
    if(!new_file || !updated_file){
        cout<<"File cannot be opened"<<endl;
        return ;
    }
    string line;
    while(getline(new_file,line)){
        stringstream ss(line);
        string serial,incantation,spell_name,effect,light;
        getline(ss,serial,',');
        int s=stoi(serial);
        if(s==id){
            if(col=="incantation"){
                cout<<"Enter :";
                cin.ignore();  
                getline(cin, incantation);
                updated_file << serial << "," << incantation << "," << spell_name << "," << effect << "," << light << endl;
            }
            else if(col=="spell name"){
                cout<<"Enter :";
                cin.ignore();  
                getline(cin,spell_name);
                updated_file << serial << "," << incantation << "," << spell_name << "," << effect << "," << light << endl;
            }
            else if(col=="effect"){
                cout<<"Enter :";
                cin.ignore();  
                getline(cin, effect);
                updated_file << serial << "," << incantation << "," << spell_name << "," << effect << "," << light << endl;
            }
            else if(col=="light"){
                cout<<"Enter :";
                cin.ignore(); 
                getline(cin, light);
                updated_file << serial << "," << incantation << "," << spell_name << "," << effect << "," << light << endl;
            }
            else{
                cout<<"Invalid option";
                new_file.close();
                updated_file.close();
                remove("temp.txt");
                return ;
            }
            updated_file<<serial<<","<<incantation<<","<<spell_name<<","<<effect<<","<<light<<endl;
        }
        else{
            updated_file<<line<<endl;
        }
        
    }
    new_file.close();
    updated_file.close();
    remove(filename.c_str());
    rename("temp.txt",filename.c_str());
}
int main(){
    cout<<"The tasks that can be performed by this software:"<<endl;
    
    cout<<"1.Insert new rows into database file"<<endl;
    cout<<"2.Update certain columns for some entries in the file."<<endl;
    cout<<"3.Delete rows from the file"<<endl;
    cout<<"4.Search rows from the file based on a unique ID."<<endl;
    cout<<"5.Exit the program"<<endl;
    cout<<"What would you like to choose: ";
    int n;
    cin>>n;
    
    string filename="spells.txt";
    switch(n){
        case 1:
            insertrow(filename);
            break;
        case 2:{
            cout<<"Enter the ID you want to update :";
            int i;
            cin>>i;
            cin.ignore();
            cout<<"Enter the entry you want to update :";
            string c;
            getline(cin,c);
            updateentry(filename,c,i);
            break;
        }  
        case 3:{
            cout<<"Enter the ID you want to delete :";
            int i;
            cin>>i;
            cin.ignore();
            deleterows(filename,i);
            break;
        }
            
        case 4:{
            cout<<"which id you want to search :"<<endl;
            int id;
            cin>>id;
            cin.ignore();
            searchdatabase(filename,id);

            break;
        }
        case 5:
            break;
        default:
            cout<<"Invalid input"<<endl;
    }
}