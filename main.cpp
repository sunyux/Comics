#include"comic.h"
//Yuxin sun
//main.cpp to test all functions

int main()
{
	int choose = 0;
	table my_comic(10);
    comic_shop to_add, an_entry;
	char name[100];
    char publisher[31];
    char sph[31];
    char issue[100];
    char review[100];
    char oth[100];
    while(true) {
        cout << "------------------------------------------------------" << endl;
		cout << ">>>>>>>>> Welcome to use the comic system! <<<<<<<<<" << endl;
		cout << "            Please choose a function :)               " << endl;
		cout << "            Enter'0' to quit the system               " << endl;
		cout << "            Enter'1' to add comics                    " << endl;
		cout << "            Enter'2' to delete a comic              " << endl;
		cout << "            Enter'3' to display a superhero          " << endl;
		cout << "            Enter'4' to try display all fuction      " << endl;
		cout << "            Enter'5' to try Retrieve fuction      " << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "            Please enter your choose                  " << endl;
		cin>>choose;
		cin.ignore(100,'\n');
		switch(choose) {
        case 0:
            cout <<"   Thanks for using the system     "<<endl;
			cout <<"   Have a good day! ^-^           "<<endl;
			return 0;
        case 1:
			int num;
            cout << "How would you like to import data ?" << endl;
            cout << "1. Import from file" << endl;
            cout << "2. Import from console manually (default)" << endl;
            cin >> num;
            if(1 == num) {
                char dataFile[100];
                cout << "Please enter the data file: " << endl;
                cin >> dataFile;
                ifstream fin(dataFile);
                char line[1001], *pstart, *pdelimiter;
                while(fin.getline(line, 1000)) {
                    pstart    = line;
                    pdelimiter= index(pstart, '|');
                    if(!pdelimiter) continue;
                    *pdelimiter = 0;
                    strcpy(name, pstart);//name
                    pstart     = pdelimiter + 1;
                    pdelimiter = index(pstart, '|');
                    *pdelimiter= 0;
                    strcpy(publisher, pstart);//publisher
                    pstart     = pdelimiter + 1;
                    pdelimiter = index(pstart, '|');
                    *pdelimiter= 0;
                    strcpy(sph, pstart);//super hero
                    pstart     = pdelimiter + 1;
                    pdelimiter = index(pstart, '|');
                    *pdelimiter= 0;
                    strcpy(issue, pstart);//issue
                    pstart     = pdelimiter + 1;
                    pdelimiter = index(pstart, '|');
                    *pdelimiter= 0;
                    strcpy(review, pstart);//review
                    pstart     = pdelimiter + 1;
                    pdelimiter = index(pstart, '|');
                    *pdelimiter= 0;
                    strcpy(oth, pstart);//other info
                    to_add.add_one(name, publisher,sph,issue,review,oth);
                    my_comic.insert(sph, to_add);
                }
                fin.close();
            } else {
                cout<<"How many comics do you want to add?"<<endl;
                cin >> num;
                cin.ignore(100,'\n');
                for(int i = 0; i < num; ++i) {
                    cout << "Please enter a comic name: ";
                    cin.get(name, 100); cin.ignore(100,'\n');
                    cout << "Please enter the publisher: ";
                    cin.get(publisher, 31); cin.ignore(100,'\n');
                    cout << "Please enter the name of the superhero: ";
                    cin.get(sph, 31); cin.ignore(100,'\n');
                    cout << "Please enter the issue: ";
                    cin.get(issue, 100); cin.ignore(100,'\n');
                    cout << "Please enter the review: ";
                    cin.get(review, 100); cin.ignore(100,'\n');
                    cout << "Please enter the other information: ";
                    cin.get(oth, 100); cin.ignore(100,'\n');
                    to_add.add_one(name, publisher,sph,issue,review,oth);
                    my_comic.insert(sph, to_add);
                }
            }
      		break;
        case 2:
            cout <<"Please enter the delete name: ";
            cin.get(name, 100); cin.ignore(100,'\n');
            my_comic.rm(name);
            break;
        case 3:
            cout <<"Please enter the superhero name: ";
            cin.get(sph, 31); cin.ignore(100,'\n');
            my_comic.display_sph(sph);
            break;
        case 4:
            my_comic.display_all();
            break;
        case 5:
         {  cout <<"Please enter the superhero name: ";
            cin.get(sph, 31); cin.ignore(100,'\n');
            int i=my_comic.retrieve(sph);
            if(i<=0)
              cout<<"The superhero is working, please check again"<<endl;
            else
               cout<<"There are "<<i<<" of superhero in the system, please use display function to check the detial of them"<<endl;
            break;
	 }
		default:
            cout << "     Wrong choose, please check again.  " << endl;
		}
	}
	cout<<"     Wrong choose,please check again.       "<<endl;
	return 0;
}
