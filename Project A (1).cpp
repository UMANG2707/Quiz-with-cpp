#include<time.h>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<mmsystem.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream>
#include"gotoxy.h"
#include"delay.h"
#include"setcolor.h"
#include"animation.h"
#include<iomanip>
using namespace std;
//variable decleration
int time_spent,score;
string name;
void PRINT_QUIZ();
void technical_quiz();
void nontech_quiz();
void get_score(int);
void scorecard();
void new_game();

class quiz
{   static int ca,guess;
    static string Que, Ans1, Ans2, Ans3, Ans4;
public:
   static void setvalues(string s1,string s2,string s3,string s4,string s5,int x)
{
    Que=s1;
    Ans1=s2;
    Ans2=s3;
    Ans3=s4;
    Ans4=s5;
    ca=x;
}
   static void askque()
    {
    PRINT_QUIZ();
    gotoxy(24,25);
    cout << Que <<  endl;
    gotoxy(35,28);
    cout << "1. " << Ans1;
    gotoxy(35,30);
    cout << "2. " << Ans2;
    gotoxy(35,32);
    cout << "3. " << Ans3;
    gotoxy(35,34);
    cout << "4. " << Ans4 ;
    gotoxy(35,36);
    cout << "5. for exit";
    gotoxy(35,37);
    cout << "UR ANSWER IS : " ;
    PlaySound(TEXT("sel.wav"),NULL,SND_SYNC);
    gotoxy(55,37);
    cin >> guess;
    if (guess>4 || guess<=0)
    {
        gotoxy(35,38);
        cout << "RE ENTER UR ANSWER : ";
        gotoxy(55,38);
        cin >> guess;
    }
    if(guess==ca)
    {
        gotoxy(40,40);
        cout << " GREAT U GOT 10 POINTS..!! " ;
        PlaySound(TEXT("point.wav"),NULL,SND_SYNC);
        score=score+10;//score is incresing 10 ifanswwer is correct
        Sleep(100);

    }
    else
    {
        gotoxy(40,40);
        cout << " OH !!! U R WRONR..." << endl;
        PlaySound(TEXT("next.wav"),NULL,SND_SYNC);
        gotoxy(40,43);
        cout << " THE CURRECT ANSWER IS : " << ca << "." ;
            if(ca==1)
        {
            PlaySound(TEXT("correct1.wav"),NULL,SND_SYNC);
        }
        else if(ca==2)
        {
            PlaySound(TEXT("Correct2.wav"),NULL,SND_SYNC);
        }
        else if(ca==3)
        {
            PlaySound(TEXT("Correct3.wav"),NULL,SND_SYNC);
        }
        else if(ca==4)
        {
            PlaySound(TEXT("Correct4.wav"),NULL,SND_SYNC);
        }
        Sleep(1000);
    }
    }
};
int quiz::ca;
int quiz::guess;
string quiz::Ans1;
string quiz::Ans2;
string quiz::Ans3;
string quiz::Ans4;
string quiz::Que;

//functions decleration
int get_rand_number();//for achive rndom numbers for quiz question


void PRINT_QUIZ()
{
    gotoxy(0,0);
    draw_lint(170);
    gotoxy(0,8);
    draw_lint(170);
    gotoxy(0,52);
    draw_lint(170);
    setcolor(2);
    gotoxy(80,3);
    setcolor(3);
    text_animation("QUIZ");
    gotoxy(8,14);
    cout << "DATE : " << __DATE__;
     gotoxy(148,14);
    cout << "TIME : " << __TIME__;
}

void get_score(int q)
{
    float score_p;
    system("cls");
    system("color 3e");
    gotoxy(40,25);
    cout << "YOUR FINAL SCORE IS : " << score ;
    Sleep(1000);
}

void current_score(int q)
{
    gotoxy(20,21);
    draw_lint(125);
    gotoxy(77,21);
    cout << "QUESTION:" << q;
    gotoxy(8,17);
    cout << "CURRENT SCORE:" << score;
    gotoxy(148,17);
    cout << "NAME : " << name;
}
int main()
{
    system("cls");
    int x=1,age;
    system("color 4e");
    PRINT_QUIZ();
    gotoxy(75,5);
    text_animation("WELCOME TO QUIZ GAME ");
    PlaySound(TEXT("welcome.wav"),NULL,SND_SYNC);
    gotoxy(68,18);
    text_animation("NAME : ");
    cin >> name;
    gotoxy(68,22);
    text_animation( "AGE : ");
    cin >> age;
    gotoxy(65,30);
    cout << "IF YOU READY THEN PRESS ENTER...!!";
    cin.get();
    if(  cin.get())
    {
        system("CLS");
        gotoxy(70,50);
        cout<<" OK,GOOD LUCK....!!!  ";
        Sleep(1000);
        system("CLS");
        system("color 7e");
        PRINT_QUIZ();
        gotoxy(68,22);
        cout << "1. TECHNICAL QUIZ";
        gotoxy(68,26);
        cout << "2. NONE-TECHNICAL QUIZ";
    }
    else
    {
        exit(0);
        system("CLS");
        system("color 5e");
        gotoxy(70,50);
        cout<<"OK,GOOD BYE !!!";
        system("cls"); gotoxy(70,50);cout<<" $$$ CREATED BY MIT AND UMANG $$$#";delay(1000);exit(1);
    }
    gotoxy(68,30);
    cout << " ENTER YOUR CHOICE : ";
    gotoxy(90,30);
    cin >> x ;
    switch(x)
    {
        case 1:technical_quiz();
        case 2:nontech_quiz();
        default:{
            system("cls");
            gotoxy(68,30);
            cout << " RE ENTER YOUR CHOICE : ";
            gotoxy(90,30);
            cin >> x ;
    }
    }
}
void new_game()
{
    int ch;
    system("cls");
    PRINT_QUIZ();
    system("color 2e");
    PlaySound(TEXT("thx.wav"),NULL,SND_SYNC);
    gotoxy(68,20);
    cout<<"1. PLAY AGAIN ";
    gotoxy(68,24);
    cout<<"2. MAIN MENU ";
    gotoxy(68,28);
    cout<<"3. EXIT";
    gotoxy(68,32);
    cout << "ENTER YOUR CHOICE : ";
    gotoxy(88,32);
    cin>>ch;
                U:
                switch(ch)
                {
                    case 1:system("cls");technical_quiz();break;//recursive call
                    case 2:system("cls");main();break;
                    case 3:system("cls");gotoxy(17,10);cout<<"$$$ CREATED BY MEET AND UMANG $$$";delay(1000);exit(1);
                    default:system("cls"); gotoxy(68,34);cout << "WRONG CHOICE ..!!" ; gotoxy(68,36); cout << " RE-ENTER YOUR CHOICE : "; gotoxy(88,36); cin >> ch; goto U;
                    main();
                }
}
void technical_quiz()
{
    int i,r,ch,a[50],m,q;
    gotoxy(60,34);
    cout << " HOW MANY QUESTION YOU WANT TO PLAY [BETWEEN 0 TO 50] : ";
    gotoxy(116,34);
    cin >> q;
    for(int i=1;i<=q;i++)
    {
        srand(time(NULL));

           int r=rand()%q+1;
            for(m=0;m<=i-1;m++)
            {
                if(r==a[m])
                {
                    break;
                }
            }
            if(m==i)
            {
                a[i]=r;
                system("cls");
                system("color 1");
                PRINT_QUIZ();
                current_score(i);
                switch(r)
                    {
                        case 1:
                            {
                                quiz::setvalues("a member function can always access the data member in _______,(in c++)." , "the class of which it is member " ,"the object of which is member " ,"the public part of its class","the private part of its class ",1);
                                quiz::askque();
                                break;
                            }
                        case 2:
                            {
                                quiz::setvalues("Which of the following keywords is used to control access to a class member?","Default ","break ","protected","asm",3);
                                quiz::askque();
                                break;
                            }
                        case 3:
                            {
                                quiz::setvalues("Which of the following access specifies is used in a class definition by default?","protected","private ","public ","eriend ",4);
                                quiz::askque();
                                break;
                            }
                        case 4:
                            {
                                quiz::setvalues("What is the difference between struct and class in C++?","All members of a structure are public and structures don't have constructors and destructors","Members of a class are private by default and members of struct are public by default. When deriving a struct from a class/struct, default access-specifier for a base class/struct is public and when deriving a class, default access specifier is private.","All members of a structure are public and structures don't have virtual functions ","All of the above",2);
                                quiz::askque();
                                break;
                            }
                        case 5:
                            {
                                quiz::setvalues("Which of the following two entities (reading from Left to Right) can be connected by the dot operator?","A class member and a class object.","A class object and a class.","A class and a member of that class.","A class object and a member of that class.",4);
                                quiz::askque();
                                break;
                            }
                        case 6:
                            {
                                quiz::setvalues("Which value we cannot assign to reference?","integer","float","unsign ","null",4);
                                quiz::askque();
                                break;
                            }
                        case 7:
                            {
                                quiz::setvalues("Identify the incorrect statement","Reference is the alternate name of the object","A reference value once defined can be reassigned"," A reference value once defined cannot be reassigned"," None of the mentioned",2);
                                quiz::askque();
                                break;
                            }
                        case 8:
                            {
                                quiz::setvalues("None of the mentioned","Alternate name for the class","Alternate name for the variable","Alternate name for the pointer ","None of the mentioned",4);
                                quiz::askque();
                                break;
                            }
                        case 9:
                            {
                                quiz::setvalues("Identify the correct sentence regarding inequality between reference and pointer."," we can not create the array of reference","we can create the Array of reference"," we can use reference to reference","none of the mentioned",1);
                                quiz::askque();
                                break;
                            }
                        case 10:
                            {
                                quiz::setvalues("Constructor is executed when ?","an object is created","an object is used","a class is declared ","an object goes out of scope.",1);
                                quiz::askque();
                                break;
                            }
                        case 11:
                            {
                                quiz::setvalues("Which of the following statement is correct regarding destructor of base class?","Destructor of base class should always be static.","	Destructor of base class should always be virtual","Destructor of base class should not be virtual.","	Destructor of base class should always be private",2);
                                quiz::askque();
                                break;
                            }
                        case 12:
                            {
                                quiz::setvalues("Which of the following statements is correct about the constructors and destructors? ","	Destructors can take arguments but constructors cannot.","Constructors can take arguments but destructors cannot."," Destructors can be overloaded but constructors cannot be overloaded.","Constructors and destructors can both return a value",2);
                                quiz::askque();
                                break;
                            }
                        case 13:
                            {
                                quiz::setvalues("Which of the following can be overloaded ?","Object"	,"Functions","perators","Both B and C",4);
                                quiz::askque();
                                break;
                            }
                        case 14:
                            {
                                quiz::setvalues(" What is the use of dynamic_cast operator?","it converts virtual base class to derived class"," it converts virtual base object to derived objeccts"," it will convert the operator based on precedence","none of the mentioned",1);
                                quiz::askque();
                                break;
                            }
                        case 15:
                            {
                                quiz::setvalues("Where does keyword ‘friend’ should be placed?"," function declaration"," function definition","main function "," none of the mentioned",1);
                                quiz::askque();
                                break;
                            }
                        case 16:
                            {
                                quiz::setvalues("Pick out the correct statement.","A friend function may be a member of another class"," A friend function may not be a member of another class","A friend function may or may not be a member of another class","None of the mentioned",3);
                                quiz::askque();
                                break;
                            }
                        case 17:
                            {
                                quiz::setvalues("What is the syntax of friend function?"," friend class1 Class2;"," friend class;","friend class "," none of the mentioned",1);
                                quiz::askque();
                                break;
                            }
                        case 18:
                            {
                                quiz::setvalues(". Which keyword is used to declare the friend function?","firend","friend","classfriend","myfriend",2);
                                quiz::askque();
                                break;
                            }
                            case 19:
                            {

                            quiz::setvalues(" Which rule will not affect the friend function?"," private and protected members of a class cannot be accessed from outside","private and protected member can be accessed anywhere"," protected member can be accessed anywhere","none of the mentioned",1);
                            quiz::askque();
                            break;
                        }
                        case 20:
                        {

                            quiz::setvalues("Which of the following statements about virtual base classes is correct?","It is used to provide multiple inheritance.","It is used to avoid multiple copies of base class in derived class.","It is used to allow multiple copies of base class in a derived class. ","	It allows private members of the base class to be inherited in the derived class.",2);
                            quiz::askque();
                            break;
                        }
                        case 21:
                        {

                            quiz::setvalues("How many objects can be created from an abstract class?","0","1","2","infinite",1);
                            quiz::askque();
                            break;
                        }
                        case 22:
                        {

                            quiz::setvalues("How can we make a class abstract?","By making all member functions constant.","	By making at least one member function as pure virtual function.","By declaring it abstract using the static keyword. ","	By declaring it abstract using the virtual keyword.",2);
                            quiz::askque();
                            break;
                        }
                        case 23:
                        {

                            quiz::setvalues("Which is used to describe the function using placeholder types?"," template parameters","template type parameters"," template type ","none of the mentioned",2);
                            quiz::askque();
                            break;
                        }
                        case 24:
                        {

                            quiz::setvalues("Pick out the correct statement.","you only need to write one function, and it will work with many different types"," it will take a long time to execute","duplicate code is increased","none of the mentioned",1);
                            quiz::askque();
                            break;
                        }
                        case 25:
                        {

                            quiz::setvalues("What can be passed by non-type template parameters during compile time?","int","float","constant expression ","none of the mentioned",3);
                            quiz::askque();
                            break;
                        }
                        case 26:
                        {

                            quiz::setvalues("What is a function template?","creating a function without having to specify the exact type","creating a function with having a exact type","all of the mentioned","none of the mentioned",1);
                            quiz::askque();
                            break;
                        }
                        case 27:
                        {
                            quiz::setvalues("From where does the template class derived?","regular non-templated C++ class"," templated class"," regular non-templated C++ class or templated class"," none of the mentioned",3);
                            quiz::askque();
                            break;
                        }
                        case 28:
                        {
                            quiz::setvalues("Which of the following functions can be used to allocate space for array in memory?","calloc()","malloc()","realloc() ","both a and b ",1);
                            quiz::askque();
                            break;
                        }
                        case 29:
                        {
                            quiz::setvalues("If a class x needs to be derived from a class y, which of the following ways is correct to do so?","class x : public y","class y : public x","class x derives public y ","class y derives public x ",1);
                            quiz::askque();
                            break;
                        }
                        case 30:
                        {
                            quiz::setvalues("Which of the following gives the memory address of the first element in array foo, an array with 100 elements?","foo[0];","foo;"," &foo; ","foo[1]; ",2);
                            quiz::askque();
                            break;
                        }
                        case 31:
                        {
                            quiz::setvalues("Which of the following is the boolean operator for logical-and?","&&","&","| ","|| ",1);
                            quiz::askque();
                            break;
                        }
                        case 32:
                        {
                            quiz::setvalues(" Which of the following is a valid inline for function foo? ","inline void foo() {}"," void foo() inline {} "," inline:void foo() {}  ","None of the above ",1);
                            quiz::askque();
                            break;
                        }
                        case 33:
                        {
                            quiz::setvalues(" How can you ensure that an inline function isn't inlined for a particular function call for function foo?"," unline x(); "," noexpand x(); "," x();  ","  This is not possible on a case-by-case basis",4);
                            quiz::askque();
                            break;
                        }
                        case 34:
                        {
                            quiz::setvalues("What keyword covers unhandled possibilities?","all","default"," other","contingency",2);
                            quiz::askque();
                            break;
                        }
                        case 35:
                        {
                            quiz::setvalues("Which conversion is not possible?","int to float","float to int","char to float ","All are possible ",4);
                            quiz::askque();
                            break;
                        }
                        case 36:
                        {
                            quiz::setvalues(" Which of the following is not a valid ofstream argument?"," ios::app","ios::trunc","os::noreplace "," ios::create ",4);
                            quiz::askque();
                            break;
                        }
                        case 37:
                        {
                            quiz::setvalues("Which is a valid typecast?"," a(char);"," char:a;"," (char)a; "," to(char, a); ",3);
                            quiz::askque();
                            break;
                        }
                        case 38:
                        {
                            quiz::setvalues(" What does the argument count variable store? ","the number of arguments "," the number of arguments plus one","the number of arguments minus one  ","The total size of the argument array ",2);
                            quiz::askque();
                            break;
                        }
                        case 39:
                        {
                            quiz::setvalues(" What type is argv?","char**","int ","char* ","int* ",1);
                            quiz::askque();
                            break;
                        }
                        case 40:
                        {
                            quiz::setvalues("Which of the following gives the memory address of a pointer a?","a","&a"," *a","none of these ",1);
                            quiz::askque();
                            break;
                        }
                        case 41:
                        {
                            quiz::setvalues("Which of the following gives the memory address of integer variable a;?","*a","&a","a "," address(a)",2);
                            quiz::askque();
                            break;
                        }
                        case 42:
                        {
                            quiz::setvalues("Which type of casting can be used only with pointers and references to objects?","Dynamic_cast","cast","Static_cast ","Pointer_Cast ",1);
                            quiz::askque();
                            break;
                        }
                        case 43:
                        {
                            quiz::setvalues("Which type of class has only one unique value for all the objects of that same class?","friend","this","static ","all of above ",3);
                            quiz::askque();
                            break;
                        }
                        case 44:
                        {
                            quiz::setvalues(" How do we check if the file has reached its end?","Use if_file_end()","use end_of_file()","use eof() ","both a and c ",3);
                            quiz::askque();
                            break;
                        }
                        case 45:
                        {
                            quiz::setvalues("How would you read the expression x.y as?","member y of object pointed by x"," member y of object x"," member x of object y "," All of the above ",2);
                            quiz::askque();
                            break;
                        }
                        case 46:
                        {
                            quiz::setvalues("Special symbol permitted with in the identifier name.","@","#","$ ","_ ",4);
                            quiz::askque();
                            break;
                        }
                        case 47:
                        {
                            quiz::setvalues("Compiler generates ___ file"," Executable code","Object code","Assembly code ","None of the above. ",2);
                            quiz::askque();
                            break;
                        }
                        case 48:
                        {
                            quiz::setvalues("The pointer which stores always the current active object address is __","auto_ptr","this","p ","none of these  ",2);
                            quiz::askque();
                            break;
                        }
                        case 49:
                        {
                            quiz::setvalues("Objects created using new operator are stored in __ memory."," Cache","heap","stack ","none of these ",2);
                            quiz::askque();
                            break;
                        }
                        case 50:
                        {
                            quiz::setvalues("Which operator is required to be overloaded as member function only?","_","__","= ","-- ",3);
                            quiz::askque();
                            break;
                        }
                    }

                }
                else
                {
                    i--;
                }
            }
        get_score(q);
        new_game();
    }
void nontech_quiz()
{
  int i,r,ch,a[50],m,x;
    gotoxy(60,34);
    cout << " HOW MANY QUESTION YOU WANT TO PLAY [BETWEEN 0 TO 50] : ";
    gotoxy(116,34);
    cin >> x;

        srand(time(NULL));
        for(i=1;i<=x;i++)
        {
           int r=rand()%x+1;
            for(m=0;m<=i-1;m++)
            {
                if(r==a[m])
                {
                    break;
                }
            }
            if(m==i)
            {
                a[i]=r;
                system("cls");
                system("color 1");
                PRINT_QUIZ();
                current_score(i);
                switch(r)
                    {
                        case 1:
                            {
                                quiz::setvalues("In which city of India, 90% of world’s small diamonds processed ?","Baroda" ,"Mumbai","Surat","Jaipur",3);
                                quiz::askque();
                                break;
                            }
                        case 2:
                            {
                                quiz::setvalues("When Ozone is heated its volume will…. ?","increases","decreases","remains unchanged","First Increase, then decrease",3);
                                quiz::askque();
                                break;
                            }
                        case 3:
                            {
                                quiz::setvalues("Chlorophyll absorbs which of the wavelength of the Sun light ?","Green & Blue","Green & Red","Red & Blue","Red & Yellow",3);
                                quiz::askque();
                                break;
                            }
                        case 4:
                            {
                                quiz::setvalues("Which among the following is the first national park of India?","Bandipur","Corbett","Periyar","Keoladeo",2);
                                quiz::askque();
                                break;
                            }
                        case 5:
                            {
                                quiz::setvalues("Which among following is rich in Ozone?","Stratosphere","Mesosphere","Ionosphere","Troposphere",1);
                                quiz::askque();
                                break;
                            }
                        case 6:
                            {
                                quiz::setvalues("First session of Loksabha was held in which among the following years?","1950","1951","1952","1953",3);
                                quiz::askque();
                                break;
                            }
                        case 7:
                            {
                                quiz::setvalues("orpus Callosum makes an important part of which among the following organs in Human body?","spinal chord","kidney","liver","Brain",4);
                                quiz::askque();
                                break;
                            }
                        case 8:
                            {
                                quiz::setvalues("Which among following is not a Fish?","Cuttle Fish","Gold Fish","Dog Fish","Zebra Fish",1);
                                quiz::askque();
                                break;
                            }
                        case 9:
                            {
                                quiz::setvalues("Which among following is also known as white gold?","Nickel","Rhodium","Platinum","Palladium",3);
                                quiz::askque();
                                break;
                            }
                        case 10:
                            {
                                quiz::setvalues("The terms Udara, Mudara and Tara are related to which among the following as per the ancient Indian texts?","Medicines","Gods","Millitary science","music",4);
                                quiz::askque();
                                break;
                            }
                        case 11:
                            {
                                quiz::setvalues("Suez Canal joins Mediterranean Sea with which among the following seas?","Red sea","dead sea","Caspian sea","White sea",1);
                                quiz::askque();
                                break;
                            }
                        case 12:
                            {
                                quiz::setvalues("Shahgarh Landscape, in Rajasthan is being considered for relocation / reintroduction of which among the following animals ?","tiger","lion","Cheetah","dog",3);
                                quiz::askque();
                                break;
                            }
                        case 13:
                            {
                                quiz::setvalues("Under which among the following Governor Generals of India, the Public works department was started in 1848?","Lord Dalhousie","Lord Viscount Canning","Lord Wellesley","Lord William Bentinck",1);
                                quiz::askque();
                                break;
                            }
                        case 14:
                            {
                                quiz::setvalues("Ian Fleming is known for creating which among the following famous characters?","Spiderman","James bond","Tom and Jerry","Pink panther",2);
                                quiz::askque();
                                break;
                            }
                        case 15:
                            {
                                quiz::setvalues("Which among the following country is inside the European Union but Outside the Eurozone?","Slovakia","Slovania","Denmark","Spain",3);
                                quiz::askque();
                                break;
                            }
                        case 16:
                            {
                                quiz::setvalues("In ancient India, the term Nishka was related to which among the following?","Crop","Tax","Currency","Tool",3);
                                quiz::askque();
                                break;
                            }
                        case 17:
                            {
                                quiz::setvalues("Birth anniversary of which among the following leaders is observed as National Education Day?","S Radhakrishnanan","Dr. Rajendra Prasad","Maulana Abul Kalam Azad","Pandit Madan Mohan Malviya",3);
                                quiz::askque();
                                break;
                            }
                        case 18:
                            {
                                quiz::setvalues("Who among the following was the first Indian to win an Olympic medal ?","K D Jadhav","P T Usha","Leander paes","Dhyan Chand",1);
                                quiz::askque();
                                break;
                            }
                            case 19:
                            {

                            quiz::setvalues("Who among the following was the First Indian Cricketer to bag 500 wickets in Test matches?","Kapil Dev","Srinath","Anil Kumble","Harbhajan Singh",3);
                            quiz::askque();
                            break;
                        }
                        case 20:
                        {

                            quiz::setvalues("Demand of which among the following will be called as Direct Demand?","Weaving Machine","Sweater","Wool for Factory","Wool for making gloves",2);
                            quiz::askque();
                            break;
                        }
                        case 21:
                        {
                            quiz::setvalues("What kind of forests are found in Siberian climate?","Deciduous ","Coniferous","Tropical","Montane Grasslands",2);
                            quiz::askque();
                            break;
                        }
                        case 22:
                        {
                            quiz::setvalues("Which of the following canals is considered to be an important link between the developed countries and the developing countries?","Panama Canal","Suez canal","Kiel canal","Grand canal",2);
                            quiz::askque();
                            break;
                        }
                        case 23:
                        {
                            quiz::setvalues("Which of the following is NOT a petrochemical centre of India?","Koyali","Jamnagar","Managlore","Rourkela",4);
                            quiz::askque();
                            break;
                        }
                        case 24:
                        {
                            quiz::setvalues("Kip is a currency of which country ?","Laos","Cambodia","uganda","Brunei",1);
                            quiz::askque();
                            break;
                        }
                        case 25:
                        {
                            quiz::setvalues("How long does the Earth take to turn 1° Longitude during its rotation?","4 min","4 sec","4 hr","40 sec",1);
                            quiz::askque();
                            break;
                        }
                        case 26:
                        {
                            quiz::setvalues("Which among the following is the longest day in northern hemisphere?","June 21","March 21","September 21","May 31",1);
                            quiz::askque();
                            break;
                        }
                        case 27:
                        {
                            quiz::setvalues("How many times Sun is heavier than Earth?","3,300 times","33,000 times","3,30,000 times","33,30,000 times",3);
                            quiz::askque();
                            break;
                        }
                        case 28:
                        {
                            quiz::setvalues("Approximately how much time does a Sun ray take reaching Earth?","400 sec","500 sec","600 sec","700 sec",2);
                            quiz::askque();
                            break;
                        }
                        case 29:
                        {
                           quiz::setvalues("What is the number of known satellites of Jupiter?","35","55","79","42",3);
                            quiz::askque();
                            break;
                        }
                        case 30:
                        {
                            quiz::setvalues("What is normally found in the western side of the continents situated near tropics?","Mountains","Deserts","Rivers","Lakes",2);
                            quiz::askque();
                            break;
                        }
                        case 31:
                        {
                            quiz::setvalues("Who has been appointed as the new Deputy Election Commissioner of India?","Anurag Agarwal","Mukul Ratra","Girish C Hosur","Chandra Bhushan Kumar",4);
                            quiz::askque();
                            break;
                        }
                        case 32:
                        {
                            quiz::setvalues("Who has been appointed as the new Joint Secretary of 15th Finance Commission of India?","Krishna Bahadur Singh","Ravi Kota","Anoop Singh ","Sanjay Adlakha",2);
                            quiz::askque();
                            break;
                        }
                        case 33:
                        {
                            quiz::setvalues("Which Indian umpire has been recently promoted as umpire for International Hockey Federation (FIH)?","Depika Kaul","Nepolean Singh","Satinder Sarma","Durga Thakur",4);
                            quiz::askque();
                            break;
                        }
                        case 34:
                        {
                            quiz::setvalues("Who has won the 2016 Laureus World Sportsman of the Year Award?","Lewis Hamilton","Usain Bolt","Novak Djokovic","Lionel Messi",3);
                            quiz::askque();
                            break;
                        }
                        case 35:
                        {
                            quiz::setvalues("“Hopman cup” is related to which sports?","Football","Lawn Tennis","Badminton","Cricket",2);
                            quiz::askque();
                            break;
                        }
                        case 36:
                        {
                            quiz::setvalues("Who has won the 2016 Formula 1 Gulf Air Bahrain Grand Prix? ","Kimi Raikkonen","Lewis Hamilton ","Nico Rosberg ","Daniel Ricciardo ",3);
                            quiz::askque();
                            break;
                        }
                        case 37:
                        {
                            quiz::setvalues("The most potent greenhouse gas among the following is __?","Carbon dioxide","Methane","Water Vapor","Ozone",3);
                            quiz::askque();
                            break;
                        }
                        case 38:
                        {
                            quiz::setvalues("“Macintosh” an Operating System is a product of ?","Microsoft","Apple","Intel","Google",2);
                            quiz::askque();
                            break;
                        }
                        case 39:
                        {
                            quiz::setvalues("In Binary System, the power of _____ is used ","2","4","6","8",1);
                            quiz::askque();
                            break;
                        }
                        case 40:
                        {
                            quiz::setvalues("In computing, 1 nibble = ?","4 Bits","4 Bytes","8 Bytes","8 Kilo Bytes",1);
                            quiz::askque();
                            break;
                        }
                        case 41:
                        {
                            quiz::setvalues("In the Windows XP, what does XP stands for? ","Extra-Powerful","Experience","Extended Platform","Experience Platform",2);
                            quiz::askque();
                            break;
                        }
                        case 42:
                        {
                            quiz::setvalues("Which among the following service does not belong to Google?","Youtube","Blogger","Picnik","Xbox",4);
                            quiz::askque();
                            break;
                        }
                        case 43:
                        {
                            quiz::setvalues("Which of the following blogging platform was first launched by Pyra Labs?","WordPress","Blogger","Typepad","Twitter",2);
                            quiz::askque();
                            break;
                        }
                        case 44:
                        {
                            quiz::setvalues("”Don’t be evil” is the informal corporate motto of which of the following internet giants?","Google","Yahoo","Microsoft","Baidu",1);
                            quiz::askque();
                            break;
                        }
                        case 45:
                        {
                            quiz::setvalues("In India, the National Voter’s Day is celebrated on?","December 17th","March 8th","January 17th","January 25",4);
                            quiz::askque();
                            break;
                        }
                        case 46:
                        {
                            quiz::setvalues("The ‘thickness’ of Stratospheric Ozone layer is measured in/on: ","Sieverts","Dobson units","Melson units","Beaufort Scale",2);
                            quiz::askque();
                            break;
                        }
                        case 47:
                        {
                            quiz::setvalues("Both the processes of transfer of power and the partition of India were hurried through in ____ days.","68","70","72","85",3);
                            quiz::askque();
                            break;
                        }
                        case 48:
                        {
                            quiz::setvalues("Which of the following rivers does not flow into the Arabian Sea?","Tungabhadra","Sabarmati","Mandovi","Narmada",1);
                            quiz::askque();
                            break;
                        }
                        case 49:
                        {
                            quiz::setvalues("On which date, Flag Day of India is celebrated?","December 3","December 7","December 11","December 17",2);
                            quiz::askque();
                            break;
                        }
                        case 50:
                        {
                            quiz::setvalues("On which of the following dates World Press Freedom Day is observed in May ?","20th February","21st February ","20th March","21st March",4);
                            quiz::askque();
                            break;
                        }
                    }

                }
                else
                {
                    i--;
                }
            }

        get_score(x);
        new_game();
    }
void getscore(int score)
{
	ofstream f1("File.txt");
	f1<<"\n Name : "<<name<<" Score : "<<score;
	f1.close();
	cout<<"scorecard updated";
}
void scorecard()
{
    char ch;
	ifstream f1;
	printf("\t\t\t....The scores are...\n");
	f1.open("File.txt");
	while(!f1.eof())
	{
	    ch=f1.get();
	    cout<<ch;
	}
	main();
}



