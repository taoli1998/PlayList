#include <iostream>
#include "PlayList.h"
#include "Song.h"

using namespace std;

/*
----------------Big O Natation-------------------
1. Default constructor
    O(1) : Default constructor is constant.
2. Destructor
    O(n): Destructor contains a while loop.
3. Copy constructor
    O(n): Copy constructor contains a while loop.
4. Overloaded assignment operator
    O(n): Overload assignment operator contains a while loop.
5. Insert
    O(n): Insert function contains a while loop.
6. Remove
    O(n): Remove function contains a for loop.
7. Get
    O(n): Get function contains a while loop.
8. Swap
    O(n): Swap function contains two while loops. However, they are not overlapping.
9. Size
    O(n): Get size function contains a while loop.
10. Enter a song
    O(n^2): This function contains a while loop inside a while loop.
11. Remove a song
    O(n^2): This function contains a while loop inside a while loop.
12. Swap two songs
    O(n^2): This function contains a while loop inside a while loop.
13. Print all the songs
    O(n^2): Print function contains a for loop inside a while loop.
*/


int main(){

    cout<<"CMPT 225 Assignment 1 - Tao Li"<<endl<<endl;
    PlayList list1;
    
    char command = 'y';
    while (command == 'y'){
        cout<<"Menu:"<<endl;
        cout<<"1 - Enter a song in the play list at a given position."<<endl;
        cout<<"2 - Remove a song from the play list at a given postion."<<endl;
        cout<<"3 - Swap two songs in the play list."<<endl;
        cout<<"4 - Print all the songs in the play list."<<endl;
        cout<<"5 - Quit."<<endl;

        unsigned int a;
        cout<<"Enter 1(insert), 2(remove), 3(swap), 4(print), 5(quit): ";
        cin>>a;
        if (a==1){
            string name;
            string artist;
            unsigned int position;
            unsigned int SongLength;

            cout<<"Song name: ";
            cin>>name;
            cout<<"Artist: ";
            cin>>artist;
            cout<<"Length: ";
            cin>>SongLength;
            cout<<"Position (1 to "<<list1.size()+1<<"): ";
            cin>>position; 
            while(position<1||position>list1.size()+1){
                cout<<"Please enter a valid positon!"<<endl;
                cout<<"Position (1 to "<<list1.size()+1<<"): ";
                cin>>position; 
            }
            Song s(name, artist, SongLength);
            list1.insert(s,position-1);
            cout<<"You entered "<<name<<" at position "<<position<<" in the play list."<<endl<<endl;
        }
        else if(a==2){
            unsigned int position;
            if(list1.size()==0)
            {
                cout<<"The play list is empty! No song left to be removed!"<<endl<<endl;
            }
            else{
                cout<<endl<<"Position (1 to "<<list1.size()<<"): ";
                cin>>position; 
            
                while(position<1||position>list1.size()){
                cout<<"Please enter a valid positon!"<<endl;
                cout<<"Position (1 to "<<list1.size()<<"): ";
                cin>>position; 
            }
            list1.remove(position-1); 

            }
                     

        }
        else if(a==3){
            unsigned int pos1, pos2;
            if(list1.size()==0)
            {
                cout<<"The play list is empty!"<<endl<<endl;
            }
            else if(list1.size()==1){
                cout<<"There is only one song in the play lsit!"<<endl<<endl;
            }
            else{
                cout<<"swap song at position (1 to "<<list1.size()<<"): ";
                cin>>pos1;
                while(pos1<1||pos1>list1.size()){
                    cout<<"Please enter a valid positon!"<<endl;
                    cout<<"Position (1 to "<<list1.size()<<"): ";
                    cin>>pos1; 
                }
                cout<<"with the song at position (1 to "<<list1.size()<<"): ";
                cin>>pos2;
                while(pos2<1||pos2>list1.size()){
                    cout<<"Please enter a valid positon!"<<endl;
                    cout<<"Position (1 to "<<list1.size()<<"): ";
                    cin>>pos2; 
            }
            list1.swap(pos1,pos2);
            }
            
            
        }
        else if(a==4){
            list1.print(list1);
            
        }
        else if(a==5){
            cout<<"You have chosen to quit the program!"<<endl<<endl;
            command = 'n';
            
        }
        else{
            cout<<endl<<"Invalid input! Please enter the above listed commands!"<<endl<<endl;
            command = 'y';
        }
        
    }

    return 0;
} 