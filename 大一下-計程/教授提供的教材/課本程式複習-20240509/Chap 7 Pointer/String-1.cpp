#include <cstring>

int main(){
   char msg1[] = "Hello";
   char *msg2 = "Hello";
   char *cp;
   cp = &msg1[0];
   
   cout<<(void *)msg1<<' '<<(void *)msg2<<' '<<(void *)cp<<endl;
   
      // warning: deprecated conversion from string constant to 'char*'
 
   cout << strlen(msg1) << endl;    // 5
   cout << strlen(msg2) << endl;
   cout << strlen("Hello") << endl;
 
   int size = sizeof(msg1)/sizeof(char);
   cout << size << endl;  // 6 - including the terminating '\0'
   for (int i = 0; msg1[i] != '\0'; ++i) {
      cout << msg1[i];
   }
   cout << endl;
 
   for (char *p = msg1; *p != '\0'; ++p) {
          // *p != '\0' is the same as *p != 0, is the same as *p
      cout << *p;
   }
   cout << endl;
   
   for (char *p = msg1; *p; ++p) 
     cout <<*p;
   cout << endl;
   
   for (char *p = msg1; *p;  cout <<*p, ++p) 
     ;
   cout << endl;
   
   for (char *p = msg1; *p;  cout <<*p++) 
     ;
   cout << endl;
}