
#include "comic.h"
//Yuxin SUn 
//Implement the member function of the comic class

comic_shop::comic_shop()//default constructor
{
    name      = NULL;
    publisher = NULL;
    sph       = NULL;
    issue     = NULL;
	review    = NULL;
	oth       = NULL;
}

//release all memory
comic_shop::~comic_shop()
{
    delete [] name;
    delete [] publisher;
    delete [] sph;
    delete [] issue;
    delete [] review;
    delete [] oth;
    name     =
    publisher= 
	sph      =
    issue    =
    review   =
    oth      = NULL;   
}

//copy the argument into the current object
int comic_shop::copy_one(const comic_shop& to_add)
{
    return add_one(to_add.name, 
            to_add.publisher, to_add.sph,
			to_add.issue, to_add.review, to_add.oth
    );
}

//establishe values for all data members
int comic_shop::add_one(char * name_add, char * publisher_add,
			 				char * sph_add,char * issue_add,
							 char * review_add,char * oth_add)
{
     if (name) delete [] name;
     name = new char[strlen(name_add) + 1];
     strcpy(name, name_add);
     publisher = new char[strlen(publisher_add) + 1];
     strcpy(publisher, publisher_add);
     sph = new char[strlen(sph_add) + 1];
     strcpy(sph, sph_add);
     issue = new char[strlen(issue_add) + 1];
     strcpy(issue, issue_add);
     review = new char[strlen(review_add) + 1];
     strcpy(review, review_add);
     oth = new char[strlen(oth_add) + 1];
     strcpy(oth, oth_add);
     return 1;
}

//output a values
int comic_shop::display()const
{
    if (!name || !sph) return 0;
    cout <<"The comic is "<<name<<" ."<<endl;
	cout << "The publisher of the comic is " << publisher << " ." << endl;
	cout << "The superhero is " << sph << " ." << endl;
	cout << "The issue of the comic is " << issue << " ." << endl;
	cout << "The review of the comic is " << review << " ." << endl;
	cout << "The other information of the comic is " << oth << " ." << endl;
    return 1;
}
//default constructor
table::table(int size)
{
      hash_table = new node *[size];
      for(int i = 0;i<size;++i) hash_table[i] = NULL;
      hash_table_size = size;
}
//deallocate
table::~table(void)
{
	node * current;
	node * ptr;
	int size = hash_table_size;
	for(int i = 0;i<size;++i) {
		current = hash_table[i];
		while(current) {
			ptr = current->next;
			delete current;
			current = ptr;
		}
	}
	delete []hash_table;
	hash_table = NULL;
}
//hash function
int table::hash_function(char *key) const
{
	int i = 0;
	int size = strlen(key);
	for(int j = 0; j < size; ++j) i += key[j];
    return i % 10;
}
//add to the hash table
int table::insert(char * key_value, const comic_shop & to_add)
{
	node* temp = new node;
	temp->comic.copy_one(to_add);
    temp->next = NULL;
	int i = hash_function(key_value);
	if(hash_table[i] == NULL) {
		hash_table[i] = temp;
	} else {
		node* current = hash_table[i];
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
	}
    return 0;
}
//display by a sph
int table::display_sph(char * sph_to_find)const
{
	for(int i = 0;i < hash_table_size; ++i) {
		if(hash_table[i] == NULL) continue;
		node* temp = hash_table[i];
		do {
			if(strcmp(temp->comic.sph,sph_to_find) == 0) {
				temp->comic.display();
            }
            temp = temp->next;
		} while(temp != NULL);	
	}
	return 0;
}
//find a superhero
int table::retrieve(char * name_to_find)const
{
	int count=0;
	for(int i = 0;i < hash_table_size; ++i) {
		if(hash_table[i] == NULL) continue;
		node* temp = hash_table[i];
		do {
			if(strcmp(temp->comic.sph,name_to_find) == 0) {
				++count;
            }
            temp = temp->next;
		} while(temp != NULL);	
	}
	return count;
}
//delete an arguement from the table
void table::rm(char * name_to_rm)
{
     for(int i=0;i<hash_table_size;++i){
	node* temp = hash_table[i];
	node* ptr  = NULL;
    while(temp) {
        if(!strcmp(temp->comic.name, name_to_rm)) {
            if(!ptr) {
                hash_table[i] = temp->next;
            } else {
                ptr->next = temp->next;
            }
            delete temp;
            temp = ptr->next;
        } else {
            ptr  = temp;
            temp = temp->next;
		}
	}
}
}
//display all comics in the table
int table::display_all(void) const
{
	for(int i = 0; i < hash_table_size; ++i) {
		if(hash_table[i] == NULL) continue;
		node* temp = hash_table[i];
		while(temp != NULL) {
			temp->comic.display();
			temp = temp->next;
		}	
	}
	return 1;
}
