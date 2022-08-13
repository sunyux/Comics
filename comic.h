#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>
using namespace std;
class comic_shop
{
      public:
             /* All of these functions have ALREADY been written */
             comic_shop(void);
             ~comic_shop(void);
             int add_one(char * name, char * publisher,char * sph,char * issue,char * review,char * oth);
             int copy_one(const comic_shop & to_add);
             int display(void) const;
      //private:
              char * name;
              char * publisher;
              char * sph;
              char * issue;
              char * review;
              char * oth;
};
struct node
{
       comic_shop comic; //just one comic 
       node * next;
};
class table
{
      public:
             table(int size=10);
             ~table(void);  
             int insert(char * key_value, const comic_shop & to_add);   
             int retrieve(char * name_to_find) const;
	     void rm(char * name_to_rm);
	     int display_sph(char * sph_to_find)const;
             int hash_function(char *key) const;
             int display_all(void) const; 
      private:
              node ** hash_table;  
	          int hash_table_size;
};
