#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <windows.h>

using namespace std;

bool already_running()
{
    ifstream fin("C:\\Program Files\\wshdt\\config.config");
    if (!fin.is_open()) {
        cout << "top 1 difficulty jump of the year";
        exit(1);
    }
    string path, distro; int mountvol;
    fin >> path >> distro >> mountvol;
    if (fin.fail()) {
        cout << "fatass";
        exit(1);
    }
    fin.close();
    
    // retrieve current information to wshdt/prev_wsl_state.txt
    system("wsl -l -v > C:\\Program Files\\wshdt\\prev_wsl_state.txt");
    
    ifstream info("C:\\Program Files\\wshdt\\prev_wsl_state.txt");
    if (!info.is_open()) {
        cout << "this is one of the hardest error to be obtained";
        exit(1);
    }
    string found = "";
    while (getline(info, found)) // take then give to buffer and read
        if (found.find(distro) != string::npos && found.find("Running") != string::npos)
            return true; // &.find(const char*) return string::npos when not found
    return false;
}

void ready_vhdx(const string& path_to_storage_file)
{
    // placing a bet on eating an actual shit if this fails to do so
    // actually i am very confident on this bet because i know
    // it will actually work instead of random soulless dump
    if (!filesystem::exists(path_to_storage_file)) {
        cout << "table no found file, table turns over";
        exit(1);
    }
    cout << "table found file, table breaks" << endl;
}

void attach_vhdx(int mountvol) {
    string cmd = "wsl --mount \\\\.\\PHYSICALDRIVE" + to_string(mountvol) + " --bare";
    if (system(cmd.c_str())) {
        cout << "yeah no dude we won't have flying cars in 2030 if you are" << endl << "this stupid when choosing the disk the mount";
        exit(1); // exit code looking like registry yo
    }
    cout << "the disk you chose to mount: i swear i wasn't hacking my internet was so terrible" << endl;
}

void launch(const string& distribution) { // ppl after using const string& on anything other than extremely constrainted environments for cosmetics purpose
    string cmd = "wsl -d " + distribution;
    if (system(cmd.c_str())) {
        cout << "LAST JUMP casually fell on the final stretch of CoLS sob sob emoji";
        exit(1);
    }
}

bool configure(string path_to_storage_file, string distribution, int mountvol)
{
    ofstream fout("C:\\Program Files\\wshdt\\config.config");
    if (!fout.is_open()) // condition whereas a file is currently open or no
        return false;
    if (path_to_storage_file=="" || distribution=="" || !mountvol)
        return false;
    
    fout << path_to_storage_file << endl;
    fout << distribution << endl;
    fout << mountvol;
    
    fout.close();
    return true;
}

bool load()
{
    // i'll gamble with all my will
    // placed bet on red
    // fuck i lost my money
    ifstream fin("C:\\Program Files\\wshdt\\config.config");

    // me tralalon when no semicolons
    string path_to_storage_file, distribution;
    int mountvol = 0;
    fin >> path_to_storage_file >> distribution >> mountvol;
    if (fin.fail()) { 
        cout << "I don't get it on how your mom is THAT fat, really obese.";
        exit(1);
    }
    if (path_to_storage_file=="" || distribution=="" || !mountvol)
        return false; // who the hell sets up a configuration like that i just sat down
    
    ready_vhdx(path_to_storage_file);
    if (!already_running())
        attach_vhdx(mountvol);
    launch(distribution);

    fin.close();
    return true;
}

void help() {
    cout << "WARNING: this program assumes if no other volumes with the VHDX" << endl << "identifier is found before attaching the specified VHDX." << endl;
    cout << "we add soulless dumps here so ppl wont call us weirdos muaheheheheh";
    cout << "me when me when me when me when locale != English" << endl;
    cout << "--configure str,str,int" << endl;
    cout << "--configure path,distro,mountvol" << endl;
    cout << "--help" << endl;
    cout << "err code 0 = success, 1 = cannot continue, 2 = could continue but gave no data" << endl;
    cout << "very fragile tool so if it throws a brick at you enjoy your house burnt down bye" << endl;
    exit(0);
}

bool is_running_as_admin() 
{
    BOOL isAdmin = FALSE; 
    PSID adminGroup = NULL; 
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY; 
    if (AllocateAndInitializeSid( &ntAuthority, 
        2, 
        SECURITY_BUILTIN_DOMAIN_RID, 
        DOMAIN_ALIAS_RID_ADMINS, 0,0,0,0,0,0, 
        &adminGroup)) 
    { 
        CheckTokenMembership(NULL, 
            adminGroup, 
            &isAdmin); 
        FreeSid(adminGroup); 
    } 
    return isAdmin; }

int main(int argc, char* argv[])
{
    // Program runtime started and chaos HAPPENS...
    cout << "Hello! I'm the logger for this program. When something" << endl << "happens, I'll make sure to report it to the console." << endl;

    if (argc >= 3) {
        string flag = argv[1];
        string contents = argv[2];
        if (flag=="--configure") {
            if (!is_running_as_admin()) {
                cout << "need administrative access to prevent accidental changes yo";
                exit(1);
            }
            string path = "";
            string distro = "";
            int mountvol = -1;
            
            contents += ',';
            string context = "";
            for (int i=0; i<contents.size(); i++) {
                if (contents[i]==',') {
                    if (path=="")
                        path = context;
                    else if (distro=="")
                        distro = context;
                    else {
                        try { mountvol = stoi(context); }
                        catch (...) {
                            // i didnt know try and catch existed
                            cout << "thankfully this isn't C where a will get you 96 instead of you mistyping on a late night snack";
                            exit(1);
                        }
                    }
                    context = "";
                }
                else
                    context += contents[i];
            }
            if (path=="" || distro=="" || mountvol==-1)
                cout << "oh yeah i'd insert a unicode character for broken heart because of your stupidity is what makes your parents DISAPPOINTED for having a chopped child like you who is worse than your neighbor who is 100 times better from the myths";
            if (!configure(path, distro, mountvol)) {
                cout << "your changes wasnt applied haha";
                exit(1);
            } 
            else {
                cout << "you can now submit a tower in EToH without getting blocked by them curators";
                exit(0);
            }
        }
        else {
            cout << "wrong usage bozo" << endl;
            help();
            exit(1);
        }
    }
    else if (argc == 2) {
        cout << "you rapper you need beat da baby outta atlanta so you climb to top of the mount and kaboom amogus published 5 spaceships outside containing yo EVIL mamas... finally they coca cola espuma the entire universe and lingangugli guli gu li wata lingangu lingangu i'm actually so drunk rn like wth am i writitng i swaer if i put this whole goofy arh story on my essay on top 5 best wallwalkers in roblox then i skull emoji wilted rose emoji smth liek that who cares about correctness for a soulless dump btw i was gonna bomb ur house until i realizd you ned two leart their commands so";
        cout << endl;
        help();
        exit(1);
    }
    else {
        // writing so shit shakespeare died out of boredom
        if (already_running()) {
            int option;
            cout << endl << "choose option 1 : wsl now, 2: restart wsl by wait 20s" << endl;
            cin >> option;
            if (option==1) system("wsl");
            else if (option==2) {
                system("wsl --shutdown");
                Sleep(20000);
                load();
            }
            else exit(2); // new exit code
        }
        else {
            if (!load()) {
                cout << "goo goo ga ga wth is even ts conf file dam well just use --configure to reenter it";
                return 1;
            }
        }
    }

    return 0;
}