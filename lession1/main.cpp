#include <iostream>
#include <string>
using namespace std;
   //1 
class Person
{
private:
    string FamilyName,Name,Surname
public:
    Person(){FamilyName="",Name="",Surname="";} 
    Person(const string& f,const string& n,const string& s="")     
    {
        FamilyName=f,Name=n,Surname=s;
    }
    Person(const Person& a)  
    {
        FamilyName=a.FamilyName;
        Name=a.Name;
        Surname=a.Surname;
    }
    Person& operator=(const Person& a) 
    {
        if(this==&a)  
            return *this;
        FamilyName=a.FamilyName;
        Name=a.Name;
        Surname=a.Surname;
        return *this;
    }
    bool operator==(const Person& a) 
    {
        return 
           FamilyName==a.FamilyName &&
           Name==a.Name &&
           Surname==a.Surname;
    }
    bool operator<(const Person& a) 
    {
        return 
           FamilyName<a.FamilyName; 
    }
 
    friend ostream& operator<<(ostream& os,const Person& a); 
    friend istream& operator>>(istream& os,Person& a);
};

ostream& operator<<(ostream& os,const Person& a)
{
   is<<a.FamilyNane<<" "<<a.Name<<" "<<a.Surname;
    return os;
}
istream& operator>>(istream& is,Person& a)
{
   is>>a.FamilyNane>>a.Name>>a.Surname;
   return is;
}

   // 2
struct PhoneNumber
{
    unsigned int codeCountry, codeCity, adNumber;
    string callNumber;
    PhoneNumber(unsigned int c1 = 0, unsigned int c2 = 0, const string & str ="null", unsigned int ad = 0):codeCountry(c1), codeCity(c2), callNumber(str),adNumber(ad){};
    friend ostream & operator<<(ostream &out, const PhoneNumber &pn);
}number{7, 911, "1234567", 12};
 
ostream & operator<<(ostream &out, const PhoneNumber &pn)
    {
        out << "+" << pn.codeCountry << "(" << pn.codeCity << ")" << pn.callNumber << " " << pn.adNumber;
        return out;
    }
int main() 
   //1
{
    Peson a; 
    cin>>a;
    string sf,sn;
    cin>>sf>>sn;
    person b(sf,sn);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<(b==a)<<endl;
    cout<<(b<a)<<endl;
    
    //2
    cout << number;
   
    
    
    return 0;
}
