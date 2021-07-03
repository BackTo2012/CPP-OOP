#include <iostream>
#include <cstring> // strcpy and strcat prototypes
using namespace std;


class String
{
public:
    String( const char * = "" ); // 输出"Conversion (and default) constructor: "
    String( const String & ); //输出 "Copy constructor: "
    ~String(); // 输出"Destructor: "

    bool operator==( const String & ) const; // test s1 == s2
    operator  char*() { return this->sPtr; }; //转换函数
    friend ostream &operator<<( ostream &out, const String &t );

    String& operator=( const char *t);
    String& operator=( const String &t );
    String& operator+=( const String &t );



private:
    int length; // string length (not counting null terminator)
    char *sPtr; // pointer to start of pointer-based string
};
//StudybarCommentEnd
String::String ( const char *ptr) {
    length = 0;
    while (ptr[length] != '\0') {
        length++;
    }
    sPtr = new char[length + 1];
    int i = 0;
    while (ptr[i] != '\0') {
        sPtr[i] = ptr[i];
        i++;
    }
    sPtr[i] = ptr[i];
    cout << "Conversion (and default) constructor: " << sPtr << endl;
};
String::String( const String &a ) {
    cout << "Copy constructor: " << a.sPtr << endl;
    length = a.length;
    sPtr = new char[a.length];
    for (int i = 0; i < length; i++) {
        sPtr[i] = a.sPtr[i];
    }
    sPtr[length] = '\0';
};
String::~String() {
    cout << "Destructor: " << sPtr << endl;
    if (sPtr != NULL)
    {
        delete[] sPtr;
    }
};
bool String::operator==( const String & ptr) const {
    if (strcmp(sPtr, ptr.sPtr))
        return false;
    else
        return true;
};
ostream &operator<<( ostream &out, const String &t ) {
    out << t.sPtr << endl;
    return out;
};

String& String::operator=( const char *t) {
    delete []sPtr;
    sPtr = new char[strlen(t) + 1];
    strcpy(sPtr, t);
    return *this;
};
String& String::operator=( const String &t ) {
    delete []sPtr;
    sPtr = new char[t.length + 1];
    strcpy(sPtr, t.sPtr);
    return *this;

};
String& String::operator+=( const String &t ) {
    length += t.length + 1;
    char *temp = new char[length];
    strcpy(temp, sPtr);
    strcat(temp, t.sPtr);
    sPtr = temp;
    return *this;
};










//StudybarCommentBegin
int main()
{
    String s1( "happy" );
    String s2( " birthday" );
    String s3;

    // test overloaded equality and relational operators
    cout << "s1 is \"" << s1 << "\"; s2 is \"" << s2
         << "\"; s3 is \"" << s3 << '\"'
         << boolalpha << "\n\nThe results of comparing s2 and s1:"
         << "\ns2 == s1 yields " << ( s2 == s1 )
         << "\ns2 != s1 yields " << ( s2 != s1 )
         << "\ns2 >  s1 yields " << ( s2 > s1 )
         << "\ns2 <  s1 yields " << ( s2 < s1 )
         << "\ns2 >= s1 yields " << ( s2 >= s1 )
         << "\ns2 <= s1 yields " << ( s2 <= s1 );


    // test overloaded String empty (!) operator
    cout << "\n\nTesting !s3:" << endl;

    if ( !s3 )
    {
        cout << "s3 is empty; assigning s1 to s3;" << endl;
        s3 = s1; // test overloaded assignment
        cout << "s3 is \"" << s3 << "\"";
    } // end if

    // test overloaded String concatenation operator
    cout << "\n\ns1 += s2 yields s1 = ";
    s1 += s2; // test overloaded concatenation
    cout << s1;

    // test conversion constructor
    cout << "\n\ns1 += \" to you\" yields" << endl;
    s1 += " to you"; // test conversion constructor
    cout << "s1 = " << s1 << "\n";

    // test copy constructor
    String *s4Ptr = new String( s1 );
    cout << "\n*s4Ptr = " << *s4Ptr << "\n";

    // test destructor
    delete s4Ptr;

    // test using subscript operator to create a modifiable lvalue
    s1[ 0 ] = 'H';
    s1[ 6 ] = 'B';
    cout << "\ns1 after s1[0] = 'H' and s1[6] = 'B' is: "
         << s1 << "\n";

    // test subscript out of range
    cout << "Attempt to assign 'd' to s1[30] yields:" << endl;
    s1[ 30] = 'd'; // ERROR: subscript out of range

    return 0;
} // end main
//StudybarCommentEnd